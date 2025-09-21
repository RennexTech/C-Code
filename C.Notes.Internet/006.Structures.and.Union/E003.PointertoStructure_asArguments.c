#include <stdio.h>
#include <string.h>

// Our `Student` blueprint, as before.
struct student
{
    char name[20];
    int rollnum;
    int marks;
};

// Function prototypes. Both functions now take a `struct student` pointer.
// A pointer is a variable that stores the memory address of another variable.
void display(struct student *);
void int_marks(struct student *);

int main(void)
{
    // We declare and initialize two `struct student` variables.
    struct student stu1 = {"Nayan", 2, 98};
    struct student stu2 = {"Akshay", 3, 97};

    // We pass the **address** of each `struct` to our functions using the `&` operator.
    // The `&` operator gives us the memory address of `stu1` and `stu2`.
    int_marks(&stu1);
    int_marks(&stu2);
    display(&stu1);
    display(&stu2);
    
    return 0;
}

// This function is meant to work with the marks, but the body is currently empty.
// To modify a member using a pointer, we use the arrow `->` operator.
// For example, to increment marks: `stuptr->marks += 1;`
void int_marks(struct student *stuptr)
{
    // This is just a placeholder. The function doesn't do anything yet.
    // A useful implementation might be to add 2 marks to the student's score:
    // stuptr->marks += 2;
}

// This function receives a pointer to a `struct student`.
void display(struct student *stuptr)
{
    // To access members of a `struct` using a pointer, we use the `->` (arrow) operator.
    // The arrow operator is a shorthand for `(*stuptr).name`.
    printf("Name = %s\t", stuptr->name);
    printf("rollnum = %d\t", stuptr->rollnum);
    printf("marks = %d\n", stuptr->marks);
}