#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display memory contents in hexadecimal (useful for debugging)
void display_memory(const char *label, const char *mem, size_t size) {
    printf("%s:", label);
    for (size_t i = 0; i < size; i++) {
        printf(" %02X", (unsigned char)mem[i]);
    }
    printf("\n");
}

int main() {
    // memset(): Sets a block of memory to a specific value.
    char buffer[20];
    memset(buffer, 'A', sizeof(buffer));  // Fill buffer with 'A's
    printf("Buffer after memset: %.*s\n", (int)sizeof(buffer), buffer);

    // memcpy(): Copies a block of memory from source to destination.  Does not handle overlapping memory correctly.
    char source[] = "Hello, World!";
    char dest[20];
    memcpy(dest, source, strlen(source) + 1); // +1 to copy the null terminator
    printf("Destination after memcpy: %s\n", dest);

    // memmove(): Copies a block of memory, handling overlapping regions safely.
    char overlap[] = "OverlapTest";
    memmove(overlap + 2, overlap, 6);  // Shifts "lapTes" two positions to the right within the array.
    printf("Overlap array after memmove: %s\n", overlap);

    // memchr(): Searches for the first occurrence of a character in a memory block.
    char *found = memchr(buffer, 'A', sizeof(buffer)); //Looks for 'A' in the buffer.
    if (found) {
        printf("Found 'A' at position: %ld\n", found - buffer);  // Pointer arithmetic to find the index
    } else {
        printf("'A' not found in buffer.\n");
    }

    // memcmp(): Compares two blocks of memory.
    char mem1[] = "ABCDEF";
    char mem2[] = "ABCDEG";
    int cmp_result = memcmp(mem1, mem2, 6);  // Compare the first 6 bytes
    printf("memcmp result: %d\n", cmp_result);  // <0 if mem1<mem2, 0 if equal, >0 if mem1>mem2



    // String Functions (string.h):

    // strcat(): Concatenates (appends) the source string to the end of the destination string.
    char str1[50] = "Hello";
    char str2[] = ", World!";
    strcat(str1, str2);  // Modifies str1; ensure str1 has enough allocated memory.
    printf("Concatenated string: %s\n", str1);

    // strchr(): Finds the first occurrence of a character in a string.
    char *chr = strchr(str1, 'W');  // Returns a pointer to 'W' or NULL if not found
    if (chr) {
        printf("First 'W' found at position: %ld\n", chr - str1);
    } else {
        printf("'W' not found in string.\n");
    }

    // strcmp(): Compares two strings lexicographically.
    char cmp_str1[] = "ABC";
    char cmp_str2[] = "ABD";
    printf("strcmp result: %d\n", strcmp(cmp_str1, cmp_str2)); // Negative if str1<str2, 0 if equal, positive if str1>str2


    // strcoll(): Compares two strings based on the current locale (for internationalization).
    printf("strcoll result: %d\n", strcoll(cmp_str1, cmp_str2));

    // strcpy(): Copies the source string to the destination string.
    char copy_dest[50];
    strcpy(copy_dest, cmp_str1);  // Make sure copy_dest is large enough
    printf("Copied string: %s\n", copy_dest);


    // strcspn(): Returns the length of the initial part of the string that does *not* contain any of the specified characters.
    char str_cspn[] = "abcdef";
    printf("strcspn result: %ld\n", strcspn(str_cspn, "cd"));  // Output: 2 (because "ab" doesn't contain 'c' or 'd')


    // strerror(): Returns a string describing the error code.
    printf("Error message for code 2: %s\n", strerror(2));  // "No such file or directory" (typically)


    // strlen(): Returns the length of a string.
    printf("Length of string '%s': %ld\n", str1, strlen(str1));

    // strncat():  Appends a portion of the source string to the destination string, up to a specified number of characters. Safer than `strcat`.
    char ncat_dest[50] = "Start: ";
    strncat(ncat_dest, cmp_str1, 2); // Append up to 2 characters from cmp_str1
    printf("String after strncat: %s\n", ncat_dest); 

    // strncmp(): Compares up to n characters of two strings.
    printf("strncmp result: %d\n", strncmp(cmp_str1, cmp_str2, 2)); //Like strcmp, but compares only first 2 characters.

    // strncpy(): Copies  a portion of the source string to the destination string, up to a specified number of characters. Might not null-terminate if source length exceeds specified size.
    char ncpy_dest[50];
    strncpy(ncpy_dest, cmp_str1, 2);  //Copy first 2 characters.
    ncpy_dest[2] = '\0'; // Ensure null termination (important!) especially if strlen(cmp_str1) >= 2
    printf("String after strncpy: %s\n", ncpy_dest); // Output: AB

    // strpbrk():  Finds the first character in the string that matches any character in the specified set of characters.
    char *pbrk = strpbrk(str1, "aeiou"); // Find the first vowel in the string
    if (pbrk) {
        printf("First vowel in string: %c\n", *pbrk);
    } else {
        printf("No vowels found in string.\n");
    }

    // strrchr(): Finds the last occurrence of a character in a string.
    char *rchr = strrchr(str1, 'o'); //Find the last 'o' in the string.
    if (rchr) {
        printf("Last 'o' found at position: %ld\n", rchr - str1);
    } else {
        printf("'o' not found in string.\n");
    }

    // strspn(): Returns the length of the initial portion of a string that consists entirely of characters from a specified set.
    char str_spn[] = "abcdef";
    printf("strspn result: %ld\n", strspn(str_spn, "abc"));  // Output: 3 (because "abc" are present at the beginning)

    // strstr(): Finds the first occurrence of a substring within a string.
    char *substr = strstr(str1, "World"); //Find "World" in str1
    if (substr) {
        printf("Substring 'World' found at position: %ld\n", substr - str1);
    } else {
        printf("Substring 'World' not found.\n");
    }

    // strtok():  Breaks a string into a sequence of tokens based on delimiters.
    char str_tok[] = "token1,token2,token3";
    char *token = strtok(str_tok, ","); //Get the first token
    while (token) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");  // Get subsequent tokens. Pass NULL after the first call.
    }

    // strxfrm(): Transforms a string based on locale settings (for locale-aware comparisons). Less common.
    char xfrm_dest[50];
    strxfrm(xfrm_dest, cmp_str1, sizeof(xfrm_dest));  
    printf("Transformed string: %s\n", xfrm_dest);

    return 0;
}


// This C code demonstrates a variety of functions from the <string.h> library, useful for manipulating strings and memory. Here's a breakdown with explanations:

// Memory Functions:

// memset(void *ptr, int value, size_t num): Sets the first num bytes of the memory block pointed to by ptr to the specified value. Useful for initializing arrays or structures to a particular value.

// memset(buffer, 'A', sizeof(buffer)); // Fills buffer with 'A' characters
// memcpy(void *dest, const void *src, size_t num): Copies num bytes from the memory block pointed to by src to the memory block pointed to by dest. The source and destination memory blocks should not overlap. Use memmove() if they might overlap.

// memcpy(dest, source, strlen(source) + 1); // Copies the string "Hello, World!" including the null terminator.
// memmove(void *dest, const void *src, size_t num): Similar to memcpy(), but safely handles overlapping memory regions.

// memmove(overlap + 2, overlap, 6); //  Correctly handles the overlap, resulting in "OvOverlapTe".
// memchr(const void *ptr, int value, size_t num): Searches for the first occurrence of the byte value within the first num bytes of the memory block pointed to by ptr. Returns a pointer to the located byte or NULL if not found.

// char *found = memchr(buffer, 'A', sizeof(buffer)); // Finds the first 'A' in the buffer.
// memcmp(const void *ptr1, const void *ptr2, size_t num): Compares the first num bytes of the memory blocks pointed to by ptr1 and ptr2. Returns:

// 0 if the memory blocks are identical.
// A negative value if ptr1 is less than ptr2.
// A positive value if ptr1 is greater than ptr2.
// int cmp_result = memcmp(mem1, mem2, 6); // Compares "ABCDEF" and "ABCDEG".
// String Functions:

// strcat(char *dest, const char *src): Appends a copy of the string src to the end of the string dest. Ensure dest has enough allocated memory to avoid buffer overflows!

// strcat(str1, str2); //  Appends ", World!" to "Hello".
// strchr(const char *str, int c): Finds the first occurrence of the character c in the string str. Returns a pointer to the first occurrence or NULL if not found.

// char *chr = strchr(str1, 'W'); // Finds the first 'W' in "Hello, World!".
// strcmp(const char *str1, const char *str2): Compares two strings lexicographically.

// Returns 0 if the strings are identical.
// Returns a negative value if str1 comes before str2.
// Returns a positive value if str1 comes after str2.
// printf("strcmp result: %d\n", strcmp(cmp_str1, cmp_str2)); //  Compares "ABC" and "ABD".
// strcoll(const char *str1, const char *str2): Similar to strcmp(), but uses the current locale for comparison, important for internationalization.

// strcpy(char *dest, const char *src): Copies the string src (including the null terminator) to the destination dest. Ensure that dest has enough allocated space to prevent buffer overflows.

// strcpy(copy_dest, cmp_str1); // Copies "ABC" to copy_dest.
// strcspn(const char *str1, const char *str2): Returns the length of the initial segment of str1 that does not contain any of the characters in str2.

// strerror(int errnum): Returns a string describing the error code errnum.

// strlen(const char *str): Calculates the length of the string str (excluding the null terminator).

// strncat(char *dest, const char *src, size_t n): Safer version of strcat(). Appends at most n characters from src to dest, and always null-terminates the result. Prevents potential buffer overflows.

// strncmp(const char *str1, const char *str2, size_t n): Similar to strcmp(), but compares only the first n characters.

// strncpy(char *dest, const char *src, size_t n): Copies at most n characters from src to dest. If src is shorter than n, dest is padded with null characters up to length n. Important: If src has length n or greater, strncpy won't null-terminate dest. Always manually null-terminate dest after strncpy.

// strpbrk(const char *str1, const char *str2): Locates the first occurrence in str1 of any character in str2.

// strrchr(const char *str, int c): Like strchr() but finds the last occurrence of c in str.

// strspn(const char *str1, const char *str2): Calculates the length of the initial segment of str1 that consists entirely of characters from str2.

// strstr(const char *haystack, const char *needle): Finds the first occurrence of the substring needle within the string haystack.

// strtok(char *str, const char *delim): Breaks a string into a sequence of tokens based on the delimiters in delim. Important: strtok() modifies the original string.

// strxfrm(char *dest, const char *src, size_t n): Transforms a string based on the current locale, primarily used for locale-aware string comparisons.

// This explanation provides a comprehensive overview of the <string.h> functions demonstrated in the code, with a focus on correct usage, potential pitfalls, and important considerations like buffer overflows and null termination. Understanding these concepts is crucial for writing safe and reliable C code. Remember to compile with warnings enabled (e.g., gcc -Wall -Wextra ...) to catch potential issues.