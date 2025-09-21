#include <stdio.h>

// `typedef` is a keyword in C that lets you create an alias or a synonym for an
// existing data type. Think of it like giving a nickname to a long name.

// Here, we're giving the nickname `std` to the `struct Student`.
// This means we can use `std` instead of `struct Student` when declaring variables.
typedef struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[34];
} std;

int main()
{
    // We can also use `typedef` to create aliases for pointers.
    // Here, `intepointer` becomes a nickname for `int *`.
    // This makes the code more readable and consistent.
    typedef int *intepointer;

    // Now, we can declare two integer pointers using our new nickname.
    // `a` and `b` are both pointers that can store the address of an integer.
    intepointer a, b;

    // We declare a regular integer variable `c` and give it a value of 89.
    int c = 89;

    // We assign the address of `c` to both pointers `a` and `b`.
    // The `&` operator gets the memory address of a variable.
    // So, `a` and `b` now both "point to" the same location in memory where `c` is stored.
    a = &c;
    b = &c;

    // The `*` operator is the dereference operator. It "dereferences" a pointer,
    // which means it retrieves the value stored at the memory address the pointer is pointing to.
    printf("The value at the address a points to is: %d\n", *a);
    printf("The value at the address b points to is: %d\n", *b);

    return 0;
}