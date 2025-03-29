#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
    pid_t child_pid;
    child_pid=fork();
    if (child_pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        printf("Child process has PID: %d\n",getpid());
        printf("Child process has PPID: %d\n",getppid());
        exit(52);
    }else{
        printf("Perent process has PID: %d\n",getpid());
        printf("Perent process has PPID: %d\n",getppid());
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("child process ended with status: %d\n",WEXITSTATUS(status));
        }
        else{
            printf("the child process ended incorrectly\n");
        }
    }
    exit(0);
}