#include <stdio.h>
#include <string.h>

// We give the `struct Student` blueprint a nickname: `std`.
// This means we can now use `std` to declare variables.
typedef struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[34];
} std;

int main()
{
    // We declare two variables of our custom type `std`.
    std s1, s2;
    
    // We assign values to the `id` member of each `struct` variable.
    s1.id = 34;
    s2.id = 89;

    // We print the values. `\n` at the end of each `printf` makes the output cleaner.
    printf("Value of s1's id is: %d\n", s1.id);
    printf("Value of s2's id is: %d\n", s2.id);
    
    return 0;
}