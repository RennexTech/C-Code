/*
     *
    ***
   *****
  *******
 *********
*/
#include <stdio.h>
int main() {
    int i, j, n;
    printf("Enter a value of n: \n");
    scanf("%d", &n);
    
    // This loop controls the rows. Each row is a new level of our pyramid.
    for (i = 1; i <= n; i++) {
        // First, we print the spaces. The number of spaces decreases with each row,
        // which pushes the stars to the center. It's like a receding shoreline.
        for (j = 1; j <= n - i; j++)
            printf(" ");
            
        // Now, we print the stars. The number of stars increases by two for each row.
        // `2 * i - 1` gives us 1, 3, 5, 7, etc., stars, which is perfect for a pyramid.
        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");
            
        // Time to move to the next row.
        printf("\n");
    }
    return 0;
}