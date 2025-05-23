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
    printf("| %%d | For whole numbers (like your follower count or streak) |\n");
    printf("| %%f | For decimals (like your GPA or discount on that drip) |\n");
    printf("-------------------------------------------------------------------\n"); // Mid-table break for aesthetics!
    printf("| %%e | Big/small decimals (scientific notation, like crypto gains) |\n");
    printf("| %%g | Smart decimal! Uses shortest form (like a smart casual outfit) |\n");
    printf("| %%lf | Same as %%f in printf. (But in scanf, it's serious biz – double the float fun!) |\n");
    printf("-------------------------------------------------------------------\n");
    printf("| %%o | Numbers in Octal (base-8) – for that retro tech vibe |\n");
    printf("| %%x | Numbers in Hex (base-16) – for when you're feeling hacky! |\n");
    printf("| %%i | The 'flexible' number filter (auto-detects decimal, octal, hex) |\n");
    printf("| %%s | For text/words (your fire caption, a trending hashtag) |\n");
    printf("| %%u | For positive whole numbers only (like a never-negative score) |\n");
    printf("| %%c | For a single character (like that perfect emoji reaction) |\n");
    printf("+--------+-------------------------------------------------------+\n\n");

    // --- The '%%' Mystery: Why Double the Percent? ---
    printf("--- 🕵️‍♂️ The Case of the Double Percent (%%): A C Mystery! 🕵️‍♂️ ---\n");
    printf("Imagine you want to say 'You got 100%% of the answers right!'\n");
    printf("If you just do printf(\"You got 100% of the answers right!\");\n");
    printf("Your C compiler is gonna be like: 🤨 'Bro, '% o' what? Is that an octal number? What's going on?'\n");
    printf("It sees the first '%%' and expects a *filter* (like %%d, %%s, %%f).\n\n");
    printf("So, to tell C, 'Nah, this is just a regular percent sign, fam. No special powers!',\n");
    printf("You gotta double it up! It's like an escape sequence for the percent itself.\n");
    printf("You type '%%%%' to print just '%%'.\n\n");
    printf("Example:\n");
    printf("Actual Score: 95%%\n"); // Using '%%' to print a literal percent sign.
    printf("See? It printed '%%' and didn't throw a fit!\n");
    printf("Your battery is at 50%% and you're still on TikTok? Wild.\n"); // Another example with '%%'.

    printf("\n--- 🏁 Filter Guide: Mission Complete! 🏁 ---\n");
    printf("Now you're ready to make your data flex properly in C!\n");




    // I know someone's head is itching to try out this one:
    printf("Score: \%d", 95); 

    // Because C thinks you're trying to use a fake escape sequence — and it'll panic and throw a tantrum.😤😤
    // We don't need that coz ...
    // We're just printing %d not substituting a value dynamically into it.
    // Neither do we want it to perform an action on the screen the way \t , \r and the squad usually perform.  



    printf("CPU Usage: 70%%");
    printf("Battery: 50%%");
    // Gives us Battery: 50%



    return 0; // Exits smoothly, like closing all your apps for the night.
    
}