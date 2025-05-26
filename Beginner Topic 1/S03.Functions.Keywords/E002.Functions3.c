/**
 * 
 * You usually write top level comments(executive summary), over here containing a brief description of what the .c file does...asm
 * The copyright information, author and date, license information and other stuff you'd like. 
 * 
 * The header files will follow after this top level comment.
 * 
 * Also other directives like #define - for defining constants or macros
 * ... and #ifndef or #endif directives for conditional compilation might also be here if you are using them.
 *  
 * You're allowed to put these directives before the header files, but for the functions and normal code, nah. 
 * Gerrarahia men!🤨😤Put that code right below the headers. 
 * 
 * The compiler says "How can you build walls before you lay the foundation? You can't🤔."
 * 
 * So, any code, comes after the top level comments, headers and directives. These 3 are the most important, 
 *  ... and they are interchangeable, but code only comes after. Directives generally appear above includes, 
 * comments are the ones that are fully flexible. 
 * 
 */

#include <stdio.h>
#include <stdlib.h> 

// Crash Course: Function Declaration Styles

/**
 *  Let's set this straight, you'll meet this stuff in the future, so let me clear things out.
 * 
 *  In C, you can define a function before the main() if you don't care about flexibility. 
 * 
 *  But you can also define that function's prototype(blueprint), and include it only after you define main.
 * 
 *  This ensures that your main is always on top, and more prototypes are added as you add more functions. 
 * 
 *  The second method is generally better coz it accounts for flexibility. 
 * 
 * You can write your prototype on this first.c file and go write the actual function on its own second.c file. 
 * 
 * A prototype is essentially telling the compiler "Bruh, you'll see this function somewhere, don't panic for now!🤗"
 * 
 * It allows you to write the main() function on top of other functions. 
 * 
*/

// I know you're confused, this code is the only one needed to open your eyes fully. Let's go!😎



//==========================================================================

// Style 001 _ Function Prototype A.K.A forward declaration

#include <stdio.h>
#include <stdlib.h> 

// Prototype = promise, tells the compiler:
// “I swear this function will show up later fully constructed, but here's its blueprint...
// what it needs, what it returns (int, void etc), 
// so don't stress when you see it defined over here before its fully cooked...”

void shout_out(char name[]);
void launch_mission(int level);
int calculate_juice(int energy, int caffeine);
void secret_code(int code);

int main()
{
    printf("Welcome to the Matrix, chief!\n\n");

    shout_out("Nicholas");
    launch_mission(7);
    
    int juice = calculate_juice(10, 5);
    printf("Your productivity juice level: %d 💪\n", juice);
    
    secret_code(42);

    return 0;
}


// 4 Functions defined after main, as promised, compiler is now happy, the prototype promise has been fulfilled🤗
void shout_out(char name[])
{
    printf("Shout out to %s for keeping it real! 🚀\n", name);
}



void launch_mission(int level)
{
    if (level > 5)
        printf("Mission level %d initiated: Enter beast mode! 🦾\n", level);
    else
        printf("Mission level %d: Take it easy, chief 😎\n", level);
}



int calculate_juice(int energy, int caffeine)
{
    // Mixing energy and caffeine for max output
    int juice = energy * caffeine;
    return juice;
}



void secret_code(int code)
{
    if (code == 42)
        printf("You've unlocked the ultimate answer. Hitchhiker's guide approved! 🌌\n");
    else
        printf("Access denied. Wrong code, try again! ❌\n");
}




//======================================================================================

#include <stdio.h>
#include <stdlib.h> 

// Style 2: No prototype needed because functions show up BEFORE main
void shout_out(char name[])
{
    printf("Shout out to %s for keeping it real! 🚀\n", name);
}



void launch_mission(int level)
{
    if (level > 5)
        printf("Mission level %d: Enter beast mode! 🦾\n", level);
    else
        printf("Mission level %d: Chill mode activated 😎\n", level);
}



int calculate_juice(int energy, int caffeine)
{
    int juice = energy * caffeine;
    return juice;
}



void secret_code(int code)
{
    if (code == 42)
        printf("Ultimate answer unlocked! Hitchhiker's Guide vibes 🌌\n");
    else
        printf("Wrong code, try again! ❌\n");
}



// Main is lonely and crying because it's pushed to the bottom by all these functions.
// It works, but it doesn't like being sat on by so many functions — 🪑🪑🪑🪑
// not very flexible or clean. At least with the last method (Style 1), you can write prototypes,
// and keep your main on top, or even go write your functions in another .c file for better organization and flexibility.

int main()
{
    printf("Welcome to the Matrix, chief!\n\n");

    shout_out("Nicholas");
    launch_mission(7);

    int juice = calculate_juice(10, 5);
    printf("Your productivity juice level: %d 💪\n", juice);

    secret_code(42);

    return 0;
}
