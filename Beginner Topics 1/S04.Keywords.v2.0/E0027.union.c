/**
 * 
 * union is like a special, space-saving storage box that can hold different kinds of items, 
 * 
 * but only one at a time. Think of a single memory slot that can be used to store either a whole number (an int), 
 * 
 * or a decimal number (a float), or even a character (a char). 
 * 
 * But if you put the int in, the float that was there before is gone. 
 * 
 * It's used when you need to save memory and you know that at any given moment, 
 * 
 * you'll only need one of the possible data types stored in that spot.
 * 
 */

#include <stdio.h> // For printf
#include <string.h> // For strcpy (though not directly used in this simple example)
#include <unistd.h> // For sleep

// Defining our 'space-saving box' (the union)
// This union 'ValueHolder' can hold an integer, a float, OR a character.
// BUT, they all share the SAME memory location.
union ValueHolder {
    int i;    // Can hold an integer
    float f;  // Can hold a floating-point number
    char c;   // Can hold a single character
};

int main() {
    printf("--------------------------------------------\n");
    printf("28. union\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'union' is like a special, space-saving storage box that can hold different kinds of items, but only one at a time... It's used when you need to save memory and you know that at any given moment, you'll only need *one* of the possible data types stored in that spot.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    union ValueHolder my_data;

    printf("--- Demonstrating Union's Single-Memory Slot ---\n");
    printf("Size of union (determined by largest member): %zu bytes\n\n", sizeof(my_data));

    // --- Scenario 1: Storing an integer ---
    my_data.i = 123; // Put an integer value into the 'i' slot
    printf("1. After assigning my_data.i = %d\n", my_data.i);
    // What about the other slots? They are now holding the *reinterpretation* of those bytes
    printf("   my_data.f (reinterpreted): %f (garbage!)\n", my_data.f);
    printf("   my_data.c (reinterpreted): %c (garbage/unprintable!)\n\n", my_data.c);
    sleep(2);

    // --- Scenario 2: Now, storing a float. This OVERWRITES the integer! ---
    my_data.f = 98.76f; // Put a float value into the 'f' slot
    printf("2. After assigning my_data.f = %f\n", my_data.f);
    // Now, if we try to read 'i', it's garbage because 'f' overwrote its memory.
    printf("   my_data.i (reinterpreted): %d (garbage now!)\n", my_data.i);
    printf("   my_data.c (reinterpreted): %c (garbage now!)\n\n", my_data.c);
    sleep(2);

    // --- Scenario 3: Storing a character. This OVERWRITES the float! ---
    my_data.c = 'Z'; // Put a character value into the 'c' slot
    printf("3. After assigning my_data.c = %c\n", my_data.c);
    // Again, trying to read other members now will yield garbage.
    printf("   my_data.i (reinterpreted): %d (garbage!)\n", my_data.i);
    printf("   my_data.f (reinterpreted): %f (garbage!)\n\n", my_data.f);
    sleep(2);

    printf("--- Union Demonstration Complete ---\n");
    sleep(5);
    return 0;
}