/**
 * 
 * switch is like a smart traffic controller at a complex intersection. 
 * 
 * Instead of a bunch of if-else if-else if statements checking every single lane, 
 * 
 * switch looks at one incoming car (your variable's value) and immediately directs it down the correct, 
 * 
 * pre-defined lane (case). It's a clean way to handle multiple choices or scenarios based on a single value,
 * 
 * making your decision-making code much tidier.
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("26. switch\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'switch' is like a smart traffic controller at a complex intersection... It's a clean way to handle multiple choices or scenarios based on a single value, making your decision-making code much tidier.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int day_of_week = 3; // 1 for Monday, 2 for Tuesday, etc.

    printf("Checking the day of the week (day %d):\n", day_of_week);
    switch (day_of_week) {
        case 1:
            printf("It's Monday. Back to the grind! 😴\n");
            break;
        case 2:
            printf("It's Tuesday. Two days in! 💪\n");
            break;
        case 3:
            printf("It's Wednesday. Hump day! 🐪\n");
            break;
        case 4:
            printf("It's Thursday. Almost there! 🎉\n");
            break;
        case 5:
            printf("It's Friday. Weekend vibes! 🥳\n");
            break;
        case 6:
            printf("It's Saturday. Party time! 💃🕺\n");
            break;
        case 7:
            printf("It's Sunday. Relax and recharge. 🧘\n");
            break;
        default:
            printf("That's not a valid day of the week, fam. 🤔\n");
            break;
    }
    sleep(5);
    return 0;
}