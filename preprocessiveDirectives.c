#include <stdio.h>

#define PI 3.14159

#ifdef PI
    #define AREA(radius) (PI * (radius) * (radius))
#else
    #define AREA(radius) (3.14 * (radius) * (radius))
#endif

int main() {
    float radius = 5.0;
    printf("Area of circle: %.2f\n", AREA(radius));
    return 0;
}


// Explanation:

//     #define: Used to define constants or macros.
//     #ifdef and #endif: Used for conditional compilation, allowing code to be compiled based on the presence of a macro.