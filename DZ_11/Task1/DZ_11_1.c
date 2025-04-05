#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 5
void *thread_function_id(void *arg){
int* i =(int*)arg;
printf("pthread num : %d\n",*i);
}
int main(){
int i;
int j;
int *s;
int v[N];
pthread_t thread_id[N];
for (int i = 0; i < 5; i++)
{
    v[i]=i;
    pthread_create(&thread_id[i],NULL,thread_function_id,&v[i]);
}
for (int j = 0; j < 5; j++)
{
    pthread_join(thread_id[j],(void**)&s);
}
exit(EXIT_SUCCESS); 
}