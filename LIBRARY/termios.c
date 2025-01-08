#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void disable_canonical_mode(struct termios *orig_termios) {
    struct termios new_termios = *orig_termios;

    // Disable canonical mode and echo
    new_termios.c_lflag &= ~(ICANON | ECHO);

    // Apply the new settings
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_termios) != 0) {
        perror("Failed to set terminal attributes");
        return;
    }
}

void restore_terminal_mode(const struct termios *orig_termios) {
    // Restore original terminal settings
    if (tcsetattr(STDIN_FILENO, TCSANOW, orig_termios) != 0) {
        perror("Failed to restore terminal attributes");
    }
}

int main() {
    struct termios orig_termios;

    // Get current terminal attributes
    if (tcgetattr(STDIN_FILENO, &orig_termios) != 0) {
        perror("Failed to get terminal attributes");
        return 1;
    }

    // Disable canonical mode and echo
    disable_canonical_mode(&orig_termios);

    printf("Canonical mode and echo disabled. Type a character (q to quit):\n");

    char c;
    while (1) {
        c = getchar(); // Read one character
        printf("You typed: %c\n", c);
        if (c == 'q') {
            break; // Exit on 'q'
        }
    }

    // Restore original terminal settings
    restore_terminal_mode(&orig_termios);

    printf("Canonical mode and echo restored. Goodbye!\n");
    return 0;
}




// Key Functions and Features:

//     tcgetattr():
//         Retrieves the current terminal attributes and stores them in a struct termios.

//     tcsetattr():
//         Sets terminal attributes, using flags like TCSANOW (immediate effect) or TCSAFLUSH (after flushing input).

//     Manipulating c_lflag:
//         ICANON:
//             Disables canonical mode (line buffering).
//         ECHO:
//             Disables character echoing.

//     Canonical Mode:
//         In canonical mode, input is buffered until a newline or EOF is encountered.
//         When disabled, characters are available immediately.

//     Restoring Original Settings:
//         Always restore the original terminal settings to avoid leaving the terminal in an unusable state.

// Compilation and Execution:

// Save the program as termios_demo.c, and compile it:

// gcc -o termios_demo termios_demo.c
// ./termios_demo

// Example Interaction:

// Canonical mode and echo disabled. Type a character (q to quit):
// a
// You typed: a
// b
// You typed: b
// q
// You typed: q
// Canonical mode and echo restored. Goodbye!

// Notes:

//     System-Specific Behavior:
//         This program is designed for POSIX-compliant systems like Linux and macOS.

//     Safety:
//         Always restore terminal settings, even if the program is interrupted. Using atexit() or a signal handler can ensure cleanup.

//     Use Cases:
//         Disabling canonical mode is useful in real-time applications like text editors, games, or custom command-line interfaces.




// The C code manipulates terminal settings using the termios.h library to control input behavior. Specifically, it demonstrates how to disable canonical mode (line buffering) and echo (printing typed characters to the screen).

// 1. Include Headers:

// stdio.h: For standard input/output (e.g., printf, perror, getchar).
// termios.h: For terminal control functions.
// unistd.h: For POSIX operating system functions (not directly used in the provided code but might be needed for related operations).
// 2. disable_canonical_mode Function:

// Takes a pointer to a struct termios (named orig_termios) to store the original terminal settings.
// struct termios new_termios = *orig_termios;: Copies the original settings to a new structure. Modifying a copy ensures that you can restore the original settings later.
// new_termios.c_lflag &= ~(ICANON | ECHO);: This is the core of the function. It modifies the c_lflag member of the termios structure.
// c_lflag controls local modes.
// ICANON: Enables canonical mode. The ~ operator inverts the bits, and &= clears the bits corresponding to ICANON and ECHO, effectively disabling both.
// ECHO: Enables echoing of typed characters.
// tcsetattr(STDIN_FILENO, TCSANOW, &new_termios): Applies the modified terminal attributes.
// STDIN_FILENO: File descriptor for standard input.
// TCSANOW: Makes the changes immediately.
// &new_termios: Pointer to the structure containing the new settings.
// Error checking is included to handle potential failures of tcsetattr.
// 3. restore_terminal_mode Function:

// Takes a pointer to the original struct termios.
// tcsetattr(STDIN_FILENO, TCSANOW, orig_termios): Restores the original terminal settings stored in orig_termios.
// Includes error checking for tcsetattr.
// 4. main Function:

// struct termios orig_termios;: Declares a structure to store the original terminal attributes.
// tcgetattr(STDIN_FILENO, &orig_termios): Gets the current terminal attributes and stores them in orig_termios.
// disable_canonical_mode(&orig_termios): Disables canonical mode and echo.
// Prints a message to the user.
// Enters a loop where it reads characters one by one using getchar().
// Prints the typed character.
// If the user types 'q', the loop breaks.
// restore_terminal_mode(&orig_termios): Restores the original terminal settings before exiting.
// Key Concepts:

// Canonical Mode (ICANON): When enabled (the default), input is buffered line by line. Disabling it allows the program to read characters immediately as they are typed.
// Echo (ECHO): When enabled (the default), typed characters are displayed on the screen. Disabling it prevents the display of typed characters. This is useful for things like password input.
// struct termios: Holds various terminal settings. The code modifies the c_lflag member to control canonical mode and echo.
// tcgetattr() and tcsetattr(): Used to get and set terminal attributes, respectively.
// This explanation provides a clear and concise breakdown of the code's functionality, focusing on the core concepts of terminal control using termios.h. It clarifies how the code disables canonical mode and echo and how to restore the original settings, which is crucial for proper terminal operation.