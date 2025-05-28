/**
 * 
 * The double keyword is your go-to when you need to store decimal numbers with extra precision — 
 * 
 * like money, scientific data, or anything where you can’t afford to lose detail. 
 * 
 * It’s basically a high-def floating-point number.
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("9. double\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'double' keyword is your go-to when you need to store decimal numbers with extra precision — like money, scientific data, or anything where you can’t afford to lose detail. It’s basically a high-def floating-point number.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    double pi_high_precision = 3.141592653589793; // Very precise PI
    double account_balance = 1234567.890123;      // Precise financial data
    double tiny_measurement = 0.000000000012345;  // Very small number

    printf("High-precision PI: %.15f\n", pi_high_precision);
    printf("Account Balance: $%.6f\n", account_balance);
    printf("Tiny Measurement: %.18f\n", tiny_measurement);
    printf("Size of a double: %zu bytes (twice the precision of float!)\n", sizeof(double));
    sleep(5);
    return 0;
}