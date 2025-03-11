#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <libgen.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>  // Добавлено для проверки типа файла

#define NUM_WORKSPACES 2

struct workspace {
    int ptr_choice;
    int ptr_num;
    struct dirent **ptr_namelist;
    char *current_path_ptr;
};

// Прототипы функций
void free_workspace(struct workspace *ws);
int handle_directory_change(struct workspace *ws);

int main() {
    struct workspace ws[NUM_WORKSPACES] = {0};
    int running = 1;
    int active_ws = 0;

    // Инициализация обеих рабочих областей
    for (int i = 0; i < NUM_WORKSPACES; i++) {
        ws[i].current_path_ptr = (char*)malloc(PATH_MAX);
        if (!ws[i].current_path_ptr || getcwd(ws[i].current_path_ptr, PATH_MAX) == NULL) {
            perror("Initialization error");
            return 1;
        }
        
        // Первоначальное сканирование директории
        ws[i].ptr_num = scandir(ws[i].current_path_ptr, &ws[i].ptr_namelist, NULL, alphasort);
        if (ws[i].ptr_num == -1) {
            perror("scandir error");
            return 1;
        }
    }

    // Инициализация ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    ESCDELAY = 0;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    while (running) {
        clear();
        
        // Отрисовка обеих панелей
        for (int s = 0; s < NUM_WORKSPACES; s++) {
            int height, width;
            getmaxyx(stdscr, height, width);
            
            WINDOW *win = newwin(height, width/NUM_WORKSPACES, 0, s*(width/NUM_WORKSPACES));
            wbkgd(win, COLOR_PAIR(1));
            box(win, 0, 0);
            
            // Вывод содержимого директории
            for (int i = 0; i < ws[s].ptr_num; i++) {
                if (i == ws[s].ptr_choice && s == active_ws) 
                    wattron(win, A_REVERSE);
                    
                mvwprintw(win, i+1, 1, "%s", ws[s].ptr_namelist[i]->d_name);
                wattroff(win, A_REVERSE);
            }
            
            wrefresh(win);
            delwin(win);
        }

        // Обработка ввода
        int ch = getch();
        switch(ch) {
            case KEY_UP:
                ws[active_ws].ptr_choice = (ws[active_ws].ptr_choice - 1 + ws[active_ws].ptr_num) % ws[active_ws].ptr_num;
                break;
                
            case KEY_DOWN:
                ws[active_ws].ptr_choice = (ws[active_ws].ptr_choice + 1) % ws[active_ws].ptr_num;
                break;
                
            case '\n': {
                int result = handle_directory_change(&ws[active_ws]);
                if (result == -1) beep();
                break;
            }
                
            case '\t':
                active_ws = (active_ws + 1) % NUM_WORKSPACES;
                break;
                
            case 27: // ESC
                running = 0;
                break;
        }
    }

    // Освобождение ресурсов
    for (int i = 0; i < NUM_WORKSPACES; i++) {
        free_workspace(&ws[i]);
    }
    
    endwin();
    return 0;
}

void free_workspace(struct workspace *ws) {
    if (ws->ptr_namelist) {
        for (int i = 0; i < ws->ptr_num; i++) {
            free(ws->ptr_namelist[i]);
        }
        free(ws->ptr_namelist);
    }
    free(ws->current_path_ptr);
}

int handle_directory_change(struct workspace *ws) {
    struct dirent *entry = ws->ptr_namelist[ws->ptr_choice];
    char new_path[PATH_MAX];
    struct stat st; // Правильное объявление структуры

    // Создаем полный путь
    snprintf(new_path, sizeof(new_path), "%s/%s", ws->current_path_ptr, entry->d_name);

    // Проверка типа файла с обработкой ошибок
    if (stat(new_path, &st) != 0) { // Правильная проверка возвращаемого значения
        perror("stat error");
        return -1;
    }
    
    if (!S_ISDIR(st.st_mode)) {
        return -1; // Не директория
    }

    // Обновление пути
    char *old_path = strdup(ws->current_path_ptr);
    if (!old_path) return -1;

    // Освобождаем старые ресурсы
    free_workspace(ws);
    
    // Устанавливаем новый путь
    ws->current_path_ptr = strdup(new_path);
    if (!ws->current_path_ptr) {
        ws->current_path_ptr = old_path;
        return -1;
    }
    free(old_path);

    // Сканируем новую директорию
    ws->ptr_num = scandir(ws->current_path_ptr, &ws->ptr_namelist, NULL, alphasort);
    if (ws->ptr_num == -1) {
        perror("scandir error");
        return -1;
    }
    
    ws->ptr_choice = 0;
    return 0;
}