#include <stdio.h>

int main() {
    char *ptr;
    int first_num;
    int zamen_num;
    ptr = (char*)&first_num;
    printf("введите число и значение нового третьего байта в нем\n");
    scanf("%d %d",&first_num,&zamen_num);
    ptr+=2;
    *ptr=zamen_num;
    printf("%d",first_num);
    return 0;
}