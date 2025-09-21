/*
*****
****
***
**
*
*/
#include <stdio.h>
int main() {
    int i, j, n;
    printf("Enter a value of n: \n");
    scanf("%d", &n);
    
    // The outer loop counts our rows from top to bottom.
    for (i = 1; i <= n; i++) {
        // This loop prints the stars. The `n + 1 - i` calculation is the secret sauce.
        // It starts with `n` stars and decreases by one with each row, creating the inverted shape.
        for (j = 1; j <= n + 1 - i; j++)
            printf("*");
        
        // After each row is complete, we move to the next line.
        printf("\n");
    }
    return 0;
}