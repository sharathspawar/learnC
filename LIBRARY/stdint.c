#include <stdio.h>
#include <stdint.h>

int main() {
    // Fixed-width integer types
    int8_t a = INT8_MAX;             // 8-bit signed integer
    uint8_t b = UINT8_MAX;           // 8-bit unsigned integer
    int16_t c = INT16_MAX;           // 16-bit signed integer
    uint16_t d = UINT16_MAX;         // 16-bit unsigned integer
    int32_t e = INT32_MAX;           // 32-bit signed integer
    uint32_t f = UINT32_MAX;         // 32-bit unsigned integer
    int64_t g = INT64_MAX;           // 64-bit signed integer
    uint64_t h = UINT64_MAX;         // 64-bit unsigned integer

    // Integer limits and macros
    printf("int8_t max: %d\n", a);
    printf("uint8_t max: %u\n", b);
    printf("int16_t max: %d\n", c);
    printf("uint16_t max: %u\n", d);
    printf("int32_t max: %d\n", e);
    printf("uint32_t max: %u\n", f);
    printf("int64_t max: %lld\n", g);
    printf("uint64_t max: %llu\n", h);

    // Fast integer types
    int_fast8_t fast8 = 127;
    uint_fast16_t fast16 = 65535;

    printf("int_fast8_t: %d\n", fast8);
    printf("uint_fast16_t: %u\n", fast16);

    // Least integer types
    int_least8_t least8 = -128;
    uint_least16_t least16 = 0;

    printf("int_least8_t: %d\n", least8);
    printf("uint_least16_t: %u\n", least16);

    // Integer pointer types
    intptr_t intptr = (intptr_t)&a;
    uintptr_t uintptr = (uintptr_t)&b;

    printf("intptr_t: %p\n", (void *)intptr);
    printf("uintptr_t: %p\n", (void *)uintptr);

    // Constant macros
    printf("INT8_MIN: %d\n", INT8_MIN);
    printf("INT16_MIN: %d\n", INT16_MIN);
    printf("INT32_MIN: %d\n", INT32_MIN);
    printf("INT64_MIN: %lld\n", INT64_MIN);

    printf("INT8_MAX: %d\n", INT8_MAX);
    printf("UINT8_MAX: %u\n", UINT8_MAX);
    printf("INT16_MAX: %d\n", INT16_MAX);
    printf("UINT16_MAX: %u\n", UINT16_MAX);
    printf("INT32_MAX: %d\n", INT32_MAX);
    printf("UINT32_MAX: %u\n", UINT32_MAX);
    printf("INT64_MAX: %lld\n", INT64_MAX);
    printf("UINT64_MAX: %llu\n", UINT64_MAX);

    // Wide integers
    uintmax_t max = UINTMAX_MAX;
    intmax_t min = INTMAX_MIN;

    printf("intmax_t min: %lld\n", min);
    printf("uintmax_t max: %llu\n", max);

    return 0;
}


// Features Covered:

//     Fixed-width integers: int8_t, uint16_t, etc.
//     Fast and least integers: int_fast8_t, int_least8_t, etc.
//     Integer limits: INT8_MAX, UINT32_MAX, etc.
//     Pointer integers: intptr_t and uintptr_t.
//     Maximum-width integers: intmax_t, uintmax_t.
//     Printing values: Shows how to work with the types effectively.

// Compile and run this program with a C99-compliant compiler or later (gcc or similar) using the following command:

// gcc -std=c99 -o stdint_demo stdint_demo.c
// ./stdint_demo

// This program comprehensively demonstrates the types and macros provided by <stdint.h>.





// The provided C code demonstrates the use of the stdint.h library, which defines fixed-width integer types and macros. This is crucial for portability and ensuring consistent integer sizes across different platforms.

// Fixed-Width Integer Types:

// The code showcases the following fixed-width integer types:

// int8_t: 8-bit signed integer.
// uint8_t: 8-bit unsigned integer.
// int16_t: 16-bit signed integer.
// uint16_t: 16-bit unsigned integer.
// int32_t: 32-bit signed integer.
// uint32_t: 32-bit unsigned integer.
// int64_t: 64-bit signed integer.
// uint64_t: 64-bit unsigned integer.
// These types guarantee specific sizes, unlike int or long, which might vary depending on the compiler and system.

// Fast and Least Integer Types:

// The code demonstrates "fast" and "least" integer types:

// int_fast8_t: Fastest signed integer type with at least 8 bits.
// uint_fast16_t: Fastest unsigned integer type with at least 16 bits.
// int_least8_t: Smallest signed integer type with at least 8 bits.
// uint_least16_t: Smallest unsigned integer type with at least 16 bits.
// "Fast" types prioritize speed, while "least" types prioritize minimal storage.

// Integer Limits and Macros:

// The code uses macros like INT8_MAX, UINT32_MAX, INT64_MIN, etc. These macros define the maximum and minimum values for the corresponding fixed-width integer types. They are essential for range checking and preventing overflow errors.

// Integer Pointer Types:

// intptr_t: Signed integer type capable of holding a pointer.
// uintptr_t: Unsigned integer type capable of holding a pointer.
// These are useful for converting pointers to integers and vice versa.

// Maximum-Width Integers:

// intmax_t: Largest signed integer type available.
// uintmax_t: Largest unsigned integer type available.
// These types represent the largest integer sizes the system supports.

// Printing Values:

// The code demonstrates using the correct format specifiers for printing these types, such as %d for signed integers, %u for unsigned integers, %lld for int64_t, %llu for uint64_t, and %p for pointer types. It also uses the correct casting (void*) when printing pointers using %p.

// Key Purpose of stdint.h:

// The stdint.h library is vital for writing portable C code that relies on specific integer sizes. By using these types and macros, you can avoid issues caused by varying integer sizes on different systems, ensuring your code works reliably across platforms.