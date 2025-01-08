#include <stdio.h>
#include <float.h> // Include float.h for floating-point limits

int main() {
    printf("===== Floating-Point Type Properties =====\n");

    // Radix (base) of the floating-point representation
    printf("FLT_RADIX: %d (Base of the floating-point representation)\n", FLT_RADIX);

    // Rounding mode
    printf("FLT_ROUNDS: %d (Rounding mode)\n", FLT_ROUNDS);

    printf("\n===== Float Type =====\n");
    printf("FLT_DIG: %d (Decimal digits of precision)\n", FLT_DIG);
    printf("FLT_EPSILON: %.10e (Smallest x such that 1.0 + x != 1.0)\n", FLT_EPSILON);
    printf("FLT_MIN: %.10e (Minimum normalized positive value)\n", FLT_MIN);
    printf("FLT_MAX: %.10e (Maximum representable finite value)\n", FLT_MAX);
    printf("FLT_MIN_EXP: %d (Minimum base-2 exponent)\n", FLT_MIN_EXP);
    printf("FLT_MAX_EXP: %d (Maximum base-2 exponent)\n", FLT_MAX_EXP);

    printf("\n===== Double Type =====\n");
    printf("DBL_DIG: %d (Decimal digits of precision)\n", DBL_DIG);
    printf("DBL_EPSILON: %.10e (Smallest x such that 1.0 + x != 1.0)\n", DBL_EPSILON);
    printf("DBL_MIN: %.10e (Minimum normalized positive value)\n", DBL_MIN);
    printf("DBL_MAX: %.10e (Maximum representable finite value)\n", DBL_MAX);
    printf("DBL_MIN_EXP: %d (Minimum base-2 exponent)\n", DBL_MIN_EXP);
    printf("DBL_MAX_EXP: %d (Maximum base-2 exponent)\n", DBL_MAX_EXP);

    printf("\n===== Long Double Type =====\n");
    printf("LDBL_DIG: %d (Decimal digits of precision)\n", LDBL_DIG);
    printf("LDBL_EPSILON: %.10Le (Smallest x such that 1.0 + x != 1.0)\n", LDBL_EPSILON);
    printf("LDBL_MIN: %.10Le (Minimum normalized positive value)\n", LDBL_MIN);
    printf("LDBL_MAX: %.10Le (Maximum representable finite value)\n", LDBL_MAX);
    printf("LDBL_MIN_EXP: %d (Minimum base-2 exponent)\n", LDBL_MIN_EXP);
    printf("LDBL_MAX_EXP: %d (Maximum base-2 exponent)\n", LDBL_MAX_EXP);

    return 0;
}





// The <float.h> header in C defines macros that specify the limits of floating-point types (float, double, and long double) on the system. These macros provide information about precision, range, and other properties of floating-point representations.
// Key Features of <float.h>:

//     Floating-Point Type Ranges:
//         Provides the minimum and maximum representable values for float, double, and long double.

//     Floating-Point Precision:
//         Defines the precision (number of significant digits) for each floating-point type.

//     Rounding Behavior:
//         Specifies details about rounding modes and radix.

// Important Macros in <float.h>:
// Precision:

//     FLT_DIG, DBL_DIG, LDBL_DIG: Number of decimal digits of precision for float, double, and long double, respectively.
//     FLT_EPSILON, DBL_EPSILON, LDBL_EPSILON: Smallest positive number such that 1.0 + x != 1.0.

// Range:

//     FLT_MIN, DBL_MIN, LDBL_MIN: Minimum positive normalized value.
//     FLT_MAX, DBL_MAX, LDBL_MAX: Maximum representable finite value.

// Exponents:

//     FLT_MIN_EXP, DBL_MIN_EXP, LDBL_MIN_EXP: Minimum exponent (base 2) for normalized values.
//     FLT_MAX_EXP, DBL_MAX_EXP, LDBL_MAX_EXP: Maximum exponent (base 2) for normalized values.

// Other:

//     FLT_RADIX: The base (or radix) of the floating-point numbers (usually 2).
//     FLT_ROUNDS: Indicates rounding mode:
//         -1: Indeterminate.
//         0: Towards zero.
//         1: Nearest (default).
//         2: Towards positive infinity.
//         3: Towards negative infinity.







// Explanation of the Code:

//     Precision:
//         FLT_DIG, DBL_DIG, and LDBL_DIG give the number of decimal digits of precision for float, double, and long double, respectively.

//     Epsilon:
//         FLT_EPSILON, DBL_EPSILON, and LDBL_EPSILON are the smallest positive values such that 1.0 + x != 1.0 for the respective types. These measure machine precision.

//     Range:
//         FLT_MIN, DBL_MIN, and LDBL_MIN give the smallest positive normalized values.
//         FLT_MAX, DBL_MAX, and LDBL_MAX give the largest finite values.

//     Exponents:
//         FLT_MIN_EXP and FLT_MAX_EXP provide the minimum and maximum exponents (base 2) for normalized floating-point numbers.

//     Rounding and Radix:
//         FLT_RADIX indicates the base (typically 2 for binary floating-point systems).
//         FLT_ROUNDS provides information about the current rounding mode.

// Compilation:

// To compile the program, use the following command:

// gcc -o float_example float_example.c

// Execution:

// Run the program with:

// ./float_example

// Sample Output:

// ===== Floating-Point Type Properties =====
// FLT_RADIX: 2 (Base of the floating-point representation)
// FLT_ROUNDS: 1 (Rounding mode)

// ===== Float Type =====
// FLT_DIG: 6 (Decimal digits of precision)
// FLT_EPSILON: 1.1920928962e-07 (Smallest x such that 1.0 + x != 1.0)
// FLT_MIN: 1.1754943508e-38 (Minimum normalized positive value)
// FLT_MAX: 3.4028234664e+38 (Maximum representable finite value)
// FLT_MIN_EXP: -125 (Minimum base-2 exponent)
// FLT_MAX_EXP: 128 (Maximum base-2 exponent)

// ===== Double Type =====
// DBL_DIG: 15 (Decimal digits of precision)
// DBL_EPSILON: 2.2204460493e-16 (Smallest x such that 1.0 + x != 1.0)
// DBL_MIN: 2.2250738585e-308 (Minimum normalized positive value)
// DBL_MAX: 1.7976931349e+308 (Maximum representable finite value)
// DBL_MIN_EXP: -1021 (Minimum base-2 exponent)
// DBL_MAX_EXP: 1024 (Maximum base-2 exponent)

// ===== Long Double Type =====
// LDBL_DIG: 18 (Decimal digits of precision)
// LDBL_EPSILON: 1.0842021725e-19 (Smallest x such that 1.0 + x != 1.0)
// LDBL_MIN: 3.3621031431e-4932 (Minimum normalized positive value)
// LDBL_MAX: 1.1897314954e+4932 (Maximum representable finite value)
// LDBL_MIN_EXP: -16381 (Minimum base-2 exponent)
// LDBL_MAX_EXP: 16384 (Maximum base-2 exponent)

// Key Points:

//     Floating-Point Portability:
//         The limits defined in <float.h> are system-dependent but provide a standard way to query these limits for any system.

//     Precision and Range:
//         These macros are essential for understanding the behavior of floating-point computations, particularly when dealing with very small or very large values.

//     Rounding and Radix:
//         FLT_ROUNDS and FLT_RADIX are useful for understanding how the floating-point system on the machine handles rounding and arithmetic.

// This program demonstrates all the macros provided by <float.h> and explains their significance. It serves as a comprehensive guide to understanding floating-point limits in C.