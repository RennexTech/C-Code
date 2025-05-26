// We're just printing the keyword and its description in this program, nothing big, but some sleep in between.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// I will only explain the hardest keywords with a simple example, the rest, 
// I know you're smart enough to atleast understand.
// Let's start with auto
void auto_keyword();

int main()
{
    printf("--------------------------------------------\n");
    printf("I will be printing you the 32 C Keywords\n");
    printf("--------------------------------------------\n");
    sleep(1);
    
    printf("\n");
    printf("\n");

    printf("1. auto\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("Essentially telling the compiler, 'Yo, these variables are temporary on the stack.', and compiler replies, 'Bruh, don't worry I'll clean them up. I went to Harvard for that stuff😂'. Don't use auto, its already expired unless you're in the 1980s, compiler already knows local variables are temporary. When main exits, they are destroyed.\n");
    printf("\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("2. break\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'break' keyword is like rage-quitting a loop or switch — the moment it's hit, your program says 'I'm out'. Picture the school principal sends you to dig through a stack of books. You find what you need, and you dip immediately. No need to keep searching — 'break' saw the condition was met and said, 'Mission accomplished, we out.'\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("3. case\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'case' keyword is used inside a switch when you're setting up different possible outcomes, like menu options. It's like, 'If the user picks option 1, do this. Option 2? Do that.' Each 'case' is a branch waiting for a match — when it hits, the code inside that case runs. Simple as that.\n");
    printf("\n");
    printf("The 'case' keyword is like saying, 'Alright, if this happens, here’s what we do.' It’s used inside a switch — kinda like choosing a character in a video game. Case 1? Pick Mario. Case 2? Pick Luigi. The switch checks the value and jumps to the matching case to run that code.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

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

    printf("\n");
    printf("\n");

    printf("5. const\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'const' keyword means 'hands off' — once you set a value, it’s locked. You can read it, vibe with it, print it, but you *can’t* change it. It’s like putting a sign that says ‘DO NOT TOUCH’ on a variable. Great for keeping things safe and avoiding dumb mistakes.\n");
    printf("--------------------------------------------\n");
    printf(" 'const' is like giving your variable a permanent tattoo — once it's inked, you can't change it. It locks the value down so nobody (not even future you) can mess it up by accident unless you remove the keyword. Basically, it's the compiler's way of saying, 'Don't you dare try to edit this value, bro.'\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("6. continue\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'continue' keyword is like saying, 'Skip this one, move on.' Inside a loop, it tells the program to drop the rest of the code *for that round* and jump straight to the next iteration. Perfect when you're like, 'Nah, this one’s not worth my time.'\n");
    printf("--------------------------------------------\n");
    printf("Imagine you’re a teacher who wants to skip students scoring below 50 — so you can take them for a quick chat in the staffroom😂. Your C program reads each name, but when it spots a below 50, it skips printing their name. You go back to class with the printed names, those who don’t hear their name? Staffroom, baby. 😂😂\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("7. default\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'default' keyword in a switch is like the plan B you pull out when none of your options fit. It’s the catch-all, the 'else' of the switch world — if no case matches, default steps up and runs the show. No value left behind!\n");
    // If I lost you on that explanation, default is just like an else, but used in switches. Else statement is usually used when your other conditions fail.
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("8. do\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'do' keyword kicks off a do-while loop — it’s like saying, 'I’m gonna run this code at least once, then keep going as long as the vibe (condition) is right.' Unlike other loops that check first, this one checks *after* the action, so it never misses the first round. Perfect for when you gotta do the thing before deciding if you should repeat it.\n");
    // In short, run the loop first, then check for the condition. If not met, run it again, check for the condition. 
    // The old looping checks the condition -> then decides if the loop is to be run. You see the difference? 
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("9. double\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The double keyword is used to declare a variable that can hold a floating-point number with double precision. It's commonly used to store decimal values.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("10. else\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The else keyword is used in conjunction with if statements to specify a block of code that should be executed when the condition of the if statement is false.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("11. enum\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The enum keyword is used to define an enumeration, which is a set of named integer constants. Enums provide a way to create more meaningful and self-documenting code.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("12. extern\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The extern keyword is used to declare a variable or function as being defined externally, meaning it's defined in a separate file. It's often used for global variables and functions shared across multiple files.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("13. float\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The float keyword is used to declare a variable that can hold a floating-point number with single precision.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("14. for\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The for keyword is used to initiate a for loop, which is used to repeatedly execute a block of code for a specific number of times.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("15. goto\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The goto keyword is used to transfer control to a labeled statement elsewhere in the code. It's considered bad practice in most cases due to its potential to make code difficult to understand and maintain.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("16. if\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The if keyword is used to create a conditional statement, allowing different blocks of code to be executed based on whether a given condition is true or false.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("17. int\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The int keyword is used to declare a variable that can hold an integer value.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("18. long\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The long keyword is used to declare a variable that can hold a larger range of integer values compared to int.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("19. register\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The register keyword is used to suggest that a variable should be stored in a CPU register for faster access. However, modern compilers often optimize variable storage without explicit use of register.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("20. return\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf(" The return keyword is used within functions to indicate the value that the function should return. It also terminates the function's execution and transfers control back to the calling function.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("21. short\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The short keyword is used to declare a variable that can hold a smaller range of integer values compared to int.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("22. signed\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The signed keyword is used to indicate that a variable can hold both positive and negative values. It's used to specify the sign representation for integer types.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("23. sizeof\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The sizeof keyword is used to determine the size in bytes of a particular data type or variable.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("24. static\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The static keyword is used to declare a variable or function as having static storage duration. For variables, it means the variable retains its value between function calls. For functions, it limits the scope of the function to the current file.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("25. struct\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The struct keyword is used to define a structure, which is a composite data type that groups together variables of different data types under a single name.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("26. switch\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The switch keyword is used to create a switch statement, which allows branching to different parts of code based on the value of a variable.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("27. typedef\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The typedef keyword is used to create an alias or synonym for a data type, making it easier to use complex types or to enhance code readability.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("28. union\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The union keyword is used to define a union, which is a data structure that can store different data types in the same memory location.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("29. unsigned\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The unsigned keyword is used to indicate that a variable can hold only positive values. It's used to specify the sign representation for integer types.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("30. void\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The void keyword is used to declare that a function does not return a value or to indicate the absence of a data type in certain contexts.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("31. volatile\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The volatile keyword is used to indicate to the compiler that a variable's value may change at any time, even if the compiler cannot detect such changes.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("32. while\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The while keyword is used to initiate a while loop, which repeatedly executes a block of code as long as a specified condition is true.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("--------------------------------------------\n");
    printf("That's all you need to learn to use in C programming.\n");
    printf("--------------------------------------------\n");

    printf("\n");
    printf("\n");

    return 0;
}

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

// Writing auto in C in 2025 is like emailing sending an email and saying: 

auto int first_number = 20;

// "Hey, I just wanted to let you know am emailing you...", huh? 
// The compiler already knows, unless you're in a 1980s PC.
// In short auto is saying "this is temporary" but the compiler already knows your variables are all temporary, till main exits.