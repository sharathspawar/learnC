#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void display_memory(const char *label, const char *mem, size_t size) {
    printf("%s:", label);
    for (size_t i = 0; i < size; i++) {
        printf(" %02X", (unsigned char)mem[i]);
    }
    printf("\n");
}

int main() {
    double x = 0.5, y = 1.0;

    // acos(): Arccosine of x
    printf("acos(%.2f): %.2f radians\n", x, acos(x));

    // acosh(): Hyperbolic arccosine of x
    printf("acosh(%.2f): %.2f\n", x + 1, acosh(x + 1));

    // asin(): Arcsine of x
    printf("asin(%.2f): %.2f radians\n", x, asin(x));

    // asinh(): Hyperbolic arcsine of x
    printf("asinh(%.2f): %.2f\n", x, asinh(x));

    // atan(): Arctangent of x
    printf("atan(%.2f): %.2f radians\n", x, atan(x));

    // atan2(): Angle from rectangular coordinates
    printf("atan2(%.2f, %.2f): %.2f radians\n", y, x, atan2(y, x));

    // atanh(): Hyperbolic arctangent of x
    printf("atanh(%.2f): %.2f\n", x, atanh(x));

    // cbrt(): Cube root of x
    printf("cbrt(%.2f): %.2f\n", x, cbrt(x));

    // ceil(): Round x up to nearest integer
    printf("ceil(%.2f): %.2f\n", x, ceil(x));

    // copysign(): Copy sign of y to x
    printf("copysign(%.2f, %.2f): %.2f\n", x, -y, copysign(x, -y));

    // cos(): Cosine of x
    printf("cos(%.2f radians): %.2f\n", x, cos(x));

    // cosh(): Hyperbolic cosine of x
    printf("cosh(%.2f): %.2f\n", x, cosh(x));

    // exp(): Exponential of x
    printf("exp(%.2f): %.2f\n", x, exp(x));

    // exp2(): 2^x
    printf("exp2(%.2f): %.2f\n", x, exp2(x));

    // expm1(): e^x - 1
    printf("expm1(%.2f): %.2f\n", x, expm1(x));

    // erf(): Error function value at x
    printf("erf(%.2f): %.2f\n", x, erf(x));

    // erfc(): Complementary error function at x
    printf("erfc(%.2f): %.2f\n", x, erfc(x));

    // fabs(): Absolute value of x
    printf("fabs(%.2f): %.2f\n", -x, fabs(-x));

    // fdim(): Positive difference between x and y
    printf("fdim(%.2f, %.2f): %.2f\n", y, x, fdim(y, x));

    // floor(): Round x down to nearest integer
    printf("floor(%.2f): %.2f\n", x, floor(x));

    // fma(): (x * y) + z without precision loss
    printf("fma(%.2f, %.2f, %.2f): %.2f\n", x, y, x, fma(x, y, x));

    // fmax(): Maximum of x and y
    printf("fmax(%.2f, %.2f): %.2f\n", x, y, fmax(x, y));

    // fmin(): Minimum of x and y
    printf("fmin(%.2f, %.2f): %.2f\n", x, y, fmin(x, y));

    // fmod(): Floating-point remainder of x/y
    printf("fmod(%.2f, %.2f): %.2f\n", y, x, fmod(y, x));

    // frexp(): Mantissa and exponent of x
    int exp;
    double mantissa = frexp(x, &exp);
    printf("frexp(%.2f): Mantissa=%.2f, Exponent=%d\n", x, mantissa, exp);

    // hypot(): sqrt(x^2 + y^2)
    printf("hypot(%.2f, %.2f): %.2f\n", x, y, hypot(x, y));

    // ilogb(): Integer base logarithm of x
    printf("ilogb(%.2f): %d\n", y, ilogb(y));

    // ldexp(): x * 2^y
    printf("ldexp(%.2f, %d): %.2f\n", x, exp, ldexp(x, exp));

    // lgamma(): Logarithm of the gamma function
    printf("lgamma(%.2f): %.2f\n", y, lgamma(y));

    // llrint(): Rounded to long long
    printf("llrint(%.2f): %lld\n", y, llrint(y));

    // llround(): Rounded to nearest long long
    printf("llround(%.2f): %lld\n", y, llround(y));

    // log(): Natural logarithm
    printf("log(%.2f): %.2f\n", y, log(y));

    // log10(): Base-10 logarithm
    printf("log10(%.2f): %.2f\n", y, log10(y));

    // log1p(): log(1 + x)
    printf("log1p(%.2f): %.2f\n", x, log1p(x));

    // log2(): Base-2 logarithm
    printf("log2(%.2f): %.2f\n", y, log2(y));

    // logb(): Floating-point base logarithm
    printf("logb(%.2f): %.2f\n", y, logb(y));

    // lrint(): Rounded to long
    printf("lrint(%.2f): %ld\n", y, lrint(y));

    // lround(): Rounded to nearest long
    printf("lround(%.2f): %ld\n", y, lround(y));

    // modf(): Integer and fractional parts of x
    double int_part;
    double frac_part = modf(x, &int_part);
    printf("modf(%.2f): Fraction=%.2f, Integer=%.2f\n", x, frac_part, int_part);

    // nan(): Generate a NaN value
    printf("nan(): %f\n", nan(""));

    // nearbyint(): Nearest integer
    printf("nearbyint(%.2f): %.2f\n", y, nearbyint(y));

    // nextafter(): Next representable value
    printf("nextafter(%.2f, %.2f): %.2f\n", x, y, nextafter(x, y));

    // nexttoward(): Closest in direction of y
    printf("nexttoward(%.2f, %.2Lf): %.2f\n", x, (long double)y, nexttoward(x, y));

    // pow(): x^y
    printf("pow(%.2f, %.2f): %.2f\n", x, y, pow(x, y));

    // remainder(): Remainder of x/y
    printf("remainder(%.2f, %.2f): %.2f\n", y, x, remainder(y, x));

    // remquo(): Remainder and quotient
    int quo;
    printf("remquo(%.2f, %.2f): %.2f, Quotient=%d\n", y, x, remquo(y, x, &quo), quo);

    // rint(): Rounded to integer
    printf("rint(%.2f): %.2f\n", y, rint(y));

    // round(): Rounded to nearest integer
    printf("round(%.2f): %.2f\n", y, round(y));

    // scalbln(): Scale by power of 2
    printf("scalbln(%.2f, %ld): %.2f\n", x, (long)exp, scalbln(x, exp));

    // scalbn(): Scale by power of 2
    printf("scalbn(%.2f, %d): %.2f\n", x, exp, scalbn(x, exp));

    // sin(): Sine of x
    printf("sin(%.2f radians): %.2f\n", x, sin(x));

    // sinh(): Hyperbolic sine of x
    printf("sinh(%.2f): %.2f\n", x, sinh(x));

    // sqrt(): Square root of x
    printf("sqrt(%.2f): %.2f\n", y, sqrt(y));

    // tan(): Tangent of x
    printf("tan(%.2f radians): %.2f\n", x, tan(x));

    // tanh(): Hyperbolic tangent of x
    printf("tanh(%.2f): %.2f\n", x, tanh(x));

    // tgamma(): Gamma function of x
    printf("tgamma(%.2f): %.2f\n", y, tgamma(y));

    // trunc(): Truncate to integer
    printf("trunc(%.2f): %.2f\n", y, trunc(y));

    return 0;
}


// The C code explores a wide range of mathematical functions provided by the <math.h> library. It demonstrates how to use these functions with double-precision floating-point numbers. Here's a categorized explanation:

// Trigonometric Functions:

// acos(x): Calculates the arccosine of x. The result is in radians and is within the range [0, π]. x must be in the range [-1, 1].
// asin(x): Calculates the arcsine of x. The result is in radians and is within the range [-π/2, π/2]. x must be in the range [-1, 1].
// atan(x): Calculates the arctangent of x. The result is in radians and is within the range [-π/2, π/2].
// atan2(y, x): Calculates the arctangent of y/x. Unlike atan(), it considers the signs of both x and y to determine the correct quadrant for the result, which is in the range [-π, π].
// cos(x): Calculates the cosine of x (where x is in radians).
// sin(x): Calculates the sine of x (where x is in radians).
// tan(x): Calculates the tangent of x (where x is in radians).
// Hyperbolic Functions:

// acosh(x): Calculates the hyperbolic arccosine of x. x must be greater than or equal to 1.
// asinh(x): Calculates the hyperbolic arcsine of x.
// atanh(x): Calculates the hyperbolic arctangent of x. The absolute value of x must be less than 1.
// cosh(x): Calculates the hyperbolic cosine of x.
// sinh(x): Calculates the hyperbolic sine of x.
// tanh(x): Calculates the hyperbolic tangent of x.
// Exponential and Logarithmic Functions:

// exp(x): Calculates the exponential function of x (e^x).
// exp2(x): Calculates 2 raised to the power of x (2^x).
// expm1(x): Calculates e^x - 1. This function is more accurate for small values of x compared to directly calculating exp(x) - 1.
// log(x): Calculates the natural logarithm (base e) of x. x must be positive.
// log10(x): Calculates the base-10 logarithm of x. x must be positive.
// log1p(x): Calculates the natural logarithm of 1 + x. This function is more accurate for small values of x compared to directly calculating log(1 + x).
// log2(x): Calculates the base-2 logarithm of x. x must be positive.
// logb(x): Returns the exponent of x as a floating-point value.
// Rounding and Remainder Functions:

// ceil(x): Rounds x up to the nearest integer.
// floor(x): Rounds x down to the nearest integer.
// fmod(x, y): Returns the floating-point remainder of x/y.
// remainder(x, y): Computes the IEEE 754 floating-point remainder of x/y.
// remquo(x, y, quo): Calculates the remainder of x/y and stores the quotient in the integer pointed to by quo.
// rint(x): Rounds x to the nearest integer, rounding halfway cases away from zero.
// round(x): Rounds x to the nearest integer, rounding halfway cases away from zero.
// trunc(x): Truncates x (removes the fractional part), returning the integer part.
// Other Mathematical Functions:

// cbrt(x): Calculates the cube root of x.
// copysign(x, y): Returns a value with the magnitude of x and the sign of y.
// fabs(x): Calculates the absolute value of x.
// fdim(x, y): Returns the positive difference between x and y. If x <= y, the result is 0.
// fma(x, y, z): Calculates (x * y) + z with a single rounding operation, potentially improving accuracy.
// fmax(x, y): Returns the maximum of x and y.
// fmin(x, y): Returns the minimum of x and y.
// frexp(x, exp): Breaks x into a normalized fraction (mantissa) and an integral power of 2 (exponent). The mantissa is returned, and the exponent is stored in the integer pointed to by exp.
// hypot(x, y): Calculates the hypotenuse of a right-angled triangle with sides of length x and y (sqrt(x^2 + y^2)). Avoids potential overflow or underflow issues.
// ilogb(x): Extracts the exponent of x as an integer, according to the IEC 60559 standard.
// ldexp(x, exp): Multiplies x by 2 raised to the power of exp.
// lgamma(x): Calculates the natural logarithm of the absolute value of the gamma function of x.
// llrint(x): Rounds x to the nearest long long integer.
// llround(x): Rounds x to the nearest long long integer, rounding halfway cases away from zero.
// lrint(x): Rounds x to the nearest long integer.
// lround(x): Rounds x to the nearest long integer, rounding halfway cases away from zero.
// modf(x, intpart): Breaks x into its integer and fractional parts. Returns the fractional part, and stores the integer part in the double pointed to by intpart.
// nan(tagp): Returns a "Not a Number" (NaN) value. The tagp argument is optional and can be used to distinguish different NaN values (often not used).
// nearbyint(x): Rounds x to the nearest integer, according to the current rounding mode (set via fesetround).
// nextafter(x, y): Returns the next representable floating-point value after x in the direction of y.
// nexttoward(x, y): Similar to nextafter(), but y can be a long double.
// pow(x, y): Calculates x raised to the power of y.
// scalbln(x, n): Multiplies x by FLT_RADIX raised to the power of n.
// scalbn(x, n): Similar to scalbln(), but n is an int.
// tgamma(x): Calculates the gamma function of x.
// The code initializes x to 0.5 and y to 1.0 and then systematically calls each function, printing the results. This provides a practical demonstration of how to use these math functions in your C programs. To compile and run, remember to link the math library using -lm:



// gcc your_program.c -lm -o your_program
// ./your_program
