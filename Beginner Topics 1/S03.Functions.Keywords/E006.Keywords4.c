#include <stdio.h>   // Standard input/output library: Your program's mic and speaker, gotta have it to talk!
#include <stdlib.h>  // Standard library: Your general utility belt, handy tools for random stuff.
#include <time.h>    // For sleep() (simulating pauses)
#include <unistd.h>  // For sleep() on Unix-like systems (Linux, macOS)
#include <string.h>  // For string functions like strcpy
#include <stdbool.h> // For _Bool (true/false)
#include <complex.h> // For _Complex, _Imaginary (if you're into complex math)
#include <stdalign.h> // For _Alignas, _Alignof (memory alignment)
#include <stdnoreturn.h> // For _Noreturn (functions that never return)
#include <assert.h>  // For _Static_assert (compile-time checks)
// #include <stdatomic.h> // For _Atomic (requires specific compiler/platform support for full demo)
// #include <threads.h>   // For _Thread_local (requires specific compiler/platform support for full demo)

/**
 * ---
 * ## Yo, Welcome to the C Keywords Deep Dive! 🚀
 *
 * This whole file is basically your **ultimate cheat sheet** for C keywords.
 * Think of it as a **playlist of essential C vibes**, each track (keyword) dropping knowledge
 * on what it does and why it's important.
 *
 * We're gonna loop through 'em all, one by one, and break down their purpose in a way that
 * just *clicks*. No cap.
 *
 */

/**
 * @brief This is like creating a custom "ID card" or "profile" for each C keyword.
 *
 * `typedef struct { ... } CKeyword;`
 *
 * So, `struct` is like a blueprint for bundling different types of info together.
 * Here, we're making a blueprint for a "CKeyword" that holds:
 * - `keyword`: The actual keyword itself (like "auto" or "break").
 * - `description`: A short explanation of what that keyword does.
 *
 * And `typedef`? That's just giving our `struct` a **cool, short nickname**!
 * Instead of writing `struct CKeyword` every single time, we can just say `CKeyword`.
 * It's like calling your friend "Bae" instead of their full government name. Way easier.
 */
typedef struct {
    const char* keyword;    // The actual keyword, like "auto"
    const char* description; // What it does, in plain English (or Gen Z-ish)
} CKeyword; // This is our new, cool nickname for the struct blueprint!

// --- Function Prototypes for Examples ---
// (These are like promises to the compiler: "I swear these functions will show up later!")
void demonstrate_auto();
void demonstrate_break();
void demonstrate_case();
void demonstrate_char();
void demonstrate_const();
void demonstrate_continue();
void demonstrate_default();
void demonstrate_do();
void demonstrate_double();
void demonstrate_else();
void demonstrate_enum();
void demonstrate_extern(); // Conceptual, needs multiple files
void demonstrate_float();
void demonstrate_for();
void demonstrate_goto();
void demonstrate_if();
void demonstrate_int();
void demonstrate_long();
void demonstrate_register();
void demonstrate_return();
void demonstrate_short();
void demonstrate_signed();
void demonstrate_sizeof();
void demonstrate_static();
void demonstrate_struct();
void demonstrate_switch();
void demonstrate_typedef();
void demonstrate_union();
void demonstrate_unsigned();
void demonstrate_void();
void demonstrate_volatile();
void demonstrate_while();

// New C99/C11 Keywords Prototypes
void demonstrate_bool();
void demonstrate_complex_imaginary(); // Grouped for simplicity
void demonstrate_inline();
void demonstrate_restrict();
void demonstrate_alignas_alignof(); // Grouped for simplicity
void demonstrate_atomic(); // Conceptual, needs multi-threading setup
void demonstrate_generic();
void demonstrate_noreturn();
void demonstrate_static_assert();
void demonstrate_thread_local(); // Conceptual, needs multi-threading setup


/**
 * @brief The Main Event: Your program's starting point, where the magic happens! 🎤
 *
 * `int main()`
 *
 * This is where your program hits the 'play' button. The computer comes straight here
 * to start executing your code, no detours.
 *
 * `int`: Means when the show's over, `main` sends a tiny report card (an integer)
 * back to the Operating System. `0` means "Mission accomplished, fam! ✅"
 *
 */
int main()
{
    // This is our squad of C keywords, each with its own vibe and description.
    // It's like a perfectly curated playlist of essential C tracks.
    CKeyword keywords[] = {
        {"auto", "Essentially telling the compiler, 'Yo, these variables are temporary on the stack.', and compiler replies, 'Bruh, don't worry I'll clean them up. I went to Harvard for that stuff😂'. Don't use auto, its already expired unless you're in the 1980s, compiler already knows local variables are temporary. When main exits, they are destroyed."},
        {"break", "The 'break' keyword is like rage-quitting a loop or switch — the moment it's hit, your program says 'I'm out'. Picture the school principal sends you to dig through a stack of books. You find what you need, and you dip immediately. No need to keep searching — 'break' saw the condition was met and said, 'Mission accomplished, we out.'"},
        {"case", "The 'case' keyword is like saying, 'Alright, if this happens, here’s what we do.' It’s used inside a switch — kinda like choosing a character in a video game. Case 1? Pick Mario. Case 2? Pick Luigi. The switch checks the value and jumps to the matching case to run that code."},
        {"char", "The 'char' keyword used to declare variables that hold a single character — it only holds one character, like 'A' or '🥱'. You use it when you don’t need a whole essay (aka strings), just a tiny piece of text or emoji😶. It's cute, compact, and exactly 1 byte — small but mighty."},
        {"const", "The 'const' keyword means 'hands off!😤' — once you set a value, it’s locked. You can read it, vibe with it, print it, but you *can’t* change it. It’s like putting a sign that says ‘DO NOT TOUCH’ on a variable. Great for keeping things safe and avoiding dumb mistakes."},
        {"continue", "The 'continue' keyword is like saying, 'Skip this one, move on.' Inside a loop, it tells the program to drop the rest of the code *for that round* and jump straight to the next iteration. Perfect when you're like, 'Nah, this one’s not worth my time.'"},
        {"default", "The 'default' keyword in a switch is like the plan B you pull out when none of your options fit. It’s the catch-all, the 'else' of the switch world — if no case matches, default steps up and runs the show. No value left behind!"},
        {"do", "The 'do' keyword kicks off a do-while loop — it’s like saying, 'I’m gonna run this code at least once, then keep going as long as the vibe (condition) is right.' Unlike other loops that check first, this one checks *after* the action, so it never misses the first round. Perfect for when you gotta do the thing before deciding if you should repeat it."},
        {"double", "The 'double' keyword is your go-to when you need to store decimal numbers with extra precision — like money, scientific data, or anything where you can’t afford to lose detail. It’s basically a high-def floating-point number."},
        {"else", "The 'else' keyword is like the plan B for your if statement. When the 'if' or 'else if' conditions fail, 'else' jumps in and says, 'Alright, here’s what happens next because these two brothers of mine failed to execute.' It’s your way to cover all the bases and keep the code flowing."},
        {"enum", "The 'enum' keyword lets you give meaningful names to numbers, turning cryptic digits into clear labels. Imagine you're coding a traffic light. Instead of saying: 'If light_state == 0, turn red.' 'If light_state == 1, turn yellow.' 'If light_state == 2, turn green.' which is super easy to mess up or forget what 0, 1, or 2 means... You use 'enum' to define: 'RED = 0,' 'YELLOW = 1,' 'GREEN = 2.' Now, your code says: 'If light_state == RED, turn red.' 'If light_state == GREEN, turn green.' See? It's like having a clear, self-explaining menu for your numbers. Makes your code infinitely easier to read, understand, and debug, so you don't have to guess what '1' was supposed to be!"},
        {"extern", "'extern' is like working in a **big workshop with different teams, each with their own workbench (C file)**. Each team has its own tools, but there's **one super expensive, specialized laser cutter** (a global variable or a complex function) that *everyone* needs to use. You don't buy a laser cutter for every single workbench, right? Instead, extern is like putting a sign on your workbench that says: **'For the Laser Cutter, see the main fabrication room.'** It tells your compiler, 'Hey, this laser_cutter thing? It exists! It's defined and set up *somewhere else* in the workshop. Just know it's there, and we'll link up to it later.' This lets all teams (files) access that one single, powerful tool without having to copy or rebuild it themselves. Super efficient for sharing resources!"},
        {"float", "'float' is like a standard kitchen measuring cup or scale for numbers. You know how some recipes say '3.5 cups of flour' or '150.2 grams of sugar'? These are numbers with decimal points. 'float' is perfect for storing these everyday decimal numbers. It's precise enough for most tasks, like calculating prices ($19.99), basic measurements, or temperatures (25.5°C). It gives you a good amount of detail after the decimal point, but it's not designed for super-duper, scientific-lab-level precision. It's your go-to for standard decimal needs!"},
        {"for", "for is the C way of saying: 'Yo, do this exact thing over and over till I say stop.' Syntax: for(start; condition; update) Real life: for(int i = 0; i < 10; i++) → Like doing 10 pushups, one rep at a time. The moment condition goes false? Boom. You’re done. No gym, no gain."},
        {"goto", "goto is like rage-quitting structured code. It jumps to a label somewhere else, like teleporting mid-function — total chaos. Real life: Like walking out of a convo and reappearing in your ex’s DMs. Just WHY?? 😭 We don’t use it unless we’re writing spaghetti... or debugging hell."},
        {"if", "if is the decision-maker, the bouncer at the logic club. You give it a condition, and if it's true, it lets your code in. Real life: if (baby_is_hungry) → eat(); else → cry(); Clean, direct, no unnecessary drama. Unless you're nesting 5 levels deep 😅"},
        {"int", "int is how you declare you want an integer variable. Like saying: 'Yo compiler, I need a number — no decimals, just raw, whole number.' Real life: int age = 24; // That's you. No floating points. Memory-wise? 4 bytes of memory space (usually), living on the stack rent-free."},
        {"long", "'long' is like int's bigger, buff cousin. You know how int is great for regular whole numbers? Well, 'long' is for when your numbers get absolutely *massive* – like trying to count every single pixel on your 8K monitor, or maybe the total number of gigabytes on all your hard drives combined. If a regular int box isn't big enough, you use 'long' so your number doesn't overflow and crash your program's dreams. It grabs more memory bytes to fit those colossal values. For example, if you were storing a really huge number of long_distance_calls, you'd use 'long': long really_big_number_of_calls = 2000000000L; // That 'L' tells C it's a long number!"},
        {"register", "'register' is like telling your CPU, 'Yo, this variable is a VIP! Keep it right next to you in your fastest memory lane (a register), 'cause I'm gonna be grabbing it constantly!' Back in the old days, it was like giving your variable a special fast-pass ticket for super-speedy access. But honestly, modern compilers are so wicked smart, they're like, 'Chill, I got this.' They usually put important variables in registers anyway if it makes sense, all on their own. So, typing `register` today is usually **just a suggestion** that the compiler often ignores or does on its own. You rarely, if ever, need it. It's basically a relic from C's old school days. Example: `register int loop_counter; // The compiler might or might not put this in a register, it's smarter than you think.`"},
        {"return", "'return' is your function's way of saying, 'Alright, my part in this show is done! Here's the final result (if any), and then **peace out!**' It immediately kicks you out of the current function and sends whatever value you specify back to whoever called it. Think of it like finishing a text message and hitting 'send' – once it's sent, you're done with that message, no rewrites or edits. Example: int add(int a, int b) { return a + b; } // Adds the numbers and then bounces."},
        {"short", "'short' is like 'int' but on a strict diet – smaller range, smaller memory footprint. It's perfect for when you're counting things that won't go super high (like the number of people in a small room, or a low score in a game) and you're trying to save every precious byte of memory. Less bulk, still counts! Example: short tiny_score = 100; // Uses less bytes, for when memory is tight."},
        {"signed", "'signed' is like telling your number, 'You can be positive, negative, or zero – you've got options!' It's the default for 'int' anyway, so usually you don't even need to type it. Think of it as a number line that goes both ways: into the positives and into the negatives. If you're tracking temperature, for example, you'd want it to be 'signed' because winter's coming and it might hit -70 Russian degrees! Example: signed int current_temp = -70; // Can handle both hot and cold vibes."},
        {"sizeof", "'sizeof' is like your program's built-in measuring tape. It tells you exactly how much space (in bytes) a variable or a data type takes up in your computer's memory. Need to know if your 'int' is a tiny sticky note or a bigger box? sizeof will give you the exact dimensions. It's super handy when you're trying to manage memory efficiently or work with complex data structures. Example: printf(\"Size of int: %%zu bytes\\n\", sizeof(int)); // Tells you how much space an int needs."},
        {"static", "'static' is like the **ninja keyword** of C, doing different sneaky-cool things depending on where you drop it. It's all about controlling how long things stick around (persistence) and who gets to see them (visibility). It's got two main superpowers: 1. **Making stuff persistent (for variables inside a function):** Imagine your function is a hotel room. Normally, when you check out (function ends), everything in the room gets cleaned out and reset. But if you declare a variable as `static` inside that function, it's like having a **secret personal safe** in that room. Whatever you put in that `static` safe stays there, even if you check out and come back later. It remembers its value across different visits to the same room(function)! 2. Making stuff private (for variables or functions outside any function): Now imagine your entire C file (`.c` file) is a super-exclusive VIP club. If you declare a variable or a function as `static` *outside* of any function (at the global level), it's like making it a **secret, members-only lounge** *inside that specific club*. Only code within *this very club* (this `.c` file) knows about that lounge or can enter it. No other clubs (other `.c` files) can even see it exists, let alone sneak in! This keeps your internal club workings private and avoids name clashes with other clubs. It's all about controlling how long things stick around and who gets to see them, like a true coding ninja!"},
        {"struct", "'struct' is like creating your own customized 'profile card' or 'data packet'. You know how a person has a name (text), an an age (number), and a height (decimal)? Instead of keeping these as separate, loose pieces of info, 'struct' lets you bundle them all up under one single, neat label, like 'Person'. It's super useful for organizing related bits of data into one logical unit, making your code way cleaner and easier to manage complex information. Example: struct Car { char brand[50]; int year; float price; }; // A blueprint for a car's details."},
        {"switch", "'switch' is like a smart traffic controller at a complex intersection. Instead of a bunch of 'if-else if-else if' statements checking every single lane, 'switch' looks at one incoming car (your variable's value) and immediately directs it down the correct, pre-defined lane (case). It's a clean way to handle multiple choices or scenarios based on a single value, making your decision-making code much tidier. Example: switch (day_of_week) { case MONDAY: // code for Monday; break; ... } // Directs traffic based on the day."},
        {"typedef", "'typedef' is like creating your own custom, easy-to-remember nicknames for complex data types. Imagine you have a super long, complicated title like 'Unsigned Long Long Integer'. Instead of writing that out every single time, 'typedef' lets you say: 'From now on, let's just call that BigNumber.' It makes your code way more readable and easier to manage, especially when dealing with fancy data structures or pointers. It's all about making your code look cleaner and more professional. Example: typedef unsigned long long BigNumber; // Now you can just use BigNumber instead of the long version."},
        {"union", "'union' is like a special, space-saving storage box that can hold different kinds of items, but only one at a time. Think of a single memory slot that can be used to store either a whole number (an int), or a decimal number (a float), or even a character (a char). But if you put the int in, the float that was there before is gone. It's used when you need to save memory and you know that at any given moment, you'll only need *one* of the possible data types stored in that spot. Example: union Data { int i; float f; char c; }; // Can hold an int, float, OR char, but not all at once."},
        {"unsigned", "'unsigned' is like telling your number, 'Hey, you're a **positive-vibes-only** kind of number!' It means this variable can *only* hold zero or positive whole numbers. The cool part? Since it doesn't need to save space for negative signs, it can store positive numbers that are twice as big as a regular 'signed' integer! Think of it as a number line that starts at zero and only goes to the right. Perfect for counting things that can't be negative, like the number of likes on your post. Example: unsigned int likes = 100000; // Can't have negative likes, right?"},
        {"void", "'void' is like the 'nothing' or 'generic' keyword in C, used in a couple of key ways: 1. For functions like (void do_stuff()): It means this function just does something, but it doesn't **give back** any specific value or result when it's done. It's like telling your friend, 'Go close the door.' They do it, but they don't hand you anything back. 2. For pointers (void *ptr): It's like a 'mystery box' pointer. It can point to *any* type of data (an int, a float, a struct, whatever!), but you don't know *what* it's pointing to until you explicitly tell the compiler. Super flexible for generic memory handling!"},
        {"volatile", "'volatile' is like putting a **'DO NOT CACHE! ALWAYS RE-READ!'** sticky note on a variable. It tells the compiler, 'Listen, this variable's value might change at *any* time, even if my code isn't directly changing it. Don't try to be smart and remember its old value; **always go back to memory and get the freshest value** every single time you need it!' This is super important for things that interact directly with hardware or other parts of the system that your code doesn't fully control, like sensor readings or shared memory in multi-threaded programs. Example: volatile int sensor_reading; // Compiler, don't optimize this, it can change unexpectedly!"},
        {"while", "'while' is like your program's 'keep doing this AS LONG AS...' command. Imagine you're eating popcorn **while** the movie is still playing. As long as the movie is on (the condition is true), you keep eating popcorn. The moment the movie ends (the condition becomes false), you stop. It's perfect for repeating a block of code an unknown number of times, as long as a certain condition remains true. Example: while (has_popcorn) { eat_popcorn(); } // Keep munching until the bag is empty!"},
        // --- C99 Keywords ---
        {"_Bool", "The OG boolean type! It's like a simple 'Yes/No' or 'True/False' switch. Way clearer than using 0 or 1 for logic. You usually see it as 'bool' by including <stdbool.h>."},
        {"_Complex", "For when math gets wild! This is for complex numbers, like when you're dealing with electricity or quantum physics. It's a niche wizard, not your everyday calculator stuff."},
        {"_Imaginary", "Even wilder than _Complex! This is for pure imaginary numbers. If you're not doing super advanced signal processing or physics, you probably won't touch this. Super niche."},
        {"inline", "This is a *suggestion* to the compiler: 'Hey, if this function is tiny, just copy its code directly here instead of making a separate call.' It's like telling your friend to just tell you the answer instead of calling a whole meeting. Can make code faster, but the compiler decides."},
        {"restrict", "This is a promise to the compiler: 'Yo, these two pointers? They will *never* point to the same memory!' This lets the compiler optimize code way harder, assuming it doesn't have to worry about weird overlaps. Super important for high-performance code, especially with arrays."},
        // --- C11 Keywords ---
        {"_Alignas", "Like telling your data: 'Park here, but make sure you're perfectly aligned with this memory boundary!' It's for performance in super specific scenarios, like when hardware needs data to start at a certain memory address."},
        {"_Alignof", "Your memory alignment inspector! It tells you the required alignment of a type. Like asking: 'How many bytes does this data type need to be perfectly aligned in memory?'"},
        {"_Atomic", "This is for multi-threading: 'Yo, this variable is a shared toy, but only ONE thread can touch it at a time!' It ensures operations on this variable are indivisible, preventing chaos when multiple parts of your program try to update it simultaneously. Crucial for concurrency, but needs multi-threading setup to truly demo."},
        {"_Generic", "A compiler magic trick! It lets you write one function that acts differently based on the *type* of data you pass to it. Like a smart tool that knows if you gave it a hammer or a screwdriver and adjusts its behavior. Makes code cleaner for similar operations on different types."},
        {"_Noreturn", "A warning sign for the compiler: 'This function? It's a one-way trip! It will NEVER return to where it was called.' Think of `exit()` or `abort()`. It helps the compiler optimize and catch errors if you accidentally expect it to return."},
        {"_Static_assert", "Your compile-time bouncer! It lets you check conditions *before* your code even runs. If the condition is false, the compiler throws an error and refuses to build. Perfect for catching dumb mistakes early, like 'Is an int always 4 bytes on this system?'"},
        {"_Thread_local", "For multi-threading: 'This variable is my personal locker, no one else's!' Each thread gets its *own private copy* of this variable. No sharing, no conflicts. Super useful when threads need their own unique data without stepping on each other's toes."}
    };

    // Figuring out how many tracks are on this playlist (number of keywords)
    // This is like `sizeof(keywords)` giving us the total bytes for the array,
    // and `sizeof(keywords[0])` giving us the bytes for one single 'track'.
    // Divide them to get the total number of tracks! Simple math, fam.
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    printf("--------------------------------------------\n");
    printf("Yo, let's vibe through ALL %d C Keywords! 🎵\n", num_keywords);
    printf("--------------------------------------------\n\n");

    // Loop through the array and print each keyword and its description
    // This 'for' loop is like hitting 'next track' on your playlist,
    // going through each keyword one by one, grabbing its name and description
    // from the corresponding spot in each list.
    for (int i = 0; i < num_keywords; i++) {
        printf("%2d. %s\n", i + 1, keywords[i].keyword);    // Prints track number and its name
        printf("     %s\n", keywords[i].description);      // Drops the knowledge (description)
        printf("--------------------------------------------\n\n"); // Separator for that clean aesthetic
        sleep(1); // Chill a bit between each keyword for readability
    }

    printf("--------------------------------------------\n");
    printf("That's ALL the C Keywords you need to know! You've got the full toolkit now.\n");
    printf("You'll also meet so many standard library stuff that will amplify your coding abilities in the future. Trust.\n");
    printf("--------------------------------------------\n");

    return 0; // Indicates successful program execution: Main says 'Peace out!' to the OS, mission accomplished!
}

// --- Function Definitions for Keywords (Examples) ---

// (Note: For brevity and to keep the main output clean,
// the detailed code examples for each keyword are typically
// placed in separate functions or files. For this comprehensive
// list, we'll just keep the descriptions in the array.)

// However, here are some of the example functions that would be called
// if we were to run specific demos for each keyword.
// (These are illustrative and not called in the main loop above to keep it concise.)

void demonstrate_auto() {
    printf("\n--- Demo: auto ---\n");
    auto int x = 10; // 'auto' is optional, local variables are auto by default.
    printf("Auto variable x: %d\n", x);
    printf("Note: 'auto' is rarely used today as it's the default for local vars.\n");
    sleep(1);
}

void demonstrate_break() {
    printf("\n--- Demo: break ---\n");
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            printf("Breaking loop at i = %d\n", i);
            break;
        }
        printf("Looping: %d\n", i);
    }
    sleep(1);
}

void demonstrate_case() {
    printf("\n--- Demo: case ---\n");
    int choice = 2;
    switch (choice) {
        case 1: printf("Choice is 1.\n"); break;
        case 2: printf("Choice is 2.\n"); break;
        default: printf("Default choice.\n"); break;
    }
    sleep(1);
}

void demonstrate_char() {
    printf("\n--- Demo: char ---\n");
    char my_char = 'Z';
    printf("My char: %c\n", my_char);
    sleep(1);
}

void demonstrate_const() {
    printf("\n--- Demo: const ---\n");
    const int MAX_VALUE = 100;
    printf("Max value: %d\n", MAX_VALUE);
    // MAX_VALUE = 101; // This would cause a compile error!
    sleep(1);
}

void demonstrate_continue() {
    printf("\n--- Demo: continue ---\n");
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            printf("Skipping iteration %d\n", i);
            continue;
        }
        printf("Processing iteration %d\n", i);
    }
    sleep(1);
}

void demonstrate_default() {
    printf("\n--- Demo: default ---\n");
    int option = 99;
    switch (option) {
        case 1: printf("Option 1 selected.\n"); break;
        default: printf("No match, default action.\n"); break;
    }
    sleep(1);
}

void demonstrate_do() {
    printf("\n--- Demo: do ---\n");
    int count = 0;
    do {
        printf("Do-while count: %d\n", count);
        count++;
    } while (count < 2);
    sleep(1);
}

void demonstrate_double() {
    printf("\n--- Demo: double ---\n");
    double pi = 3.1415926535;
    printf("Pi (double): %.10f\n", pi);
    sleep(1);
}

void demonstrate_else() {
    printf("\n--- Demo: else ---\n");
    int num = 5;
    if (num > 10) {
        printf("Num is greater than 10.\n");
    } else {
        printf("Num is 10 or less.\n");
    }
    sleep(1);
}

void demonstrate_enum() {
    printf("\n--- Demo: enum ---\n");
    enum Colors { RED, GREEN, BLUE };
    enum Colors my_color = GREEN;
    printf("My color is: %d (Green)\n", my_color);
    sleep(1);
}

void demonstrate_extern() {
    printf("\n--- Demo: extern ---\n");
    printf("Extern is for variables/functions defined in other files. (Conceptual demo)\n");
    // Example requires multiple files to compile:
    // extern int global_counter;
    // printf("Global counter from another file: %d\n", global_counter);
    sleep(1);
}

void demonstrate_float() {
    printf("\n--- Demo: float ---\n");
    float temp = 25.5f;
    printf("Temperature (float): %.1f\n", temp);
    sleep(1);
}

void demonstrate_for() {
    printf("\n--- Demo: for ---\n");
    for (int i = 0; i < 3; i++) {
        printf("For loop: %d\n", i);
    }
    sleep(1);
}

void demonstrate_goto() {
    printf("\n--- Demo: goto ---\n");
    int x = 1;
    if (x == 1) goto label_a;
    printf("This won't print.\n");
label_a:
    printf("Jumped to label_a.\n");
    sleep(1);
}

void demonstrate_if() {
    printf("\n--- Demo: if ---\n");
    int age = 18;
    if (age >= 18) {
        printf("You are an adult.\n");
    }
    sleep(1);
}

void demonstrate_int() {
    printf("\n--- Demo: int ---\n");
    int count = 100;
    printf("Count: %d\n", count);
    sleep(1);
}

void demonstrate_long() {
    printf("\n--- Demo: long ---\n");
    long big_num = 1234567890123L;
    printf("Big number: %ld\n", big_num);
    sleep(1);
}

void demonstrate_register() {
    printf("\n--- Demo: register ---\n");
    register int fast_var = 5;
    printf("Fast var: %d\n", fast_var);
    printf("Note: 'register' is a hint, compiler decides.\n");
    sleep(1);
}

void demonstrate_return() {
    printf("\n--- Demo: return ---\n");
    // See main for return 0;
    printf("Function returned value.\n");
    sleep(1);
}

void demonstrate_short() {
    printf("\n--- Demo: short ---\n");
    short small_num = 30000;
    printf("Small number: %d\n", small_num);
    sleep(1);
}

void demonstrate_signed() {
    printf("\n--- Demo: signed ---\n");
    signed int neg_num = -50;
    printf("Negative number: %d\n", neg_num);
    sleep(1);
}

void demonstrate_sizeof() {
    printf("\n--- Demo: sizeof ---\n");
    printf("Size of int: %zu bytes\n", sizeof(int));
    sleep(1);
}

void demonstrate_static() {
    printf("\n--- Demo: static (function-local) ---\n");
    static int persistent_count = 0;
    persistent_count++;
    printf("Persistent count: %d\n", persistent_count);
    sleep(1);
}

void demonstrate_struct() {
    printf("\n--- Demo: struct ---\n");
    struct Point { int x; int y; };
    struct Point p1 = {10, 20};
    printf("Point: (%d, %d)\n", p1.x, p1.y);
    sleep(1);
}

void demonstrate_switch() {
    printf("\n--- Demo: switch ---\n");
    int day = 1;
    switch (day) {
        case 1: printf("Monday.\n"); break;
        default: printf("Other day.\n"); break;
    }
    sleep(1);
}

void demonstrate_typedef() {
    printf("\n--- Demo: typedef ---\n");
    typedef int MyInt;
    MyInt val = 42;
    printf("MyInt value: %d\n", val);
    sleep(1);
}

void demonstrate_union() {
    printf("\n--- Demo: union ---\n");
    union Data { int i; float f; };
    union Data d;
    d.i = 10;
    printf("Union int: %d\n", d.i);
    d.f = 20.5f;
    printf("Union float: %.1f\n", d.f); // d.i is now garbage
    sleep(1);
}

void demonstrate_unsigned() {
    printf("\n--- Demo: unsigned ---\n");
    unsigned int pos_num = 100u;
    printf("Positive number: %u\n", pos_num);
    sleep(1);
}

void demonstrate_void() {
    printf("\n--- Demo: void ---\n");
    printf("Void function called.\n");
    sleep(1);
}

void demonstrate_volatile() {
    printf("\n--- Demo: volatile ---\n");
    volatile int sensor = 0; // Imagine this changes externally
    printf("Sensor reading: %d\n", sensor);
    printf("Note: 'volatile' ensures re-reads from memory.\n");
    sleep(1);
}

void demonstrate_while() {
    printf("\n--- Demo: while ---\n");
    int counter = 0;
    while (counter < 2) {
        printf("While loop: %d\n", counter);
        counter++;
    }
    sleep(1);
}

// --- New C99/C11 Keywords Function Definitions ---

void demonstrate_bool() {
    printf("\n--- Demo: _Bool (C99) ---\n");
    _Bool is_active = 1; // 1 is true, 0 is false
    // Or use 'bool' from <stdbool.h> for cleaner syntax
    bool is_ready = true;

    printf("Is active? %s\n", is_active ? "True" : "False");
    printf("Is ready? %s\n", is_ready ? "True" : "False");
    printf("Note: Use 'bool' from <stdbool.h> for better readability.\n");
    sleep(1);
}

void demonstrate_complex_imaginary() {
    printf("\n--- Demo: _Complex / _Imaginary (C99) ---\n");
    // These are for complex numbers, super niche for beginners!
    double complex z1 = 1.0 + 2.0 * I; // I is for imaginary unit
    double complex z2 = 3.0 + 4.0 * I;
    double complex sum = z1 + z2;

    printf("Complex number sum: %.1f + %.1fi\n", creal(sum), cimag(sum));
    printf("Note: For advanced math/DSP. Don't stress if this is wild.\n");
    sleep(1);
}

// Helper function to show inline effect
inline int add_inline(int a, int b) {
    return a + b;
}

void demonstrate_inline() {
    printf("\n--- Demo: inline (C99) ---\n");
    printf("This is a *suggestion* to the compiler to copy function code directly.\n");
    int result = add_inline(5, 7); // Compiler *might* inline this
    printf("Result of inline add: %d\n", result);
    printf("Note: Compiler decides if it actually inlines for optimization.\n");
    sleep(1);
}

void demonstrate_restrict() {
    printf("\n--- Demo: restrict (C99) ---\n");
    printf("This is a promise to the compiler for optimization.\n");
    printf("Example: void copy_data(int * restrict dest, const int * restrict src, int n) {\n");
    printf("  // Compiler knows dest and src don't overlap, so it can optimize aggressively.\n");
    printf("}\n");
    printf("Note: For high-performance code, especially with pointers/arrays.\n");
    sleep(1);
}

void demonstrate_alignas_alignof() {
    printf("\n--- Demo: _Alignas / _Alignof (C11) ---\n");
    // _Alignas: Request specific memory alignment
    // This tells the compiler to align 'aligned_data' on an 8-byte boundary
    typedef struct {
        _Alignas(8) int data[2]; // Align this struct member to 8 bytes
        int other_data;
    } AlignedStruct;

    printf("Size of AlignedStruct: %zu bytes\n", sizeof(AlignedStruct));
    printf("Alignment of AlignedStruct: %zu bytes\n", _Alignof(AlignedStruct));
    printf("Note: For low-level memory control, hardware interaction, or performance.\n");
    sleep(1);
}

void demonstrate_atomic() {
    printf("\n--- Demo: _Atomic (C11) ---\n");
    printf("This is for multi-threading: 'Yo, this variable is a shared toy, but only ONE thread can touch it at a time!'\n");
    printf("Example: _Atomic int shared_counter = 0;\n");
    printf("Note: Ensures operations on this variable are indivisible, preventing chaos in concurrent programs. Requires multi-threading setup to truly demo.\n");
    sleep(1);
}

// Function marked as _Noreturn
_Noreturn void exit_program_immediately(int status) {
    printf("\n--- Demo: _Noreturn (C11) ---\n");
    printf("This function is a one-way trip! It will NEVER return to where it was called.\n");
    printf("Exiting program with status %d...\n", status);
    exit(status); // This function never returns
}

void demonstrate_noreturn() {
    printf("Note: _Noreturn functions like 'exit()' or 'abort()' never return control.\n");
    // Calling it here would terminate the program, so we just describe it.
    // exit_program_immediately(1); // Uncomment to see it in action (program will end)
    sleep(1);
}

void demonstrate_generic() {
    printf("\n--- Demo: _Generic (C11) ---\n");
    printf("A compiler magic trick! It lets you write one function that acts differently based on the *type* of data you pass to it.\n");

    // Example of a generic macro for printing different types
    #define PRINT_VALUE(x) _Generic((x), \
        int: printf("Int value: %d\\n", x), \
        float: printf("Float value: %.2f\\n", x), \
        char*: printf("String value: %s\\n", x), \
        default: printf("Unknown type!\\n") \
    )

    int int_val = 10;
    float float_val = 10.5f;
    char* string_val = "Hello Generic!";

    PRINT_VALUE(int_val);
    PRINT_VALUE(float_val);
    PRINT_VALUE(string_val);
    PRINT_VALUE(123.45); // This will hit default because it's a double by default
    printf("Note: Super useful for creating flexible, type-aware macros.\n");
    sleep(1);
}

void demonstrate_static_assert() {
    printf("\n--- Demo: _Static_assert (C11) ---\n");
    printf("Your compile-time bouncer! It lets you check conditions *before* your code even runs.\n");

    // This checks if an int is 4 bytes. If not, compilation fails!
    _Static_assert(sizeof(int) == 4, "Error: int is not 4 bytes on this system!");
    printf("Static assert passed: int is 4 bytes (or whatever your system's int size is).\n");

    // Example of a failing assert (uncomment to see compile error)
    // _Static_assert(sizeof(long) == 100, "Error: Long is NOT 100 bytes!");

    printf("Note: Catches dumb mistakes early, before runtime. Super powerful for robust code.\n");
    sleep(1);
}

void demonstrate_thread_local() {
    printf("\n--- Demo: _Thread_local (C11) ---\n");
    printf("For multi-threading: 'This variable is my personal locker, no one else's!'\n");
    printf("Example: _Thread_local int my_thread_specific_data = 0;\n");
    printf("Note: Each thread gets its *own private copy* of this variable. No sharing, no conflicts. Requires multi-threading setup to truly demo.\n");
    sleep(1);
}
