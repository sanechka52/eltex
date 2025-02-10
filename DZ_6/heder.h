#ifndef HEDER_H
#define HEDER_H
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};

int add(struct abonent **ptr, int count);
int dell(struct abonent **ptr, int count);
int serch(struct abonent **ptr, int count);
int full_vision(struct abonent **ptr, int count);

#endif