#include <stdio.h>   // Standard input/output library: Our program's mic and speaker, gotta have it!
#include <stdlib.h>  // For general utilities (like exit, if we ever needed to bail out).
#include <unistd.h>  // For sleep() to chill between outputs, keep the flow smooth.

/**
 * @brief 🎮 C Control Flow: The Code's Vibe Check & Decision-Making
 *
 * @analog Imagine your code is a choose-your-own-adventure game.
 * Control statements are the rules that decide where the story goes next!
 * They dictate:
 * 1. **Which path to take** (conditional statements like `if`, `switch`).
 * 2. **How many times to repeat an action** (loops like `while`, `for`, `do-while`).
 * 3. **When to bail out or skip ahead** (`break`, `continue`, `goto`).
 *
 * This program is your playground to see all these decision-makers and loop masters
 * in action. Get ready to control the flow like a boss! 🕹️
 */

int main() {
    int a = 10, b = 5, c = 20;
    int value = 2; // For switch example
    int i, j;      // Loop counters
    int result;    // For ternary operator
    int *ptr = NULL; // For short-circuit evaluation example (it's NULL, so it's a trap!)

    printf("=============================================================\n");
    printf("C Control Flow: Making Your Code Make Decisions! 🧠\n");
    printf("=============================================================\n");
    sleep(1);



    // --- if Statement: The Basic Vibe Check ---
    printf("\n--- if Statement: The Basic Vibe Check 🤔 ---\n");
    printf("    @analog: 'If the pizza is here, eat it!' Simple, direct.\n");
    if (a > b) { // Is 10 > 5? Yes, it is!
        printf("    'a' is definitely bigger than 'b'. Pizza's here! 🍕\n");
    }
    sleep(1);



    // --- if-else Statement: Two Paths, One Choice ---
    printf("\n--- if-else Statement: Two Paths, One Choice 🛣️ ---\n");
    printf("    @analog: 'If it's sunny, go outside. ELSE, play video games.'\n");
    if (a < b) { // Is 10 < 5? Nah, that's cap.
        printf("    'a' is less than 'b'. (This won't print)\n");
    } else { // So, we go here!
        printf("    'a' is NOT less than 'b'. Video game time! 🎮\n");
    }
    sleep(1);



    // --- if-else if-else Statement: Multiple Paths, One Destination ---
    printf("\n--- if-else if-else Statement: Multiple Paths, One Destination 🚦 ---\n");
    printf("    @analog: 'If it's a Monday, groan. ELSE IF it's Friday, party! ELSE, it's just another day.'\n");
    if (a > c) { // Is 10 > 20? Nope.
        printf("    'a' is greater than 'c'. (Won't print)\n");
    } else if (a == b) { // Is 10 == 5? Nah.
        printf("    'a' is equal to 'b'. (Won't print)\n");
    } else { // Since neither was true, we land here.
        printf("    Neither condition was true. Just another day, I guess. 🤷‍♀️\n");
    }
    sleep(1);



    // --- switch Statement: Picking Your Character ---
    printf("\n--- switch Statement: Picking Your Character! 🕹️ ---\n");
    printf("    @analog: You pick a character in a game (1 for Mario, 2 for Luigi). The game instantly jumps to your choice.\n");
    switch (value) { // 'value' is 2
        case 1:
            printf("    You picked Character 1. (Won't print)\n");
            break; // Don't forget break, or it'll keep running!
        case 2:
            printf("    You picked Character 2: Luigi! Let's-a go! 🍄\n");
            break; // This stops it from "falling through" to case 3.
        case 3:
            printf("    You picked Character 3. (Won't print)\n");
            break;
        default:
            printf("    You picked something else. (Won't print)\n");
    }
    sleep(1);



    // --- while Loop: Keep Doing This AS LONG AS... ---
    printf("\n--- while Loop: Keep Doing This AS LONG AS... 🔄 ---\n");
    printf("    @analog: Eating popcorn WHILE the movie is still playing. You stop when the movie ends.\n");
    i = 0;
    while (i < 3) { // As long as 'i' is less than 3...
        printf("    While loop iteration: %d (Still munching popcorn!)\n", i);
        i++; // Don't forget to update 'i', or it's an infinite movie!
    }
    sleep(1);



    // --- do-while Loop: Do It At Least Once, Then Check ---
    printf("\n--- do-while Loop: Do It At Least Once, Then Check! ✅ ---\n");
    printf("    @analog: You try on a shirt (do it once), THEN check if it fits. If it doesn't, you try another.\n");
    i = 0;
    do { // This block runs AT LEAST ONCE, even if 'i' starts at 100.
        printf("    Do-while loop iteration: %d (Trying on shirts!)\n", i);
        i++;
    } while (i < 3); // Check condition AFTER the first run.
    sleep(1);



    // --- for Loop: Do It A Fixed Number of Times ---
    printf("\n--- for Loop: Do It A Fixed Number of Times! 🏃 ---\n");
    printf("    @analog: Doing 3 push-ups. You know exactly how many reps you need.\n");
    for (i = 0; i < 3; i++) { // (Start; Condition; Update)
        printf("    For loop iteration: %d (One more push-up!)\n", i);
    }
    sleep(1);



    // --- break Statement: Rage-Quit the Loop! ---
    printf("\n--- break Statement: Rage-Quit the Loop! 🚪💨 ---\n");
    printf("    @analog: You're searching for your phone. The moment you find it, you STOP searching, no matter what.\n");
    for (i = 0; i < 5; i++) {
        if (i == 3) { // When 'i' hits 3...
            printf("    Found my phone at i = %d! Breaking loop. I'm out! 🏃💨\n", i);
            break; // Exits the loop IMMEDIATELY. Nothing else in this loop runs.
        }
        printf("    Searching... (Break loop iteration: %d)\n", i);
    }
    sleep(1);



    // --- continue Statement: Skip This Round! ---
    printf("\n--- continue Statement: Skip This Round! ⏭️ ---\n");
    printf("    @analog: You're grading papers. If a paper is blank, you skip it and move to the next one. You don't stop grading entirely.\n");
    for (i = 0; i < 5; i++) {
        if (i == 2) { // When 'i' hits 2...
            printf("    Paper is blank at i = %d. Skipping this one. Next! 📄➡️\n", i);
            continue; // Skips the rest of the code in *this* iteration, goes to the next 'i'.
        }
        printf("    Grading paper: %d\n", i);
    }
    sleep(1);



    // --- Nested Loops: Loops Within Loops ---
    printf("\n--- Nested Loops: Loops Within Loops! 🌀 ---\n");
    printf("    @analog: Like a clock (outer loop for hours) with a minute hand (inner loop for minutes).\n");
    for (i = 0; i < 2; i++) { // Outer loop (hours)
        for (j = 0; j < 2; j++) { // Inner loop (minutes)
            printf("    Outer i: %d (Hour), Inner j: %d (Minute)\n", i, j);
        }
    }
    sleep(1);



    // --- Loop Labels (goto Statement): The Teleport Button (Use with Caution!) ---
    printf("\n--- Loop Labels (goto Statement): The Teleport Button (Use with Caution!) ⚠️ ---\n");
    printf("    @analog: Hitting a 'teleport' button that zaps you to a specific spot in your code.\n");
    printf("    Generally, avoid 'goto' in modern C. It can make your code messy and hard to follow (spaghetti code!).\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                printf("    Whoa! Jumping out of nested loops using goto. 🚀\n");
                goto exit_loops; // Zaps execution to the 'exit_loops' label.
            }
            printf("    Goto loop: i=%d, j=%d\n", i, j);
        }
    }


exit_loops: // This is the 'label' where goto jumps to.
    printf("    Exited loops via goto. Made it out alive! 😮‍💨\n");
    sleep(1);



    // --- Switch Fallthrough: When You Forget Your Break! ---
    printf("\n--- Switch Fallthrough: When You Forget Your Break! 🤦‍♀️ ---\n");
    printf("    @analog: You pick a character, but the game keeps loading the next character too because you forgot to press 'Stop'.\n");
    printf("    If you don't use 'break' in a switch case, execution 'falls through' to the next case.\n");
    switch (value) { // 'value' is still 2 from earlier
        case 1:
            printf("    One "); // If value was 1, this would print, then fall through to case 2.
        case 2:
            printf("    Two "); // Value IS 2, so this prints, then falls through to case 3.
        case 3:
            printf("    Three "); // This also prints because of fallthrough.
            break; // This finally stops the fallthrough.
        default:
            printf("    Default "); // This won't print.
    }
    printf("\n    (See 'Two Three' printed? That's fallthrough!)\n");
    sleep(1);



    // --- Ternary Operator: The Quick Decision Maker ---
    printf("\n--- Ternary Operator: The Quick Decision Maker! 🤔 ---\n");
    printf("    @analog: 'Is it hot? If yes, wear shorts. Else, wear pants.' All in one line!\n");
    // Syntax: `condition ? value_if_true : value_if_false;`
    result = (a > b) ? a : b; // (10 > 5) is true, so result gets 'a' (10).
    printf("    Max of 'a' (%d) and 'b' (%d) is: %d (Ternary did the job!)\n", a, b, result);
    sleep(1);



    // --- Short-Circuit Evaluation (&&): The Smart Bouncer ---
    printf("\n--- Short-Circuit Evaluation (&&): The Smart Bouncer! 🧠 ---\n");
    printf("    @analog: 'If you have a ticket AND you're on the guest list.' If you don't have a ticket, the bouncer doesn't even check the guest list.\n");
    printf("    In C, if the first part of `&&` is false, it stops and doesn't check the rest. Prevents crashes!\n");
    // 'ptr' is NULL. `ptr != NULL` is false. So, `ptr[0] > 0` is NOT evaluated.
    // This prevents a crash because we're not trying to access memory at a NULL pointer.
    if (ptr != NULL && ptr[0] > 0) { // Using ptr[0] (dereferencing NULL) is dangerous if not short-circuited.
        printf("    This won't print if ptr is NULL. (Good thing it's short-circuited!)\n");
    } else {
        printf("    Short-circuit prevented access to a NULL pointer. Phew! 😮‍💨\n");
    }
    sleep(1);



    // --- Short-Circuit Evaluation (||): The Easy Way Out ---
    printf("\n--- Short-Circuit Evaluation (||): The Easy Way Out! 💨 ---\n");
    printf("    @analog: 'I'll go to the party if it's free OR if my bestie is going.' If it's free, you're in, no need to check on your bestie.\n");
    printf("    If the first part of `||` is true, it stops and doesn't check the rest.\n");
    // `a < b` is (10 < 5), which is false.
    // So, it *does* evaluate `c > d` (20 > 15), which is true.
    // false || true is true.
    if (a < b || c > d) {
        printf("    One of the conditions is true. (It checked the second one!)\n");
    }
    printf("    (If the first condition was true, it wouldn't have checked the second.)\n");
    sleep(1);


    
    printf("\n=============================================================\n");
    printf("That's the lowdown on C's control flow! You're now a master of code decisions. 🏆\n");
    printf("Keep coding, you're leveling up! 🚀\n");
    printf("=============================================================\n");

    return 0; // Program finished successfully. Peace out! ✌️
}
