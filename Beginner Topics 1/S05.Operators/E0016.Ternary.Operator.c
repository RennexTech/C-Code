#include <stdio.h>   // For printf, our program's mic.
#include <stdbool.h> // For 'bool' type and 'true'/'false' values, makes logic clearer!
#include <unistd.h>  // For sleep() to chill between outputs.

/**
 * 
 * @brief 🤔 C Ternary Operator: The Quick Decision Maker!
 *
 * @analog Ever had to make a quick "if this, then that, else this other thing"
 * decision? Like, "If it's sunny, I'll wear sunglasses; otherwise, I'll grab an umbrella."
 *
 * The ternary operator is C's slick, one-line shortcut for these simple
 * if-else scenarios, especially when you want to assign a value based on a condition.
 * It's perfect for when you need to decide between two outcomes on the fly.
 *
 * Syntax: `condition ? value_if_true : value_if_false;`
 *
 * This program will show you how this neat little operator works its magic,
 * giving you concise code that's easy to read once you get the hang of it.
 * Let's get these quick decisions sorted! 🚀
 * 
 */

int main() {
    printf("=============================================================\n");
    printf("  C Ternary Operator: The Quick Decision Maker! 🤔        \n");
    printf("=============================================================\n");
    sleep(1);

    // --- Example 1: Simple Age Check ---
    printf("\n--- Example 1: Simple Age Check (Are you an adult?) ---\n");
    printf("    @analog: 'Am I 18 or older? If yes, I'm an adult. Else, I'm a minor.'\n");
    sleep(1);

    int myAge = 20;
    char *ageStatus = (myAge >= 18) ? "Adult ✅" : "Minor ❌"; // This is the ternary magic!
    printf("    My age: %d\n", myAge);
    printf("    Status: %s\n", ageStatus); // 'ageStatus' gets "Adult ✅" because 20 >= 18 is true.
    sleep(2);

    int kidAge = 15;
    char *kidStatus = (kidAge >= 18) ? "Adult ✅" : "Minor ❌";
    printf("    Kid's age: %d\n", kidAge);
    printf("    Status: %s\n", kidStatus); // 'kidStatus' gets "Minor ❌" because 15 >= 18 is false.
    sleep(2);

    // --- Example 2: Determining Max Value (Who's Bigger?) ---
    printf("\n--- Example 2: Determining Max Value (Who's the GOAT? 🐐) ---\n");
    printf("    @analog: 'Is Player A's score higher than Player B's? If yes, A is GOAT. Else, B is GOAT.'\n");
    sleep(1);

    int scoreA = 150;
    int scoreB = 120;
    int maxScore = (scoreA > scoreB) ? scoreA : scoreB; // If scoreA > scoreB is true, maxScore = scoreA, else maxScore = scoreB.
    printf("    Score A: %d, Score B: %d\n", scoreA, scoreB);
    printf("    The max score is: %d\n", maxScore); // maxScore is 150.
    sleep(2);

    int newScoreA = 90;
    int newScoreB = 180;
    int newMaxScore = (newScoreA > newScoreB) ? newScoreA : newScoreB;
    printf("    New Score A: %d, New Score B: %d\n", newScoreA, newScoreB);
    printf("    The new max score is: %d\n", newMaxScore); // newMaxScore is 180.
    sleep(2);

    // --- Example 3: Simple Pass/Fail Grade ---
    printf("\n--- Example 3: Simple Pass/Fail Grade (Did you pass the vibe check? ✔️) ---\n");
    printf("    @analog: 'Is my grade 70 or higher? If yes, I passed. Else, I failed.'\n");
    sleep(1);

    int myGrade = 75;
    char *gradeResult = (myGrade >= 70) ? "PASS! 🎉" : "FAIL! 😭";
    printf("    My grade: %d\n", myGrade);
    printf("    Result: %s\n", gradeResult);
    sleep(2);

    int failGrade = 60;
    char *failResult = (failGrade >= 70) ? "PASS! 🎉" : "FAIL! 😭";
    printf("    My fail grade: %d\n", failGrade);
    printf("    Result: %s\n", failResult);
    sleep(2);

    // --- Example 4: Outputting directly in printf ---
    printf("\n--- Example 4: Using Ternary Directly in printf (Super concise!) ---\n");
    printf("    @analog: Saying 'It's sunny' or 'It's rainy' directly in a sentence.\n");
    sleep(1);

    bool isRaining = true;
    printf("    Is it raining? %s\n", isRaining ? "Yes, grab the umbrella! ☔" : "No, let's go outside! ☀️");
    sleep(2);

    bool isSunny = false; // Let's pretend it's not sunny
    printf("    Is it sunny? %s\n", isSunny ? "Yes, shades on! 😎" : "Nah, cloudy today. ☁️");
    sleep(2);

    printf("\n--- The Takeaway: Concise Decisions! 🤯 ---\n");
    printf("    The ternary operator is awesome for short, conditional assignments or expressions.\n");
    printf("    It's like the 'if-else' statement's cooler, more compact sibling.\n");
    printf("    Use it when your decision is simple and you just need one of two outcomes. Keep it clean! 💯\n");
    sleep(2);

    printf("=============================================================\n");
    printf("You just mastered the C Ternary Operator! Your code is leveling up! ⬆️\n");
    printf("=============================================================\n");

    return 0; // Program finished successfully. GG! 🎮
}
