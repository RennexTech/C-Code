/*
*
**
***
****
*****
*/
#include <stdio.h>
int main() {
    int i, j, n;
    printf("Enter a number: \n");
    scanf("%d", &n);
    
    // The outer loop handles the rows, moving us down from top to bottom.
    // Think of it as a person walking down a staircase, one step at a time.
    for (i = 1; i <= n; i++) {
        // The inner loop handles the columns, printing the stars for each row.
        // This is the person walking across the stairs, placing a star at each step.
        // Since `j` goes up to `i`, each row gets one more star than the last.
        for (j = 1; j <= i; j++)
            printf("*");
        
        // After each row, we move to the next line.
        printf("\n");
    }
    return 0;
}