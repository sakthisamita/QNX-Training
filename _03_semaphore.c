#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;   // Semaphore declaration

void* task(void* arg)
{
    int id = *(int*)arg;

    printf("Thread %d: Waiting for semaphore...\n", id);
    sem_wait(&sem);   // Acquire semaphore

    // Critical Section
    printf("Thread %d: Entered critical section\n", id);
    sleep(2);
    printf("Thread %d: Leaving critical section\n", id);

    sem_post(&sem);   // Release semaphore
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3, t4;
    int id1 = 1, id2 = 2, id3=7, id4=9;

    // Initialize semaphore
    sem_init(&sem, 0, 1);  // 1 → binary semaphore

    pthread_create(&t1, NULL, task, &id1);
    pthread_create(&t2, NULL, task, &id2);
    pthread_create(&t3, NULL, task, &id3);
    pthread_create(&t4, NULL, task, &id4);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    sem_destroy(&sem);
    return 0;
}
