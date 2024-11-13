#include <stdio.h>

void printBinary(unsigned int n) {
    int a[32];
    // Определяем количество бит в числе
    int bits = sizeof(n) * 8;
   
    // Проходим по каждому биту числа
    for (int i = bits - 1; i >= 0; i--) {
        // Сдвигаем число вправо и проверяем младший бит
        if (n & (1 << i)) {
       //   printf("1");
       a[i]=1;
        } else {
        //   printf("0");
        a[i]=0;
        }
        
    }
int count =0;
int count_1_in = 0;
for (int i = 31; i >=0; i--)
{
    if (a[i]==0&&count==0)
    {
        continue;
    }
    else  {
        if (a[i]==1)
        {
            count_1_in++;
        }
        
    printf("%d", a[i]);
     count++;}
}
printf("\nKоличество единиц в двоичном представлении целого положительного числа = %d\n", count_1_in);
}

int main() {
    unsigned int number;

  printf("Введите положительное целое число: ");
    scanf("%u", &number);

   printf("Двоичное представление числа %u: ", number);
    printBinary(number);

    return 0;
}
