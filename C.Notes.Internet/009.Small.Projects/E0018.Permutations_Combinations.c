#include <stdio.h>
long int factorial(int);
long int perm(int n, int r);
long int comb(int n, int r);

int main() {
    int n, r;
    printf("Enter n and r : \n");
    scanf("%d%d", &n, &r);
    
    // It's a good practice to validate user input. Permutations and combinations
    // are only valid when n is greater than or equal to r and both are non-negative.
    if (n < 0 || r < 0 || n < r) {
        printf("Invalid input. n must be >= r and both must be non-negative.\n");
        return 1;
    }

    printf("Total Permutations are : %ld\n", perm(n, r));
    printf("Total Combinations are : %ld\n", comb(n, r));
    return 0;
}

// Permutation is the number of ways to arrange 'r' items from a set of 'n' items.
// Think of it as a race: the order matters. It's calculated as n! / (n-r)!.
long int perm(int n, int r) {
    long p;
    p = factorial(n) / factorial(n - r);
    return p;
}

// Combination is the number of ways to choose 'r' items from a set of 'n' items.
// Here, the order doesn't matter, like picking a team. It's calculated as n! / (r! * (n-r)!).
long int comb(int n, int r) {
    long c;
    c = factorial(n) / (factorial(r) * factorial(n - r));
    return c;
}

// This is our helper function to calculate the factorial of a number.
long int factorial(int n) {
    int i;
    long int fact = 1;
    if (n == 0) {
        return 1;
    }
    // We multiply 'fact' by each number from 'n' down to 1.
    for (i = n; i > 1; i--) {
        fact = fact * i;
    }
    return fact;
}