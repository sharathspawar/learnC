#include <stdio.h>
#include <limits.h> // Include limits.h for system-dependent limits

int main() {
    printf("===== Integer Type Limits =====\n");

    // Character type limits
    printf("CHAR_BIT: %d bits in a char\n", CHAR_BIT);
    printf("SCHAR_MIN: %d (Minimum value of signed char)\n", SCHAR_MIN);
    printf("SCHAR_MAX: %d (Maximum value of signed char)\n", SCHAR_MAX);
    printf("UCHAR_MAX: %u (Maximum value of unsigned char)\n", UCHAR_MAX);
    printf("CHAR_MIN: %d (Minimum value of char)\n", CHAR_MIN);
    printf("CHAR_MAX: %d (Maximum value of char)\n", CHAR_MAX);

    // Short type limits
    printf("\nSHRT_MIN: %d (Minimum value of short)\n", SHRT_MIN);
    printf("SHRT_MAX: %d (Maximum value of short)\n", SHRT_MAX);
    printf("USHRT_MAX: %u (Maximum value of unsigned short)\n", USHRT_MAX);

    // Integer type limits
    printf("\nINT_MIN: %d (Minimum value of int)\n", INT_MIN);
    printf("INT_MAX: %d (Maximum value of int)\n", INT_MAX);
    printf("UINT_MAX: %u (Maximum value of unsigned int)\n", UINT_MAX);

    // Long type limits
    printf("\nLONG_MIN: %ld (Minimum value of long)\n", LONG_MIN);
    printf("LONG_MAX: %ld (Maximum value of long)\n", LONG_MAX);
    printf("ULONG_MAX: %lu (Maximum value of unsigned long)\n", ULONG_MAX);

    // Long long type limits (if supported)
    printf("\nLLONG_MIN: %lld (Minimum value of long long)\n", LLONG_MIN);
    printf("LLONG_MAX: %lld (Maximum value of long long)\n", LLONG_MAX);
    printf("ULLONG_MAX: %llu (Maximum value of unsigned long long)\n", ULLONG_MAX);

    // Multibyte character limits
    printf("\n===== Other Limits =====\n");
    printf("MB_LEN_MAX: %d (Maximum number of bytes in a multibyte character)\n", MB_LEN_MAX);

    return 0;
}



// The <limits.h> header in C provides macros that define various properties of the fundamental data types (such as the size and range of integers). These macros are crucial for writing portable programs, as they allow you to understand the system-dependent limits of data types.
// Key Features of <limits.h>:

//     Integer Type Limits:
//         Defines the minimum and maximum values for char, short, int, long, and their unsigned counterparts.
//     Character Type Limits:
//         Includes the ranges of signed char, unsigned char, and char (which may be signed or unsigned depending on the implementation).
//     Other Constants:
//         Defines limits for various constants, such as the number of bits in a char (CHAR_BIT).

// Important Macros:
// Integer Type Limits:

//     CHAR_BIT: Number of bits in a char.
//     SCHAR_MIN, SCHAR_MAX: Minimum and maximum values of a signed char.
//     UCHAR_MAX: Maximum value of an unsigned char.
//     CHAR_MIN, CHAR_MAX: Minimum and maximum values of a char (signed or unsigned, implementation-defined).
//     SHRT_MIN, SHRT_MAX: Minimum and maximum values of a short.
//     USHRT_MAX: Maximum value of an unsigned short.
//     INT_MIN, INT_MAX: Minimum and maximum values of an int.
//     UINT_MAX: Maximum value of an unsigned int.
//     LONG_MIN, LONG_MAX: Minimum and maximum values of a long.
//     ULONG_MAX: Maximum value of an unsigned long.
//     LLONG_MIN, LLONG_MAX: Minimum and maximum values of a long long (if supported).
//     ULLONG_MAX: Maximum value of an unsigned long long.

// Other Constants:

//     MB_LEN_MAX: Maximum number of bytes in a multibyte character.





// Explanation of the Code:

//     Integer Type Limits:
//         The macros such as INT_MIN and INT_MAX give the minimum and maximum values of int on the current platform.
//         The program prints these values using the appropriate format specifiers (%d, %u, %ld, %llu, etc.).

//     Character Type Limits:
//         CHAR_MIN and CHAR_MAX indicate the range of the char type. These depend on whether char is treated as signed or unsigned on the platform.
//         CHAR_BIT indicates the number of bits in a char (usually 8).

//     Multibyte Character Limits:
//         MB_LEN_MAX defines the maximum length of a multibyte character for the current locale.

// Compilation:

// To compile the program, use the following command:

// gcc -o limits_example limits_example.c

// Execution:

// Run the program with:

// ./limits_example

// Sample Output:

// ===== Integer Type Limits =====
// CHAR_BIT: 8 bits in a char
// SCHAR_MIN: -128 (Minimum value of signed char)
// SCHAR_MAX: 127 (Maximum value of signed char)
// UCHAR_MAX: 255 (Maximum value of unsigned char)
// CHAR_MIN: -128 (Minimum value of char)
// CHAR_MAX: 127 (Maximum value of char)

// SHRT_MIN: -32768 (Minimum value of short)
// SHRT_MAX: 32767 (Maximum value of short)
// USHRT_MAX: 65535 (Maximum value of unsigned short)

// INT_MIN: -2147483648 (Minimum value of int)
// INT_MAX: 2147483647 (Maximum value of int)
// UINT_MAX: 4294967295 (Maximum value of unsigned int)

// LONG_MIN: -9223372036854775808 (Minimum value of long)
// LONG_MAX: 9223372036854775807 (Maximum value of long)
// ULONG_MAX: 18446744073709551615 (Maximum value of unsigned long)

// LLONG_MIN: -9223372036854775808 (Minimum value of long long)
// LLONG_MAX: 9223372036854775807 (Maximum value of long long)
// ULLONG_MAX: 18446744073709551615 (Maximum value of unsigned long long)

// ===== Other Limits =====
// MB_LEN_MAX: 16 (Maximum number of bytes in a multibyte character)

// Key Points:

//     Portability:
//         These limits are system-dependent. By using <limits.h>, you can write portable code that adapts to different platforms.

//     Integer Ranges:
//         Signed integer types have both a minimum and maximum value.
//         Unsigned integer types only have a maximum value.

//     Character Limits:
//         The range of char depends on whether char is treated as signed or unsigned on the platform.

//     Multibyte Characters:
//         The MB_LEN_MAX macro defines the maximum number of bytes required for a multibyte character in the current locale.

// This program comprehensively explains and demonstrates the use of all the macros provided by <limits.h>. It is essential for understanding the limits of data types and writing robust, portable C programs.
