#include "stdio.h" // Your app's main "talk-to-the-world" module (like your social media API).

int main() {
    // --- The 'printf' Filter Guide: Your Data's Glow Up! ---
    printf("--- 📸 Your Data's Best Filters: The printf() Guide 📸 ---\n");
    printf("These are the filters (format specifiers) you use in printf() to make your data shine.\n");
    printf("Think of them as how you tell the app, 'Hey, print this as a whole number, different from this random text or this decimal number!'\n\n");



    // Let's drop some knowledge on the basic filters.
    // Don't confuse, for the escape sequences, we printed the \ by adding another one like \\ 
    // For % to be printed we're going to add another one too, %% 
    // Essentially printing the %something eg instead of d we shall get a %d within the output.

    printf("📊 Basic Data Filters 📊\n");
    printf("+--------+-------------------------------------------------------+\n");
    printf("| Filter | Description |\n");
    printf("+--------+-------------------------------------------------------+\n");
    printf("| %%d | Shows whole numbers (like your follower count) |\n");
    printf("| %%f | For decimals (like PI: 3.14 or your bank balance: 12500.75) |\n");



    printf("-------------------------------------------------------------------\n"); // Mid-table break for aesthetics!
    printf("| %%e  | Scientific notation—used in serious calculations. Example: 5.23e+3 (aka 5230, like estimating galaxy distances). |\n");
    printf("| %%g  | Adaptive float formatting—chooses shortest between %%f and %%e. Example: 0.00005 prints as 5e-05, but 5.23 prints as 5.23. |\n");
    printf("| %%lf | Standard float in printf (same as %%f), but in scanf, it ensures precision for doubles (bigger, more accurate decimals). |\n");



    printf("-------------------------------------------------------------------\n");
    printf("| %%o | Numbers in Octal (base-8) – for that retro tech vibe |\n");
    printf("| %%x | Numbers in Hex (base-16) – for when you're feeling hacky! |\n");
    printf("| %%i | The 'flexible' integer (auto-detects decimal, octal, hex)|\n"); // Example: `scanf("%i", &num);` can handle `42`, `052`, or `0x2A`.
    printf("| %%s | String – Your Twitter bio, Insta caption, or WiFi password (the one you always forget). |\n");
    printf("| %%u | For positive whole numbers only or Unsigned integers - yeah I know, 'unsigned sounds negative' |\n");
    printf("| %%c | For a single character (like that perfect emoji reaction or Elon Musk's child's name.) |\n");
    printf("+--------+-------------------------------------------------------+\n\n");



    // --- The '%%' Mystery: Why Double the Percent? ---
    printf("--- 🕵️‍♂️ The Case of the Double Percent (%%): A C Mystery! 🕵️‍♂️ ---\n");
    printf("Imagine you want to say 'You got 100%% of the answers right!'\n");
    printf("If you just do printf(\"You got 100% of the answers right!\");\n");
    printf("Your C compiler is gonna be like: 🤨 'Bro, '% o' what? Is that an octal number? What's going on?'\n");
    printf("It sees the first '%%' and expects a *filter* (like %%d, %%s, %%f).\n\n");
    printf("So, to tell C, 'Nope, this is just a regular percent sign bro. No special powers!',\n");
    printf("You gotta double it up! It's like an escape sequence for the percent itself.\n");
    printf("You type '%%%%' to print just '%%'.\n\n");
    printf("Example:\n");
    printf("Actual Score: 95%%\n"); // Using '%%' to print a literal percent sign. The second % is the one getting printed.
    printf("See? It printed '%%' and didn't throw a tantrum!\n");
    printf("Your battery is at 50%% and you're still on TikTok? Wild.\n"); // Another example with '%%'.

    printf("\n--- 🏁 Filter Guide: Mission Complete! 🏁 ---\n");
    printf("Now you're ready to make your data flex properly in C!\n");




    // I know someone's head is itching to try out this one:
    printf("Score: \%d", 95); 

    // Because C thinks you're trying to use a fake escape sequence — and it'll panic and throw a tantrum.😤😤
    // We don't need that coz ...
    // We're just printing %d itself, not substituting a value dynamically into it.
    // Neither do we want it to perform an action on the screen the way \t , \r and the squad usually perform.  



    printf("CPU Usage: 70%%");
    printf("Battery: 50%%");
    // Gives us Battery: 50%



    return 0; // Exits smoothly, like closing all your apps for the night.
    
}