#include <stdio.h>

int main() {
    FILE *file;
    char data[] = "This is a test file.";

    // Writing to a file
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }
    fwrite(data, sizeof(char), sizeof(data), file);
    fclose(file);

    // Reading from the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }
    char buffer[100];
    fread(buffer, sizeof(char), sizeof(data), file);
    printf("Data read from file: %s\n", buffer);
    fclose(file);

    return 0;
}
