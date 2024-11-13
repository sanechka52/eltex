#include <stdio.h>
#include <stdlib.h>

int main() {
   int  n,i, j;
   float chek;
    printf("Введите размер массива: ");
    if((!scanf("%f", &chek))||(chek!=(int)chek)||(chek <= 0)){
        printf("ээээу! вводи нормально жи есть да?!\n");
    } 
    n = (int)chek;
    int *arr1 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr1[i]=i+1;
    }
        for (int i = 0; i < n; i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    int *arr_reverb = (int *)malloc(n * sizeof(int));
       for (int i = 0; i < n; i++)
    {
        arr_reverb[i]=arr1[n-i-1];
    }
       for (int i = 0; i < n; i++)
    {
        printf("%d ",arr_reverb[i]);
    }
    free(arr1);
    free(arr_reverb);

    return 0;
}