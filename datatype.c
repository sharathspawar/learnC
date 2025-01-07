#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Integer types
    int integer = 42;
    short shortInt = 32000;
    long longInt = 1000000;
    long long longLongInt = 123456789012345;

    // Unsigned integer types
    unsigned int unsignedInt = 100;
    unsigned short unsignedShortInt = 65000;
    unsigned long unsignedLongInt = 2000000;
    unsigned long long unsignedLongLongInt = 987654321098765;

    // Floating-point types
    float floatNum = 3.14f;
    double doubleNum = 2.718281828459;
    long double longDoubleNum = 1.618033988749895L;

    // Character types
    char charValue = 'A';
    unsigned char unsignedCharValue = 255;

    // Boolean type
    bool booleanValue = true;

    // Void type pointer
    void *voidPointer = &integer;

    // Print all data types
    printf("Integer: %d\n", integer);
    printf("Short Integer: %d\n", shortInt);
    printf("Long Integer: %ld\n", longInt);
    printf("Long Long Integer: %lld\n", longLongInt);

    printf("Unsigned Integer: %u\n", unsignedInt);
    printf("Unsigned Short Integer: %u\n", unsignedShortInt);
    printf("Unsigned Long Integer: %lu\n", unsignedLongInt);
    printf("Unsigned Long Long Integer: %llu\n", unsignedLongLongInt);

    printf("Float: %f\n", floatNum);
    printf("Double: %lf\n", doubleNum);
    printf("Long Double: %Lf\n", longDoubleNum);

    printf("Character: %c\n", charValue);
    printf("Unsigned Character: %u\n", unsignedCharValue);

    printf("Boolean Value: %d\n", booleanValue);

    printf("Void Pointer Value: %p\n", voidPointer);

    // Demonstrate type sizes
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Size of char: %zu byte\n", sizeof(char));
    printf("Size of unsigned char: %zu byte\n", sizeof(unsigned char));
    printf("Size of bool: %zu byte\n", sizeof(bool));
    printf("Size of void pointer: %zu bytes\n", sizeof(void*));

    return 0;
}
