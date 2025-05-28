/**
 * 
 * signed is like telling your number, 'You can be positive, negative, or zero – you've got options!' 
 * 
 * It's the default for int anyway, so usually you don't even need to type it. 
 * 
 * Think of it as a number line that goes both ways: into the positives and into the negatives. 
 * 
 * If you're tracking temperature, for example, you'd want it to be signed because winter's coming 
 * 
 * and it might hit -70 Russian degrees!
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("22. signed\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'signed' is like telling your number, 'You can be positive, negative, or zero – you've got options!'... Think of it as a number line that goes both ways.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    signed int current_temp = -70;  // Can hold negative values
    signed char offset = -5;        // Can hold negative characters (as small integers)
    int default_signed = 100;       // 'int' is signed by default

    printf("Current temperature: %d degrees (brrr!)\n", current_temp);
    printf("Offset value: %d\n", offset);
    printf("Default signed int: %d\n", default_signed);

    printf("\nRange of signed int (typical): %d to %d\n", -2147483648, 2147483647);
    printf("Size of signed int: %zu bytes\n", sizeof(signed int));
    sleep(5);
    return 0;
}


