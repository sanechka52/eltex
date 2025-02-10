#include <stdio.h>
#include <string.h>
struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};
int add(struct abonent *ptr,int count); 
int dell(struct abonent *ptr,int count);
int serch(struct abonent *ptr,int count);
int full_vision(struct abonent *ptr,int count);

int main() {
    struct abonent ab[100];
    struct abonent *ptr = ab;
    int deistvie = 0;
    int count = 0;
    int count_abonent_add = 0;
    while (1) {
        printf("Введите действие:\n1 - добавление абонента\n2 - удаление абонента\n3 - поиск абонента\n4 - список абонентов\n5 - выйти\n");
        if(scanf("%d", &deistvie)!=1){
            int c;
            while ((c = getchar()) != '\n' && c != EOF);//бесконечно сходит сума если нет чистки потока входа при недопустимых не числовых значений
        }
        
        switch (deistvie) {
            case 1:
                count_abonent_add=add(ptr,count_abonent_add);
                break;

            case 2:
                dell(ptr,count_abonent_add);
                break;

            case 3:
                serch(ptr,count_abonent_add);
                break;

            case 4:
                full_vision(ptr,count_abonent_add);
                break;

            case 5:
                return 0;

            default:
                printf("Некорректное действие. Попробуйте еще раз.\n");
                break;
        }
    }

    return 0;
}

int add(struct abonent *ptr,int count) {
    if (count >=100)
    {
        printf("Переполнение Справочника, перезапустите программу для его обнуления\n");
        return 0;
    }  
  int c;
  printf("Введите имя Абонента(до 9 символов)\n");
  scanf("%9s", ptr[count].name);
  while ((c = getchar()) != '\n' && c != EOF);
  printf("Введите фамилию Абонента(до 9 символов)\n");
  scanf("%9s", ptr[count].second_name);
  while ((c = getchar()) != '\n' && c != EOF);
  printf("Введите телефон Абонента(до 9 символов)\n");
  scanf("%9s", ptr[count].tel);
  while ((c = getchar()) != '\n' && c != EOF);
  count++;
  return count;
}
int full_vision(struct abonent *ptr,int count){
for (int i = 0; i < count; i++)
{
   printf("Абонент № %d\t Имя:%s\tФамилия:%s\tТелефон:%s\n",i, ptr[i].name,ptr[i].second_name, ptr[i].tel);
}
}
int dell(struct abonent *ptr,int count){
    int num;
    printf("Введите номер Абонента для удаления\n");
    if ((scanf("%d",&num)!=1)||(num>=100))
    {
        printf("Некоректный порядковый номер пользователя, ожидаеться диапазон чисел 0-99\n");
    }
    if (num >count) return printf("Элемента с таким номером еще не существует\n");
    memset(&ptr[num], 0, sizeof(ptr[num]));//занулили структуру!
    return 0;
}
int serch(struct abonent *ptr,int count){
    int c;
    char serch[10]={0};
    printf("Введите необходимое имя для поиска Абонента\n");
    scanf("%9s",serch);
    while ((c = getchar()) != '\n' && c != EOF);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(serch, ptr[i].name) == 0)//сравнение поиска и i элемента структуры
        {
        printf("Абонент № %d\t Имя:%s\tФамилия:%s\tТелефон:%s\n",i, ptr[i].name,ptr[i].second_name, ptr[i].tel);
        }
        
    }
    return 0;
}