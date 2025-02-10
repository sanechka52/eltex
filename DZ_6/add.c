#include "heder.h"
int add(struct abonent **ptr,int count) {
    count++;
    struct abonent *ptr_new = (struct abonent *)realloc(*ptr, count * sizeof(struct abonent));
        if (ptr_new == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            exit(1);
        }
        *ptr = ptr_new; 
      int c;
      printf("Введите имя Абонента(до 9 символов)\n");
      scanf("%9s", (*ptr)[count-1].name);
      while ((c = getchar()) != '\n' && c != EOF);
      printf("Введите фамилию Абонента(до 9 символов)\n");
      scanf("%9s", (*ptr)[count-1].second_name);
      while ((c = getchar()) != '\n' && c != EOF);
      printf("Введите телефон Абонента(до 9 символов)\n");
      scanf("%9s", (*ptr)[count-1].tel);
      while ((c = getchar()) != '\n' && c != EOF);
      return count;
    }
