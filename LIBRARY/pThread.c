#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define INCREMENTS 1000000

// Shared data
long counter = 0;

// Mutex for synchronizing access to shared data
pthread_mutex_t mutex;

void *increment_counter(void *arg) {
    for (int i = 0; i < INCREMENTS; i++) {
        // Lock the mutex before modifying the shared counter
        pthread_mutex_lock(&mutex);
        
        // Increment the counter
        counter++;
        
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    
    // Initialize the mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex initialization failed");
        return 1;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) {
            perror("Thread creation failed");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final value of the counter
    printf("Final counter value: %ld\n", counter);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}



// The <pthread.h> header in C is used for creating and managing threads in a program, allowing for concurrent execution. Threads are independent units of execution within a process, and they share the same memory space. The POSIX threads (Pthreads) library provides a standard set of functions to work with threads.
// Key Concepts in <pthread.h>:

//     Thread Creation: You can create threads using pthread_create().
//     Thread Termination: Threads can be terminated using pthread_exit() or by returning from the thread function.
//     Thread Joining: pthread_join() is used to wait for a thread to finish execution.
//     Mutexes: Mutexes (pthread_mutex_t) are used to prevent race conditions when multiple threads access shared data.
//     Thread Synchronization: Condition variables (pthread_cond_t) are used for more advanced synchronization.
//     Thread Attributes: pthread_attr_t allows setting various attributes for threads.

// Key Functions in <pthread.h>:

//     pthread_create(): Creates a new thread.
//     pthread_join(): Waits for a thread to terminate.
//     pthread_exit(): Exits the calling thread.
//     pthread_mutex_init(): Initializes a mutex.
//     pthread_mutex_lock(): Locks a mutex to prevent race conditions.
//     pthread_mutex_unlock(): Unlocks a mutex.
//     pthread_cond_wait(): Makes a thread wait for a condition variable to be signaled.
//     pthread_cond_signal(): Signals a condition variable to wake up a waiting thread.



// Explanation of the Code:

//     Global Counter:
//         long counter = 0; is a shared variable that all threads will increment.

//     Mutex:
//         pthread_mutex_t mutex; is declared globally to synchronize access to the shared counter. This prevents race conditions where multiple threads try to modify the counter at the same time.

//     Thread Function (increment_counter):
//         Each thread will execute this function. It loops INCREMENTS times, incrementing the global counter.
//         Before modifying the counter, the thread locks the mutex using pthread_mutex_lock(&mutex);.
//         After updating the counter, it unlocks the mutex using pthread_mutex_unlock(&mutex); to allow other threads to access the counter.

//     Creating Threads:
//         pthread_create(&threads[i], NULL, increment_counter, NULL); creates each thread. The increment_counter function is passed as the thread function to execute.
//         The NULL argument is passed for thread attributes, indicating default behavior for the thread (e.g., default stack size, priority, etc.).

//     Waiting for Threads:
//         pthread_join(threads[i], NULL); ensures that the main thread waits for all threads to finish before printing the result.

//     Destroying Mutex:
//         After all threads have finished, we destroy the mutex using pthread_mutex_destroy(&mutex); to release resources.

//     Final Output:
//         The program prints the final value of the counter after all threads have completed their work.

// Compilation:

// To compile the program, you need to link the pthread library. Use the following command:

// gcc -o pthread_example pthread_example.c -lpthread

// Execution:

// Run the program with the following command:

// ./pthread_example

// Sample Output:

// Final counter value: 5000000

// This output is the expected value after all 5 threads each increment the counter 1,000,000 times. The use of a mutex ensures that the counter is updated safely without race conditions.
// Explanation of Key Functions and Concepts:

//     pthread_create():
//         Creates a new thread.
//         Takes a pointer to a pthread_t variable (to store thread identifier), thread attributes (or NULL for default), the function to execute, and any argument to pass to the function (or NULL).

//     pthread_join():
//         Waits for the specified thread to terminate. The main thread uses pthread_join() to ensure all threads finish before it continues execution.

//     pthread_exit():
//         This function is used inside a thread to terminate its execution. The main thread doesn't need to call pthread_exit() since it automatically exits when the main() function completes.

//     pthread_mutex_init():
//         Initializes the mutex, which is required before using pthread_mutex_lock() and pthread_mutex_unlock().

//     pthread_mutex_lock() and pthread_mutex_unlock():
//         These functions lock and unlock the mutex, respectively. Locking prevents other threads from entering critical sections where shared data (like the counter) is accessed or modified.

//     pthread_mutex_destroy():
//         Destroys the mutex after it is no longer needed, releasing any resources it holds.

//     Thread Synchronization:
//         Mutexes are critical for synchronizing access to shared resources. Without the mutex, multiple threads could modify the shared counter at the same time, leading to race conditions and incorrect results.

// Advanced Features:

//     Thread Attributes:
//         pthread_attr_t allows customizing various aspects of thread creation (e.g., stack size, detach state, scheduling policy).

//     Thread Cancellation:
//         Threads can be canceled using pthread_cancel(), and they can handle cancellation via pthread_setcancelstate() and pthread_setcanceltype().

//     Condition Variables:
//         For more advanced synchronization, condition variables (pthread_cond_t) can be used to wait for specific conditions to be met. This is useful for producer-consumer scenarios.

// Notes:

//     Thread Safety:
//         Ensure proper synchronization when using shared resources in multi-threaded environments to prevent data corruption and race conditions.

//     Error Handling:
//         Always check the return values of Pthread functions like pthread_create(), pthread_mutex_init(), etc., to handle errors gracefully.

//     Performance Considerations:
//         While multi-threading can improve performance, excessive use of locks (like mutexes) can cause performance bottlenecks due to contention, especially with a large number of threads. Fine-grained locking or other synchronization mechanisms like read-write locks can be more efficient in certain scenarios.

// This example provides a detailed breakdown of the most commonly used features in <pthread.h>, giving you a foundation for multithreading in C.