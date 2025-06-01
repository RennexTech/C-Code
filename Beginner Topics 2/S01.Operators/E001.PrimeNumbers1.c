#include <stdio.h> // This is our essential toolkit for input (scanf) and output (printf).

/*
 * 🌟 Prime Number Checker: The Definitive Vibe 🌟
 *
 * What's a Prime Number, Really? 🤔
 *
 * A prime number is a positive whole number (an integer) that's greater than 1.
 * The super specific rule: it can *only* be divided perfectly by two numbers: 1 and itself.
 *
 * ✅ Example: 7 is a prime number.
 * - Can 7 be divided perfectly by 1? Yes (7 / 1 = 7).
 * - Can 7 be divided perfectly by 7? Yes (7 / 7 = 1).
 * - Can 7 be divided perfectly by 2, 3, 4, 5, or 6? Nope! You'll get a remainder.
 * So, 7 is a true prime! 🎉
 *
 * ❌ Example: 6 is NOT a prime number.
 * - Divisors for 6 are: 1, 2, 3, and 6.
 * - Since 6 has *more than two* distinct divisors (2 and 3 are extra!), it's not prime.
 *
 * TLDR: Prime numbers are exclusive. They only let 1 and themselves into their division circle. No extras.
 * 
 */

int main() {
    // 'num' will hold the number the user types in.
    // 'isPrime' is like our "vibe check" flag. We assume the number is prime (set to 1, or TRUE)
    // until we find evidence that it's not. If we find any extra divisors, we flip it to 0 (FALSE).
    int num;
    int isPrime = 1; // Start with the assumption: "This number is prime, no cap!" (1 means true)

    printf("Prime check incoming! Enter a whole number: ");
    scanf("%d", &num); // This line grabs the number you type and stores it in 'num'.

    // --- Step 1: The First Vibe Check (Numbers that can't be prime) ---
    // Numbers less than 2 (like 0, 1, or any negative numbers) are *never* prime.
    // It's like saying you're too young to join the squad.
    if (num < 2) {
        printf("%d is NOT a prime number (too young to join the prime squad).\n", num);
        return 0; // Mission complete for these numbers. We exit the program.
    }

    // --- Step 2: The "Friend" (Divisor) Hunt Loop ---
    /*
     * Think of this 'for' loop as your personal assistant for repetitive tasks.
     * It's like telling your phone, "Hey, scroll through my entire playlist, one song at a time, until you hit the end."
     *
     * The structure is: `for (initialization; condition; increment)`
     *
     * 1. `int i = 2;` (Initialization):
     * - We create a temporary number `i` and start it at 2.
     * - Why 2? Because we already know every number can be divided by 1, and we're looking for *other* divisors.
     * 2 is the smallest possible "other" divisor.
     *
     * 2. `i < num;` (Condition):
     * - This is the loop's "keep going?" check. The loop will keep running as long as `i` is less than `num`.
     * - Why stop before `num`? Because we already know `num` is divisible by itself, and that doesn't prove it's NOT prime.
     * We only care if it's divisible by numbers *between* 1 and itself.
     *
     * 3. `i++` (Increment):
     * - After each round (iteration) of the loop, `i` increases by 1.
     * - It's like moving to the next contact in your phone list to check if they're a "friend" (divisor).
     */
    for (int i = 2; i < num; i++) {
        // Inside the loop, we ask: "Can 'num' be divided perfectly by 'i'?"
        // The '%' (modulo) operator gives you the remainder of a division.
        // If 'num % i == 0', it means 'i' divides 'num' perfectly, with no remainder.
        // This is like finding out a number has a "homie" (divisor) other than 1 or itself.
        if (num % i == 0) {
            isPrime = 0; // Vibe check failed! Flip our flag to 0 (FALSE).
            printf("Nah fam, %d is divisible by %d. ❌ Not prime.\n", num, i);
            break; // Mic drop! We found a divisor, so we don't need to check any further.
                   // This `break` immediately stops the loop, saving time and energy.
                   // It's like leaving a party once you've seen enough drama.
        }
    }

    // --- Step 3: The Final Verdict ---
    // After the loop finishes (either because it found a divisor and broke, or it checked all numbers),
    // we check our `isPrime` flag one last time.
    if (isPrime) { // If `isPrime` is still 1 (TRUE), it means no other divisors were found.
        printf("%d is a PRIME number! 🎉 Loyal to just 1 and itself.\n", num);
    } else { // If `isPrime` is 0 (FALSE), it means we found at least one other divisor.
        printf("%d is NOT a prime. Got too many homies in its circle. 😔\n", num);
    }

    printf("\nMission accomplished! You're now a prime number pro. Keep coding! 💻\n");

    return 0; // Program ended successfully.
}
