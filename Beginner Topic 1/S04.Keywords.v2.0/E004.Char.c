/**
 * The char keyword is used to declare variables that hold a single character — it only holds one character, 
 * 
 * like 'A' or '🥱'. You use it when you don’t need a whole essay (aka strings), 
 * 
 * just a tiny piece of text or emoji😶. It's cute, compact, and exactly 1 byte — small but mighty.
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("4. char\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'char' keyword used to declare variables that hold a single character — it only holds one character, like 'A' or '🥱'. You use it when you don’t need a whole essay (aka strings), just a tiny piece of text or emoji😶. It's cute, compact, and exactly 1 byte — small but mighty.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    char initial = 'J'; // Holding a single letter
    char emoji = '😎';   // Holding a single emoji (might need UTF-8 support for console)
    char grade = 'A';   // Holding a single grade

    printf("My initial is: %c\n", initial);
    printf("Feeling: %c\n", emoji);
    printf("My grade in C: %c\n", grade);
    printf("Size of a char: %zu bytes (small but mighty!)\n", sizeof(char));
    sleep(5);
    return 0;
}