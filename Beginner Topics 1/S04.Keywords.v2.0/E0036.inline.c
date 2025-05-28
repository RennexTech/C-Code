/**
 *
 * inline is like telling the compiler: “Yo, just paste this function here instead of calling it.”
 *
 * It’s like putting a sticky note in your notebook instead of flipping pages to look for info.
 *
 * Makes small functions faster by avoiding function call overhead — but don’t abuse it.
 *
 */

#include <stdio.h>

inline int square(int x) {
    return x * x;
}

int main() {
    printf("--------------------------------------------\n");
    printf("36. inline\n");
    printf("--------------------------------------------\n");
    printf("'inline' suggests the compiler replaces the function call with the function’s body to save time.\n");
    printf("--------------------------------------------\n");

    int side = 5;
    int area = square(side);
    printf("Area of a square with side %d = %d\n", side, area);

    return 0;
}


//=================================== ANOTHER EXAMPLE ============================


#include <stdio.h>   // For printf
#include <unistd.h>  // For sleep

/**
 * * inline is a *suggestion* to the compiler: 
 * * 'Hey, if this function is tiny, just copy its code directly here instead of making a separate call.' 
 * * It's like telling your friend to just tell you the answer instead of calling a whole meeting. 
 * * Can make code faster, but the compiler decides if it actually does it. 
 * * It's like a compiler's optimization hint, not a command.
 * */

// This is our 'inline' function. We're *suggesting* to the compiler to inline it.
inline int add_fast(int a, int b) {
    return a + b;
}

int main() {
    printf("--------------------------------------------\n");
    printf("36. inline (C99)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("This is a *suggestion* to the compiler: 'Hey, if this function is tiny, just copy its code directly here instead of making a separate call.' It's like telling your friend to just tell you the answer instead of calling a whole meeting. Can make code faster, but the compiler decides.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int num1 = 10;
    int num2 = 20;

    printf("Calling our 'inline' suggested function...\n");
    int sum = add_fast(num1, num2); // The compiler *might* replace this call with the actual code of add_fast
    sleep(1);
    printf("Result of add_fast(%d, %d): %d\n", num1, num2, sum);
    sleep(1);

    printf("Note: 'inline' is just a hint. The compiler decides if it actually copies the code or not, based on its own smarts and optimization settings. It's for performance, but usually, you don't need to worry about it as a beginner.\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
