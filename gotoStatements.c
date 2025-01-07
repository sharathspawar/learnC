#include <stdio.h>

int main() {
    int i = 0;

    loop_start:
        printf("%d ", i);
        i++;
        if (i < 5) {
            goto loop_start; // Jump back to the label
        }

    return 0;
}
// Explanation:

//     goto: Jumps to a specific label in the code. It's often considered bad practice, but in certain cases (like breaking out of nested loops), it might be useful.