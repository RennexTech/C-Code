#include <stdio.h> // Standard input/output library

/**
 * @brief Main function demonstrating C trigraphs for beginners.
 *
 * This program shows how certain character sequences (trigraphs) are
 * replaced by the C preprocessor before compilation.
 * 
 * Trigraphs are sequences of three characters that are interpreted as a single character by the C preprocessor before the code is compiled. 
 * The C preprocessor is a program that processes C source code before it's compiled. It handles tasks like macro expansion, file inclusion, and conditional compilation, effectively preparing the code for the compiler. 
 * 
 * Here's a quick list of the trigraphs and what they represent:

        ??= -> # (pound sign)
        ??( -> [ (left bracket)
        ??) -> ] (right bracket)
        ??< -> { (left brace)
        ??> -> } (right brace)
        ??! -> | (vertical bar)
        ??- -> ~ (tilde)
        ??' -> ^ (caret)
        ??/ -> \ (backslash)

 */

int main()
{
    // Trigraph for '#' (hash) - used in preprocessor directives
    // This line: ??=include <stdio.h> would be replaced by #include <stdio.h>
    // Essentially preprocessor replaces the ??= with # if you're using super old PC.
    // Modern PCs don't need trigraphs, UTF-8 solves that.
    printf("Example of a trigraph for #: ??=\n");

    // Trigraph for '[' (left bracket)
    printf("This is a left bracket: ??(\n");

    // Trigraph for ']' (right bracket)
    printf("This is a right bracket: ??)\n");

    // Trigraph for '{' (left brace) - used to define code blocks
    // This line: int main() ??< would be replaced by int main() {
    printf("Example of a trigraph for {: ??<\n");

    // Trigraph for '}' (right brace) - used to close code blocks
    // This line: ??> would be replaced by }
    printf("Example of a trigraph for }: ??>\n");

    // Trigraph for '|' (vertical bar) - used in bitwise OR or logical OR
    printf("This is a vertical bar: ??!\n");

    // Trigraph for '~' (tilde) - used in bitwise NOT
    printf("This is a tilde: ??-\n");

    // Trigraph for '^' (caret) - used in bitwise XOR
    printf("This is a caret: ??'\n");

    // Trigraph for '\' (backslash) - used for escape sequences or line continuation
    // This line: printf("Newline: \\n"); would be printf("Newline: ??/n");
    printf("Example of a trigraph for backslash: ??/\n");

    printf("\nNote: Trigraphs are rarely used in modern C code.\n");
    printf("They are processed by the compiler *before* compilation.\n");

    return 0; // Indicates successful program execution.
}
