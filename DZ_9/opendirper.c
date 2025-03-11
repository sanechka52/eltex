#include "heder_9_2.h"


int opendirper(struct workspace *ws) {
    // Проверяем, что ws инициализирован
    if (ws == NULL) {
        fprintf(stderr, "Ошибка: ws не инициализирован\n");
        return -1;
    }

    // Проверяем, что current_path_ptr инициализирован
    if (ws[0].current_path_ptr == NULL) {
        ws[0].current_path_ptr = (char *)malloc(PATH_MAX);
        if (ws[0].current_path_ptr == NULL) {
            perror("Ошибка выделения памяти");
            return -1;
        }
    }

    char old_parent[PATH_MAX];
    char save[PATH_MAX];

    // Проверяем, выбрана ли текущая директория "."
    if (strcmp(ws[0].ptr_namelist[ws[0].ptr_choice]->d_name, ".") == 0) {
        DIR *dir = opendir(ws[0].current_path_ptr);
        if (dir == NULL) {
            perror("Ошибка при открытии директории");
            return -1;
        }
        int n = scandir(ws[0].current_path_ptr, &ws[0].ptr_namelist, NULL, alphasort);
        closedir(dir);
        if (n == -1) {
            perror("Ошибка при чтении директории");
        }
        return n;
    } else {
        // Копируем текущий путь в save и old_parent
        strncpy(save, ws[0].current_path_ptr, PATH_MAX);
        strncpy(old_parent, ws[0].current_path_ptr, PATH_MAX);

        // Добавляем выбранную директорию к пути
        strncat(save, "/", PATH_MAX - strlen(save) - 1);
        strncat(save, ws[0].ptr_namelist[ws[0].ptr_choice]->d_name, PATH_MAX - strlen(save) - 1);

        // Освобождаем старый current_path_ptr, если он был выделен динамически
        if (ws[0].current_path_ptr != NULL) {
            free(ws[0].current_path_ptr);
        }

        // Выделяем память для нового пути и копируем save
        ws[0].current_path_ptr = strdup(save);
        if (ws[0].current_path_ptr == NULL) {
            perror("Ошибка при выделении памяти");
            return -1;
        }
    }

    // Открываем новую директорию
    DIR *dir = opendir(ws[0].current_path_ptr);
    if (dir == NULL) {
        perror("Ошибка при открытии директории");

        // Восстанавливаем старый путь
        if (ws[0].current_path_ptr != NULL) {
            free(ws[0].current_path_ptr);
        }
        ws[0].current_path_ptr = strdup(old_parent);
        if (ws[0].current_path_ptr == NULL) {
            perror("Ошибка при выделении памяти");
            return -1;
        }

        return -1;
    }

    // Сканируем новую директорию
    int n = scandir(ws[0].current_path_ptr, &ws[0].ptr_namelist, NULL, alphasort);
    if (n == -1) {
        perror("Ошибка при чтении директории");
    }

    closedir(dir);
    return n;
}