#include "heder.h"
int serch(struct abonent **ptr,int count){
    int c;
    char serch[10]={0};
    printf("Введите необходимое имя для поиска Абонента\n");
    scanf("%9s",serch);
    while ((c = getchar()) != '\n' && c != EOF);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(serch, (*ptr)[i].name) == 0)//сравнение поиска и i элемента структуры
        {
        printf("Абонент № %d\t Имя:%s\tФамилия:%s\tТелефон:%s\n",i, (*ptr)[i].name,(*ptr)[i].second_name, (*ptr)[i].tel);
        }
    }
    return 0;
}
