#include "heder.h"
int full_vision(struct abonent **ptr,int count){
    for (int i = 0; i < count; i++)
    {
       printf("Абонент № %d\t Имя:%s\tФамилия:%s\tТелефон:%s\n",i, (*ptr)[i].name,(*ptr)[i].second_name,(*ptr)[i].tel);
    }
    }