/**
 * 
 * for is the C way of saying: 'Yo, do this exact thing over and over till I say stop.' 
 * 
 * Syntax: for(start; condition; update) 
 * 
 * Real life: for(int i = 0; i < 10; i++) → Like doing 10 pushups, one rep at a time. 
 * 
 * The moment condition goes false? Boom. You’re done. No gym, no gain.
 * 
 */

 #include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("14. for\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("for is the C way of saying: 'Yo, do this exact thing over and over till I say stop.' Syntax: for(start; condition; update) Real life: for(int i = 0; i < 10; i++) → Like doing 10 pushups, one rep at a time. The moment condition goes false? Boom. You’re done. No gym, no gain.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Starting push-up challenge (10 reps):\n");
    for (int rep = 1; rep <= 10; rep++) { // (start; condition; update)
        printf("Push-up #%d...\n", rep);
        sleep(1); // Simulate time for one push-up
    }
    printf("Challenge complete! 💪\n");

    printf("\nCounting down for rocket launch:\n");
    for (int i = 5; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("LIFTOFF! 🚀\n");
    sleep(5);
    return 0;
}