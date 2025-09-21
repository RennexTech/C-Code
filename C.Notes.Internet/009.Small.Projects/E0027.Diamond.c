#include <stdio.h>
int main() {
    int i, j, n;
    printf("Enter n: \n");
    scanf("%d", &n);

    // This is the top half of the diamond, built just like our regular pyramid.
    for (i = 1; i <= n; i++) {
        // Prints the leading spaces.
        for (j = 1; j <= n - i; j++)
            printf(" ");
            
        // Prints the stars for the top half.
        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");
            
        printf("\n");
    }
    
    // This is a neat trick. We decrement `n` so the bottom half of the diamond
    // doesn't have an extra row and perfectly mirrors the top half.
    n--;
    
    // This is the bottom half of the diamond, built like our inverted pyramid.
    for (i = 1; i <= n; i++) {
        // Prints the leading spaces.
        for (j = 1; j <= i; j++)
            printf(" ");
            
        // Prints the stars for the bottom half.
        for (j = 1; j <= 2 * (n - i) + 1; j++)
            printf("*");
            
        printf("\n");
    }
    return 0;
}