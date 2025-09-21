#include <stdio.h>

// This function demonstrates how the 'continue' statement works.
//
// Analogy: Think of it like a to-do list where you decide to skip
// certain items. This loop is your to-do list from 1 to 10.
// When you see an even number, you hit 'continue,' which is like
// saying, "Nah, not doing this one," and immediately jumping to
// the next number on the list without doing the 'printf' task.
// That's why only the odd numbers get printed.
int main() {
    int i;
    printf("--- Using 'continue' to skip even numbers ---\n");
    for (i = 1; i <= 10; i++) {
        // Skips even numbers.
        if (i % 2 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n\n");

    // Call other example functions.
    goto_function();
    goto_function_2();
    goto_function_3();
    date_check();

    return 0;
}

// This function shows how 'goto' can be used for error handling.
//
// Analogy: Imagine you're building with LEGOs and something breaks.
// Instead of trying to fix it right there, you have a designated "cleanup zone."
// The 'goto' statement is like a panic button that instantly teleports
// you to that cleanup zone to handle things, like closing a file.
void goto_function() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        // Jumps to the cleanup label.
        goto cleanup;
    }

    // Normal file processing code would go here.
    printf("--- 'goto' used for file cleanup ---\n");
    printf("File opened successfully.\n");
    
cleanup:
    if (file != NULL) {
        fclose(file);
    }
    printf("File closed.\n\n");
}

// This function demonstrates a simple, unconditional jump with 'goto'.
//
// Analogy: This is like a literal teleport. The code is supposed to
// execute in order, but the 'goto' command just says, "Forget this
// part, just jump straight to the 'label' spot." This is why the
// first 'printf' statement is completely skipped.
void goto_function_2() {
    int num = 1;
    printf("--- 'goto' as a teleport ---\n");
    if (num == 1) {
        // Jumps to the 'label' below.
        goto label;
    }

    printf("This will not be executed.\n");

label:
    printf("This will be executed because of the goto statement.\n\n");
}

// This function shows 'goto' used to jump to different sections of code.
//
// Analogy: Think of this as a train with multiple tracks. Based on
// your number, the 'if' statement puts you on the 'even' track or the
// 'odd' track. But after you get your result, both tracks merge and
// head to the final destination, the 'end' label.
void goto_function_3() {
    int n;
    printf("--- 'goto' as a logic branch ---\n");
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n % 2 == 0) {
        goto even;
    } else {
        goto odd;
    }

even:
    printf("Number is even.");
    goto end;

odd:
    printf("Number is odd.");
    
end:
    printf("\n\n");
}

// This function validates a date. It's a bit of a logical maze, so
// the comments are here to help you through the checks.
//
// Analogy: This code is a bouncer at a club, and the date is the person's
// ID. The bouncer has a 'valid ID' stamp (the 'flag' variable). He
// starts with the stamp, but as he checks different things (year range,
// month range, day count), he might take the stamp away if something's
// off. He even has a special stamp for a "leap year" VIP pass.
void date_check() {
    int d, m, y;
    int flag = 1, isleap = 0;

    printf("--- Date validation example ---\n");
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d, &m, &y);

    // Checks if the year is a leap year.
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
        isleap = 1;
    }

    // Check year and month boundaries.
    if (y <= 1850 || y >= 2050) {
        flag = 0;
    } else if (m < 1 || m > 12) {
        flag = 0;
    }
    // Days can't be less than 1.
    else if (d < 1) {
        flag = 0;
    }
    // Checks for February.
    else if (m == 2) {
        if (d > 28) {
            flag = 0;
        }
        if (d == 29 && isleap) {
            flag = 1; // Allows 29 days for a leap year.
        }
    }
    // Checks for months with 30 days.
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 30) {
            flag = 0;
        }
    }
    // Checks for months with 31 days.
    else {
        if (d > 31) {
            flag = 0;
        }
    }

    // Prints the final result based on the 'flag' variable.
    if (flag == 0) {
        printf("Not a valid date\n");
    } else {
        printf("Valid Date\n");
    }
}
