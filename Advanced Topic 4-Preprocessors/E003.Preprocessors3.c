/* * ======================================================================================
 * MASTERING C PREPROCESSORS: A Guide for Everyone
 * From Beginner to Advanced
 * ======================================================================================
 * * WHAT IS A PREPROCESSOR?
 * Think of the Preprocessor as a "Text Editor" that runs automatically before
 * your code is actually compiled (turned into a program).
 * * It doesn't know C logic (like 'if' or 'while'). It only knows text.
 * It scans your file for lines starting with '#' and performs simple
 * "Find and Replace" operations.
 * * We will walk through 5 Levels of mastery in this single file.
 */

#include <stdio.h>

/* * ======================================================================================
 * LEVEL 1: THE BASICS (Nicknames for Numbers)
 * ======================================================================================
 * Problem: Using magic numbers like 3.14159 or 100 everywhere makes code hard to read.
 * Solution: Give them a nickname!
 */

// Whenever the preprocessor sees 'MAX_SCORE', it replaces it with '100'.
#define MAX_SCORE 100 

// You can use other definitions inside new ones.
#define BASE_SCORE 50
// WARNING: This is a "Find and Replace", not math!
// It copies "50 + 20" literally. It does NOT calculate 70 yet.
#define BONUS_SCORE BASE_SCORE + 20 


/* * ======================================================================================
 * LEVEL 2: MACROS (Mini-Functions)
 * ======================================================================================
 * You can make definitions that take inputs. These are called Macros.
 */

// A simple macro to square a number.
// NOTE: We use extra parenthesis ((x) * (x)) to prevent math errors.
// If we just wrote x * x, and input (1+2), it would become 1+2 * 1+2 = 5 (Wrong!)
// With parenthesis: ((1+2) * (1+2)) = 9 (Correct!)
#define SQUARE(x) ((x) * (x))

// A macro to find the absolute value (positive version of a number)
#define ABS(x) ((x) < 0 ? -(x) : (x))

// A macro to swap two variables of ANY type (int, float, etc.)
// We use { } to create a small local scope so 'temp' doesn't conflict with other variables.
#define SWAP(type, a, b) { type temp; temp = a; a = b; b = temp; }


/* * ======================================================================================
 * LEVEL 3: STRING MAGIC (Converting Text)
 * ======================================================================================
 * Sometimes you want to print the *name* of a variable, not just its value.
 * The '#' symbol tells the preprocessor: "Don't replace this, turn it into a string".
 */

// This prints: "The value of variable_name is: [value]"
#define PRINT_VAR(var) printf("The value of " #var " is: %d\n", var)


/* * ======================================================================================
 * LEVEL 4: ADVANCED (Writing Code that Writes Code)
 * ======================================================================================
 * This is powerful. We can use macros to generate entire functions!
 * This avoids writing the same function 4 times for int, float, double, etc.
 * * \ (backslash) allows the macro to span multiple lines.
 */

// This macro creates a function named 'func_name' that subtracts two numbers.
// It works for any data type (DTYPE) you specify.
#define CREATE_DIFF_FUNC(func_name, DTYPE) \
    DTYPE func_name(DTYPE a, DTYPE b) {    \
        return a - b;                      \
    }

// Now we "call" the macro to actually write the code for us right here.
// The preprocessor pastes a whole function named 'diff_int' here:
CREATE_DIFF_FUNC(diff_int, int)

// And here it pastes a function named 'diff_float':
CREATE_DIFF_FUNC(diff_float, float)


/* * ======================================================================================
 * MAIN EXECUTION (Putting it all together)
 * ======================================================================================
 */
int main() {
    printf("--- LEVEL 1: CONSTANTS ---\n");
    printf("Max Score: %d\n", MAX_SCORE);
    
    // THE TRAP: Remember BONUS_SCORE is "50 + 20"
    // If we do: BONUS_SCORE * 2
    // It becomes: 50 + 20 * 2  = 50 + 40 = 90.
    // It does NOT do: (50 + 20) * 2 = 140.
    // This is why parenthesis in #defines are crucial!
    int calc = BONUS_SCORE * 2; 
    printf("Calculation Trap Result: %d (Expected 140 if parens were used, got 90)\n", calc);


    printf("\n--- LEVEL 2: MACROS ---\n");
    int num = 3;
    printf("Square of 3: %d\n", SQUARE(num));
    printf("Square of (1+2): %d\n", SQUARE(1+2)); // Works because of ((x)*(x))

    int x = 10, y = 99;
    printf("Before Swap: x=%d, y=%d\n", x, y);
    SWAP(int, x, y); // Swaps them effectively
    printf("After Swap:  x=%d, y=%d\n", x, y);


    printf("\n--- LEVEL 3: STRING MAGIC ---\n");
    int my_age = 25;
    // The macro turns 'my_age' into the string "my_age" automatically
    PRINT_VAR(my_age);


    printf("\n--- LEVEL 4: GENERATED FUNCTIONS ---\n");
    // We are using the functions created by the CREATE_DIFF_FUNC macro above
    int i_res = diff_int(10, 3);
    float f_res = diff_float(5.5, 1.2);
    
    printf("Integer Difference: %d\n", i_res);
    printf("Float Difference:   %.1f\n", f_res);


    printf("\n--- LEVEL 5: BUILT-IN DEBUGGING ---\n");
    // __LINE__ and __FILE__ are special macros built into every C compiler.
    // They tell you exactly where you are in the code.
    printf("Currently running line %d in file %s\n", __LINE__, __FILE__);

    return 0;
}