#include "heder_9_2.h"


int main() {
    char current_path[PATH_MAX];
    if (getcwd(current_path, sizeof(current_path)) == NULL) {
        perror("Ошибка при получении текущей директории");
        return 1;
    }

    struct dirent **namelist = NULL;
    DIR *dir = opendir(current_path);
    if (dir == NULL) {
        perror("Ошибка при открытии директории");
        return 1;
    }
    closedir(dir); // Закрываем директорию сразу после использования

    int num = scandir(current_path, &namelist, NULL, alphasort);
    if (num == -1) {
        perror("Ошибка при чтении директории");
        return 1;
    }

    struct workspace ws[2] = {
        {0, num, namelist, NULL},
        {0, num, namelist, NULL}
    };

    // Выделяем память для current_path_ptr и копируем пути
    for (int i = 0; i < 2; i++) {
        ws[i].current_path_ptr = (char *)malloc(PATH_MAX);
        if (ws[i].current_path_ptr == NULL) {
            perror("Ошибка выделения памяти");
            return 1;
        }
        strncpy(ws[i].current_path_ptr, current_path, PATH_MAX - 1);
        ws[i].current_path_ptr[PATH_MAX - 1] = '\0'; // Гарантируем завершение строки
    }

    system_start();

    int running = 1;
    int num_stract = 0;

    while (running) {
        draw_menu(ws);
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                ws[num_stract].ptr_choice = 
                    (ws[num_stract].ptr_choice - 1 + ws[num_stract].ptr_num) % ws[num_stract].ptr_num;
                break;
            case KEY_DOWN:
                ws[num_stract].ptr_choice = 
                    (ws[num_stract].ptr_choice + 1) % ws[num_stract].ptr_num;
                break;

            case '\n': {
                int error_flags = opendirper(&ws[num_stract]);
                if (error_flags != -1) {
                    ws[num_stract].ptr_num = error_flags;
                    ws[num_stract].ptr_choice = (ws[num_stract].ptr_choice > 1) ? 0 : ws[num_stract].ptr_choice;
                }
                break;
            }

            case 27: // ESC
                running = 0;
                break;

            case '\t': // TAB
                num_stract ^= 1; // Переключаем между 0 и 1
                break;
        }
    }

    // Корректное освобождение памяти
    for (int i = 0; i < 2; i++) {
        if (ws[i].current_path_ptr) {
            free(ws[i].current_path_ptr);
        }
        if (ws[i].ptr_namelist) {
            for (int j = 0; j < ws[i].ptr_num; j++) {
                free(ws[i].ptr_namelist[j]); // Освобождаем каждый элемент
            }
            free(ws[i].ptr_namelist); // Освобождаем сам массив
        }
    }

    // Завершение ncurses
    echo();
    curs_set(1);
    endwin();

    return 0;
}