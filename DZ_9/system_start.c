#include "heder_9_2.h"
void system_start(){
    initscr(); // Инициализация ncurses
    cbreak(); // Режим cbreak
    noecho(); // Отключение автоматического вывода нажатых клавиш
    keypad(stdscr, TRUE); // Включение поддержки функциональных клавиш
    curs_set(0); // Скрытие курсора
    ESCDELAY = 0;
}