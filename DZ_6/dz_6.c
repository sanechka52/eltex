#include "heder.h"
int main() {
    int count = 0;
        int deistvie = 0;
    struct abonent *ptr = NULL;     
    while (1) {
        printf("Введите действие:\n1 - добавление абонента\n2 - удаление абонента\n3 - поиск абонента\n4 - список абонентов\n5 - выйти\n");
        if(scanf("%d", &deistvie)!=1){
            int c;
            while ((c = getchar()) != '\n' && c != EOF);//бесконечно сходит сума если нет чистки потока входа при недопустимых не числовых значений
        }
        
        switch (deistvie) {
            case 1:
                count=add(&ptr,count);
                break;

            case 2:
                count=dell(&ptr,count);
                break;

            case 3:
                serch(&ptr,count);
                break;

            case 4:
                full_vision(&ptr,count);
                break;

            case 5:
                free(ptr);
                return 0;

            default:
                printf("Некорректное действие. Попробуйте еще раз.\n");
                break;
        }
    }

    return 0;
}