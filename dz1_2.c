#include <stdio.h>

void printBinary(int n) {
    unsigned int mask = 1 << (sizeof(n) * 8 - 1); // создаем маску для самого старшего бита
    int started = 0; // флаг для отслеживания начала вывода

    for (int i = 0; i < sizeof(n) * 8; i++) {
        if (n & mask) { // проверяем, установлен ли бит
            printf("1");
            started = 1; // начинаем вывод
        } else if (started) {
            printf("0");
        }
        mask >>= 1; // сдвигаем маску вправо
    }

    if (!started) { // если число равно 0
        printf("0");
    }
}

int main() {
    int number;

    printf("Введите целое отрицательное число: ");
    scanf("%d", &number);

    if (number >= 0) {
        printf("Ошибка: введено неотрицательное число.\n");
        return 1;
    }

    printf("Двоичное представление: ");
    printBinary(number);
    printf("\n");

    return 0;
}
