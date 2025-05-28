#include <stdio.h> // Still need this for the mic (printf)

/**
 * ---
 * ## Ditching the Struct: Parallel Arrays Vibe 🤙
 *
 * So, instead of making a single "ID card" (struct) for each keyword,
 * we're just gonna keep two separate lists.
 *
 * It's like having:
 * 1. A playlist of just the song *titles*.
 * 2. Another playlist, perfectly synced, of just the song *lyrics*.
 *
 * When you wanna know the lyrics for song #3, you just go to spot #3 on both lists!
 * Simple. No fancy custom blueprints needed for this.
 *
 */

int main()
{
    // Our first playlist: just the C Keyword names
    // Gotta keep these in the exact same order as their descriptions!
    /**
     * 
     *  Const means READ-ONLY!
     * 
     *  char* means we're pointing to the first location where the string starts in memory. Like GPS's to the string's starting location in memory. 
     * 
     *  keywords_playlist[] means it's the label for the whole collection keywords. 
     * 
     *  [] means its an array, you're not just storing one GPS coordinate (one char*), you're storing a list of them. 
     * 
     * 
     */

    const char* keywords_playlist[] = {
        "auto",
        "break",
        "case",
        "char",
        "const",
        "continue",
        "default",
        "do",
        "double",
        "else",
        "enum",
        "extern",
        "float",
        "for",
        "goto",
        "if",
        "int",
        "long",
        "register",
        "return",
        "short",
        "signed",
        "sizeof",
        "static",
        "struct",
        "switch",
        "typedef",
        "union",
        "unsigned",
        "void",
        "volatile",
        "while"
    };

    // Our second playlist: just the super fire descriptions, synced with the names
    const char* descriptions_playlist[] = {
        "Essentially telling the compiler, 'Yo, these variables are temporary on the stack.', and compiler replies, 'Bruh, don't worry I'll clean them up. I went to Harvard for that stuff😂'. Don't use auto, its already expired unless you're in the 1980s, compiler already knows local variables are temporary. When main exits, they are destroyed.",
        "The 'break' keyword is like rage-quitting a loop or switch — the moment it's hit, your program says 'I'm out'. Picture the school principal sends you to dig through a stack of books. You find what you need, and you dip immediately. No need to keep searching — 'break' saw the condition was met and said, 'Mission accomplished, we out.'",
        "The 'case' keyword is like saying, 'Alright, if this happens, here’s what we do.' It’s used inside a switch — kinda like choosing a character in a video game. Case 1? Pick Mario. Case 2? Pick Luigi. The switch checks the value and jumps to the matching case to run that code.",
        "The 'char' keyword used to declare variables that hold a single character — it only holds one character, like 'A' or '🥱'. You use it when you don’t need a whole essay (aka strings), just a tiny piece of text or emoji😶. It's cute, compact, and exactly 1 byte — small but mighty.",
        "The 'const' keyword means 'hands off!😤' — once you set a value, it’s locked. You can read it, vibe with it, print it, but you *can’t* change it. It’s like putting a sign that says ‘DO NOT TOUCH’ on a variable. Great for keeping things safe and avoiding dumb mistakes.",
        "The 'continue' keyword is like saying, 'Skip this one, move on.' Inside a loop, it tells the program to drop the rest of the code *for that round* and jump straight to the next iteration. Perfect when you're like, 'Nah, this one’s not worth my time.'",
        "The 'default' keyword in a switch is like the plan B you pull out when none of your options fit. It’s the catch-all, the 'else' of the switch world — if no case matches, default steps up and runs the show. No value left behind!",
        "The 'do' keyword kicks off a do-while loop — it’s like saying, 'I’m gonna run this code at least once, then keep going as long as the vibe (condition) is right.' Unlike other loops that check first, this one checks *after* the action, so it never misses the first round. Perfect for when you gotta do the thing before deciding if you should repeat it.",
        "The 'double' keyword is your go-to when you need to store decimal numbers with extra precision — like money, scientific data, or anything where you can’t afford to lose detail. It’s basically a high-def floating-point number.",
        "The 'else' keyword is like the plan B for your if statement. When the 'if' or 'else if' conditions fail, 'else' jumps in and says, 'Alright, here’s what happens next because these two brothers of mine failed to execute.' It’s your way to cover all the bases and keep the code flowing.",
        "The 'enum' keyword lets you give meaningful names to numbers, turning cryptic digits into clear labels. Imagine you're coding a traffic light. Instead of saying: 'If light_state == 0, turn red.' 'If light_state == 1, turn yellow.' 'If light_state == 2, turn green.' which is super easy to mess up or forget what 0, 1, or 2 means... You use 'enum' to define: 'RED = 0,' 'YELLOW = 1,' 'GREEN = 2.' Now, your code says: 'If light_state == RED, turn red.' 'If light_state == GREEN, turn green.' See? It's like having a clear, self-explaining menu for your numbers. Makes your code infinitely easier to read, understand, and debug, so you don't have to guess what '1' was supposed to be!",
        "The 'extern' keyword is like working in a **big workshop with different teams, each with their own workbench (C file)**. Each team has its own tools, but there's **one super expensive, specialized laser cutter** (a global variable or a complex function) that *everyone* needs to use. You don't buy a laser cutter for every single workbench, right? Instead, extern is like putting a sign on your workbench that says: **'For the Laser Cutter, see the main fabrication room.'** It tells your compiler, 'Hey, this laser_cutter thing? It exists! It's defined and set up *somewhere else* in the workshop. Just know it's there, and we'll link up to it later.' This lets all teams (files) access that one single, powerful tool without having to copy or rebuild it themselves. Super efficient for sharing resources!",
        "The 'float' keyword is like a standard kitchen measuring cup or scale for numbers. You know how some recipes say '3.5 cups of flour' or '150.2 grams of sugar'? These are numbers with decimal points. 'float' is perfect for storing these everyday decimal numbers. It's precise enough for most tasks, like calculating prices ($19.99), basic measurements, or temperatures (25.5°C). It gives you a good amount of detail after the decimal point, but it's not designed for super-duper, scientific-lab-level precision. It's your go-to for standard decimal needs!",
        "for is the C way of saying: 'Yo, do this exact thing over and over till I say stop.' Syntax: for(start; condition; update) Real life: for(int i = 0; i < 10; i++) → Like doing 10 pushups, one rep at a time. The moment condition goes false? Boom. You’re done. No gym, no gain.",
        "goto is like rage-quitting structured code. It jumps to a label somewhere else, like teleporting mid-function — total chaos. Real life: Like walking out of a convo and reappearing in your ex’s DMs. Just WHY?? 😭 We don’t use it unless we’re writing spaghetti... or debugging hell.",
        "if is the decision-maker, the bouncer at the logic club. You give it a condition, and if it's true, it lets your code in. Real life: if (baby_is_hungry) → eat(); else → cry(); Clean, direct, no unnecessary drama. Unless you're nesting 5 levels deep 😅",
        "int is how you declare you want an integer variable. Like saying: 'Yo compiler, I need a number — no decimals, just raw, whole number.' Real life: int age = 24; // That's you. No floating points. Memory-wise? 4 bytes of memory space (usually), living on the stack rent-free.",
        "long is like int's bigger, buff cousin. You know how int is great for regular whole numbers? Well, long is for when your numbers get absolutely massive – like trying to count every single pixel on your 8K monitor, or maybe the total number of gigabytes on all your hard drives combined. If a regular int box isn't big enough, you use long so your number doesn't overflow and crash your program's dreams. It grabs more memory bytes to fit those colossal values. For example, if you were storing a really huge number of long_distance_calls, you'd use long: long really_big_number_of_calls = 2000000000L; // That 'L' tells C it's a long number!",
        "register is like telling your CPU, 'Yo, this variable is a VIP! Keep it right next to you in your fastest memory lane (a register), 'cause I'm gonna be grabbing it constantly!' Back in the old days, it was like giving your variable a special fast-pass ticket for super-speedy access. But honestly, modern compilers are so wicked smart, they're like, 'Chill, I got this.' They usually put important variables in registers anyway if it makes sense, all on their own. So, typing `register` today is usually **just a suggestion** that the compiler often ignores or does on its own. You rarely, if ever, need it. It's basically a relic from C's old school days. Example: `register int loop_counter; // The compiler might or might not put this in a register, it's smarter than you think.`",
        "return is your function's way of saying, 'Alright, my part in this show is done! Here's the final result (if any), and then **peace out!**' It immediately kicks you out of the current function and sends whatever value you specify back to whoever called it. Think of it like finishing a text message and hitting 'send' – once it's sent, you're done with that message, no rewrites or edits. Example: int add(int a, int b) { return a + b; } // Adds the numbers and then bounces.",
        "short is like int but on a strict diet – smaller range, smaller memory footprint. It's perfect for when you're counting things that won't go super high (like the number of people in a small room, or a low score in a game) and you're trying to save every precious byte of memory. Less bulk, still counts! Example: short tiny_score = 100; // Uses less bytes, for when memory is tight.",
        "signed is like telling your number, 'You can be positive, negative, or zero – you've got options!' It's the default for 'int' anyway, so usually you don't even need to type it. Think of it as a number line that goes both ways: into the positives and into the negatives. If you're tracking temperature, for example, you'd want it to be 'signed' because winter's coming and it might hit -70 Russian degrees! Example: signed int current_temp = -70; // Can handle both hot and cold vibes.",
        "sizeof is like your program's built-in measuring tape. It tells you exactly how much space (in bytes) a variable or a data type takes up in your computer's memory. Need to know if your 'int' is a tiny sticky note or a bigger box? sizeof will give you the exact dimensions. It's super handy when you're trying to manage memory efficiently or work with complex data structures. Example: printf(\"Size of int: %%zu bytes\\n\", sizeof(int)); // Tells you how much space an int needs.",
        "static is like the **ninja keyword** of C, doing different sneaky-cool things depending on where you drop it. It's all about controlling how long things stick around (persistence) and who gets to see them (visibility). It's got two main superpowers: 1. **Making stuff persistent (for variables inside a function):** Imagine your function is a hotel room. Normally, when you check out (function ends), everything in the room gets cleaned out and reset. But if you declare a variable as `static` inside that function, it's like having a **secret personal safe** in that room. Whatever you put in that `static` safe stays there, even if you check out and come back later. It remembers its value across different visits to the same room(function)! 2. Making stuff private (for variables or functions outside any function): Now imagine your entire C file (`.c` file) is a super-exclusive VIP club. If you declare a variable or a function as `static` *outside* of any function (at the global level), it's like making it a **secret, members-only lounge** *inside that specific club*. Only code within *this very club* (this `.c` file) knows about that lounge or can enter it. No other clubs (other `.c` files) can even see it exists, let alone sneak in! This keeps your internal club workings private and avoids name clashes with other clubs. It's all about controlling how long things stick around and who gets to see them, like a true coding ninja!",
        "struct is like creating your own customized 'profile card' or 'data packet'. You know how a person has a name (text), an age (number), and a height (decimal)? Instead of keeping these as separate, loose pieces of info, 'struct' lets you bundle them all up under one single, neat label, like 'Person'. It's super useful for organizing related bits of data into one logical unit, making your code way cleaner and easier to manage complex information. Example: struct Car { char brand[50]; int year; float price; }; // A blueprint for a car's details.",
        "switch is like a smart traffic controller at a complex intersection. Instead of a bunch of 'if-else if-else if' statements checking every single lane, 'switch' looks at one incoming car (your variable's value) and immediately directs it down the correct, pre-defined lane (case). It's a clean way to handle multiple choices or scenarios based on a single value, making your decision-making code much tidier. Example: switch (day_of_week) { case MONDAY: // code for Monday; break; ... } // Directs traffic based on the day.",
        "typedef is like creating your own custom, easy-to-remember nicknames for complex data types. Imagine you have a super long, complicated title like 'Unsigned Long Long Integer'. Instead of writing that out every single time, 'typedef' lets you say: 'From now on, let's just call that BigNumber.' It makes your code way more readable and easier to manage, especially when dealing with fancy data structures or pointers. It's all about making your code look cleaner and more professional. Example: typedef unsigned long long BigNumber; // Now you can just use BigNumber instead of the long version.",
        "union is like a special, space-saving storage box that can hold different kinds of items, but only one at a time. Think of a single memory slot that can be used to store either a whole number (an int), or a decimal number (a float), or even a character (a char). But if you put the int in, the float that was there before is gone. It's used when you need to save memory and you know that at any given moment, you'll only need *one* of the possible data types stored in that spot. Example: union Data { int i; float f; char c; }; // Can hold an int, float, OR char, but not all at once.",
        "unsigned is like telling your number, 'Hey, you're a **positive-vibes-only** kind of number!' It means this variable can *only* hold zero or positive whole numbers. The cool part? Since it doesn't need to save space for negative signs, it can store positive numbers that are twice as big as a regular 'signed' integer! Think of it as a number line that starts at zero and only goes to the right. Perfect for counting things that can't be negative, like the number of likes on your post. Example: unsigned int likes = 100000; // Can't have negative likes, right?",
        "void is like the 'nothing' or 'generic' keyword in C, used in a couple of key ways: 1. For functions like (void do_stuff()): It means this function just does something, but it doesn't **give back** any specific value or result when it's done. It's like telling your friend, 'Go close the door.' They do it, but they don't hand you anything back. 2. For pointers (void *ptr): It's like a 'mystery box' pointer. It can point to *any* type of data (an int, a float, a struct, whatever!), but you don't know *what* it's pointing to until you explicitly tell the compiler. Super flexible for generic memory handling!",
        "volatile is like putting a **'DO NOT CACHE! ALWAYS RE-READ!'** sticky note on a variable. It tells the compiler, 'Listen, this variable's value might change at *any* time, even if my code isn't directly changing it. Don't try to be smart and remember its old value; **always go back to memory and get the freshest value** every single time you need it!' This is super important for things that interact directly with hardware or other parts of the system that your code doesn't fully control, like sensor readings or shared memory in multi-threaded programs. Example: volatile int sensor_reading; // Compiler, don't optimize this, it can change unexpectedly!",
        "while is like your program's 'keep doing this AS LONG AS...' command. Imagine you're eating popcorn **while** the movie is still playing. As long as the movie is on (the condition is true), you keep eating popcorn. The moment the movie ends (the condition becomes false), you stop. It's perfect for repeating a block of code an unknown number of times, as long as a certain condition remains true. Example: while (has_popcorn) { eat_popcorn(); } // Keep munching until the bag is empty!"
    };

    // Figuring out how many tracks are on this playlist (number of keywords)
    // This is like `sizeof(keywords_playlist)` giving us the total bytes for the array,
    // and `sizeof(keywords_playlist[0])` giving us the bytes for one single 'track name'.
    // Divide them to get the total number of tracks! Simple math, fam.
    int num_keywords = sizeof(keywords_playlist) / sizeof(keywords_playlist[0]);

    printf("--------------------------------------------\n");
    printf("Yo, let's vibe through the 32 C Keywords! 🎵\n");
    printf("--------------------------------------------\n\n");

    // Loop through the arrays and print each keyword and its description
    // This 'for' loop is like hitting 'next track' on your playlist,
    // going through each keyword one by one, grabbing its name and description
    // from the corresponding spot in each list.
    for (int i = 0; i < num_keywords; i++) {
        printf("%2d. %s\n", i + 1, keywords_playlist[i]);    // Prints track number and its name
        printf("     %s\n", descriptions_playlist[i]);      // Drops the knowledge (description)
        printf("--------------------------------------------\n\n"); // Separator for that clean aesthetic
    }

    printf("That's almost everything you need to learn to use in C programming.\n");
    printf("You'll also meet so many standard library stuff that will amplify your coding abilities in the future. Trust.\n");
    printf("--------------------------------------------\n");

    return 0; // Indicates successful program execution: Main says 'Peace out!' to the OS, mission accomplished!
}

/**
 * 
 * In this approach, we are essentially allocating distinct memory spaces: 
 * one array to hold the character strings (titles/keywords) and a second array to hold their corresponding 
 * character strings (descriptions). Both arrays are then iterated through simultaneously, 
 * using the same index to ensure that each title is correctly paired and printed with its respective description.
 * 
 */