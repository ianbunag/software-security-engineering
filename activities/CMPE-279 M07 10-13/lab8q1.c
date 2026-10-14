#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS 1000000000
pthread_mutex_t mutex4counter;
// Shared global variable
int counter = 0;

// Thread function that increments the shared counter
void* increment_counter(void* arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        // CRITICAL SECTION: A race condition occurs here
        // fprintf(stderr,"%d\n",counter);
        pthread_mutex_lock(&mutex4counter);
        counter++;
        pthread_mutex_unlock(&mutex4counter);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    // Create two threads that run the same function
    if (pthread_create(&thread1, NULL, increment_counter, NULL) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }
    if (pthread_create(&thread2, NULL, increment_counter, NULL) != 0)
    {
        perror("Failed to create thread 2");
        return 1;
    }

    // Wait for both threads to finish execution
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final result
    printf("Expected value: %d\n", ITERATIONS * 2);
    printf("Actual value  : %d\n", counter);

    return 0;
}
