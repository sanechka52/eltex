#ifndef HEDER_9_2_H
#define HEDER_9_2_H

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <libgen.h>
#include <limits.h>
#include <unistd.h>

struct workspace {
    int ptr_choice;
    int ptr_num;
    struct dirent **ptr_namelist;
    char *current_path_ptr;
};

void draw_menu(struct workspace *ws);
int opendirper(struct workspace *ws);
void system_start();
void free_workspace(struct workspace *ws, int size);

#endif

