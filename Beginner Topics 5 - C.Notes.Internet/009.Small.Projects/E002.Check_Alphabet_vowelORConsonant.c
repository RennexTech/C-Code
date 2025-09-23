#include <stdio.h>
#include <ctype.h> // Include this for isalpha() and tolower()

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch); // Add a space before %c to consume any leading whitespace

    if (isalpha(ch)) {
        printf("'%c' is an alphabet.\n", ch);

        // Convert the character to lowercase to simplify the vowel check.
        switch (tolower(ch)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                printf("It is a vowel.\n");
                break;
            default:
                printf("It is a consonant.\n");
                break;
        }
    } else {
        printf("'%c' is not an alphabet.\n", ch);
    }

    return 0;
}