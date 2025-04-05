#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h> 
#include <time.h>  
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
int shop[5]={500,500,500,500,500};
void *thread_function_user_buy(void *arg){
    int random_num = rand() % 2001 + 10000;
    int* num_user =(int*)arg;
    int need_buy_resurs = random_num;
    while (need_buy_resurs > 0)
    {
        for (int i = 0; i < 5; i++)
        {  pthread_mutex_lock(&m1);
            if (shop[i]!=0)
            {
                if (need_buy_resurs<=shop[i])
                {
                    shop[i] = shop[i] -need_buy_resurs;
                    need_buy_resurs = 0;
                    printf("LOG\n USER:%d need by resurses: %d\nshop1:%d,shop2:%d,shop3:%d,shop4:%d,shop5:%d\n",*num_user,need_buy_resurs,shop[0],shop[1],shop[2],shop[3],shop[4]);
                    pthread_mutex_unlock(&m1);
                    break;
                }else{
                
                need_buy_resurs =need_buy_resurs -shop[i];
                shop[i]=0;
                printf("LOG\n USER:%d need by resurses: %d\nshop1:%d,shop2:%d,shop3:%d,shop4:%d,shop5:%d\n",*num_user,need_buy_resurs,shop[0],shop[1],shop[2],shop[3],shop[4]);
                pthread_mutex_unlock(&m1);
                sleep(2);
                break;
                }
            }else{
                pthread_mutex_unlock(&m1);
            }
        }
    }

}
void *thread_function_work_man(void *arg){
    while (1)
    {
        for (int i = 0; i < 5; i++)
        {  
            pthread_mutex_lock(&m1);
            shop[i]=shop[i] + 500;
            printf("LOG\n WORK MAN\nshop1:%d,shop2:%d,shop3:%d,shop4:%d,shop5:%d\n",shop[0],shop[1],shop[2],shop[3],shop[4]);
            pthread_mutex_unlock(&m1);
            sleep(1);
        }
    }
    
}
int main(){
    srand(time(NULL));
    pthread_t thread_user[3];
    pthread_t thread_work_man;
    int num_user[3];
    for (int i = 0; i < 3; i++)
    {
        num_user[i]=i;
        pthread_create(&thread_user[i],NULL,thread_function_user_buy,&num_user[i]);
    }
    pthread_create(&thread_work_man,NULL,thread_function_work_man,NULL);
    for (int i = 0; i < 3; i++)
    {
        pthread_join(thread_user[i],NULL);
    }
//pthread_join(thread_work_man,NULL);

    exit(EXIT_SUCCESS); 
}