/*Program to find out the number of notes required for a given amount of money*/

#include <stdio.h>

int main() {
    int n, choice, notes;
    printf("Enter the total amount in Rs: ");
    scanf("%d", &n);
    printf("Enter the value of notes from which you want to begin: ");
    scanf("%d", &choice);

    // This switch statement will check the user's choice and then 'fall through' to the smaller notes.
    // This is a feature of switch statements in C. If you want to stop after a case, you need to use a 'break' statement.
    switch (choice) {
        case 100:
            notes = n / 100;
            printf("Number of 100 Rs notes is = %d\n", notes);
            n = n % 100;
        case 50:
            notes = n / 50;
            printf("Number of 50 Rs notes is = %d\n", notes);
            n = n % 50;
        case 20:
            notes = n / 20;
            printf("Number of 20 Rs notes is = %d\n", notes);
            n = n % 20;
        case 10:
            notes = n / 10;
            printf("Number of 10 Rs notes is = %d\n", notes);
            n = n % 10;
        case 5:
            notes = n / 5;
            printf("Number of 5 Rs notes is = %d\n", notes);
            n = n % 5;
        case 2:
            notes = n / 2;
            printf("Number of 2 Rs notes is = %d\n", notes);
            n = n % 2;
        case 1:
            notes = n / 1;
            printf("Number of 1 Rs notes is = %d\n", notes);
            n = n % 1;
        default:
            printf("Enter only valid value\n");
            // The break statement here prevents the default case from falling through,
            // which is a good practice, even if there's nothing after it.
            break;
    }
    return 0;
}