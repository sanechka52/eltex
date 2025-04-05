#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 16
long int a;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
void *thread_function_case_2(void *arg){
    for (long int i = 0; i < 10000000; i++) a = a+1;
    }
void *thread_function_case_3(void *arg){
    for (long int i = 0; i < 10000000; i++){
        pthread_mutex_lock(&m1);
        a = a+1;
        pthread_mutex_unlock(&m1);
    } 
    }
void *thread_function_case_4(void *arg){
    int kostil = 0;
    for (long int i = 0; i < 10000000; i++){
        kostil = kostil + 1;
    } 
    pthread_mutex_lock(&m1);
        a = kostil+a;
    pthread_mutex_unlock(&m1);
    }
int main(){
    int n;
    while (1)
    {
        printf("ienter the operating mode number\n1 - serial code\n2 - multithreaded program\n3 - adding critical sections\n4 - mapreduce\n5 - EXIT\n");
        scanf("%d",&n);
            switch (n)
            {
            case 1:
                for (long int i = 0; i < 160000000; i++) a = a+1;
                printf("a = %ld\n",a);
                a = 0;
                break;
            
            case 2:
                pthread_t thread_case_2[N];
                for (int i = 0; i < N; i++)
                {                
                    pthread_create(&thread_case_2[i],NULL,thread_function_case_2,NULL);
                }
                for (int i = 0; i < N; i++)
                {
                    pthread_join(thread_case_2[i],NULL);
                }
                printf("a = %ld\n",a);
                a = 0;
                break;
            
            case 3:
                pthread_t thread_case_3[N];
                for (int i = 0; i < N; i++)
                {                
                    pthread_create(&thread_case_3[i],NULL,thread_function_case_3,NULL);
                }
                for (int i = 0; i < N; i++)
                {
                    pthread_join(thread_case_3[i],NULL);
                }
                printf("a = %ld\n",a);
                a = 0;
                break;
            
            case 4:
                pthread_t thread_case_4[N];
                for (int i = 0; i < N; i++)
                {                
                    pthread_create(&thread_case_4[i],NULL,thread_function_case_4,NULL);
                }
                for (int i = 0; i < N; i++)
                {
                    pthread_join(thread_case_4[i],NULL);
                }
                printf("a = %ld\n",a);
                a = 0;
                break;
                    break;
            case 5:
                exit(EXIT_SUCCESS); 
                break;
            
            default:
                printf("invalid mode number\n");
                break;
            }

    }
    exit(EXIT_SUCCESS); 
}


