#include <stdio.h>
#include <pthread.h>

void* printMessage(void* arg) {
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, printMessage, NULL)) {
        printf("Error creating thread\n");
        return 1;
    }
    pthread_join(thread, NULL); // Wait for the thread to finish
    printf("Main thread ends\n");
    return 0;
}


// Explanation:

//     pthread_create: Creates a new thread.
//     pthread_join: Waits for the specified thread to finish execution.

