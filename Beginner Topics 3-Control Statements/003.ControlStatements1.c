#include <stdio.h>
#include <math.h>

int main() {
    int i, num, flag = 1;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Any number that's 1 or less is automatically not a prime.
    // That's just the rule. No need to check any further.
    if (num <= 1) {
        printf("%d is not prime\n", num);
    } else {
        // Analogy: Imagine 'num' is a suspect, and you're a detective.
        // You have to check for any accomplices. The 'for' loop is your
        // investigative team, starting from agent '2'.
        //
        // The 'sqrt(num)' part is a major brain move. You don't need to check
        // every single number. If there's an accomplice, you'll find them
        // by the time you've checked up to the square root. Any accomplice
        // larger than that would have a smaller accomplice you would have
        // already found. It saves a ton of time.
        for (i = 2; i <= sqrt(num); i++) {
            // The '% i == 0' is the interrogation. If 'num' gives a clean
            // division by any agent 'i', it means it has an accomplice.
            // It's not a true prime.
            if (num % i == 0) {
                // You found an accomplice! The suspect is not a prime.
                // We're setting the flag to '0' as a final verdict.
                flag = 0;
                printf("%d is not prime\n", num);
                // Now that we have our answer, there's no reason to keep
                // investigating. We use 'break' to shut down the investigation
                // and move on. No more looping, we got the info we needed.
                break;
            }
        }

        // After the whole investigation, if the flag is still a '1',
        // it means no accomplices were found. The number is innocent.
        // It's a prime.
        if (flag == 1) {
            printf("%d is prime\n", num);
        }
    }

    return 0;
}
