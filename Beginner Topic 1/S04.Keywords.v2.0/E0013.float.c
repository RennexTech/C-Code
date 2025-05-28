/**
 * float is like a standard kitchen measuring cup or scale for numbers. 
 * 
 * You know how some recipes say '3.5 cups of flour' or '150.2 grams of sugar'? 
 * 
 * These are numbers with decimal points. float is perfect for storing these everyday decimal numbers. 
 * 
 * It's precise enough for most tasks, like calculating prices ($19.99), basic measurements, 
 * 
 * or temperatures (25.5°C). It gives you a good amount of detail after the decimal point, 
 * 
 * but it's not designed for super-duper, scientific-lab-level precision. 
 * 
 * It's your go-to for standard decimal needs!
 * 
 */

 #include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("13. float\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'float' is like a standard kitchen measuring cup or scale for numbers... It's your go-to for standard decimal needs!\n");
    printf("--------------------------------------------\n");
    sleep(1);

    float item_price = 19.99f;     // The 'f' suffix tells C it's a float literal
    float temperature_celsius = 25.5f;
    float pi_approx = 3.14f;       // Less precision than 'double'

    printf("Item price: $%.2f\n", item_price);
    printf("Room temperature: %.1f degrees Celsius\n", temperature_celsius);
    printf("Approximate PI: %.2f\n", pi_approx);
    printf("Size of a float: %zu bytes\n", sizeof(float)); // Usually 4 bytes
    sleep(5);
    return 0;
}