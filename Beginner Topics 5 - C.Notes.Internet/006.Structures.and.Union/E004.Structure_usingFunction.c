#include <stdio.h>
#include <string.h> // Needed for strcpy()

// This is our blueprint for a `Student` variable.
struct student
{
    char name[20];
    int rollnum;
    int marks;
};

// Function prototype: `display` takes a string, an integer, and another integer.
void display(char name[], int rollnum, int marks);

int main()
{
    // We declare and initialize `stu1` directly.
    struct student stu1 = {"Nayan", 35, 98};
    
    // We declare `stu2`.
    struct student stu2;

    // We use `strcpy` to assign the name string and the `=` operator for the numbers.
    strcpy(stu2.name, "Akshay");
    stu2.rollnum = 36;
    stu2.marks = 97;
    
    // We call the `display` function for `stu1` and `stu2`, passing each field individually.
    display(stu1.name, stu1.rollnum, stu1.marks);
    display(stu2.name, stu2.rollnum, stu2.marks);
    
    return 0;
}

// This function receives the values of the `struct` members and prints them.
// It doesn't know that these values originally came from a `struct`.
void display(char name[], int rollnum, int marks)
{
    printf("Name = %s\t", name);
    printf("Roll num = %d\t", rollnum);
    printf("Marks = %d\n", marks);
}