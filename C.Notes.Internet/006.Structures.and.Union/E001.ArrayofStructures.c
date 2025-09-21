#include <stdio.h>
#include <string.h> // Good practice to include for string operations

// This is our blueprint for a `Student`.
struct student
{
    char name[20];
    int rollnum;
    float marks;
};

int main()
{
    // An array of 10 `student` structures. This is like having 10 empty folders,
    // each with the same labels (`name`, `rollnum`, `marks`).
    struct student stuarr[10];

    // This `for` loop is our input section. We'll fill in the data for each of the 10 students.
    for (int i = 0; i < 2; i++) // Reduced to 2 for a faster example.
    {
        // We prompt the user for input.
        printf("Enter name, roll number, and marks for student %d:\n", i + 1);
        
        // We read the input. Note: no `\n` in the `scanf` format string.
        // `&stuarr[i].rollnum` and `&stuarr[i].marks` are correct because `scanf` needs the address to store the value.
        // `stuarr[i].name` is correct because a character array's name already acts as a pointer to its first element.
        scanf("%s %d %f", stuarr[i].name, &stuarr[i].rollnum, &stuarr[i].marks);
    }

    // This `for` loop is our output section. We'll print the data we just stored.
    printf("\n--- Student Details ---\n");
    for (int i = 0; i < 2; i++) // Looping through the same number of students.
    {
        // The fix: We remove the `&` operator because we want to print the VALUE of the variables, not their addresses.
        printf("Student %d: %s\t%d\t%.2f\n", i + 1, stuarr[i].name, stuarr[i].rollnum, stuarr[i].marks);
    }
    
    return 0;
}