#include <stdio.h>
int main() {
    int num, i = 1;
    printf("Enter any Number : \n");
    scanf("%d", &num);
    
    // A multiplication table is basically a list of a number's multiples.
    // This `for` loop is like an assembly line, where we take the input number,
    // multiply it by each number from 1 to 10, and then print the result.
    for (i = 1; i <= 10; i++) {
        printf("%d X %d = %d", num, i, num * i);
        printf("\n");
    }
    return 0;
}