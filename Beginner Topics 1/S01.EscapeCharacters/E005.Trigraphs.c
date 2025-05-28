#include <stdio.h>  // Standard input/output library, our program's voice.
#include <unistd.h> // For sleep() to chill between prints.

/**
 * @brief 👴 C Trigraphs: The Ancient Code Secrets (Now Obsolete!) ⏳
 *
 * @analog Imagine you're trying to send emojis on a super old phone that only
 * has really basic buttons. You can't type 🚀 directly, so you'd have to type
 * something weird like `??=D` and the phone would magically turn it into a rocket emoji.
 * That's kinda what trigraphs were!
 *
 * Back in the day (like, ancient internet history), some keyboards couldn't type
 * certain C symbols (like `[` or `#`). So, C introduced trigraphs: special
 * sequences of three characters (`??` followed by another character) that the
 * preprocessor (the program that gets your code ready before the main compiler)
 * would automatically swap out for the actual symbol.
 *
 * It's basically a find-and-replace mission that happens super early.
 *
 * Are they important now? Nah, fam. They're pretty much **obsolete**.
 * Modern keyboards and character encodings (like UTF-8) mean we don't have
 * this problem anymore. But it's cool to know about this quirky piece of C history!
 *
 * Here's the ancient cheat sheet for what they replaced:
 *
 * ??= -> # (pound sign)
 * ??( -> [ (left bracket)
 * ??) -> ] (right bracket)
 * ??< -> { (left brace)
 * ??> -> } (right brace)
 * ??! -> | (vertical bar)
 * ??- -> ~ (tilde)
 * ??' -> ^ (caret)
 * ??/ -> \ (backslash)
 *
 * Let's peek at these old-school symbols in action (but please, don't use them!).
 */

int main()
{
    printf("=============================================================\n");
    printf("  C Trigraphs: The Ancient Code Secrets (Now Obsolete!) ⏳ \n");
    printf("=============================================================\n");
    sleep(1);

    printf("\nChecking out these old-school C symbols:\n");
    printf("--------------------------------------------\n");
    sleep(1);

    // Trigraph for '#' (pound sign) - used in preprocessor directives
    // If you typed `??=include <stdio.h>` on an old setup, it became `#include <stdio.h>`
    printf("Old-school #: ??=\n"); // Looks weird, right?
    sleep(1);

    // Trigraph for '[' (left bracket)
    printf("Old-school [: ??(\n");
    sleep(1);

    // Trigraph for ']' (right bracket)
    printf("Old-school ]: ??)\n");
    sleep(1);

    // Trigraph for '{' (left brace) - defines code blocks
    // `int main() ??<` would be `int main() {`
    printf("Old-school {: ??<\n");
    sleep(1);

    // Trigraph for '}' (right brace) - closes code blocks
    // Just `??>` would become `}`
    printf("Old-school }: ??>\n");
    sleep(1);

    // Trigraph for '|' (vertical bar) - bitwise OR or logical OR
    printf("Old-school |: ??!\n");
    sleep(1);

    // Trigraph for '~' (tilde) - bitwise NOT
    printf("Old-school ~: ??-\n");
    sleep(1);

    // Trigraph for '^' (caret) - bitwise XOR
    printf("Old-school ^: ??'\n");
    sleep(1);

    // Trigraph for '\' (backslash) - escape sequences or line continuation
    // `printf("Newline: ??/n");` would become `printf("Newline: \n");`
    printf("Old-school \\: ??/\n");
    sleep(1);

    printf("\n--------------------------------------------\n");
    printf("THE REALITY CHECK:\n");
    printf("Trigraphs are processed by the preprocessor *before* the compiler even sees them.\n");
    printf("But honestly? You'll prob never see these in real modern code. They're kinda cringe now. 😂\n");
    printf("Stick to the actual symbols! Your keyboard can handle it, fam.\n");
    printf("--------------------------------------------\n");
    sleep(2);

    return 0; // Indicates successful program execution. Mission accomplished! ✅
}
