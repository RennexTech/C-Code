#include <stdio.h>
#include <string.h> // We need this header for the `strcpy` function.

// This is a `struct` (short for structure).
// Think of a `struct` as a custom blueprint for a variable.
// This blueprint, named `Student`, specifies that any variable of this type
// will contain four distinct pieces of information: an integer `id`, an integer `marks`,
// a character `fav_char`, and a string `name`.
struct Student
{
    int id;           // A unique identifier for the student.
    int marks;        // The student's marks.
    char fav_char;    // The student's favorite character.
    char name[34];    // An array of characters to hold the student's name.
};

int main()
{
    // We're declaring three variables of our custom `Student` type.
    // Each of these variables (`nayan`, `ravi`, `shubham`) is a separate instance of our `Student` blueprint.
    struct Student nayan, ravi, shubham;

    // Now, we'll assign values to the members of each `struct` variable using the dot `.` operator.
    // The dot operator lets us access a specific item within the blueprint.

    // Assigning values for nayan.
    nayan.id = 1;
    nayan.marks = 455;
    nayan.fav_char = 'q';
    
    // For strings, you can't use the `=` operator. You must use `strcpy` to copy the name into the character array.
    strcpy(nayan.name, "Nayan Khade");

    // Assigning values for ravi.
    ravi.id = 2;
    ravi.marks = 466;
    ravi.fav_char = 'p';
    strcpy(ravi.name, "Ravi Kumar"); // FIX: Added Ravi's name.

    // Assigning values for shubham.
    shubham.id = 3;
    shubham.marks = 466;
    shubham.fav_char = 'p';
    strcpy(shubham.name, "Shubham Kumar");

    // Printing the details for each student.
    // The `\t` creates a tab for clean spacing.
    printf("Nayan id = %d\tMarks = %d\tFav char = %c\n", nayan.id, nayan.marks, nayan.fav_char);
    printf("Ravi id = %d\tMarks = %d\tFav char = %c\n", ravi.id, ravi.marks, ravi.fav_char);
    printf("Shubham id = %d\tMarks = %d\tFav char = %c\n", shubham.id, shubham.marks, shubham.fav_char);

    // Printing the full names.
    printf("\nNayan's name is: %s\n", nayan.name);
    printf("Ravi's name is: %s\n", ravi.name);
    printf("Shubham's name is: %s\n", shubham.name);

    return 0;
}