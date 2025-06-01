#include <stdio.h>   // For printf, scanf_s
#include <string.h>  // Not strictly needed here, but commonly used with strings

int main() {
    // Declare subject marks and total result
    int math, science, english, kiswahili, socialstudies, cre, results;

    // Grade characters for display
    char grade1 = 'A';
    char grade2 = 'B';
    char grade3 = 'C';
    char grade4 = 'D';
    char grade5 = 'E';

    // Get user input for each subject
    printf("Enter your math marks: \\n");
    scanf_s("%d", &math);
    printf("Enter your science marks: \\n");
    scanf_s("%d", &science);
    printf("Enter your english marks: \\n");
    scanf_s("%d", &english);
    printf("Enter your kiswahili marks: \\n");
    scanf_s("%d", &kiswahili);
    printf("Enter your social studies marks (out of 60): \\n");
    scanf_s("%d", &socialstudies);
    printf("Enter your CRE marks (out of 30): \\n");
    scanf_s("%d", &cre);

    // Combine Social Studies and CRE marks and compute their percentage
    int social_cre_total = cre + socialstudies;
    double social_cre_percent = ((double)social_cre_total / 90) * 100;

    // Total marks (math, science, english, kiswahili, combined social/CRE)
    results = math + science + english + kiswahili + social_cre_total;

    // Basic sanity check
    if (results > 500 || results < 0) {
        printf("Stop the cap! Re-enter your marks!\\n");
    } else {
        printf("\\n--------------------------------------------------\\n");
        printf("Your official exam results: %d/500\\n", results);
        printf("--------------------------------------------------\\n");
    }

    printf("\\nYou are going to be assigned your subject grades shortly.\\n");
    printf("==============================================\\n");

    // Subject grading logic (reused for each subject below)

    // --- Math ---
    if (math > 100) {
        printf("Math can't be more than 100%%. Re-enter math marks.\\n");
    } else if (math >= 80) {
        printf("You got an %c in math.\\n", grade1);
    } else if (math >= 70) {
        printf("You got a %c in math.\\n", grade2);
    } else if (math >= 60) {
        printf("You got a %c in math.\\n", grade3);
    } else if (math >= 50) {
        printf("You got a %c in math.\\n", grade4);
    } else if (math >= 0) {
        printf("You got an %c in math.\\n", grade5);
    } else {
        printf("Invalid math marks entered.\\n");
    }

    // --- Science ---
    if (science > 100) {
        printf("Science can't be more than 100%%. Re-enter science marks.\\n");
    } else if (science >= 80) {
        printf("You got a %c in science.\\n", grade1);
    } else if (science >= 70) {
        printf("You got a %c in science.\\n", grade2);
    } else if (science >= 60) {
        printf("You got a %c in science.\\n", grade3);
    } else if (science >= 50) {
        printf("You got a %c in science.\\n", grade4);
    } else if (science >= 0) {
        printf("You got a %c in science.\\n", grade5);
    } else {
        printf("Invalid science marks entered.\\n");
    }

    // --- Kiswahili ---
    if (kiswahili > 100) {
        printf("Kiswahili can't be more than 100%%. Re-enter kiswahili marks.\\n");
    } else if (kiswahili >= 80) {
        printf("You got a %c in kiswahili.\\n", grade1);
    } else if (kiswahili >= 70) {
        printf("You got a %c in kiswahili.\\n", grade2);
    } else if (kiswahili >= 60) {
        printf("You got a %c in kiswahili.\\n", grade3);
    } else if (kiswahili >= 50) {
        printf("You got a %c in kiswahili.\\n", grade4);
    } else if (kiswahili >= 0) {
        printf("You got a %c in kiswahili.\\n", grade5);
    } else {
        printf("Invalid kiswahili marks entered.\\n");
    }

    // --- English ---
    if (english > 100) {
        printf("English can't be more than 100%%. Re-enter english marks.\\n");
    } else if (english >= 80) {
        printf("You got a %c in english.\\n", grade1);
    } else if (english >= 70) {
        printf("You got a %c in english.\\n", grade2);
    } else if (english >= 60) {
        printf("You got a %c in english.\\n", grade3);
    } else if (english >= 50) {
        printf("You got a %c in english.\\n", grade4);
    } else if (english >= 0) {
        printf("You got a %c in english.\\n", grade5);
    } else {
        printf("Invalid english marks entered.\\n");
    }

    // --- Social Studies + CRE ---
    printf("Your social-cre percentage is: %.2lf%%\\n", social_cre_percent);

    if (social_cre_percent > 100) {
        printf("Combined score can't exceed 100%%. Re-enter social/CRE marks.\\n");
    } else if (social_cre_percent >= 80) {
        printf("You got a %c in social studies + CRE.\\n", grade1);
    } else if (social_cre_percent >= 70) {
        printf("You got a %c in social studies + CRE.\\n", grade2);
    } else if (social_cre_percent >= 60) {
        printf("You got a %c in social studies + CRE.\\n", grade3);
    } else if (social_cre_percent >= 50) {
        printf("You got a %c in social studies + CRE.\\n", grade4);
    } else if (social_cre_percent >= 0) {
        printf("You got a %c in social studies + CRE.\\n", grade5);
    } else {
        printf("Invalid marks for social/CRE combo.\\n");
    }

    printf("==============================================\\n");
    printf("Done!\\n");

    return 0;
}