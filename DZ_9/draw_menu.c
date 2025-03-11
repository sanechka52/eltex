#include "heder_9_2.h"
#include <ncurses.h>

void draw_menu(struct workspace *ws) {
    if (ws == NULL) {
        return; // Проверка на NULL, чтобы избежать ошибок сегментации
    }

    clear(); // Очищаем экран
    refresh();

    for (int s = 0; s < 2; s++) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLUE);

        int HEIGHT, WIDTH;
        getmaxyx(stdscr, HEIGHT, WIDTH);

        int start_y = (LINES - HEIGHT) / 2;
        int start_x = (COLS - WIDTH) / 2 + COLS * 0.5 * s;

        // Создаем новое окно
        WINDOW *menu_win = newwin(HEIGHT, WIDTH / 2, start_y, start_x);
        if (menu_win == NULL) {
            continue; // Пропускаем итерацию, если не удалось создать окно
        }

        wbkgd(menu_win, COLOR_PAIR(1));
        box(menu_win, 0, 0);

        for (int i = 0; i < ws[s].ptr_num; i++) {
            if (ws[s].ptr_choice == i) {
                wattron(menu_win, A_REVERSE); // Подсвечиваем выбранный пункт
            }
            mvwprintw(menu_win, i + 2, 2, "%s", (ws[s].ptr_namelist)[i]->d_name);
            wattroff(menu_win, A_REVERSE);
        }

        wrefresh(menu_win);

        // Освобождаем память, выделенную под окно
        delwin(menu_win);
    }
}