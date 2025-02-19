#include "heder.h"
int main(){
    int deistvie =0;
    while (1) {
        float a,b,result=0;
        printf("Введите действие:\n1) Сложение\n2) Вычитание\n3) Умножение\n4) Деление\n5) Выход\n");
        if(scanf("%d", &deistvie)!=1){
            int c;
            while ((c = getchar()) != '\n' && c != EOF);//бесконечно сходит сума если нет чистки потока входа при недопустимых не числовых значений
        }
        
        switch (deistvie) {
            case 1:
                vvod(&a,&b);
                result=add(a,b);
                antivvod(result);
                break;
            case 2:
                vvod(&a,&b);
                result=sub(a,b);
                antivvod(result);
                break;

            case 3:
                vvod(&a,&b);
                result=mul(a,b);
                antivvod(result);
                break;

            case 4:
                vvod(&a,&b);
                result=div(a,b);
                antivvod(result);
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