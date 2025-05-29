#include <stdio.h>  // For printf.
#include <unistd.h> // For sleep() on Unix-like systems. If on Windows, use <windows.h> and Sleep().


/**
 * @brief Demonstrates undefined behavior with post-increment/decrement.
 *
 * @analog This is like trying to change your outfit twice at the exact same millisecond
 * while looking in the mirror. The mirror (compiler) gets confused, and the final outfit
 * (variable value) could be anything! It's wild, unpredictable, and you should
 * NEVER rely on it. It's basically a bug waiting to happen.
 */


void demonstrate_undefined_behavior_with_increment() {
    printf("\n--- Undefined Behavior Example (DO NOT RELY ON THIS) ---\n");
    printf("This is where C gets spicy and unpredictable. 🌶️\n");
    int a = 10;
    printf("Initial 'a': %d\n", a);
    sleep(1); // Adding a little pause for dramatic effect.

    // 'a' is modified twice here within one line, without a "sequence point."
    // The C standard says this is UNDEFINED BEHAVIOR.
    // It means the compiler can do whatever it wants, and the result might change
    // every time you run it, or on different computers.
    // Real-world analog: It's like trying to double-tap a post and comment at the
    // EXACT same nanosecond. The app might glitch, or one action might override the other.
    // The outcome is not guaranteed!
    a = a++ * a--; // 🤯 This is the spicy line!
    printf("Result of a = a++ * a--; (Undefined Behavior): %d\n", a);
    printf("Warning: The actual value of 'a' might be different on other compilers or runs. Don't do this IRL! 🙅‍♂️\n");
    sleep(2); // Another pause to let that sink in.
}

int main() {
    printf("Yo, fam! Get ready to see some C language chaos. This ain't for the faint of heart. 😵‍💫\n");
    demonstrate_undefined_behavior_with_increment();
    printf("\nRemember, undefined behavior is a big NO-GO in clean code. Stay safe out there! ✨\n");
    return 0;
}
