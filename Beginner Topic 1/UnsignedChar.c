#include <stdio.h>
#include <string.h> // For strcpy, strlen

int main() {
    // --- String in char array ---
    char str[20];
    strcpy(str, "Hello World!");

    printf("The string stored is: %s\n", str);
    // sizeof returns allocated array size, not string length.
    printf("The size of the 'str' array is: %zu bytes\n", sizeof(str));
    // strlen returns string length EXCLUDING null terminator.
    printf("The actual length of the string 'Hello World!' is: %zu characters\n", strlen(str));

    // --- Single character ---
    char letter = 'A';
    printf("The letter is: %c\n", letter);
    printf("The size of 'letter' (char) is: %zu bytes\n", sizeof(letter));

    // --- Numbers using unsigned char ---
    unsigned char number_ascii = 65; // 65 is ASCII for 'A'
    printf("The ASCII value %d corresponds to character: %c\n", number_ascii, number_ascii);
    printf("The size of 'number_ascii' (unsigned char) is: %zu bytes\n", sizeof(number_ascii));

    unsigned char max_val = 255;
    printf("Max value for unsigned char: %u\n", max_val);

    // --- Key Concept: Null Termination ---
    // C strings end with '\0'. Functions like printf(%s) rely on this.
    char example_null_term[] = {'H', 'i', '\0', 'X'};
    printf("Example null termination: %s\n", example_null_term); // Prints "Hi"

    return 0;
}
