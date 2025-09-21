#include <stdio.h>
void exchangingValues(int *, int *);

int main() {
    int n1, n2;
    printf("Input 1st number : ");
    scanf("%d", &n1);
    printf("Input 2nd number : ");
    scanf("%d", &n2);

    printf("Before swapping: n1 = %d, n2 = %d ", n1, n2);

    // We're passing the 'address' of our two numbers,
    // like giving a delivery driver a GPS location instead of a picture of the package.
    // This lets the function change the actual values in our main program.
    exchangingValues(&n1, &n2);

    printf("\nAfter swapping: n1 = %d, n2 = %d \n\n", n1, n2);

    return 0;
}

// This function takes in two memory addresses, pointing to where our numbers live.
void exchangingValues(int *p, int *q) {
    int tmp;

    // We take the value from the first location and store it in a temporary spot.
    // Think of this as putting one of the numbers on a placeholder table.
    tmp = *p;

    // Now, we move the value from the second location into the first.
    // The first number's original value is safe in our temporary spot.
    *p = *q;

    // Finally, we bring the value from our temporary spot and place it in the second location.
    // The two numbers have now switched places!
    *q = tmp;
}