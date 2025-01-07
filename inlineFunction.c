#include <stdio.h>

inline int square(int x) {
    return x * x;
}

int main() {
    int num = 5;
    printf("Square of %d is %d\n", num, square(num));
    return 0;
}


// Explanation:

//     The inline keyword tells the compiler to insert the function's code directly at the point of call, rather than performing a regular function call.