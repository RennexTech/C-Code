#include <stdio.h> // Gives us access to standard input/output functions like printf and scanf.

/*
 * clear_input_buffer() — Clean-up crew for messy input.
 *
 * When users type stuff, sometimes they add extra characters (like hitting space or typing letters by mistake).
 * These leftovers stay in the input buffer and mess up the next scanf().
 * 
 * This function removes everything left behind on the current line after a scanf() call,
 * so your next input reads fresh, no leftovers. Think of it like sweeping your desk
 * before starting a new homework assignment. Clean vibes only.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Keep eating characters until newline or end-of-file.
}


/**
 * get_integer_input() — A pro-level way to get clean integer input from the user.
 *
 * @param prompt - A message to display to the user, like "Enter your age: ".
 * @return - A valid integer input from the user.
 *
 * This function keeps asking for input until the user enters a valid integer.
 * It also makes sure the input buffer is cleaned after each attempt.
 * 
 * 🔍 About 'const char* prompt':
 * 
 * In C, a string is just a pointer to characters in memory — that's what 'char*' means.
 * 
 * But we don't want this function to accidentally modify the string (the prompt text), so we say 'const'.
 * 
 * So: 
 * - `char*` means “pointer to characters.”
 * - `const char*` means “pointer to read-only characters.”
 * 
 * In other words, this function accepts a message to display — but promises *not* to change it.
 * 
 * Why this matters:
 * - If the prompt string is a literal like "Enter age:", it’s stored in read-only memory.
 * - Trying to modify it will cause a crash or weird behavior.
 *
 * 🧠 TLDR:
 * `const char* prompt` = "Here’s a message to show the user. Use it, don’t touch it."
 */
int get_integer_input(const char* prompt) {
    int value;

    printf("%s", prompt); // Display the prompt message to the user.

    // Keep asking for input until a valid integer is entered.
    while (scanf("%d", &value) != 1) {
        printf("⚠️  Invalid input! Please enter a valid whole number:\n");

        clear_input_buffer(); // Remove leftover junk from the input buffer.
    }

    clear_input_buffer(); // Final cleanup after successful input.
    return value; // Return the valid number to the caller.
}


/**
 * main() — Where the program begins. Demonstrates real-world use of safe integer input.
 */
int main() {
    printf("👋 Welcome to the Integer Input Demo! Let’s work with some clean, whole numbers.\n\n");

    // 🧪 Example 1: Counting people — can't have half a person!
    int squad_members = get_integer_input("👥 How many friends are coming over? (Enter a whole number): ");
    printf("✅ %d confirmed! The squad is pulling up. 🔥\n", squad_members);

    // 🧪 Example 2: Setting a timer — only full minutes allowed.
    int timer_minutes = get_integer_input("\n⏳ How many minutes should the timer run? (Whole numbers only): ");
    printf("✅ Timer is set for %d minutes. Time to focus up! 🧠\n", timer_minutes);

    printf("\n🎉 That’s a wrap! You just handled user input like a boss. Peace out.\n");

    return 0; // Exit status: success.
}
