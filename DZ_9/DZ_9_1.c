#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    int text = open("output.txt", O_CREAT | O_RDWR, 0666);
    if (text == -1) {
        perror("Ошибка при открытии файла output.txt");
        return 1;
    }

    const char *buf = "String from file";
    ssize_t zapis = write(text, buf, strlen(buf));
    if (zapis == -1) {
        perror("Ошибка при записи в файл");
        close(text);
        return 1;
    }

    if (close(text) == -1) {
        perror("Ошибка при закрытии файла output.txt");
        return 1;
    }

    int text2 = open("output.txt", O_RDWR);
    if (text2 == -1) {
        perror("Ошибка при открытии файла output.txt для чтения");
        return 1;
    }

    char buf_reverse[1];

    for (int i = 1; i <= strlen(buf); i++) {
        off_t kursor = lseek(text2, -i, SEEK_END);
        if (kursor == -1) {
            perror("Ошибка при перемещении курсора");
            close(text2);
            return 1;
        }

        ssize_t xport = read(text2, buf_reverse, 1);
        if (xport == -1) {
            perror("Ошибка при чтении файла");
            close(text2);
            return 1;
        }

        printf("%c", buf_reverse[0]);
    }
    printf("\n");

    if (close(text2) == -1) {
        perror("Ошибка при закрытии файла output.txt");
        return 1;
    }

    return 0;
}