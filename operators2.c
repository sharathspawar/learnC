#include <stdio.h>

int main() {
    // Declaration of variables for demonstration
    int a = 10, b = 5, result;
    float x = 7.5, y = 2.5, f_result;
    char ch = 'A';

    // Arithmetic Operators (+, -, *, /, %)
    printf("Arithmetic Operators:\n");
    
    result = a + b; // Addition
    printf("%d + %d = %d\n", a, b, result);
    
    result = a - b; // Subtraction
    printf("%d - %d = %d\n", a, b, result);
    
    result = a * b; // Multiplication
    printf("%d * %d = %d\n", a, b, result);
    
    result = a / b; // Division
    printf("%d / %d = %d\n", a, b, result);
    
    result = a % b; // Modulus (remainder of division)
    printf("%d %% %d = %d\n", a, b, result);
    
    // Using float for division
    f_result = x / y;
    printf("%.2f / %.2f = %.2f\n", x, y, f_result);

    // Relational Operators (==, !=, >, <, >=, <=)
    printf("\nRelational Operators:\n");
    
    printf("%d == %d: %d\n", a, b, a == b); // Equal to
    printf("%d != %d: %d\n", a, b, a != b); // Not equal to
    printf("%d > %d: %d\n", a, b, a > b); // Greater than
    printf("%d < %d: %d\n", a, b, a < b); // Less than
    printf("%d >= %d: %d\n", a, b, a >= b); // Greater than or equal to
    printf("%d <= %d: %d\n", a, b, a <= b); // Less than or equal to

    // Logical Operators (&&, ||, !)
    printf("\nLogical Operators:\n");
    
    // AND (&&)
    printf("%d && %d: %d\n", a > b, b > 2, (a > b) && (b > 2));
    
    // OR (||)
    printf("%d || %d: %d\n", a < b, b > 2, (a < b) || (b > 2));
    
    // NOT (!)
    printf("!(%d < %d): %d\n", a, b, !(a < b));

    // Bitwise Operators (&, |, ^, ~, <<, >>)
    printf("\nBitwise Operators:\n");

    printf("%d & %d: %d\n", a, b, a & b); // AND
    printf("%d | %d: %d\n", a, b, a | b); // OR
    printf("%d ^ %d: %d\n", a, b, a ^ b); // XOR
    printf("~%d: %d\n", a, ~a); // NOT (bitwise)
    printf("%d << 1: %d\n", a, a << 1); // Left shift by 1 (multiply by 2)
    printf("%d >> 1: %d\n", a, a >> 1); // Right shift by 1 (divide by 2)

    // Assignment Operators (=, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=)
    printf("\nAssignment Operators:\n");

    result = a; // Simple assignment
    printf("a = %d\n", result);
    
    result += b; // Add and assign
    printf("a += b -> %d\n", result);
    
    result -= b; // Subtract and assign
    printf("a -= b -> %d\n", result);
    
    result *= b; // Multiply and assign
    printf("a *= b -> %d\n", result);
    
    result /= b; // Divide and assign
    printf("a /= b -> %d\n", result);
    
    result %= b; // Modulo and assign
    printf("a %%= b -> %d\n", result);

    // Unary Operators (++ (increment), -- (decrement), +, -)
    printf("\nUnary Operators:\n");

    result = ++a; // Pre-increment
    printf("++a = %d\n", result);

    result = --b; // Pre-decrement
    printf("--b = %d\n", result);

    result = +a; // Unary plus
    printf("+a = %d\n", result);

    result = -a; // Unary minus
    printf("-a = %d\n", result);

    // Ternary Operator (condition ? true_case : false_case)
    printf("\nTernary Operator:\n");

    result = (a > b) ? a : b;
    printf("The greater of a and b is: %d\n", result);

    // Comma Operator (,)
    printf("\nComma Operator:\n");

    result = (a = a + 5, a * 2); // Assign a + 5, then multiply a by 2
    printf("Result of a = a + 5, a * 2: %d\n", result);

    // Sizeof Operator
    printf("\nSizeof Operator:\n");

    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of char: %zu bytes\n", sizeof(char));

    // Typecast Operator
    printf("\nTypecast Operator:\n");

    f_result = (float)a / b; // Typecast int to float for division
    printf("a / b as float: %.2f\n", f_result);

    // Conditional Operator (if-else) Example (not a true operator but commonly used)
    printf("\nCondition with if-else:\n");

    if (a > b)
        printf("a is greater than b\n");
    else
        printf("b is greater than or equal to a\n");

    return 0;
}
