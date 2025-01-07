#include <stdio.h>

int main() {
    // Variables for demonstration
    int a = 10, b = 5, c = 0;
    float x = 10.5, y = 3.5, z = 0.0;
    char ch = 'A';

    // 1. Arithmetic Operators (+, -, *, /, %)
    // Addition
    int sum = a + b;
    printf("Addition: %d + %d = %d\n", a, b, sum);

    // Subtraction
    int difference = a - b;
    printf("Subtraction: %d - %d = %d\n", a, b, difference);

    // Multiplication
    int product = a * b;
    printf("Multiplication: %d * %d = %d\n", a, b, product);

    // Division (integer division)
    int quotient = a / b;
    printf("Integer Division: %d / %d = %d\n", a, b, quotient);

    // Modulus (remainder of division)
    int remainder = a % b;
    printf("Modulus: %d %% %d = %d\n", a, b, remainder);

    // Floating point division
    float float_quotient = x / y;
    printf("Floating-point Division: %.2f / %.2f = %.2f\n", x, y, float_quotient);

    // 2. Relational Operators (>, <, >=, <=, ==, !=)
    // Greater than
    int is_greater = a > b;
    printf("Greater than: %d > %d = %d\n", a, b, is_greater);

    // Less than
    int is_less = a < b;
    printf("Less than: %d < %d = %d\n", a, b, is_less);

    // Greater than or equal to
    int is_greater_equal = a >= b;
    printf("Greater than or equal to: %d >= %d = %d\n", a, b, is_greater_equal);

    // Less than or equal to
    int is_less_equal = a <= b;
    printf("Less than or equal to: %d <= %d = %d\n", a, b, is_less_equal);

    // Equal to
    int is_equal = a == b;
    printf("Equal to: %d == %d = %d\n", a, b, is_equal);

    // Not equal to
    int is_not_equal = a != b;
    printf("Not equal to: %d != %d = %d\n", a, b, is_not_equal);

    // 3. Logical Operators (&&, ||, !)
    // Logical AND (true if both conditions are true)
    int and_result = (a > b) && (x > y);
    printf("Logical AND: (%d > %d) && (%.2f > %.2f) = %d\n", a, b, x, y, and_result);

    // Logical OR (true if at least one condition is true)
    int or_result = (a > b) || (x < y);
    printf("Logical OR: (%d > %d) || (%.2f < %.2f) = %d\n", a, b, x, y, or_result);

    // Logical NOT (reverses the condition)
    int not_result = !(a == b);
    printf("Logical NOT: !(%d == %d) = %d\n", a, b, not_result);

    // 4. Bitwise Operators (&, |, ^, ~, <<, >>)
    // Bitwise AND
    int and_bitwise = a & b;
    printf("Bitwise AND: %d & %d = %d\n", a, b, and_bitwise);

    // Bitwise OR
    int or_bitwise = a | b;
    printf("Bitwise OR: %d | %d = %d\n", a, b, or_bitwise);

    // Bitwise XOR
    int xor_bitwise = a ^ b;
    printf("Bitwise XOR: %d ^ %d = %d\n", a, b, xor_bitwise);

    // Bitwise NOT
    int not_bitwise = ~a;
    printf("Bitwise NOT: ~%d = %d\n", a, not_bitwise);

    // Left shift (shift bits to the left, equivalent to multiplying by 2)
    int left_shift = a << 1;
    printf("Left shift: %d << 1 = %d\n", a, left_shift);

    // Right shift (shift bits to the right, equivalent to dividing by 2)
    int right_shift = a >> 1;
    printf("Right shift: %d >> 1 = %d\n", a, right_shift);

    // 5. Assignment Operators (=, +=, -=, *=, /=, %=)
    // Assignment
    c = a + b;
    printf("Assignment: c = %d + %d = %d\n", a, b, c);

    // Add and assign
    c += b;
    printf("Add and Assign: c += %d => c = %d\n", b, c);

    // Subtract and assign
    c -= b;
    printf("Subtract and Assign: c -= %d => c = %d\n", b, c);

    // Multiply and assign
    c *= b;
    printf("Multiply and Assign: c *= %d => c = %d\n", b, c);

    // Divide and assign
    c /= b;
    printf("Divide and Assign: c /= %d => c = %d\n", b, c);

    // Modulus and assign
    c %= b;
    printf("Modulus and Assign: c %%= %d => c = %d\n", b, c);

    // 6. Increment and Decrement Operators (++, --)
    // Pre-increment
    int pre_increment = ++a;
    printf("Pre-increment: ++a = %d\n", pre_increment);

    // Post-increment
    int post_increment = b++;
    printf("Post-increment: b++ = %d, b = %d\n", post_increment, b);

    // Pre-decrement
    int pre_decrement = --a;
    printf("Pre-decrement: --a = %d\n", pre_decrement);

    // Post-decrement
    int post_decrement = b--;
    printf("Post-decrement: b-- = %d, b = %d\n", post_decrement, b);

    // 7. Ternary (Conditional) Operator (condition ? expr1 : expr2)
    int max = (a > b) ? a : b;
    printf("Ternary Operator: max = (%d > %d) ? %d : %d = %d\n", a, b, a, b, max);

    // 8. Sizeof Operator (returns size in bytes)
    printf("Sizeof a: %zu bytes\n", sizeof(a));
    printf("Sizeof x: %zu bytes\n", sizeof(x));
    printf("Sizeof ch: %zu bytes\n", sizeof(ch));

    return 0;
}
