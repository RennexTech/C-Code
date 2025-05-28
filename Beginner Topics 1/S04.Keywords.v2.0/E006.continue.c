/**
 * 
 * The continue keyword is like saying, 'Skip this one, move on.' 
 * 
 * Inside a loop, it tells the program to drop the rest of the code for that round and 
 * 
 * jump straight to the next iteration. Perfect when you're like, 'Nah, this one’s not worth my time.' 
 * 
 * Imagine you’re a teacher who wants to skip students scoring below 50 — 
 * 
 * so you can take them for a quick chat in the staffroom 😂. 
 * 
 * Your C program reads each name, but when it spots a below 50, it skips printing their name.
 * 
 */

 #include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("6. continue\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'continue' keyword is like saying, 'Skip this one, move on.' Inside a loop, it tells the program to drop the rest of the code *for that round* and jump straight to the next iteration. Perfect when you're like, 'Nah, this one’s not worth my time.'\n");
    printf("Imagine you’re a teacher who wants to skip students scoring below 50 — so you can take them for a quick chat in the staffroom😂. Your C program reads each name, but when it spots a below 50, it skips printing their name.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int scores[] = {85, 40, 92, 55, 70, 48, 65};
    int num_students = sizeof(scores) / sizeof(scores[0]);

    printf("Grading student scores...\n");
    for (int i = 0; i < num_students; i++) {
        if (scores[i] < 50) {
            printf("Student with score %d needs a chat in the staffroom (skipping print). 😅\n", scores[i]);
            continue; // Skip the rest of this loop iteration for this student
        }
        printf("Student %d scored %d. Great job! 👍\n", i + 1, scores[i]);
        sleep(1);
    }
    printf("All students processed.\n");
    sleep(5);
    return 0;
}