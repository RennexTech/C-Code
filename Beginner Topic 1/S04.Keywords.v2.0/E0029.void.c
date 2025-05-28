/**
 * 
 * void is like the 'nothing' or 'generic' keyword in C, used in a couple of key ways:
 * 
 * For functions like (void do_stuff()): It means this function just does something, but it doesn't give back any specific value or result when it's done. 
 * 
 * It's like telling your friend, 'Go close the door.' They do it, but they don't hand you anything back.
 * 
 * For pointers (void *ptr): It's like a 'mystery box' pointer. 
 * 
 * It can point to any type of data (an int, a float, a struct, whatever!), 
 * 
 * but you don't know what it's pointing to until you explicitly tell the compiler. 
 * 
 * Super flexible for generic memory handling!
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h> // For malloc
#include <unistd.h> // For sleep

// Function that returns nothing (void)
void print_message() {
    printf("  [print_message function] Just printing a message, not returning anything. 👋\n");
}

// Function that takes no arguments (void)
void ask_user_input(void) { // 'void' in parentheses means no arguments
    printf("  [ask_user_input function] I'm asking for input, but don't need any info from you.\n");
    // In a real scenario, you'd use scanf here
}

int main() {
    printf("--------------------------------------------\n");
    printf("30. void\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'void' is like the 'nothing' or 'generic' keyword in C... For functions it means it doesn't **give back** any specific value... For pointers, it's a 'mystery box' pointer.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Calling a function that returns void:\n");
    print_message();

    printf("\nCalling a function that takes void arguments:\n");
    ask_user_input();

    // --- void pointer (Mystery Box Pointer) ---
    printf("\n--- Demonstrating void pointer (Mystery Box) ---\n");
    int my_int = 10;
    float my_float = 20.5f;

    void *mystery_ptr; // A void pointer can point to anything!

    mystery_ptr = &my_int; // Now it points to an int
    printf("Mystery pointer now points to an int. Value: %d\n", *(int*)mystery_ptr); // Cast back to int*

    mystery_ptr = &my_float; // Now it points to a float
    printf("Mystery pointer now points to a float. Value: %.1f\n", *(float*)mystery_ptr); // Cast back to float*

    // Using malloc, which returns a void pointer:
    int *dynamic_int = (int*)malloc(sizeof(int)); // malloc returns void*, cast to int*
    if (dynamic_int != NULL) {
        *dynamic_int = 99;
        printf("Dynamically allocated int: %d\n", *dynamic_int);
        free(dynamic_int); // Don't forget to free memory!
    }

    sleep(5);
    return 0;
}