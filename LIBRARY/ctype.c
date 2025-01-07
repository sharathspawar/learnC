#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char ch1 = 'A', ch2 = '1', ch3 = ' ', ch4 = '\t';

    // isalnum(): Check if character is alphanumeric
    printf("isalnum('%c'): %d\n", ch1, isalnum(ch1));
    printf("isalnum('%c'): %d\n", ch2, isalnum(ch2));

    // isalpha(): Check if character is a letter
    printf("isalpha('%c'): %d\n", ch1, isalpha(ch1));
    printf("isalpha('%c'): %d\n", ch2, isalpha(ch2));

    // isblank(): Check if character is a blank (space or tab)
    printf("isblank('%c'): %d\n", ch3, isblank(ch3));
    printf("isblank('%c'): %d\n", ch4, isblank(ch4));

    // iscntrl(): Check if character is a control character
    printf("iscntrl('\n'): %d\n", iscntrl('\n'));

    // isdigit(): Check if character is a decimal digit
    printf("isdigit('%c'): %d\n", ch2, isdigit(ch2));

    // isgraph(): Check if character has a graphical representation
    printf("isgraph('%c'): %d\n", ch1, isgraph(ch1));
    printf("isgraph('%c'): %d\n", ch3, isgraph(ch3));

    // islower(): Check if character is a lowercase letter
    printf("islower('%c'): %d\n", ch1, islower(ch1));
    printf("islower('a'): %d\n", islower('a'));

    // isprint(): Check if character is printable
    printf("isprint('%c'): %d\n", ch1, isprint(ch1));
    printf("isprint('%c'): %d\n", ch3, isprint(ch3));

    // ispunct(): Check if character is a punctuation mark
    printf("ispunct('!'): %d\n", ispunct('!'));
    printf("ispunct('%c'): %d\n", ch1, ispunct(ch1));

    // isspace(): Check if character is a whitespace character
    printf("isspace('%c'): %d\n", ch3, isspace(ch3));
    printf("isspace('%c'): %d\n", ch4, isspace(ch4));

    // isupper(): Check if character is an uppercase letter
    printf("isupper('%c'): %d\n", ch1, isupper(ch1));
    printf("isupper('a'): %d\n", isupper('a'));

    // isxdigit(): Check if character is a hexadecimal digit
    printf("isxdigit('%c'): %d\n", 'F', isxdigit('F'));
    printf("isxdigit('%c'): %d\n", ch2, isxdigit(ch2));

    // tolower(): Convert character to lowercase
    printf("tolower('%c'): %c\n", ch1, tolower(ch1));

    // toupper(): Convert character to uppercase
    printf("toupper('a'): %c\n", toupper('a'));

    return 0;
}


// The C code you provided demonstrates the use of character classification and manipulation functions from the <ctype.h> library. These functions are useful for validating user input, parsing text, and other character-related operations. Here's a breakdown:

// Character Classification Functions:

// These functions test a character and return a non-zero value (true) if the character meets the specified criteria, and 0 (false) otherwise.

// isalnum(ch): Checks if ch is an alphanumeric character (a letter or a digit).
// isalpha(ch): Checks if ch is an alphabetic character (a letter).
// isblank(ch): Checks if ch is a blank character (space or horizontal tab).
// iscntrl(ch): Checks if ch is a control character (e.g., newline, backspace, tab).
// isdigit(ch): Checks if ch is a decimal digit (0-9).
// isgraph(ch): Checks if ch has a graphical representation (any printing character except space).
// islower(ch): Checks if ch is a lowercase letter.
// isprint(ch): Checks if ch is any printable character (including space).
// ispunct(ch): Checks if ch is a punctuation character (neither alphanumeric nor a space).
// isspace(ch): Checks if ch is a whitespace character (space, tab, newline, vertical tab, form feed, carriage return).
// isupper(ch): Checks if ch is an uppercase letter.
// isxdigit(ch): Checks if ch is a hexadecimal digit (0-9, A-F, a-f).
// Character Manipulation Functions:

// These functions convert the case of a character:

// tolower(ch): Converts ch to its lowercase equivalent. If ch is already lowercase or not a letter, it is returned unchanged.
// toupper(ch): Converts ch to its uppercase equivalent. If ch is already uppercase or not a letter, it is returned unchanged.
// Example Breakdown:

// The main function initializes four characters: ch1 ('A'), ch2 ('1'), ch3 (space), and ch4 (tab). It then calls each of the ctype.h functions with these characters (and a few others) to demonstrate their behavior. The output of the printf statements will show the results of each function call. For example:

// printf("isalnum('%c'): %d\n", ch1, isalnum(ch1));

// This line will print: isalnum('A'): 1 because 'A' is an alphanumeric character. The %d format specifier displays the integer result of isalnum(), where 1 represents true and 0 represents false.

// The code provides a comprehensive overview of how to use the ctype.h functions in C to classify and manipulate characters. This is fundamental for tasks like input validation, text processing, and parsing.
