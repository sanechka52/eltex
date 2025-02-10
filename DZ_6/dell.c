#include "heder.h"
int dell(struct abonent **ptr,int count){
    int num;
    printf("Введите номер Абонента для удаления\n");
    if ((scanf("%d",&num)!=1)||(num>=100))
    {
        printf("Некоректный порядковый номер пользователя, ожидаеться диапазон чисел 0-99\n");
    }
    if (num >count) return printf("Элемента с таким номером еще не существует\n");
    for (int i = num; i < count - 1; i++) {
        (*ptr)[i] = (*ptr)[i+1 ];
    }
    struct abonent *ptr_new = (struct abonent *)realloc(*ptr, (count-1) * sizeof(struct abonent));
        if (ptr_new == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            exit(1);
        }
        *ptr = ptr_new;
    count =count-1;  
    return count;
}