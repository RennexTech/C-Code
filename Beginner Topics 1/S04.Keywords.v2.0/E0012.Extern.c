/**
 * 
 * extern is like working in a big workshop with different teams, each with their own workbench (independent C file).
 * 
 * Each team has its own tools, but there's one super expensive, specialized laser cutter (a global variable or a complex function) that everyone needs to use.
 * 
 * You don't buy a laser cutter for every single workbench, right? Instead, extern is like putting a sign on your workbench that says: 
 * 
 * 'For the Laser Cutter, see the main fabrication room.' 
 * 
 * It tells your compiler, 'Hey, this laser_cutter thing? It exists! 
 * 
 * It's defined and set up somewhere else in the workshop. 
 * 
 * Just know it's there, and we'll link up to it later.' 
 * 
 * This lets all teams (files) access that one single, powerful tool without having to copy or rebuild it themselves. 
 * 
 * Super efficient for sharing resources!
 * 
 * Code Example (Conceptual - requires multiple files to fully demonstrate):
 * 
 * For extern to truly shine, you need at least two .c files. 
 * 
 * One file defines the global variable or function, and another file declares it as extern to use it. 
 * 
 * Below is a conceptual example, as a single file cannot fully demonstrate inter-file linkage.
 * 
 */

 // ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

 // File1: globals.c - The main fabrication room where the laser cutter is DEFINED
int shared_laser_cutter_usage = 0; // This variable is DEFINED here

void use_laser_cutter() { // This function is DEFINED here
    shared_laser_cutter_usage++;
    // ... complex laser cutting operations ...
}


// ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

// File2: main.c -  Your workbench with a "See shared doc for this" note

#include <stdio.h>
#include <unistd.h> // For sleep



// Analogy: Telling your compiler, "Hey, 'shared_laser_cutter_usage' exists somewhere else!"
extern int shared_laser_cutter_usage; // This variable is DECLARED here as extern

// Analogy: Telling your compiler, "Hey, 'use_laser_cutter()' exists somewhere else!"
extern void use_laser_cutter(); // This function is DECLARED here as extern

int main() {
    printf("--------------------------------------------\n");
    printf("12. extern (Conceptual - requires multiple files)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("It tells your compiler, 'Hey, this thing? It exists! It's defined and set up *somewhere else* in the workshop. Just know it's there, and we'll link up to it later.' This lets all teams (files) access that one single, powerful tool without having to copy or rebuild it themselves. Super efficient for sharing resources!\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Before using laser cutter, usage count: %d\n", shared_laser_cutter_usage);
    printf("Using the shared laser cutter for Project Alpha...\n");
    use_laser_cutter(); // Calling the function defined in globals.c
    printf("After Project Alpha, usage count: %d\n", shared_laser_cutter_usage);

    printf("\nUsing the shared laser cutter for Project Beta...\n");
    use_laser_cutter();
    printf("After Project Beta, usage count: %d\n", shared_laser_cutter_usage);

    printf("To compile: `gcc globals.c main.c -o my_project`\n");
    printf("Then run: `./my_project`\n");
    sleep(5);
    return 0;
}

// ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/**
 * 
 * To run this: You'd save the first block as globals.c and the second as main.c in the same folder. 
 * 
 * Then, open your terminal and compile them together: gcc globals.c main.c -o my_project. 
 * 
 * After that, you can run your program: ./my_project. 
 * 
 * This demonstrates how main.c can use things defined in globals.c.
 * 
 */

 