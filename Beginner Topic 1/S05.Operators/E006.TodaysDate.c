#include <stdio.h>   // For printf — the program’s mouthpiece 🎤
#include <time.h>    // For all things time: time_t, localtime, struct tm, etc.

/**
 * 
 * This episode is not safe for beginners, only advanced users. You can skip it for now... 
 * 
 * @brief 🕒 What’s the Date Today? — Real-World Style
 *
 * Imagine you're building a CLI tool that logs journal entries, generates receipts,
 * timestamps messages, or sets reminders. You need to grab the current date and format it like a pro.
 *
 * This program shows how to get the current local date using <time.h> — and explains 
 * the logic like you're actually going to use it IRL, not just for textbook points.
 */
int main() {
    // STEP 1: Get the current time (raw format — seconds since Jan 1, 1970, a.k.a. "Unix Epoch").
    // time_t is like a big integer for tracking time in seconds.
    time_t now = time(NULL); 

    // Sanity check: Did time() fail?
    if (now == -1) {
        printf("⛔ Error: Could not get the current time.\n");
        return 1; // Exit with error
    }

    // STEP 2: Convert the raw time into local time components (like day, month, year).
    // localtime() breaks the time into a readable format based on your system's timezone.
    struct tm *local = localtime(&now); // Returns a pointer to a 'struct tm'

    // Sanity check: Did localtime() fail?
    if (local == NULL) {
        printf("⛔ Error: Could not convert to local time.\n");
        return 1;
    }

    // STEP 3: Extract what we need
    int day   = local->tm_mday;        // Day of the month: 1–31
    int month = local->tm_mon + 1;     // Month: 0–11 (so add 1 to get 1–12)
    int year  = local->tm_year + 1900; // Years since 1900 (so add 1900 to get real year)

    // STEP 4: Format the output like MM/DD/YYYY
    // We use %02d to pad numbers with zeroes if needed (e.g., 03 instead of 3)
    printf("📅 Today's date is: %02d/%02d/%04d\n", month, day, year);

    // Bonus Example Use Case:
    printf("\n🧾 [Receipt Timestamp]\n");
    printf("Purchase Date: %02d/%02d/%04d — Keep this for your records.\n", month, day, year);

    printf("\n📝 [Journal Entry Prompt]\n");
    printf("You’re writing a journal entry for %02d/%02d/%04d. How was your day?\n", month, day, year);

    return 0; // Smooth exit 😎
}
