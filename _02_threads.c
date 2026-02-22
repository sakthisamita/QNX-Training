#include <stdio.h>
#include <pthread.h> // POSIX thread library

void* thread_func(void* arg)
{
    printf("Hello from thread!\n");
    return NULL;
}

int main()
{
    pthread_t tid; // Declares thread ID

    pthread_create(&tid, NULL, thread_func, NULL);
    pthread_join(tid, NULL); // wait for the execution of the ongoing thread until it completes

    printf("Main thread exiting\n");
    return 0;
}
