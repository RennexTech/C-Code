/**
 * Hope you finished E002.Functions.c
 * 
 * We're just printing the keyword and its description in this program, nothing big 
 * 
 * and we introduce time.h for sleeping, the compiler needs to chill between prints😫 
 * 
 * He's going to be doing a lot of printing work.
 * 
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("--------------------------------------------\n");
    printf("I will be printing you the 32 C Keywords\n");
    printf("--------------------------------------------\n");
    sleep(1);
    


    printf("\n\n");

//=====================================================================================

    printf("1. auto\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("Essentially telling the compiler, 'Yo, these variables are temporary on the stack.', and compiler replies, 'Bruh, don't worry I'll clean them up. I went to Harvard for that stuff😂'. Don't use auto, its already expired unless you're in the 1980s, compiler already knows local variables are temporary. When main exits, they are destroyed.\n");
    printf("\n");
    printf("--------------------------------------------\n");
    sleep(5);

    // (Heads-up: C doesn't support nested functions by default — this is just for laughs and learning.)
    // If you dare use nested functions like me, 🤤 It's like feeding your compiler alcohol, it just laughs and says "who gave this bastard an IDE!😂"
    // Am adding functions inside the main function for explanation.
    // Over here, both x and y are stored in the stack, and both vanish after main() ends.
    // Auto keyword here does nothing different because local variables are auto by default.
    void simple_auto_keyword()
    {
        printf("Am auto, let me tell you what I usually do in C Programming.\n");
        auto int x = 10; // auto is optional, local variables are auto by default.
        int y = 20; // same thing, just without auto
        printf("x: %d\n", x);
        printf("y: %d\n", y);

    }

    // Writing auto in C in 2025 is like sending an email and saying: 

    auto int first_number = 20;

    // "Hey, I just wanted to let you know am emailing you...", huh? 
    // The compiler already knows, unless you're in a 1980s PC. Auto is obsolete😴.
    // In short auto is saying "this is temporary" but the compiler already knows your variables are all temporary, till main exits.



    printf("\n\n");

//=====================================================================================

    printf("2. break\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'break' keyword is like rage-quitting a loop or switch — the moment it's hit, your program says 'I'm out'. Picture the school principal sends you to dig through a stack of books. You find what you need, and you dip immediately. No need to keep searching — 'break' saw the condition was met and said, 'Mission accomplished, we out.'\n");
    printf("--------------------------------------------\n");
    sleep(5);



    printf("\n\n");

//=====================================================================================

    printf("3. case\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'case' keyword is used inside a switch when you're setting up different possible outcomes, like menu options. It's like, 'If the user picks option 1, do this. Option 2? Do that.' Each 'case' is a branch waiting for a match — when it hits, the code inside that case runs. Simple as that.\n");
    printf("\n");
    printf("The 'case' keyword is like saying, 'Alright, if this happens, here’s what we do.' It’s used inside a switch — kinda like choosing a character in a video game. Case 1? Pick Mario. Case 2? Pick Luigi. The switch checks the value and jumps to the matching case to run that code.\n");
    printf("--------------------------------------------\n");
    sleep(5);



    printf("\n\n");


//=====================================================================================

    printf("4. char\n");
    sleep(1);
    printf("--------------------------------------------\n");
    // This definition is something a compiler would say in an interview, not me and you.
    printf("The char keyword is used to declare a variable that can hold a single character. It's often used to represent characters or small integers.\n");
    printf("\n");
    // This is how we speak!😤😤
    printf("The 'char' keyword used to declare variables that hold a single character — it only holds one character, like 'A' or '🥱'. You use it when you don’t need a whole essay (aka strings), just a tiny piece of text or emoji😶. It's cute, compact, and exactly 1 byte — small but mighty.\n");
    printf("--------------------------------------------\n");
    sleep(5);



    printf("\n\n");

//=====================================================================================

    printf("5. const\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'const' keyword means 'hands off!😤' — once you set a value, it’s locked. You can read it, vibe with it, print it, but you *can’t* change it. It’s like putting a sign that says ‘DO NOT TOUCH’ on a variable. Great for keeping things safe and avoiding dumb mistakes.\n");
    printf("--------------------------------------------\n");
    printf(" 'const' is like giving your variable a permanent tattoo — once it's inked, you can't change it. It locks the value down so nobody (not even future you) can mess it up by accident unless you remove the keyword. Basically, it's the compiler's way of saying, 'Don't you dare try to edit this value, bro.'\n");
    sleep(5);



    printf("\n\n");

//=====================================================================================

    printf("6. continue\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'continue' keyword is like saying, 'Skip this one, move on.' Inside a loop, it tells the program to drop the rest of the code *for that round* and jump straight to the next iteration. Perfect when you're like, 'Nah, this one’s not worth my time.'\n");
    printf("--------------------------------------------\n");
    printf("Imagine you’re a teacher who wants to skip students scoring below 50 — so you can take them for a quick chat in the staffroom😂. Your C program reads each name, but when it spots a below 50, it skips printing their name. You go back to class with the printed names, those who don’t hear their name? Staffroom, baby. 😂😂\n");
    sleep(5);



    printf("\n\n");

//=====================================================================================

    printf("7. default\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'default' keyword in a switch is like the plan B you pull out when none of your options fit. It’s the catch-all, the 'else' of the switch world — if no case matches, default steps up and runs the show. No value left behind!\n");
    // If I lost you on that explanation, default is just like an else, but used in switches. Else statement is usually used when your other conditions fail.
    printf("--------------------------------------------\n");
    sleep(5);



    printf("\n\n");

//=====================================================================================

    printf("8. do\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'do' keyword kicks off a do-while loop — it’s like saying, 'I’m gonna run this code at least once, then keep going as long as the vibe (condition) is right.' Unlike other loops that check first, this one checks *after* the action, so it never misses the first round. Perfect for when you gotta do the thing before deciding if you should repeat it.\n");
    // In short, run the loop first, then check for the condition. If not met, run it again, check for the condition. 
    // The old looping checks the condition -> then decides if the loop is to be run. You see the difference? 
    printf("--------------------------------------------\n");
    sleep(5);


    printf("\n\n");

//=====================================================================================

    printf("9. double\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'double' keyword is your go-to when you need to store decimal numbers with extra precision — like money, scientific data, or anything where you can’t afford to lose detail. It’s basically a high-def floating-point number.\n");
    printf("--------------------------------------------\n");
    sleep(5);



    printf("\n\n");

//=====================================================================================

    printf("13. float\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'float' is for when you want to store decimal numbers but don’t need crazy precision like doubles, I call him, 'chilled-out double' or 'doubles little bro' — it’s the lightweight cousin of double. Think of it as the ‘fast and loose’ way to handle decimals when you’re chillin’ and don’t need full HD.\n");    
    printf("--------------------------------------------\n");
    sleep(5);


    
    printf("\n\n");

//=====================================================================================

    printf("10. else\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'else' keyword is like the plan B for your if statement. When the 'if' or 'else if' conditions fail, 'else' jumps in and says, 'Alright, here’s what happens next because these two brothers of mine failed to execute.' It’s your way to cover all the bases and keep the code flowing.\n");
    printf("--------------------------------------------\n");
    sleep(5);



    printf("\n\n");


//=====================================================================================

    printf("--------------------------------------------\n");
    printf("11. enum\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'enum' keyword lets you give meaningful names to numbers, turning cryptic digits into clear labels.\n");
    printf("Imagine you're coding a traffic light. Instead of saying:\n");
    printf("  'If light_state == 0, turn red.'\n");
    printf("  'If light_state == 1, turn yellow.'\n");
    printf("  'If light_state == 2, turn green.'\n");
    printf("which is super easy to mess up or forget what 0, 1, or 2 means...\n");
    printf("You use 'enum' to define:\n");
    printf("  'RED = 0,'\n");
    printf("  'YELLOW = 1,'\n");
    printf("  'GREEN = 2.'\n");
    printf("Now, your code says:\n");
    printf("  'If light_state == RED, turn red.'\n");
    printf("  'If light_state == GREEN, turn green.'\n");
    printf("See? It's like having a clear, self-explaining menu for your numbers. Makes your code infinitely easier to read, understand, and debug, so you don't have to guess what '1' was supposed to be!\n");
    printf("--------------------------------------------\n");
    sleep(5);

    // In C, its illegal to define a function inside another one like I have done here!!😤😤
    // Some compilers like GCC have non standard extension that allow nested functions, 
    // ... but why even use that if your program will refuse to compile when you switch your compiler?
    // Just stick to separate functions, separate jobs.

    // Define your squad of named constants
    enum GameState { PLAYING, PAUSED, GAME_OVER };

    int enum_example() 
    {
        enum GameState state = PAUSED;  // WAY better than "state = 1"

        if (state == PLAYING) {
            printf("Game is running! 🎮\n");
        } 
        else if (state == PAUSED) {
            printf("Game paused! ⏸️\n");  // See? No magic numbers!
        }
    
        return 0;
    }

    // Atleast you have an idea now... we'll use them later on.



    printf("\n\n");


//=====================================================================================

    printf("--------------------------------------------\n");
    printf("12. extern\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'extern' is like working in a **big workshop with different teams, each with their own workbench (C file)**.\n");
    printf("Each team has its own tools, but there's **one super expensive, specialized laser cutter** (a global variable or a complex function) that *everyone* needs to use. You don't buy a laser cutter for every single workbench, right?\n");
    printf("Instead, extern is like putting a sign on your workbench that says: **'For the Laser Cutter, see the main fabrication room.'**\n");
    printf("It tells your compiler, 'Hey, this laser_cutter thing? It exists! It's defined and set up *somewhere else* in the workshop. Just know it's there, and we'll link up to it later.'\n");
    printf("This lets all teams (files) access that one single, powerful tool without having to copy or rebuild it themselves. Super efficient for sharing resources!\n");
    printf("--------------------------------------------\n");
    sleep(5);


//=====================================================================================

    printf("\n\n");


    printf("14. for\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("for is the C way of saying: 'Yo, do this exact thing over and over till I say stop.'\n");
    printf("Syntax: for(start; condition; update)\n");
    printf("Real life: for(int i = 0; i < 10; i++) → Like doing 10 pushups, one rep at a time.\n");
    printf("The moment condition goes false? Boom. You’re done. No gym, no gain.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");


//=====================================================================================

    printf("15. goto\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("goto is like rage-quitting structured code.\n");
    printf("It jumps to a label somewhere else, like teleporting mid-function — total chaos.\n");
    printf("Real life: Like walking out of a convo and reappearing in your ex’s DMs. Just WHY?? 😭\n");
    printf("We don’t use it unless we’re writing spaghetti... or debugging hell.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    // Example using goto
    #include <stdio.h>
    #include <unistd.h>  // for sleep()

    // A void function showing goto in action
    void goto_demo(int num) {
        printf("Starting goto_demo with num = %d\n", num);

        if (num < 0) {
            goto handle_negative;
        }

        printf("Number is non-negative, keep calm and carry on.\n");
        printf("Doing some important work...\n");
        sleep(1);
        printf("Finished important work!\n");
        goto end;  // skip the negative handler

    handle_negative:
        printf("Whoa! Negative number alert 🚨, aborting normal flow.\n");
        printf("Skipping to safe zone...\n");

    end:
        printf("End of goto_demo, peace out.\n");
    }

    int main() {
        printf("Calling goto_demo with 5:\n");
        goto_demo(5);

        printf("\nCalling goto_demo with -3:\n");
        goto_demo(-3);

        return 0;
    }

//=====================================================================================

    printf("\n\n");

    printf("16. if\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("if is the decision-maker, the bouncer at the logic club.\n");
    printf("You give it a condition, and if it's true, it lets your code in.\n");
    printf("Real life: if (baby_is_hungry) → eat(); else → cry();\n");
    printf("Clean, direct, no unnecessary drama. Unless you're nesting 5 levels deep 😅\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n"); 

    /**
     * 
     *  You can also do it
     *  printf("\n");
     *  printf("\n");
     * 
     *  But coding is about simplicity and functionality, just use:
     *  printf("\n\n");
     * 
     */

    
//=====================================================================================

    printf("17. int\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("int is how you declare you want an integer variable. Like saying:\n");
    printf("'Yo compiler, I need a number — no decimals, just raw, whole number.'\n");
    printf("Real life: int age = 24; // That's you. No floating points.\n");
    printf("Memory-wise? 4 bytes of memory space (usually), living on the stack rent-free.\n");
    printf("--------------------------------------------\n");
    sleep(5);


    printf("\n\n");

    
//=====================================================================================

    printf("--------------------------------------------\n");
    printf("18. long\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'long' is like int's bigger, buff cousin.\n");
    printf("You know how 'int' is great for regular whole numbers? Well, 'long' is for when your numbers get absolutely *massive* – like trying to count every single pixel on your 8K monitor, or maybe the total number of bytes on all your hard drives combined.\n");
    printf("If a regular 'int' box isn't big enough, you use 'long' so your number doesn't overflow and crash your program. It grabs more memory bytes to fit those colossal values.\n");
    printf("For example, if you were storing a really huge number of 'long_distance_calls', you'd use 'long':\n");
    printf("    long really_big_number_of_calls = 2000000000L; // That 'L' tells C it's a long number!\n");
    printf("--------------------------------------------\n");
    sleep(5);
    printf("\n\n");


//=====================================================================================

    printf("--------------------------------------------\n");
    printf("19. register\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'register' is like telling your CPU, 'Yo, this variable is a VIP! Keep it right next to you in your fastest memory lane (a register), 'cause I'm gonna be grabbing it constantly!'\n");
    printf("Back in the old days, it was like giving your variable a special fast-pass ticket for super-speedy access. But honestly, modern compilers are so smart, they're like, 'Chill, I got this.' They usually put important variables in registers anyway if it makes sense, without you even asking.\n");
    printf("So, typing register today is usually **just a suggestion** that the compiler often ignores or does on its own. You rarely need it.\n");
    printf("Example: register int loop_counter; // The compiler might or might not put this in a register.\n");
    printf("--------------------------------------------\n");
    sleep(5);

//=====================================================================================

    printf("20. return\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'return' is your function's way of saying, 'Alright, my part in this show is done! Here's the final result (if any), and then **peace out!**'\n");
    printf("It immediately kicks you out of the current function and sends whatever value you specify back to whoever called it. Think of it like finishing a text message and hitting 'send' – once it's sent, you're done with that message, no rewrites or edits.\n");
    printf("Example: int add(int a, int b) { return a + b; } // Adds the numbers and then bounces.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

   /**
     * ---
     * The Function's Grand Exit (return)
     *
     * int add(int a, int b)
     *  {
     *     return a + b;
     *  }
     *
     * The return keyword is the function's way of saying,
     * "Alright, I'm out! Here's the final answer you asked for, and then **peace out!** 🏃‍♀️💨"
     *
     * So, if you call add(500, 700) from main, this add function will:
     * 
     * 1. Do the addition (500 + 700 = 1200).
     * 2. return that answer (1200) directly back to wherever it was called (in main or any other function).
     * 3. Immediately exit itself. Any code written *after* the return statement, will never run! The compiler just adds it to trash🚮🚮and gives you a kiss 💋 so you stop being silly next time...😂
     *
     * ---
     * Main finishes its exams, comes home to mamaOS(Windows, Linux, Mac) with his Report Card (return 0 or return 1;)
     *
     * Main's return isn't just like other functions'. It's a special return...
     * 
     * Mama Operating System takes the report card and checks: 
     *
     * return 0; My son succeeded this term😎 || Everything ran smoothly, all good here. ✅" (Success!)
     * return 1(or any non-zero number); Ooh my goodness, my son bite dust in the finals🤣 : This tells the OS, "Uh oh, something went wrong during execution! ⚠️" (Failure/Error!)
     *
     * Once main returns, the OS takes over, tidies up the program's memory, and gracefully ends the process, deletes the process control blocks and all its children.
     *
     */

//=====================================================================================

    printf("21. short\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'short' is like 'int' but on a **strict diet** – smaller range, smaller memory footprint.\n");
    printf("It's perfect for when you're counting things that won't go super high (like the number of people in a small room, or a low score in a game) and you're trying to save every precious byte of memory. Less bulk, still counts!\n");
    printf("Example: short tiny_score = 100; // Uses less bytes, for when memory is tight.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");


//=====================================================================================

    printf("22. signed\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'signed' is like telling your number, 'You can be **positive, negative, or zero** – you've got options!' It's the default for 'int' anyway, so usually you don't even need to type it.\n");
    printf("Think of it as a number line that goes both ways: into the positives and into the negatives. If you're tracking temperature, for example, you'd want it to be 'signed' because winter's coming and it might hit -10 degrees!\n");
    printf("Example: signed int current_temp = -5; // Can handle both hot and cold vibes.\n");
    printf("--------------------------------------------\n");
    sleep(5);


    printf("\n\n");


//=====================================================================================

    printf("23. sizeof\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'sizeof' is like your program's **built-in measuring tape**.\n");
    printf("It tells you exactly how much space (in bytes) a variable or a data type takes up in your computer's memory. Need to know if your 'int' is a tiny sticky note or a bigger box? sizeof will give you the exact dimensions.\n");
    printf("It's super handy when you're trying to manage memory efficiently or work with complex data structures.\n");
    printf("Example: printf(\"Size of int: %%zu bytes\\n\", sizeof(int)); // Tells you how much space an int needs.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

//=====================================================================================

    printf("24. static\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'static' is a bit of a chameleon, doing different cool things depending on where you use it:\n");
    printf("1. **For variables inside a function:** Imagine a **secret whiteboard in a meeting room** (your function). What's written on it (static variable) *stays there* and remembers its value, even after everyone leaves the room and comes back later for another meeting. It's unique to *that* room, but its content persists across visits.\n");
    printf("2. **For variables or functions outside any function (global):** It's like making a **secret club** for that variable or function. Only code within *this specific file* can see or use it. Other files can't peek inside your club, keeping things private and organized.\n");
    printf("It's all about controlling how long things stick around and who gets to see them.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

//=====================================================================================

    printf("25. struct\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'struct' is like creating your own **customized 'profile card' or 'data packet'**.\n");
    printf("You know how a person has a name (text), an age (number), and a height (decimal)? Instead of keeping these as separate, loose pieces of info, 'struct' lets you bundle them all up under one single, neat label, like 'Person'.\n");
    printf("It's super useful for organizing related bits of data into one logical unit, making your code way cleaner and easier to manage complex information.\n");
    printf("Example: struct Car { char brand[50]; int year; float price; }; // A blueprint for a car's details.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

//=====================================================================================

    printf("26. switch\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'switch' is like a **smart traffic controller at a complex intersection**.\n");
    printf("Instead of a bunch of 'if-else if-else if' statements checking every single lane, 'switch' looks at one incoming car (your variable's value) and immediately directs it down the correct, pre-defined lane (case).\n");
    printf("It's a clean way to handle multiple choices or scenarios based on a single value, making your decision-making code much tidier.\n");
    printf("Example: switch (day_of_week) { case MONDAY: // code for Monday; break; ... } // Directs traffic based on the day.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

//=====================================================================================

    printf("27. typedef\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'typedef' is like creating your own **custom, easy-to-remember nicknames** for complex data types.\n");
    printf("Imagine you have a super long, complicated title like 'Unsigned Long Long Integer'. Instead of writing that out every single time, 'typedef' lets you say: 'From now on, let's just call that BigNumber.'\n");
    printf("It makes your code way more readable and easier to manage, especially when dealing with fancy data structures or pointers. It's all about making your code look cleaner and more professional.\n");
    printf("Example: typedef unsigned long long BigNumber; // Now you can just use BigNumber instead of the long version.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

//=====================================================================================

    printf("28. union\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'union' is like a **special, space-saving storage box** that can hold *different kinds of items*, but **only one at a time**.\n");
    printf("Think of a single memory slot that can be used to store either a whole number (an int), or a decimal number (a float), or even a character (a char). But if you put the int in, the float that was there before is gone.\n");
    printf("It's used when you need to save memory and you know that at any given moment, you'll only need *one* of the possible data types stored in that spot.\n");
    printf("Example: union Data { int i; float f; char c; }; // Can hold an int, float, OR char, but not all at once.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

//=====================================================================================

    printf("29. unsigned\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'unsigned' is like telling your number, 'Hey, you're a **positive-vibes-only** kind of number!'\n");
    printf("It means this variable can *only* hold zero or positive whole numbers. The cool part? Since it doesn't need to save space for negative signs, it can store positive numbers that are twice as big as a regular 'signed' integer!\n");
    printf("Think of it as a number line that starts at zero and only goes to the right. Perfect for counting things that can't be negative, like the number of likes on your post.\n");
    printf("Example: unsigned int likes = 100000; // Can't have negative likes, right?\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");


//=====================================================================================

    printf("30. void\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'void' is like the **'nothing' or 'generic'** keyword in C, used in a couple of key ways:\n");
    printf("1. **For functions (like void do_stuff()):** It means this function just *does* something, but it doesn't **give back** any specific value or result when it's done. It's like telling your friend, 'Go close the door.' They do it, but they don't hand you anything back.\n");
    printf("2. **For pointers (void *ptr):** It's like a **'mystery box' pointer**. It can point to *any* type of data (an int, a float, a struct, whatever!), but you don't know *what* it's pointing to until you explicitly tell the compiler. Super flexible for generic memory handling!\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

//=====================================================================================

    printf("31. volatile\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'volatile' is like putting a **'DO NOT CACHE! ALWAYS RE-READ!'** sticky note on a variable.\n");
    printf("It tells the compiler, 'Listen, this variable's value might change at *any* time, even if my code isn't directly changing it. Don't try to be smart and remember its old value; **always go back to memory and get the freshest value** every single time you need it!'\n");
    printf("This is super important for things that interact directly with hardware or other parts of the system that your code doesn't fully control, like sensor readings or shared memory in multi-threaded programs.\n");
    printf("Example: volatile int sensor_reading; // Compiler, don't optimize this, it can change unexpectedly!\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

//=====================================================================================

    printf("32. while\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'while' is like your program's **'keep doing this AS LONG AS...'** command.\n");
    printf("Imagine you're eating popcorn **while** the movie is still playing. As long as the movie is on (the condition is true), you keep eating popcorn. The moment the movie ends (the condition becomes false), you stop.\n");
    printf("It's perfect for repeating a block of code an unknown number of times, as long as a certain condition remains true.\n");
    printf("Example: while (has_popcorn) { eat_popcorn(); } // Keep munching until the bag is empty!\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n\n");

    printf("--------------------------------------------\n");
    printf("That's all you need to learn to use in C programming.\n");
    printf("--------------------------------------------\n");

    printf("\n\n");

    return 0;
}
