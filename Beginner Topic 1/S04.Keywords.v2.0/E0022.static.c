/**
 * 
 * static is like the ninja keyword of C, doing different sneaky-cool things depending on where you drop it. 
 * 
 * It's all about controlling how long things stick around (persistence) and who gets to see them (visibility).
 *
 * Making stuff persistent (for variables inside a function): Imagine your function is a hotel room. 
 * 
 * Normally, when you check out (function ends), everything in the room gets cleaned out and reset. 
 * 
 * But if you declare a variable as static inside that function, it's like having a secret personal safe in that room. 
 * 
 * Whatever you put in that static safe stays there, even if you check out and come back later. 
 * 
 * It remembers its value across different visits to the same room (function)!
 * 
 * (Advanced) Making stuff private (for variables or functions outside any function): 
 * 
 * This usage of static makes global variables or functions visible only within the file they are defined in, 
 * 
 * like a "secret, members-only lounge" inside a specific club (your .c file). 
 * 
 * Other files cannot directly see or access them. 
 * 
 * This needs multiple .c files to demonstrate, which is beyond a simple beginner's single-file example.
 * 
 */

#include <stdio.h> // Gotta have this for printf, duh!⚒🛠🔨
#include <unistd.h> // For sleep

// This function simulates visiting a hotel room with a secret safe
void visit_hotel_room() {
    // This is like a regular item on the counter. It resets every time you enter!
    int regular_item_count = 0;

    // This is our STATIC variable – the secret safe!
    // It's initialized to 0 ONLY THE FIRST TIME this function is EVER called.
    // After that, it remembers its value across calls.
    static int secret_safe_visit_count = 0;

    regular_item_count++;    // This will always be 1
    secret_safe_visit_count++; // This will keep increasing!

    printf("  [Inside Room] Regular item count: %d (Resets each visit)\n", regular_item_count);
    printf("  [Inside Room] Secret safe visit count: %d (Remembers across visits!)\n", secret_safe_visit_count);
}

int main() {
    printf("--------------------------------------------\n");
    printf("24. static (Function-internal persistence)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("For variables inside a function, 'static' is like having a **secret personal safe** in that room. Whatever you put in that `static` safe stays there, even if you check out and come back later. It remembers its value across different visits to the same room(function)!\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("--- Let's Visit the Hotel Room! ---\n");

    printf("First visit:\n");
    visit_hotel_room(); // Call the function

    printf("\nSecond visit:\n");
    visit_hotel_room(); // Call it again!

    printf("\nThird visit:\n");
    visit_hotel_room(); // And again!

    printf("--- Hotel Stay Concluded. ---\n");
    sleep(5);
    return 0; // Main says 'Peace out!' to the OS
}