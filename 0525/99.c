#include <stdio.h>

#define TABLE_SIZE 9

void print_multiplication_table(int size) {
    if (size <= 0) {
        fprintf(stderr, "Error: Table size must be a positive integer.\n");
        return;
    }

    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size; col++) {
            printf("%3d", row * col);
            if (col < size) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main(void) {
    print_multiplication_table(TABLE_SIZE);
    return 0;
}
