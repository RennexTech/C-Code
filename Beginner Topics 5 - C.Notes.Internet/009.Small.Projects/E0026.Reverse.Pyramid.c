/*
*********
 *******
  *****
   ***
    *
*/
#include <stdio.h>
int main() {
    int i, j, n;
    printf("Enter a value of n: \n");
    scanf("%d", &n);
    
    // The outer loop iterates through each row of the inverted pyramid.
    for (i = 1; i <= n; i++) {
        // We start by printing spaces. The number of spaces increases with each row,
        // pushing the stars inward and creating the inverted shape.
        for (j = 1; j <= i; j++)
            printf(" ");
            
        // The number of stars decreases with each row. The `2 * (n - i) + 1`
        // calculation does the heavy lifting, ensuring the count is always odd.
        for (j = 1; j <= 2 * (n - i) + 1; j++)
            printf("*");
            
        // We move to the next row.
        printf("\n");
    }
    return 0;
}