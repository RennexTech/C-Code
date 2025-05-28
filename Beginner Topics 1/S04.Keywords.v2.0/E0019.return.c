/**
 * 
 * return is your function's way of saying, 'Alright, my part in this show is done! 
 * 
 * Here's the final result (if any), and then peace out!' 
 * 
 * It immediately kicks you out of the current function and 
 * 
 * sends whatever value you specify back to whoever called it. 
 * 
 * Think of it like finishing a text message and hitting 'send' – 
 * 
 * once it's sent, you're done with that message, no rewrites or edits.
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

// Function that calculates sum and returns it
int add_numbers(int a, int b) {
    printf("  [Inside add_numbers] Adding %d and %d...\n", a, b);
    int sum = a + b;
    printf("  [Inside add_numbers] Calculation done. Returning sum.\n");
    return sum; // Returns the calculated sum and exits the function
    printf("  [Inside add_numbers] This line will NEVER print after return! 💀\n"); // Dead code
}

// Function that just does something and returns nothing (void)
void greet_user() {
    printf("  [Inside greet_user] Hey there, Coder! 👋\n");
    // No 'return' statement needed if function returns 'void', but you could have 'return;'
}

int main() {
    printf("--------------------------------------------\n");
    printf("20. return\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'return' is your function's way of saying, 'Alright, my part in this show is done! Here's the final result (if any), and then **peace out!**'\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int result_sum = add_numbers(10, 20); // Call function, get returned value
    printf("  [Back in main] Result from add_numbers: %d\n", result_sum);

    printf("\nCalling greet_user (no return value expected):\n");
    greet_user(); // Call function that returns void

    printf("\nMain function finishes its exams, comes home to mamaOS with its Report Card (return 0;):\n");
    printf("  return 0; means: 'My son succeeded this term😎 || Everything ran smoothly, all good here. ✅' (Success!)\n");
    printf("  return 1 (or any non-zero); means: 'Ooh my goodness, my son bite dust in the finals🤣segfault detected❌💋' (Failure/Error!)\n");
    sleep(5);
    return 0; // Main function returns 0 to the Operating System (success)
}