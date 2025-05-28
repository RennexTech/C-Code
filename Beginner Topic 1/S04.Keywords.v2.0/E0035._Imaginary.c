/**
 *
 * _Imaginary is like a shortcut for numbers that are only imaginary — no real part.
 *
 * If _Complex is a full 2D plane, _Imaginary is just the Y-axis.
 *
 * This is super niche and rarely used — mostly lives in heavy math or physics simulations.
 *
 */

#include <stdio.h>
#include <complex.h>

int main() {
    printf("--------------------------------------------\n");
    printf("35. _Imaginary\n");
    printf("--------------------------------------------\n");
    printf("'_Imaginary' handles numbers that are purely imaginary. It’s a special case of complex numbers.\n");
    printf("--------------------------------------------\n");

    float imaginarySpeed = 5.0f * I;
    printf("Imaginary Speed = %.2fi\n", cimagf(imaginarySpeed));

    // Note: In most modern C compilers, _Imaginary is rarely used directly.
    // Most use complex.h with I for both real + imaginary math.
    return 0;
}


//=================================== ANOTHER EXAMPLE ============================

#include <stdio.h>   // For printf
#include <complex.h> // For _Imaginary (and I for imaginary unit)
#include <unistd.h>  // For sleep

/**
 * * _Imaginary is even wilder than _Complex! 
 * * This is for pure imaginary numbers (like 5i, no real part). 
 * * If you're not doing super advanced signal processing or physics, you probably won't touch this. 
 * * Super niche, like a secret level in a game only a few know about.
 * */

int main() {
    printf("--------------------------------------------\n");
    printf("35. _Imaginary (C99)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("Even wilder than _Complex! This is for pure imaginary numbers. If you're not doing super advanced signal processing or physics, you probably won't touch this. Super niche.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    // Declaring pure imaginary numbers
    double imaginary_num1 = 5.0 * I; // Represents 5i
    double imaginary_num2 = 2.0 * I; // Represents 2i

    printf("Imaginary number 1: %.1fi\n", cimag(imaginary_num1));
    sleep(1);
    printf("Imaginary number 2: %.1fi\n", cimag(imaginary_num2));
    sleep(1);

    // Adding pure imaginary numbers
    double imaginary_sum = imaginary_num1 + imaginary_num2; // 5i + 2i = 7i
    printf("Sum: %.1fi\n", cimag(imaginary_sum));
    sleep(1);

    // Multiplying pure imaginary numbers
    double imaginary_product = imaginary_num1 * imaginary_num2; // (5i)(2i) = 10i^2 = -10
    printf("Product: %.1f\n", creal(imaginary_product)); // Result is real!
    sleep(1);

    printf("Note: This is for EXTREMELY advanced math. Don't sweat it if it's confusing. 👽\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
