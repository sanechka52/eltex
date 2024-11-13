#include <stdio.h>

int main() {
    unsigned int originalNumber; // Исходное число
    unsigned int newByteValue;   // Новое значение третьего байта

    // Запрашиваем у пользователя исходное число
    printf("Введите положительное целое число: ");
    scanf("%u", &originalNumber);

    // Запрашиваем у пользователя новое значение для третьего байта
    printf("Введите новое значение для третьего байта (0-255): ");
    scanf("%u", &newByteValue);

    // Проверяем, что новое значение в пределах 0-255
    if (newByteValue > 255) {
        printf("Ошибка: значение должно быть в диапазоне 0-255.\n");
        return 1;
    }

    // Меняем значение третьего байта
    // Сначала очищаем третий байт (сдвиг на 16 бит)
    originalNumber &= 0xFF00FFFF; // Очищаем третий байт (байт с индексом 2)
    
    // Затем устанавливаем новый байт (сдвигаем новое значение на 16 бит)
    originalNumber |= (newByteValue << 16); // Устанавливаем новый третий байт

    // Выводим результат
    printf("Новое число: %u\n", originalNumber);
    printf("Двоичное представление: ");
    
    // Выводим двоичное представление результата
    for (int i = sizeof(originalNumber) * 8 - 1; i >= 0; i--) {
        printf("%u", (originalNumber >> i) & 1);
    }
    printf("\n");

    return 0;
}