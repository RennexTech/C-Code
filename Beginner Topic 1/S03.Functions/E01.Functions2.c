#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library (not strictly needed here)

//You can read this for yourself
// The main is a function in C. 
// A FUNCTION means a block of code that executes when its called.

// Before you can drop a banger tiktok...
// You download all the right TikTok filters... just like we imported the standard libraries.

// After that we can define some function prototypes right before main.
// Main is where your program starts when you're running your program on a computer, 
// ... it goes straight to main and executes that as the first function.

// Simply the entry point to your program.
// Int: Here we mean main is going to spit out an integer when its done executing.

// () are empty right now but you can put some parameters/arguments - these two words are different, we'll explain.
// Parameter is just a variable you put over there.
// Argument is an actual value.


// We're telling the compiler: 
// "Yo, I’m gonna use a function called greetings() that takes in a string, trust me." 
// So this is not the function itself, but its prototype with a PARAMETER.
void greetings(char name[]);


// We said main function is like a play button. Once you build your program to an .exe or any other format
// ... main is the first function to be called, that's why we put greetings inside it, so that when main is called to execute
// ... our we print hello, then it calls the greetings function which tells the user welcome my guy😘
int main()
{

    // Yell into the void. Classic.
    printf("Hello world!\n");
    

    // Call the greetings function with an ARGUMENT(actual data)
    greetings("TikTok User");
    
    // If we don't say int, don't write return 0 coz my guy/girl, your function is not returning anything, just like greetings.\
    // What your teachers never told you is, you can use return; on a void function if you want it to just exit early.
    // But for this main function we're return 0; meaning successfully executed!
    // We can use return 1, -1 etc to show our program errors, eg failed to finish execution!😣Time to debug!
    return 0; 
}

// Function definition with a PARAMETER(just a variable/storage box)
// This function takes a parameter `name` (a char array / string).
void greetings(char name[])
{
    printf("Welcome, %s!\n", name);
    printf("Hope you're having a great day!\n");
}