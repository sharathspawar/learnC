#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char buffer[100];
    char ch;
    char filename[] = "example.txt";

    // fopen(): Open a file for writing.  "w" mode creates the file if it doesn't exist,
    // or truncates it to zero length if it does.
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file"); // Print error message if fopen fails
        return 1; // Return 1 to indicate an error
    }

    // fprintf(): Write formatted output to the file. Similar to printf, but writes to a file.
    fprintf(file, "This is a test file.\n");
    fprintf(file, "Number: %d\n", 42);

    // fputs(): Write a string to the file.  Doesn't automatically add a newline.
    fputs("Adding another line to the file.\n", file);

    // fputc(): Write a single character to the file.
    fputc('A', file);
    fputc('\n', file);

    // fclose(): Close the file.  Important to release resources and ensure data is written.
    fclose(file);


    // Reopen the file for reading. "r" mode opens the file for reading.
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // fgetc(): Read a single character from the file. Returns EOF at end of file.
    printf("Reading characters using fgetc():\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print the character to the console
    }

    // rewind(): Resets the file pointer to the beginning of the file.
    rewind(file);

    // fgets(): Reads a line from the file (including newline), up to a specified size,
    // and stores it in a buffer. Returns NULL at end of file or error.
    printf("\nReading lines using fgets():\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        puts(buffer); // Print the line to the console (puts adds a newline)
    }

    // fseek(): Moves the file pointer to a specific offset within the file.
    // SEEK_SET sets the pointer relative to the beginning.
    fseek(file, 0, SEEK_SET); // Move to the beginning of the file

    // ftell(): Returns the current position of the file pointer (offset from the beginning).
    printf("File pointer position: %ld\n", ftell(file));

    // fread(): Reads binary data from the file.  Reads a specified number of items
    // of a given size.  Returns the number of items successfully read.
    rewind(file); // Go back to the beginning
    char temp[50];
    size_t bytesRead = fread(temp, sizeof(char), 10, file); // Read 10 characters
    printf("Read %zu bytes: %.10s\n", bytesRead, temp); // Print the read characters

    // ferror(): Checks for errors during file operations.  Returns non-zero if an error has occurred.
    if (ferror(file)) {
        perror("Error detected");
    }

    // feof(): Checks if the end-of-file indicator has been set.  Returns non-zero if EOF has been reached.
    if (feof(file)) {
        printf("End of file reached.\n");
    }

    // fclose(): Close the file.
    fclose(file);



    // rename(): Renames a file. Returns 0 on success, non-zero on error.
    if (rename(filename, "renamed_example.txt") == 0) {
        printf("File renamed successfully.\n");
    } else {
        perror("Error renaming file");  // Print error message if rename fails
    }

    // remove(): Deletes a file. Returns 0 on success, non-zero on error.
    if (remove("renamed_example.txt") == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting file"); // print error message if remove fails
    }


    // printf(): Prints formatted output to the console (stdout).
    printf("Formatted output: Pi is approximately %.2f\n", 3.14159);

    // scanf(): Reads formatted input from the console (stdin).
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);  // Read an integer from the user
    printf("You entered: %d\n", num);


    // putchar(): Prints a single character to the console.
    putchar('X');
    putchar('\n');


    // getchar(): Reads a single character from the console (stdin).  Often needs to be
    // used to clear trailing newlines.
    printf("Press any key to continue: ");
    ch = getchar();
    printf("You pressed: %c\n", ch);


    // puts(): Prints a string to the console (stdout), followed by a newline.
    puts("This is a sample string.");

    // snprintf(): Formats a string and writes it to a buffer. Prevents buffer overflows
    // by specifying the maximum number of characters to write.
    snprintf(buffer, sizeof(buffer), "Formatted number: %d", 12345);
    printf("snprintf output: %s\n", buffer);

    // sscanf(): Reads formatted data from a string.  Like scanf but operates on a string.
    char data[] = "123 456";
    int a, b;
    sscanf(data, "%d %d", &a, &b); // Extract two integers from the string
    printf("sscanf extracted: %d and %d\n", a, b);

    // sprintf():  Formats data into a string. Similar to printf, but writes to a string instead of the console.
    sprintf(buffer, "Data: %d and %d", a, b);  // Format the integers into a string
    printf("sprintf output: %s\n", buffer);


    return 0;
}





// gcc stdio.c -o stdio




// This C code demonstrates various functions from the <stdio.h> standard library, which is essential for input/output operations. It covers file handling, formatted input/output, character input/output, and string manipulation related to I/O.

// File Handling:

// fopen(filename, "w"): Opens the file specified by filename in write mode ("w"). If the file doesn't exist, it's created. If it exists, its contents are truncated (erased). Returns a FILE pointer on success, or NULL on error.
// fopen(filename, "r"): Opens the file in read mode ("r"). Returns NULL if the file doesn't exist or cannot be opened.
// fprintf(file, format, ...): Writes formatted output to the file. The format string controls the output, similar to printf().
// fputs(string, file): Writes a string to the file.
// fputc(char, file): Writes a single character to the file.
// fclose(file): Closes the file, releasing resources. Essential for ensuring data is written and preventing errors.
// fgetc(file): Reads a single character from the file. Returns EOF (end-of-file) if the end of the file is reached or an error occurs.
// fgets(buffer, size, file): Reads a line from the file (up to size - 1 characters) and stores it in the buffer. Includes the newline character if read. Returns NULL at the end of the file or on error.
// rewind(file): Resets the file pointer to the beginning of the file.
// fseek(file, offset, whence): Moves the file pointer to a specified position. offset is the number of bytes to move, and whence specifies the starting point (e.g., SEEK_SET for the beginning, SEEK_CUR for the current position, SEEK_END for the end).
// ftell(file): Returns the current position of the file pointer (as an offset from the beginning of the file).
// fread(ptr, size, nmemb, file): Reads binary data from the file. Reads nmemb items of size bytes each into the memory pointed to by ptr. Returns the number of items successfully read.
// ferror(file): Checks for errors during file operations. Returns a non-zero value if an error occurred.
// feof(file): Checks if the end-of-file indicator has been set. Returns a non-zero value if EOF has been reached.
// rename(oldname, newname): Renames a file.
// remove(filename): Deletes a file.
// Console I/O (Standard Input/Output):

// printf(format, ...): Prints formatted output to the console (standard output).
// scanf(format, ...): Reads formatted input from the console (standard input).
// putchar(char): Prints a single character to the console.
// getchar(): Reads a single character from the console.
// puts(string): Prints a string to the console, followed by a newline.
// String I/O:

// snprintf(buffer, size, format, ...): Formats a string (like printf) but writes the result to a buffer with a specified maximum size to prevent buffer overflows.
// sscanf(string, format, ...): Reads formatted data from a string (like scanf, but from a string instead of standard input).
// sprintf(buffer, format, ...): Formats a string and stores the result in a character array (buffer). Be cautious about buffer overflows if the formatted string is longer than the buffer. snprintf() is safer.
// Example Flow and Compilation:

// The code first opens a file for writing, writes some data to it using different functions, and closes the file. Then, it reopens the file for reading, reads and prints the data using character and line reading functions, demonstrates file pointer manipulation with fseek() and ftell(), and shows binary reading with fread(). It also includes error and EOF checking with ferror() and feof(). It then demonstrates file renaming and deletion and shows examples of standard input/output and string formatting functions.

// To compile and run the code:

// gcc stdio.c -o stdio
// ./stdio
// This will compile stdio.c into an executable named stdio and then run it. You'll need to provide input when prompted by the scanf() function. The example file "example.txt" will be created, written to, read from, renamed, and then deleted.

// This explanation provides a comprehensive guide to understanding the core file and I/O functions in C's <stdio.h> library. Understanding these functions is essential for any C programmer. Remember to always check return values for errors when working with file I/O.
