#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 5 // Size of the circular buffer

// Circular buffer structure
struct CircularBuffer {
    int buffer[BUFFER_SIZE]; // Array to store buffer elements
    int head;                // Points to the next element to be read
    int tail;                // Points to the next empty spot for writing
    int count;               // Number of elements currently in the buffer
};

// Initialize the circular buffer
void initBuffer(struct CircularBuffer* cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Check if the buffer is empty
bool isBufferEmpty(struct CircularBuffer* cb) {
    return cb->count == 0;
}

// Check if the buffer is full
bool isBufferFull(struct CircularBuffer* cb) {
    return cb->count == BUFFER_SIZE;
}

// Write data into the buffer
void writeBuffer(struct CircularBuffer* cb, int data) {
    if (isBufferFull(cb)) {
        printf("Buffer is full! Overwriting data...\n");
        // Overwrite the oldest data by moving head forward
        cb->head = (cb->head + 1) % BUFFER_SIZE;
    } else {
        cb->count++;
    }

    // Write data at the tail and move the tail forward
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
}

// Read data from the buffer
int readBuffer(struct CircularBuffer* cb) {
    if (isBufferEmpty(cb)) {
        printf("Buffer is empty! Nothing to read.\n");
        return -1; // Return -1 if buffer is empty
    }

    // Read data from the head and move the head forward
    int data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count--;

    return data;
}

// Display the buffer contents (for debugging)
void displayBuffer(struct CircularBuffer* cb) {
    printf("Buffer contents: ");
    int i = cb->head;
    int count = cb->count;

    while (count > 0) {
        printf("%d ", cb->buffer[i]);
        i = (i + 1) % BUFFER_SIZE;
        count--;
    }
    printf("\n");
}

int main() {
    struct CircularBuffer cb;
    initBuffer(&cb);

    // Write data to the buffer
    writeBuffer(&cb, 10);
    writeBuffer(&cb, 20);
    writeBuffer(&cb, 30);
    writeBuffer(&cb, 40);
    writeBuffer(&cb, 50);  // Buffer is now full
    displayBuffer(&cb);

    // Read data from the buffer
    printf("Read: %d\n", readBuffer(&cb));
    displayBuffer(&cb);

    // Add more data (overwrite will occur)
    writeBuffer(&cb, 60);
    writeBuffer(&cb, 70);
    displayBuffer(&cb);

    return 0;
}


// Characteristics of a Circular Buffer:

//     Fixed size: The buffer has a fixed size that is predefined.
//     Wrap-around behavior: When data is added or removed, it wraps around to the beginning once the end of the buffer is reached.
//     Efficient operations: It allows constant time complexity for both inserting and removing data elements.
//     Two pointers: It typically uses two pointers:
//         Head (or read pointer): Points to the next element to be read.
//         Tail (or write pointer): Points to the next element to be written.

// How It Works:

//     Buffer: A fixed-size array that holds the data.
//     Head Pointer: Tracks where to read from.
//     Tail Pointer: Tracks where to write next.
//     Full Condition: If the buffer is full, the write pointer will overwrite the oldest data (assuming no data has been consumed).
//     Empty Condition: If the buffer is empty, the read pointer will be equal to the write pointer.

// Basic Operations:

//     Insert (Write): Place data into the buffer at the position indicated by the tail pointer, and then move the tail pointer forward.
//     Remove (Read): Read the data from the buffer at the position indicated by the head pointer, and then move the head pointer forward.
//     Full Condition: The buffer is full if the tail pointer is just behind the head pointer (i.e., (tail + 1) % buffer_size == head).
//     Empty Condition: The buffer is empty if the head pointer is equal to the tail pointer (i.e., head == tail).


// Explanation of the Code:

//     Buffer Structure:
//         buffer[]: The array holds the data in the circular buffer.
//         head: Points to the index of the next element to be read.
//         tail: Points to the index where the next element will be written.
//         count: Tracks the current number of elements in the buffer.

//     Functions:
//         initBuffer(): Initializes the circular buffer with head, tail, and count all set to 0.
//         isBufferEmpty(): Returns true if the buffer is empty (count == 0).
//         isBufferFull(): Returns true if the buffer is full (count == BUFFER_SIZE).
//         writeBuffer(): Adds data to the buffer. If the buffer is full, the oldest data is overwritten by adjusting the head pointer.
//         readBuffer(): Reads and removes data from the buffer. If the buffer is empty, it returns -1.
//         displayBuffer(): Displays the current contents of the buffer.

//     Main Logic:
//         Data is written to the buffer, and the buffer is displayed after each write.
//         When the buffer is full, new data overwrites the oldest data (handled by adjusting the head pointer).
//         Data is read from the buffer, and the remaining buffer is displayed.



// Advantages of Circular Buffers:

//     Fixed Size: It uses a fixed amount of memory, making it ideal for real-time applications where memory allocation must be predictable.
//     Efficient: Operations (insert and remove) are constant time (O(1)).
//     No Memory Wastage: It efficiently reuses space without needing to move data around.

// Applications of Circular Buffers:

//     Data Streaming: Used in scenarios like audio/video streaming where data is continuously written and read.
//     Communication Systems: Buffering of data between two processes (e.g., network communication, inter-process communication).
//     Real-Time Systems: For buffering data in real-time systems where resources are limited and fast data processing is essential.

// Circular buffers are crucial in many embedded systems and real-time applications because of their efficiency and simplicity in handling continuous data streams.


// Expected Output:

// Buffer contents: 10 20 30 40 50 
// Read: 10
// Buffer contents: 20 30 40 50 
// Buffer contents: 20 30 40 50 60 70 
