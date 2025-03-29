#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
    pid_t child_pid1,child_pid2,child_pid3,child_pid4,child_pid5;

    child_pid1=fork();
    if (child_pid1 ==-1)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (child_pid1 ==0)
    {
        child_pid3=fork();
        if (child_pid3 ==-1)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
        if (child_pid3 == 0)
        {
            printf("Child process has PID: %d\n",getpid());
            printf("Child process has PPID: %d\n",getppid());
            exit(3);
        }else{
            printf("Child process has PID: %d\n",getpid());
            printf("Child process has PPID: %d\n",getppid());
            int status;
            wait(&status);
        }
        child_pid4=fork();
        if (child_pid4 ==-1)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        if (child_pid4 == 0)
        {
            printf("Child process has PID: %d\n",getpid());
            printf("Child process has PPID: %d\n",getppid());
            exit(4);
        }else{
            int status;
            wait(&status); 
            exit(1);
        }
        
        
    }else{
        int status;
        wait(&status);
    }
    child_pid2=fork();
    if (child_pid2 ==-1)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (child_pid2 ==0)
    {
        child_pid5=fork();
        if (child_pid5 ==-1)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        if (child_pid5 ==0)
        {
            printf("Child process has PID: %d\n",getpid());
            printf("Child process has PPID: %d\n",getppid());
            exit(5);
        }else{
            printf("Child process has PID: %d\n",getpid());
            printf("Child process has PPID: %d\n",getppid());
            int status;
            wait(&status); 
            exit(2);
        }
        
    }else{
        int status;
        wait(&status); 
    }
    
    

    exit(0);
}