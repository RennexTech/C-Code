#include <stdio.h> // Essential for 'printf', your program's voice box!
#include <stdlib.h> // Good for general utility functions, though not strictly needed for this example

// --------- FILE 003 ---------

/**
 * 
 * JOHN - We left the convo hanging man in episode 2, right C?
 * 
 * MR.C - Yeah, I was saying, you can use a backslash (\) to escape things, meaning they print out literally.
 * 
 * JOHN - So, this backslash magic only applies when we want to print out things like backslashes, 
 * double quotes, or single quotes? Or is there more to it?
 * 
 * MR.C - Oh, there's *way* more! 😄 You're only seeing one side of the beast. The backslash is a 
 * true multi-tool in C. It wears different hats depending on the context. Let me break it down for you:
 * 
 *  🪄 Role 1: Escaping literal characters – like `\\`, `\"`, and `\'`. These let you print characters 
 *            that normally have a job in the syntax.
 * 
 *  🚪 Role 2: Creating escape sequences – like `\n`, `\t`, `\a`, etc. These control output formatting,
 *            like jumping to a new line or ringing a system beep.
 * 
 *  🧪 Role 3: Encoding characters in hex/octal – like `\x41` (which is 'A') or `\012` (which is newline).
 *            This is especially powerful in low-level C, reverse engineering, or binary manipulation.
 * 
 * So yeah, the backslash isn’t just some lame punctuation mark – it’s a whole hidden language of its own.
 * Learn it, and you start bending C to your will.
 * 
 * When you start analyzing malware or writing shellcode later on, you'll definitely 
 * see backslashes used for encoding stuff in hex (like \x90 for NOP instructions). 
 * Knowing how to read and write those sequences gives you a head start. (see the book image for E03)
 * 
 */


int main() {
    // --- The "Daily Digital Life" Story of Backslashes ---

    // Scene 1: Starting the day with a notification
    printf("Wassup, fam!\n"); // '\n' for that fresh new line, keeps the feed clean.


    // Scene 2: Checking a message in a group chat – notice the quotes inside!
    printf("New Group Chat Message from 'Squad Goals': \"Anyone down for Valorant tonight?\"\n");
    // The backslash is crucial here! It lets us put double quotes inside our text without C getting confused.


    // Scene 3: A quick correction – using backspace and carriage return for a dynamic update!
    // Imagine a loading bar or a quick typo fix on a single line.
    printf("Loading game assets: 10%%\r"); // '\r' (Carriage Return) moves cursor to start of line
    printf("Loading game assets: 40%%\r");
    printf("Loading game assets: 70%%\r");
    printf("Loading game assets: 100%% Complete!\n"); // Final overwrite, then new line.


    // Scene 4: Someone sends a weird file path, gotta print that literal backslash!
    printf("Dev friend shared: \"Check this bug in C:\\ProgramFiles\\MyGame\\bug_report.txt\"\n");
    // '\\' is key! Without it, C would think '\P' or '\M' are escape sequences, which they aren't.


    // Scene 5: A funny sound notification from a meme app.
    printf("Meme Alert! Get ready for a laugh! \a\a\a\n"); // '\a' (Alert) makes your computer beep!
    // You might hear a quick "ding ding ding" sound, depending on your system.


    // Scene 6: Formatting a leader board with tabs for clean alignment.
    printf("\n--- Leaderboard ---\n");
    printf("Player\t\tScore\n"); // '\t' (Tab) creates neat spacing, like in a spreadsheet.
    printf("GamerPro23\t1500\n");
    printf("NoobSlayer_X\t1200\n");
    printf("PixelQueen\t1450\n");


    // Scene 7: A secret message using hexadecimal escape sequence (just for fun/advanced stuff)
    // This example converts hex codes to characters: \x43 is 'C', \x6f is 'o', etc.
    printf("Secret Code: \x43\x6f\x64\x65\x4c\x6f\x63\x6b\x65\x64\n"); // Should print "CodeLocked"

    
    printf("\nThat's how backslashes run the show in C strings! Stay lit! 🔥\n");

    return 0; // Signals that everything executed without issues
}