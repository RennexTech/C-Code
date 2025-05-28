/**
 *
 * _Complex is like giving your program math superpowers — it can now handle imaginary numbers.
 *
 * Think of it like a vector in a game: there's an x (real) and y (imaginary) direction.
 *
 * Engineers and scientists use it in physics, signal processing, and electrical circuits.
 *
 * You don’t need to write your own complex number struct anymore — C99’s got your back.
 *
 */

#include <stdio.h>
#include <complex.h>

int main() {
    printf("--------------------------------------------\n");
    printf("34. _Complex\n");
    printf("--------------------------------------------\n");
    printf("'_Complex' lets you use complex numbers in C. Great for simulations, circuits, or math-heavy programs.\n");
    printf("--------------------------------------------\n");

    double complex voltage = 3.0 + 4.0 * I;
    printf("Voltage = %.2f + %.2fi\n", creal(voltage), cimag(voltage));

    double complex current = 1.0 - 2.0 * I;
    printf("Current = %.2f + %.2fi\n", creal(current), cimag(current));

    double complex power = voltage * current;
    printf("Power = %.2f + %.2fi\n", creal(power), cimag(power));

    return 0;
}


//=================================== ANOTHER EXAMPLE ============================

#include <stdio.h>   // For printf
#include <complex.h> // For _Complex (and I for imaginary unit)
#include <unistd.h>  // For sleep

/**
 * * _Complex is for when math gets wild! 
 * * This is for complex numbers, like when you're dealing with electricity, signals, or quantum physics. 
 * * It's a niche wizard, not your everyday calculator stuff.
 * * Don't stress if this looks like alien code; it's for very specific, advanced math problems.
 * */

int main() {
    printf("--------------------------------------------\n");
    printf("34. _Complex (C99)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("For when math gets wild! This is for complex numbers, like when you're dealing with electricity or quantum physics. It's a niche wizard, not your everyday calculator stuff.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    // Declaring complex numbers
    // 'I' is the imaginary unit (sqrt(-1)), defined in <complex.h>
    double complex z1 = 1.0 + 2.0 * I; // Represents 1 + 2i
    double complex z2 = 3.0 + 4.0 * I; // Represents 3 + 4i

    printf("Complex number Z1: %.1f + %.1fi\n", creal(z1), cimag(z1)); // creal gets real part, cimag gets imaginary part
    sleep(1);
    printf("Complex number Z2: %.1f + %.1fi\n", creal(z2), cimag(z2));
    sleep(1);

    // Adding complex numbers
    double complex sum_z = z1 + z2; // (1+3) + (2+4)i = 4 + 6i
    printf("Sum (Z1 + Z2): %.1f + %.1fi\n", creal(sum_z), cimag(sum_z));
    sleep(1);

    // Multiplying complex numbers
    double complex product_z = z1 * z2; // (1+2i)(3+4i) = 3 + 4i + 6i + 8i^2 = 3 + 10i - 8 = -5 + 10i
    printf("Product (Z1 * Z2): %.1f + %.1fi\n", creal(product_z), cimag(product_z));
    sleep(1);

    printf("Note: This is for advanced math/DSP. Don't stress if this is wild. 🤯\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
