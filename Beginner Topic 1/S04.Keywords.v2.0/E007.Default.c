/**
 * 
 * The default keyword in a switch is like the plan B you pull out when none of your options fit. 
 * 
 * It’s the catch-all, the 'else' of the switch world — if no case matches, 
 * 
 * default steps up and runs the show. No value left behind!
 * 
 */

 #include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("7. default\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'default' keyword in a switch is like the plan B you pull out when none of your options fit. It’s the catch-all, the 'else' of the switch world — if no case matches, default steps up and runs the show. No value left behind!\n");
    printf("--------------------------------------------\n");
    sleep(1);

    char user_input = 'Z'; // User typed something unexpected

    printf("Processing user input: '%c'\n", user_input);
    switch (user_input) {
        case 'A':
            printf("You chose option A.\n");
            break;
        case 'B':
            printf("You chose option B.\n");
            break;
        default:
            printf("No valid option chosen. Activating Plan B! 🤷‍♂️\n"); // Default behavior
            break;
    }
    sleep(5);
    return 0;
}