#include <stdio.h>
#include <string.h> // We need this header for the `strcpy` function.

// This is a `struct` (short for structure).
// Think of a `struct` as a custom blueprint or template for a new type of variable.
// This blueprint, named `Student`, groups related data like a student's name,
// roll number, and marks into a single, neat package.
struct Student
{
    char name[20]; // A character array to hold the student's name.
    int rollnum;   // An integer for the roll number.
    float marks;   // A floating-point number for the marks.
};

int main()
{
    // Method 1: Initializing a `struct` at the time of declaration.
    // We use curly braces `{}` to provide values for each member of the `struct`.
    // The values must be in the order they were declared in the `struct` blueprint.
    // The `int` and `float` values are not strings, so they don't need quotes.
    struct Student stu1 = {"Nayan", 25, 98.0};

    // Method 2: Declaring `struct` variables without immediate initialization.
    // We'll fill in their data later.
    struct Student stu2, stu3;
    
    // Now we populate `stu2` using the dot `.` operator.
    // The dot operator lets us access individual members within the `struct` variable.
    // For strings, we use `strcpy` to copy the string into the `name` array.
    strcpy(stu2.name, "kiran");
    stu2.rollnum = 34;
    stu2.marks = 35.0; // It's good practice to use `.0` for float assignments.

    // Method 3: Getting `struct` data from user input.
    printf("Enter name, roll number, and marks for stu3: \n");
    // We use `scanf` to read the data. We pass the addresses of `rollnum` and `marks`
    // using the `&` operator so `scanf` knows where to store the values.
    // For the `name` string, the array name `stu3.name` is already a pointer, so we don't need `&`.
    scanf("%s %d %f", stu3.name, &stu3.rollnum, &stu3.marks);

    // Printing the data for all three students to verify.
    // We use the dot operator again to access the members for printing.
    printf("\n--- Student Details ---\n");
    printf("stu1: %s, %d, %.2f\n", stu1.name, stu1.rollnum, stu1.marks);
    printf("stu2: %s, %d, %.2f\n", stu2.name, stu2.rollnum, stu2.marks);
    printf("stu3: %s, %d, %.2f\n", stu3.name, stu3.rollnum, stu3.marks);

    return 0;
}