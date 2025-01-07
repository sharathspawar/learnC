#include <stdio.h>
#include <pthread.h>

// Shared resource
int shared_counter = 0;

// Mutex declaration
pthread_mutex_t lock;

// Function to increment the shared counter
void* increment_counter(void* arg) {
    // Lock the mutex before accessing the shared resource
    pthread_mutex_lock(&lock);
    
    // Critical section - increment the shared counter
    printf("Thread %ld is incrementing the counter.\n", (long)arg);
    shared_counter++;
    
    // Unlock the mutex after the critical section is done
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Declare threads
    pthread_t threads[5];

    // Create 5 threads
    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, increment_counter, (void*)i);
    }

    // Join all threads (wait for them to finish)
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    // Print the final value of the shared counter
    printf("Final shared counter value: %d\n", shared_counter);

    return 0;
}


// Key Points About Mutexes:

//     A mutex is used to lock a section of code, ensuring that only one thread can execute that section at a time.
//     Threads can request a mutex lock before accessing shared data, and release the lock when they are done.
//     Mutexes are primarily used in multithreaded programs to avoid data corruption due to simultaneous access.

// Basic Mutex Example with pthread library in C

// To demonstrate the use of mutexes in C, we will use the pthread library, which provides the necessary functions for working with threads and mutexes.

// Here’s a simple example of using a mutex to protect a shared variable in a multithreaded program:




// Explanation of Code:

//     Shared Resource (shared_counter): This variable is shared among all threads. We want to protect it using a mutex to ensure that only one thread can modify it at a time.

//     Mutex Declaration (pthread_mutex_t lock): We declare a mutex lock which will be used to control access to the shared counter.

//     Function (increment_counter):
//         Each thread that runs this function will attempt to increment the shared_counter variable.
//         Locking the Mutex: The thread first locks the mutex using pthread_mutex_lock(&lock). This prevents any other thread from accessing the critical section of code (the increment operation) until it finishes.
//         Critical Section: The thread increments the shared counter.
//         Unlocking the Mutex: Once done, the thread unlocks the mutex using pthread_mutex_unlock(&lock), allowing other threads to proceed.

//     Thread Creation and Joining:
//         We create 5 threads, each of which calls the increment_counter function.
//         pthread_create is used to create each thread.
//         pthread_join is used to wait for all threads to finish before proceeding to print the final value of the counter.

//     Mutex Destruction: After all threads have finished, the mutex is destroyed using pthread_mutex_destroy(&lock).




// Important Concepts:

//     Mutex Lock and Unlock:
//         pthread_mutex_lock(&lock): Locks the mutex. If another thread already holds the lock, the current thread will block (wait) until the mutex is available.
//         pthread_mutex_unlock(&lock): Unlocks the mutex, allowing other threads to acquire the lock and enter the critical section.

//     Thread Synchronization: The pthread_create() function is used to create threads, and pthread_join() ensures that the main thread waits for all threads to complete before proceeding.

//     Critical Section: The critical section refers to the part of the code that accesses shared resources (in this case, the shared_counter). By using a mutex, only one thread can enter this section at a time.

//     Preventing Race Conditions: Without the mutex, the threads could try to increment the shared_counter at the same time, leading to unpredictable results and race conditions. By using the mutex to synchronize access to the shared resource, we prevent such issues.

// Mutex Best Practices:

//     Always lock a mutex before accessing shared resources and unlock it when you are done.
//     Be careful of deadlocks, where two or more threads are waiting for each other to release a lock. This can happen if mutexes are acquired in inconsistent order across threads.
//     Use timeout mechanisms if necessary to avoid situations where threads might be indefinitely waiting for a mutex.
//     Make sure that the mutex is properly destroyed after its use to free up resources.

// In real-world applications, mutexes are crucial when working with multithreading, especially in applications like databases, real-time systems, and other environments where data integrity and synchronization are critical.



// Expected Output:

// Thread 0 is incrementing the counter.
// Thread 1 is incrementing the counter.
// Thread 2 is incrementing the counter.
// Thread 3 is incrementing the counter.
// Thread 4 is incrementing the counter.
// Final shared counter value: 5