#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/gpio.h>

#define GPIO_PIN 17  // The GPIO pin to control (GPIO 17 on Raspberry Pi)

// Function to request a GPIO pin for use
int gpio_request(int pin) {
    char path[64];
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d", pin);

    // Check if the GPIO pin is already exported
    if (access(path, F_OK) != 0) {
        // Export the GPIO pin if it is not already exported
        int fd = open("/sys/class/gpio/export", O_WRONLY);
        if (fd == -1) {
            perror("Failed to open export");
            return -1;
        }
        char buf[4];
        snprintf(buf, sizeof(buf), "%d", pin);
        write(fd, buf, strlen(buf));
        close(fd);
    }

    return 0;
}

// Function to set the direction of a GPIO pin (input/output)
int gpio_direction(int pin, int direction) {
    char path[64];
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/direction", pin);
    int fd = open(path, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open GPIO direction");
        return -1;
    }
    if (direction == 0) {
        // Set as input
        write(fd, "in", 2);
    } else {
        // Set as output
        write(fd, "out", 3);
    }
    close(fd);
    return 0;
}

// Function to set the value of a GPIO pin (0 or 1)
int gpio_set_value(int pin, int value) {
    char path[64];
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);
    int fd = open(path, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open GPIO value");
        return -1;
    }
    if (value == 0) {
        write(fd, "0", 1);
    } else {
        write(fd, "1", 1);
    }
    close(fd);
    return 0;
}

// Function to read the value of a GPIO pin
int gpio_get_value(int pin) {
    char path[64];
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open GPIO value");
        return -1;
    }
    char buf[3];
    read(fd, buf, sizeof(buf));
    close(fd);
    return (buf[0] == '1') ? 1 : 0;
}

// Function to free a GPIO pin (unexport it)
int gpio_free(int pin) {
    int fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd == -1) {
        perror("Failed to open unexport");
        return -1;
    }
    char buf[4];
    snprintf(buf, sizeof(buf), "%d", pin);
    write(fd, buf, strlen(buf));
    close(fd);
    return 0;
}

int main() {
    // Request the GPIO pin
    if (gpio_request(GPIO_PIN) == -1) {
        exit(EXIT_FAILURE);
    }

    // Set the GPIO pin as output
    if (gpio_direction(GPIO_PIN, 1) == -1) {
        gpio_free(GPIO_PIN);
        exit(EXIT_FAILURE);
    }

    // Toggle the GPIO pin value
    for (int i = 0; i < 10; i++) {
        printf("Setting GPIO pin %d to HIGH\n", GPIO_PIN);
        gpio_set_value(GPIO_PIN, 1);  // Set the pin HIGH
        sleep(1);

        printf("Setting GPIO pin %d to LOW\n", GPIO_PIN);
        gpio_set_value(GPIO_PIN, 0);  // Set the pin LOW
        sleep(1);
    }

    // Free the GPIO pin
    gpio_free(GPIO_PIN);

    return 0;
}



// The <linux/gpio.h> header provides an interface for working with the GPIO (General Purpose Input/Output) pins on Linux-based systems. This allows applications to control GPIO pins for various purposes, such as reading or writing digital values to them.
// Key Concepts and Functions in <linux/gpio.h>:

//     GPIO pins are typically exposed through the /sys/class/gpio/ directory or via direct access through the gpio driver interface in Linux.

//     Functions for GPIO control: These functions allow the user to interact with GPIO pins, such as exporting pins for use, setting directions (input/output), reading/writing values, and unexporting pins when they are no longer needed.

// Common Functions in <linux/gpio.h>:

//     gpio_request(): Requests control of a GPIO pin.
//     gpio_direction_input(): Sets a GPIO pin as an input.
//     gpio_direction_output(): Sets a GPIO pin as an output.
//     gpio_get_value(): Reads the value of an input GPIO pin.
//     gpio_set_value(): Sets the value of an output GPIO pin.
//     gpio_free(): Releases control of a GPIO pin.

// GPIO Pin Access through the /sys/class/gpio/ Directory:

// Alternatively, GPIO pins can be controlled by interacting with the /sys/class/gpio/ interface. This method is available to userspace applications and can be used without directly interfacing with the kernel through gpio.h.




// Explanation of the Code:

//     gpio_request(int pin): This function exports the GPIO pin if it is not already exported. It writes the pin number to /sys/class/gpio/export, making it accessible via the /sys/class/gpio/gpioX directory.

//     gpio_direction(int pin, int direction): This function sets the direction of the GPIO pin (either input or output). It writes either "in" or "out" to the /sys/class/gpio/gpioX/direction file.
//         0 for input
//         1 for output

//     gpio_set_value(int pin, int value): This function sets the value of an output GPIO pin. It writes "0" or "1" to the /sys/class/gpio/gpioX/value file to set the GPIO pin's state.
//         0 for LOW
//         1 for HIGH

//     gpio_get_value(int pin): This function reads the value of an input GPIO pin. It reads the contents of the /sys/class/gpio/gpioX/value file and returns either 0 or 1 based on the pin's state.

//     gpio_free(int pin): This function unexports the GPIO pin by writing the pin number to /sys/class/gpio/unexport, which makes the pin no longer accessible.

// Explanation of the GPIO Interface:

//     GPIO Export: Before a GPIO pin can be used, it needs to be exported. This is done by writing the pin number to /sys/class/gpio/export.

//     GPIO Direction: After exporting a pin, its direction must be set as either input or output. This is done by writing "in" or "out" to the /sys/class/gpio/gpioX/direction file.

//     GPIO Value: For output pins, you can set the value (high or low) by writing to the /sys/class/gpio/gpioX/value file. For input pins, you can read the current value by reading from this file.

//     GPIO Unexport: After using a GPIO pin, you should release it by unexporting it. This is done by writing the pin number to /sys/class/gpio/unexport.

// Compilation and Execution:

// Save the code as gpio_demo.c, and compile it using gcc:

// gcc -o gpio_demo gpio_demo.c

// Run the program (you may need root privileges for accessing GPIO pins):

// sudo ./gpio_demo

// Sample Output:

// Setting GPIO pin 17 to HIGH
// Setting GPIO pin 17 to LOW
// Setting GPIO pin 17 to HIGH
// Setting GPIO pin 17 to LOW
// Setting GPIO pin 17 to HIGH
// Setting GPIO pin 17 to LOW
// Setting GPIO pin 17 to HIGH
// Setting GPIO pin 17 to LOW
// Setting GPIO pin 17 to HIGH
// Setting GPIO pin 17 to LOW

// Notes:

//     Permissions: Accessing GPIO pins typically requires root permissions, as they control hardware resources.
//     GPIO Pin Numbers: GPIO pin numbers can vary depending on the platform (e.g., Raspberry Pi, BeagleBone, etc.), so ensure you are using the correct GPIO pin number for your hardware.
//     Hardware-Specific: This code assumes you're working on a Linux system with GPIO support. It works well on platforms like Raspberry Pi, but you should verify the pin numbering and GPIO configuration for your specific hardware.

// This approach allows you to interact with GPIO pins via the /sys/class/gpio/ interface, which is a simple and common method for controlling hardware on Linux-based systems.