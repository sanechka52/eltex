#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <pwd.h>
#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
#define COLOR_GREEN "\x1b[32m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_RESET "\x1b[0m"

void parse_input(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, " \t\n\r");
    
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \t\n\r");
    }
    args[i] = NULL;
}

void execute_command(char **args) {
    // Проверяем, является ли команда cd
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(args[1]) ){  // Меняем директорию
                perror("cd failed");
            }
        }
        return;
    }
    if (strcmp(args[0], "help") == 0) {
        if (args[1] != NULL) {
            fprintf(stderr, "help: has many arguments\n");
        }else{
            pid_t pid = fork();
    
            if (pid == -1) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            } else if (pid == 0){
                // Дочерний процесс
                if (execv("/bin/ls",(char *[]){"ls","/bin",NULL}) == -1) {
                    // Если не найдено в /bin, попробуем /usr/bin
                    if (execv("/usr/bin/ls", (char *[]){"ls","/usr/bin",NULL}) == -1) {
                        perror("execv failed");
                        exit(EXIT_FAILURE);
                    }
                }
            }else {
                // Родительский процесс ждёт завершения
                wait(NULL);
            }
        }
        return;
    }
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Дочерний процесс
        char path[256];
        snprintf(path, sizeof(path), "/bin/%s", args[0]);
        
        if (execv(path, args) == -1) {
            // Если не найдено в /bin, попробуем /usr/bin
            snprintf(path, sizeof(path), "/usr/bin/%s", args[0]);
            if (execv(path, args) == -1) {
                perror("execv failed");
                exit(EXIT_FAILURE);
            }
        }
    } else {
        // Родительский процесс ждёт завершения
        wait(NULL);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    char current_path[PATH_MAX];
    

    while (1) {
        if (getcwd(current_path, sizeof(current_path)) == NULL) {
            perror("Ошибка при получении текущей директории");
            return 1;
        }
        uid_t uid = getuid();
        struct passwd *pw = getpwuid(uid);
        char *name = strtok(pw->pw_gecos, ",");
        if (pw) {
            printf("%s%s@%s%s:%s%s%s$ ",COLOR_GREEN, pw->pw_name,name,
                COLOR_RESET,COLOR_BLUE,current_path,COLOR_RESET);
        }
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            break; // EOF (Ctrl+D)
        }
        
        if (strcmp(input, "exit\n") == 0) {
            break; // Выход по команде exit
        }
        
        parse_input(input, args);
        
        if (args[0] != NULL) {
            execute_command(args);
        }
    }
    
    return 0;
}