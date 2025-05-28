/**
 * The break keyword is like rage-quitting a loop or switch — the moment it's hit, your program says 'I'm out'. 
 * 
 * Picture the school principal sends you to dig through a stack of books. 
 * 
 * You find what you need, and you dip immediately. 
 * 
 * No need to keep searching — break saw the condition was met and said, 'Mission accomplished, we out.'
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("2. break\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'break' keyword is like rage-quitting a loop or switch — the moment it's hit, your program says 'I'm out'. Picture the school principal sends you to dig through a stack of books. You find what you need, and you dip immediately. No need to keep searching — 'break' saw the condition was met and said, 'Mission accomplished, we out.'\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Searching for 'C' in the letters A-E...\n");
    for (char c = 'A'; c <= 'E'; c++) {
        printf("Checking letter: %c\n", c);
        if (c == 'C') {
            printf("Found 'C'! Rage-quitting the search now! 🏃💨\n");
            break; // I'm out!
        }
        sleep(1); // Chill a bit before next check
    }
    printf("Loop finished (or broke).\n");
    sleep(5);
    return 0;
}