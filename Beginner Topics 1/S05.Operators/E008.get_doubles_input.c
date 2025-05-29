#include <stdio.h> // For all the input/output ops, like printf and scanf.
#include <stdlib.h> // Just in case we need some general utilities, but not strictly for this one.


// Imagine you're tryna split the bill at a restaurant with your squad and the bill is 200.75.
// It ain't always gonna be a whole number, right? So, everyone takes a hit of like $17.34 each on their wallet. 
// The cashier will use a calculator that supports the doubles(high number of precision), so that they don't lose any coin.😂


void clear_input_buffer() {
    // This function is like hitting the "clear all notifications" button on your phone.
    // It gets rid of any extra junk (characters) left in the input buffer
    // after you type something, so it doesn't mess up the next input.
    // We don't want those old vibes sticking around, ya feel?
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


/**
 * @brief Prompts for and reads a double value from the user.
 * @return The valid double value entered by the user.
 *
 * @analog This is the bouncer (function/block of code that runs when called) for your decimal numbers. 
 * 
 * It's chill with numbers like 17.1476544 or 99.99. Anything else? "Nah."
 * 
 * Keeps the calculations right for floating points.
 */

double get_double_input(const char* prompt) {
    double value;
    printf("%s", prompt); // Spreading the prompt like a new TikTok trend.
    while (scanf("%lf", &value) != 1) { // Checking if the input is valid, like gatekeeping bad vibes.
        printf("Invalid input! Please enter a number. Fr fr. 🚫\n"); // Telling them to chill and re-enter.
        clear_input_buffer(); // Cleaning up the mess, because we don't do drama.
    }
    clear_input_buffer(); // Once we got the good vibes (valid number), clean up again.
    return value; // Sending back the realest number.
}

int main() {
    // This is where the magic happens, like your main feed.
    printf("Yo guest! Welcome to the double-trouble zone. We're about to do some math tingz. 🤙\n\n");

    // Real-world example: Calculating your share of the Netflix subscription.
    // It's never perfectly divisible, so doubles are the GOAT here.
    double netflix_cost = get_double_input("What's the total monthly Netflix cost, no cap? ($): ");
    double friends_sharing = get_double_input("How many of your main characters are sharing the Netflix, including you? (Enter a whole number): ");

    // Operations on doubles:
    // Division - Splitting the bill, duh.
    double individual_share = netflix_cost / friends_sharing;
    printf("\nEach of y'all gotta cough up: $%.2f. Don't be a stingy bestie. 🤑\n", individual_share);

    // Another example: Calculating a discount on your favorite hoodie.
    // Percentages are prime territory for doubles.
    double original_price = get_double_input("\nHow much is that fire hoodie you're eyeing? ($): ");
    double discount_percentage = get_double_input("What's the discount percentage? (e.g., for 15%% off, type 15): ");

    // To perform the discount, we need to convert the percentage to a decimal.
    // 15% becomes 0.15, like converting your feelings into emojis.
    double discount_factor = discount_percentage / 100.0; // Notice the 100.0 to ensure double division.

    // Multiplication - Finding out how much you save.
    double amount_saved = original_price * discount_factor;

    // Subtraction - Getting the final price after the discount.
    double final_price = original_price - amount_saved;

    printf("You're saving: $%.2f. That's a W! 🎉\n", amount_saved);
    printf("Your final price for the hoodie is: $%.2f. Secure the bag! 🛍️\n", final_price);

    // One more for the road: Calculating GPA (Grade Point Average).
    // This is literally the definition of needing doubles, unless you're a straight-A student
    // and only get whole numbers (which, let's be real, is rare).
    double subject1_grade = get_double_input("\nEnter your grade for Subject 1 (e.g., 3.7 for an A-): ");
    double subject2_grade = get_double_input("Enter your grade for Subject 2: ");
    double subject3_grade = get_double_input("Enter your grade for Subject 3: ");

    // Addition - Summing up all your grades.
    double total_grade_points = subject1_grade + subject2_grade + subject3_grade;
    double num_subjects = 3.0; // Again, 3.0 to ensure double division.

    // Division - Getting the average.
    double gpa = total_grade_points / num_subjects;
    printf("\nYour current GPA is: %.2f. Keep grinding! 🧠\n", gpa);


    printf("\nThat's it, bestie! You've officially leveled up your double-handling skills. Peace out! ✌️\n");

    return 0; // Everything ran smoothly, no cap.
}