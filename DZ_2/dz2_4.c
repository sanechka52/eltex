#include <stdio.h>
#include <stdlib.h>
   int  n,i, j, stroka, stolb, strok, stol, prohods;
   float chek;
    int **matrix;
    int prohod= 0;
    int chislo = 1;
    int count = 1;

    int stroka = 0;
    int stolb = 0;




int main() {


    printf("Введите размер квадратной матрицы:\nЛюбой размер матрицы\n");
    if((!scanf("%f", &chek))||(chek!=(int)chek)||(chek <= 0)){
        printf("Нельзя\n");
        return 0;
    }
    n = (int)chek;
    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
for(i=0; i<n-1; i++){
    
    while (count<=n-prohod)
    {
        matrix[strok][stol]=chislo;
        chislo++;
        stol++;
        count++;
    }
    stol--;
    chislo--;
    prohod++;
    count = 0; 
   while (count<=n-prohod)
   {matrix[strok][stol]=chislo;
        chislo++;
        strok++;
        count++;

   }
   strok--;
   chislo--;
   count = 0; 
   while (count<=n-prohod)
   {matrix[strok][stol]=chislo;
        chislo++;
        stol--;
        count++;

   }
   stol++;
   count=0;
   chislo--;
   prohod++;
   while (count<=n-prohod)
   {matrix[strok][stol]=chislo;
        chislo++;
        strok--;
        count++;

   }
   strok++;
   count=0;
   chislo--;
   
}
   
    


    printf("Ваша матрица:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t ", matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);
    

    return 0;
}