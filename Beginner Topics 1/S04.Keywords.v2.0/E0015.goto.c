/**
 * 
 * goto is like rage-quitting structured code. 
 * 
 * It jumps to a label somewhere else, like teleporting mid-function — total chaos. 
 * 
 * Real life: Like walking out of a concert and reappearing in your ex’s house😂. Just WHY?? 😭 
 * 
 * Please don't do this unless you're desperate...
 * 
 * We don’t use it unless we’re writing spaghetti... or debugging hell code from 1980s.
 * 
 * It's a manual jump to another place in your code.
 * 
 * You slap a label and then goto label_name; makes a warp speed jump to that place you tell it. 
 * 
 * It doesn't give a damn!!😤😤 All the loops, conditional flows get skipped, that's why they are scared of seeing goto within the code.
 * 
 * Goto scares all these other statements, and keeps them jobless. 
 * 
 * When you put goto in your code, nothing's structured anymore, rather, goto is the one that will dictate structure, by skipping skipping wherever and whenever.
 * 
 * You can use it to do Error handling in deeply nested code (goto cleanup;)
 * 
 * Breaking out of multi-layer loops (but there's break and continue too)
 * 
 * Don't use it. Not unless you're debugging code from 1987 or writing embedded firmware with 3KB of RAM and a prayer 😭
 * 
 * 
 */

 #include <stdio.h>
#include <unistd.h> // for sleep()

// A void function showing goto in action
void goto_demo(int num) {
    printf("Starting goto_demo with num = %d\n", num);

    if (num < 0) {
        goto handle_negative; // Jump to the 'handle_negative' label
    }

    printf("Number is non-negative, keep calm and carry on.\n");
    printf("Doing some important work...\n");
    sleep(1);
    printf("Finished important work!\n");
    goto end; // Jump to the 'end' label, skipping the negative handler

handle_negative: // This is a label
    printf("Whoa! Negative number alert 🚨, aborting normal flow.\n");
    printf("Skipping to safe zone...\n");

end: // This is another label
    printf("End of goto_demo, peace out.\n");
}

int main() {
    printf("--------------------------------------------\n");
    printf("15. goto\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("goto is like rage-quitting structured code. It jumps to a label somewhere else, like teleporting mid-function — total chaos. Real life: Like walking out of a convo and reappearing in your ex’s DMs. Just WHY?? 😭 We don’t use it unless we’re writing spaghetti... or debugging hell.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Calling goto_demo with 5:\n");
    goto_demo(5);
    sleep(2); // Short pause

    printf("\nCalling goto_demo with -3:\n");
    goto_demo(-3);

    sleep(5);
    return 0;
}


//=================================================

// Another example: 

#include <stdio.h>

void testGoto() {
    int num = 1;

    if (num == 1) {
        goto skip_stuff; // Teleport time 🌀
    }

    printf("You won't see this line.\n");

skip_stuff:
    printf("Jumped here using goto! Proceed with caution.\n");
}

int main() {
    testGoto();
    return 0;
}


/**
 * 
 * Code becomes hard to read.
 * 
 * Future you will stare at the screen and say:
 * 
 * “Which gremlin wrote this?”
 * 
 * Debugging becomes a nightmare with a machete.

 */

 