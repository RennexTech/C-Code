#include <stdio.h>

// Function prototype: `converter` takes a float (inches) and returns a float (cms).
float converter(float inch);

int main() {
    float inch, cms;

    printf("Enter a length in inches: ");
    scanf("%f", &inch);

    cms = converter(inch);

    printf("%.2f inches is equal to %.2f cm.\n", inch, cms);

    return 0;
}

// Function to perform the conversion.
float converter(float inch) {
    float cms;
    const float CM_PER_INCH = 2.54; // Use a constant for clarity and precision.
    cms = inch * CM_PER_INCH;
    return cms;
}