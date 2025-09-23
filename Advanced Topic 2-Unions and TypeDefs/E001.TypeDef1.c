#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

/*

Let's delve into the concept of typedef in C programming and explore how it can be used to define new names for data types, pointers, arrays, functions, and structs.

Typedef for Basic Data Types:

In C programming, typedef is a keyword that allows you to create an alias or a new name for an existing data type. The general syntax is as follows:

typedef existing_data_type new_name;

existing_data_type can be any standard data type (like int, float, etc.) or even a user-defined type.

new_name is an identifier that becomes a synonym for the existing_data_type.

For example, if we want to create a new name "marks" for the int data type, we can do this:

*/

typedef int marks;

/*

Now, "marks" can be used interchangeably with int in your program:

marks sub1, sub2; // sub1 and sub2 are actually int variables.

This is equivalent to:

int sub1, sub2;

---------------------------------------

Typedef for User-Defined Types:

You can also use typedef with user-defined types. For instance, if you have a custom structure type, you can create a new name for it:
*/


typedef struct {
    int age;
    char name[50];
} Person;

/*

Now, "Person" is an alias for this structure type.

Creating Multiple Names with One Typedef:

You can define multiple names for the same data type in a single typedef statement:
*/

typedef int age, marks, units;

/*
In this case, age, marks, and units are all aliases for the int data type.

Using Typedef with Pointers, Arrays, Functions, and Structs:

You can use typedef to create more readable and concise code when dealing with complex types. For example, you can create aliases for pointers, arrays, functions, and structs. Here are some examples:



*/

//Typedef for Pointer to int:
typedef int* IntPtr;
IntPtr p; // p is now an alias for int*


//Typedef for Array of char:
typedef char String[50];
String str; // str is now an alias for char[50]


//Typedef for Function Pointer:
typedef int (*MathFunction)(int, int);
MathFunction add; // add is now an alias for a function pointer

//Typedef for Struct:
typedef struct {
    int x;
    int y;
} Point;
Point p1; // p1 is now an alias for this structure


/*

In summary, typedef in C allows you to create aliases for data types, making your code more readable and maintainable, especially when dealing with complex types like pointers, arrays, functions, and structs. It's a powerful tool to enhance code clarity and abstraction.

-------------------------------------

typedef: This keyword is used to create a type alias.

int (*MathFunction)(int, int): This is the type that you are aliasing. It represents a function pointer type. Here's how to read it step by step:

int is the return type of the function pointed to by the MathFunction.
(*MathFunction) indicates that MathFunction is a pointer to a function.
(int, int) represents the function's parameter list, indicating that the function takes two int parameters.
So, MathFunction is now an alias for a pointer to a function that takes two int parameters and returns an int.

MathFunction add;: This declares a variable named add of type MathFunction. In other words, add is a pointer to a function that matches the signature described by MathFunction (i.e., a function that takes two int parameters and returns an int).
Here's an example of how you might use this add function pointer alias:

*/

//Typedef for Function Pointer:
typedef int (*MathFunction)(int, int);
MathFunction add; // add is now an alias for a function pointer

int sum(int a, int b) {
    return a + b;
}

int main() {
    MathFunction add = sum; // 'add' points to the 'sum' function
    int result = add(5, 3); // Calls 'sum(5, 3)' through 'add'
    printf("Result: %d\n", result); // Prints "Result: 8"
    return 0;
}

/*

In this example, add is used to point to the sum function, and you can call add as if it were a regular function, passing it two int parameters, and it returns the sum of those values.

---------------------------------------------

//Typedef for Pointer to int:
typedef int* IntPtr;
IntPtr p; // p is now an alias for int*

typedef: This keyword is used to create a type alias.

int*: This is the type that you are aliasing. It represents a pointer to an integer (int* is a common notation for a pointer to an int).

So, IntPtr is now an alias for the type "pointer to int."

IntPtr p;: This declares a variable named p of type IntPtr. In other words, p is now an alias for a pointer to an integer.

Here's an example of how you might use this IntPtr type alias:

*/

//Typedef for Pointer to int:
typedef int* IntPtr;
IntPtr p; // p is now an alias for int*

int main() {
    int x = 42;
    IntPtr p = &x; // 'p' is a pointer to an integer
    printf("Value of x: %d\n", *p); // Accessing the value through 'p'
    return 0;
}

/*

In this example, IntPtr is used to declare p as a pointer to an integer. You can then use p to point to an integer variable (x in this case) and access its value through the pointer. The *p notation is used to dereference the pointer and access the value it points to.


=====================================================

I've provided a detailed explanation of typedef in C programming and how it can be used with various data types, including pointers, arrays, functions, and structures. Here's a summary of the key points I've covered:

Basic typedef for Data Types:

typedef creates an alias for an existing data type.
It improves code readability and maintainability.
You can create aliases for standard data types or user-defined types.
Creating Aliases for Pointers:

You can use typedef to create aliases for pointers, making the code more descriptive.
For example, typedef int* IntPtr; creates an alias IntPtr for int*.
Creating Aliases for Arrays:

You can also create aliases for arrays, specifying their size.
For instance, typedef int intarr[10]; creates an alias intarr for an integer array of size 10.
Creating Aliases for Functions:

typedef can be used to define aliases for function types.
For example, typedef float funct(float, int); creates an alias funct for a function taking a float and an int and returning a float.
Creating Aliases for Structures:

You can use typedef to create more concise names for structures.
This helps in simplifying the code and improving readability.
For instance, typedef struct studentrec Student; creates an alias Student for the studentrec structure.
Advantages of Using typedef:

Improves code readability by giving meaningful names.
Simplifies the use of structures by avoiding repetitive struct keywords.
Enhances code portability, especially when dealing with different machine architectures.
Difference from #define Directives:

typedef is interpreted by the compiler, while #define directives are processed by the preprocessor.
typedef is primarily used for creating new names for data types, while #define can be used for any text substitution.

*/

#include <stdio.h>

// Define an alias for a standard data type (int)
typedef int marks;

// Define an alias for a pointer to float
typedef float* FloatPtr;

// Define an alias for an array of integers of size 5
typedef int IntArray[5];

// Define an alias for a function taking two int parameters and returning an int
typedef int (*MathFunction)(int, int);

// Define a structure
typedef struct {
    char name[20];
    int age;
} Person;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Division by zero is not allowed.\n");
        return 0;
    }
}

int main() {
    // Usage of aliases
    marks sub1 = 90;
    marks sub2 = 85;

    printf("Subject 1 Marks: %d\n", sub1);
    printf("Subject 2 Marks: %d\n", sub2);

    // Usage of pointer alias
    FloatPtr floatValue = NULL;
    float num = 3.14;
    floatValue = &num;
    printf("Value through pointer: %.2f\n", *floatValue);

    // Usage of array alias
    IntArray numbers = {1, 2, 3, 4, 5};
    printf("Array Element at Index 2: %d\n", numbers[2]);

    // Usage of function alias
    MathFunction operation = add;
    int result = operation(10, 5);
    printf("Result of Addition: %d\n", result);

    operation = subtract;
    result = operation(10, 5);
    printf("Result of Subtraction: %d\n", result);

    operation = multiply;
    result = operation(10, 5);
    printf("Result of Multiplication: %d\n", result);

    operation = divide;
    result = operation(10, 0); // Division by zero case
    result = operation(10, 5);
    printf("Result of Division: %d\n", result);

    // Usage of structure alias
    Person student;
    strcpy(student.name, "John");
    student.age = 20;

    printf("Student Name: %s\n", student.name);
    printf("Student Age: %d\n", student.age);

    return 0;
}

/*

In this program:

We create aliases for int, float*, int[5], and function types.
We use these aliases to declare variables, pointers, arrays, and functions.
The program demonstrates the usage of these aliases in various contexts, including assigning values and using them in operations.
There's also a simple structure (Person) and its alias (Person) that is used to create a structure variable.
This program covers the usage of typedef for different data types comprehensively.

---------------------------------------

let's break down the typedef stuff in a way that's easy to understand, like I'm talking to a teenager.

1. Aliases for Data Types:

So, think of typedef like giving a nickname to a type. Like, you know how people might call you "buddy" or "dude"? It's kinda like that.
For example, instead of always saying "int," we can say "marks." So, "marks" becomes our cool way of saying "int."

2. Aliases for Pointers:

Imagine you have a remote control for your TV. You can call it "clicker" if you want, right? That's what we're doing here.
We say "FloatPtr" is just a fancy way of saying "pointer to a float." So, if you have a float, FloatPtr is like your remote control to it.

3. Aliases for Arrays:

Think of an array like a list of things. If you have a list of 5 numbers, we can give that list a short name.
So, instead of saying "int numbers[5]," we can say "IntArray numbers." It's like saying "My list of 5 numbers is called 'numbers'."

4. Aliases for Functions:

You know how you call your friends by their names, right? Well, functions can have names too, and we can give them a special name.
So, if we say "MathFunction," it's like saying "Hey, MathFunction is a way to call any function that does math."

5. Aliases for Structures:

Structures are like containers for different types of data, and they can have long names. We can give them shorter names.
For example, instead of always saying "struct Person," we can say "Person." So, "Person" is just a quick way to talk about that container for people's info.

6. Why We Do This:

It's like making your code easier to read. Instead of using big words all the time, we use these cool nicknames.
Also, when we want to change things later, we only have to change the nickname once, and it updates everywhere in the code. Super handy!
So, typedef is like giving cool nicknames to things in our code, making it simpler and more fun to work with.


-----------------------------------------


Let's dive into a more detailed explanation of typedef for experienced programmers.

1. Aliases for Data Types:

In C, typedef allows us to create aliases for data types. This is often used to enhance code readability and provide more context.
For instance, instead of repeatedly using int, we can define typedef int marks;. This makes our code more self-explanatory when we see marks used in place of int.

2. Aliases for Pointers:

typedef can be used to create aliases for pointer types. This is particularly useful for complex pointer declarations.
For example, typedef float* FloatPtr; gives us a convenient way to declare pointers to float values as FloatPtr, improving code clarity.

3. Aliases for Arrays:

Arrays can be cumbersome to declare and maintain, especially when dealing with multiple arrays of the same type and size.
With typedef, we can define aliases for array types. For example, typedef int IntArray[10]; simplifies the declaration of arrays of integers with a size of 10.

4. Aliases for Functions:

typedef is versatile enough to create aliases for function types. This is valuable when dealing with function pointers or defining function pointer arrays.
Consider typedef int (*MathFunction)(int, int);, which defines MathFunction as a type representing functions taking two integers and returning an integer.

5. Aliases for Structures:

When working with structures, typedef can streamline code by providing shorter names for structure types.
For instance, typedef struct { char name[20]; int age; } Person; allows us to declare Person variables instead of struct variables, simplifying our code.

6. Advantages of typedef:

Improved Readability: Aliases make code more self-explanatory and easier to understand, reducing the need for comments.
Code Portability: When transitioning code between platforms with different data type sizes, updating typedef declarations is more straightforward than modifying multiple instances of a data type.
Enhanced Maintainability: typedef centralizes type definitions, making it easier to refactor code or switch data types when necessary.

7. Difference from #define Directives:

typedef is interpreted by the compiler and applies specifically to type definitions.
#define directives are processed by the preprocessor and can be used for text substitution, making them more versatile but less type-safe.
In essence, typedef is a powerful tool that aids in code organization, enhances readability, and simplifies code maintenance by providing meaningful and concise aliases for various programming constructs.

*/

#include <stdio.h>

#define fp float *

int main() {
    fp pl, p2, p3; // Using #define to define fp as float *
    typedef float *fptr; // Using typedef to define fptr as a pointer to float
    fptr ptrl, ptr2, ptr3;

    printf("%u %u %u\n", sizeof(pl), sizeof(p2), sizeof(p3));
    printf("%u %u %u\n", sizeof(ptrl), sizeof(ptr2), sizeof(ptr3));

    return 0;
}

/*

This program demonstrates the difference between using the #define directive and the typedef declaration to define a new name for a pointer to float. Let's break down the code and its output:

Here's what's happening:

#define fp float *: This line uses the #define directive to create a macro fp that is replaced by float *. So, fp pl, p2, p3; is expanded to float * pl, p2, p3;. This means that pl is a pointer to float, but p2 and p3 are regular variables.

typedef float *fptr;: Here, we use typedef to create an alias fptr for the type "pointer to float." So, fptr ptrl, ptr2, ptr3; declares ptrl, ptr2, and ptr3 as pointers to float.

The printf statements display the size of each variable using the sizeof operator.

Output:

The first printf shows that pl (defined with #define) has a larger size (4 bytes) because it's a pointer to float. On the other hand, p2 and p3 are regular variables, so they have a smaller size (usually 2 bytes).

The second printf shows that ptrl, ptr2, and ptr3 (defined with typedef) all have the same size, which is typically 4 bytes because they are all pointers to float.

So, the key difference is that #define is used for text substitution before compilation, and it doesn't create a new type; it simply replaces one text with another.

typedef, on the other hand, creates a new type alias, making the code more expressive and less error-prone.

In this case, typedef successfully defines a new name for the type "pointer to float," while #define is used for text substitution and doesn't create a new type.

-------------------------------------------

Yes, your understanding of the difference between #define and typedef is correct.

#define is a preprocessor directive that allows you to define macros. Macros are simply text replacements that are performed by the preprocessor before the code is compiled.

typedef is a keyword that allows you to define new names for existing data types. This can be useful for making your code more readable and maintainable.

In your example program, the #define directive is used to define a macro called fp. This macro is expanded to the text float * whenever it is used in the code.

The typedef declaration is used to define a new name for the data type float *. This new name is called fptr.

When the compiler sees the declaration fp pl, p2, p3;, it expands the macro fp to float *. This means that the variables pl, p2, and p3 are all declared as pointers to floats.

When the compiler sees the declaration fptr ptrl, ptr2, ptr3;, it recognizes fptr as a new data type that is defined as float *. This means that the variables ptrl, ptr2, and ptr3 are also declared as pointers to floats.

The output of the program shows that the size of all of the variables is the same, which is 4 bytes. This is because all of the variables are pointers to floats.

It is important to note that #define macros are not type-safe. This means that you can accidentally use a macro in a way that is not intended. For example, you could accidentally use the macro fp to define a variable that is not a pointer to float.

Typedef declarations, on the other hand, are type-safe. This means that the compiler will not allow you to use a typedef name in a way that is not intended. For example, the compiler would not allow you to use the typedef name fptr to define a variable that is not a pointer to float.

In general, it is better to use typedef declarations instead of #define macros to define new names for data types. This is because typedef declarations are type-safe and make your code more readable and maintainable.


Now, to examples.....


*/

#include <stdio.h>

// Structure definition
struct A {
    int marks;
    char grade;
};

// Function to initialize and print struct A
void initializeStructA() {
    struct A Al;
    Al.marks = 80;
    Al.grade = 'A';

    printf("Marks: %d\n", Al.marks);
    printf("Grade: %c\n", Al.grade);
}

// Structure definition
struct student {
    char name[20];
    int age;
};

// Function to initialize and print struct student
void initializeStructStudent() {
    struct student stul = {"Anita", 10};
    struct student stu2 = {"Anita", 12};

    if (stul.age == stu2.age && strcmp(stul.name, stu2.name) == 0)
        printf("Same\n");
    else
        printf("Not same\n");
}

// Structure definition
struct tag {
    int i;
    char c;
};

// Function to initialize and print struct tag
void initializeStructTag() {
    struct tag var = {2, 's'};
    printf("%d %c\n", var.i, var.c);
}

// Function to modify struct tag using a pointer
void modifyStructTag(struct tag *ptr) {
    ptr->i++;
}

int main() {
    // Call the functions to demonstrate each struct and its operations
    initializeStructA();
    initializeStructStudent();
    initializeStructTag();

    // Modify struct tag using a pointer
    struct tag var = {12, 'c'};
    modifyStructTag(&var);
    printf("Modified i: %d\n", var.i);

    return 0;
}

/*

In this program:

We have defined three structures: struct A, struct student, and struct tag.
Each structure is initialized and printed in its respective function: initializeStructA, initializeStructStudent, and initializeStructTag.
We also demonstrate how to modify a structure using a pointer in the modifyStructTag function.
The main function calls these functions one by one to demonstrate each structure and its operations.
This program separates each part into functions for clarity and maintains the logic of your original code.

-------------------------------------------

Program Overview:

This program demonstrates the use of structures and functions in C.
Structures:

struct A: This structure represents student data, including marks and grade.

struct student: Another structure represents student information with name and age.

struct tag: A simple structure with i and c members is used for demonstration.

Functions:

initializeStructA: Initializes a struct A variable, sets values for marks and grade, and prints them.

initializeStructStudent: Initializes two struct student variables, stul and stu2, compares their age and name, and prints whether they are the same or not.

initializeStructTag: Initializes a struct tag variable, var, and prints its i and c members.

modifyStructTag: Takes a pointer to a struct tag, increments the i member, and prints the modified i value.

Main Function:

In the main function, we call each of the above functions to demonstrate each structure and its operations.
We show how structures are initialized and accessed, and how they can be modified using pointers.
Output:

The program's output displays the values of different structure members and the results of comparisons and modifications.

Overall, this program serves as a practical example of using structures and functions in C to manage and manipulate data efficiently.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure definition for the first part
union tag1 {
    char name[15];
    int age;
};

// Function for the first part
void demonstrateUnion() {
    union tag1 rec;
    strcpy(rec.name, "Somalika");
    rec.age = 23;
    printf("Name: %s\n", rec.name);
    printf("Age: %d\n", rec.age);
}

// Structure definition for the second part
struct tag2 {
    char a[20];
    int b;
    union {
        double c;
        struct {
            char d[15];
            float e;
        } x;
    } y;
};

// Function for the second part
void demonstrateNestedUnion() {
    struct tag2 z;
    printf("Sizes: %u %u %u\n", sizeof(z.y.x), sizeof(z.y), sizeof(z));
}

// Typedef definition for the third part
typedef short unsigned int s_int;

// Function for the third part
void demonstrateTypedef() {
    s_int var;
    printf("%u\n", var);
}

// Structure definition for the fourth part
struct tag3 {
    int i;
    char c;
};

// Function for the fourth part
void demonstrateStruct() {
    struct tag3 vl = {1, 'a'};
    struct tag3 v2 = {2, 'b'};
    printf("%d %c %d %c\n", vl.i, vl.c, v2.i, v2.c);
}

// Structure definition for the fifth part
struct node {
    struct {
        char name[20];
        int data;
    } stu;
    struct node* link;
};

// Function for the fifth part
void demonstrateNestedStructAndMalloc() {
    struct node* p = malloc(sizeof(struct node));
    struct node* ptr = malloc(sizeof(struct node));

    p->stu.age = 30;
    ptr->stu.data = 3;

    printf("Age: %d\n", p->stu.age);
    printf("Data: %d\n", ptr->stu.data);

    free(p);
    free(ptr);
}

int main() {
    // Call each function to demonstrate its respective part
    demonstrateUnion();
    demonstrateNestedUnion();
    demonstrateTypedef();
    demonstrateStruct();
    demonstrateNestedStructAndMalloc();

    return 0;
}

/*

Explanation of the Hard Parts:

Nested Union and Struct (Part 2):

In this part, we define a structure (tag2) with a nested union and struct.
The y member is a union that can either hold a double or a nested struct (x) with a char array and a float.
The hard part here is understanding the concept of nesting different data types within a union and struct, which allows for flexible data storage.

Typedef (Part 3):

In this part, we use typedef to create an alias (s_int) for a short unsigned int.
The challenge is grasping the purpose of typedef and how it simplifies type declarations by providing a shorter name for a data type.

Dynamic Memory Allocation and Nested Struct (Part 5):

In this part, we define a structure (node) that contains a nested struct (stu) and a pointer to another node.

We allocate memory for two node structures using malloc.

The complexity here lies in managing memory allocation and understanding how to access members of nested structures through pointers.

These parts involve more advanced concepts in C, including nested data structures, memory allocation, and typedef. Understanding these concepts is essential for working with complex data structures and dynamic memory in C programs.

Sure, let's start with the first exercise: "Write a program to accept the name, age, and address of five persons and display the name of each person."

Here's a C program to accomplish that task:

*/

#include <stdio.h>

// Define a structure to represent a person
struct Person {
    char name[50];
    int age;
    char address[100];
};

int main() {
    // Declare an array to hold information for five persons
    struct Person people[5];

    // Accept input for each person
    for (int i = 0; i < 5; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", people[i].name);

        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &people[i].age);

        printf("Enter address for person %d: ", i + 1);
        scanf("%s", people[i].address);
    }

    // Display the names of each person
    printf("Names of the persons:\n");
    for (int i = 0; i < 5; i++) {
        printf("Person %d: %s\n", i + 1, people[i].name);
    }

    return 0;
}

/*

Explanation:

We define a structure named Person to store information about a person, including their name, age, and address.

In the main function, we declare an array people to hold information for five persons.

We use a for loop to accept input for each person's name, age, and address.

After collecting the data, we display the names of each person using another for loop.

The program provides a basic example of accepting and displaying information for multiple persons.

You can run this program and enter the name, age, and address for each of the five persons, and it will display their names.

-----------------------------------------

Of course, let's move on to the second exercise: "Write a program to accept the name and arrival time of five trains and display the name with the Rail time format (e.g., 2 PM as 14.00)."

Here's a C program to accomplish this task:

*/


#include <stdio.h>

int main() {
    char trainNames[5][50];
    int arrivalTimes[5];

    // Accept input for train names and arrival times
    for (int i = 0; i < 5; i++) {
        printf("Enter name for train %d: ", i + 1);
        scanf("%s", trainNames[i]);

        printf("Enter arrival time for train %d (in 12-hour format, e.g., 2 PM as 2): ", i + 1);
        scanf("%d", &arrivalTimes[i]);
    }

    // Display train names with arrival times in Rail time format
    printf("Train Schedule (Rail Time Format):\n");
    for (int i = 0; i < 5; i++) {
        if (arrivalTimes[i] >= 1 && arrivalTimes[i] <= 12) {
            printf("Train %d: %s - %d.00 AM\n", i + 1, trainNames[i], arrivalTimes[i]);
        } else {
            printf("Train %d: %s - %d.00 PM\n", i + 1, trainNames[i], arrivalTimes[i] - 12);
        }
    }

    return 0;
}

/*

Explanation:

In this program, we declare two arrays: trainNames to store the names of the trains and arrivalTimes to store their arrival times in 12-hour format.

We use a for loop to accept input for the names and arrival times of five trains.

The user is prompted to enter the name of each train and its arrival time.

After collecting the data, we display the train schedule in Rail time format using another for loop. We convert the 12-hour format to Rail time format, where morning times remain the same, and afternoon times are adjusted accordingly.

The program provides a way to input train information and display it in the required format.

You can run this program, input train names and their arrival times, and it will display the schedule in Rail time format.


--------------------------------------------

Let's move on to the third exercise: "Write a program to accept 10 records with the structure - struct { char *name; int *age; float salary; } Display the records before sorting and after sorting. Sorting is based on the primary key 'name' and secondary key 'age'."

For this exercise, we'll create a C program that accepts 10 records, sorts them based on name and age, and then displays the sorted records. We'll use a function to perform the sorting.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for a record
struct Record {
    char name[50];
    int age;
    float salary;
};

// Function to compare two records for sorting
int compareRecords(const void *a, const void *b) {
    struct Record *recordA = (struct Record *)a;
    struct Record *recordB = (struct Record *)b;

    // First, compare by 'name'
    int nameComparison = strcmp(recordA->name, recordB->name);

    // If names are the same, compare by 'age'
    if (nameComparison == 0) {
        return recordA->age - recordB->age;
    }

    return nameComparison;
}

int main() {
    struct Record records[10];

    // Accept input for 10 records
    for (int i = 0; i < 10; i++) {
        printf("Enter name for record %d: ", i + 1);
        scanf("%s", records[i].name);

        printf("Enter age for record %d: ", i + 1);
        scanf("%d", &records[i].age);

        printf("Enter salary for record %d: ", i + 1);
        scanf("%f", &records[i].salary);
    }

    // Display records before sorting
    printf("Records before sorting:\n");
    for (int i = 0; i < 10; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", records[i].name, records[i].age, records[i].salary);
    }

    // Sort the records based on 'name' and 'age'
    qsort(records, 10, sizeof(struct Record), compareRecords);

    // Display records after sorting
    printf("\nRecords after sorting:\n");
    for (int i = 0; i < 10; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", records[i].name, records[i].age, records[i].salary);
    }

    return 0;
}

/*

Explanation:

We define a structure named Record to store information about a person, including their name, age, and salary.

In the compareRecords function, we define the comparison logic for sorting records. We first compare by name, and if names are the same, we compare by age.

In the main function, we declare an array records to hold information for 10 records.

We use a for loop to accept input for each record's name, age, and salary.

After collecting the data, we display the records before sorting.

We then use the qsort function from the <stdlib.h> library to sort the records based on the compareRecords function.

Finally, we display the records after sorting.

This program allows you to input records, sort them by name and age, and then display the sorted records.

--------------------------------------------------

Let's move on to the fourth exercise: "Write a program to accept five records of employees. The structure is - struct { char name[25]; int age; int basic; } Calculate the total salary of the employees as Total salary = Basic + DA + HRA. DA (Dearness Allowance) is 10% of the basic, and HRA (House Rent Allowance) is 5% of the basic. Display the name, age, and total salary of the employees in descending order based on salary."

For this exercise, we'll create a C program that accepts information for five employees, calculates their total salary, and displays the employee details in descending order based on their total salary. We'll use a sorting function for this purpose.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for an employee
struct Employee {
    char name[25];
    int age;
    int basic;
    float totalSalary;
};

// Function to calculate the total salary of an employee
void calculateTotalSalary(struct Employee *employee) {
    float da = 0.10 * employee->basic; // 10% of basic as DA
    float hra = 0.05 * employee->basic; // 5% of basic as HRA
    employee->totalSalary = employee->basic + da + hra;
}

// Function to compare two employees for sorting by total salary in descending order
int compareEmployees(const void *a, const void *b) {
    struct Employee *employeeA = (struct Employee *)a;
    struct Employee *employeeB = (struct Employee *)b;
    return (employeeB->totalSalary - employeeA->totalSalary);
}

int main() {
    struct Employee employees[5];

    // Accept input for 5 employees
    for (int i = 0; i < 5; i++) {
        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", employees[i].name);

        printf("Enter age for employee %d: ", i + 1);
        scanf("%d", &employees[i].age);

        printf("Enter basic salary for employee %d: ", i + 1);
        scanf("%d", &employees[i].basic);

        // Calculate total salary for each employee
        calculateTotalSalary(&employees[i]);
    }

    // Sort employees in descending order of total salary
    qsort(employees, 5, sizeof(struct Employee), compareEmployees);

    // Display employee details after sorting
    printf("\nEmployee Details (Descending Order of Total Salary):\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d, Total Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].totalSalary);
    }

    return 0;
}


/*

Explanation:

We define a structure named Employee to store information about an employee, including their name, age, basic salary, and total salary.

The calculateTotalSalary function calculates the total salary of an employee based on the given formula, including Dearness Allowance (DA) and House Rent Allowance (HRA).

In the main function, we declare an array employees to hold information for 5 employees.

We use a for loop to accept input for each employee's name, age, and basic salary. Then, we calculate the total salary for each employee using the calculateTotalSalary function.

After collecting the data and calculating total salaries, we sort the employees in descending order based on total salary using the qsort function.

Finally, we display the employee details in descending order of total salary.

This program allows you to input employee details, calculate their total salaries, and display the employee information in descending order based on total salary.


---------------------------------------

Let's continue with the fifth exercise: "Write a program to concatenate one linked list at the end of another."

In this exercise, we'll create a C program that concatenates one linked list to the end of another linked list. We'll define and manipulate linked lists for this purpose.

*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of a linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to concatenate two linked lists
void concatenateLists(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
    } else {
        struct Node* current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize two linked lists
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Add elements to the first linked list
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    appendNode(&list1, 3);

    // Add elements to the second linked list
    appendNode(&list2, 4);
    appendNode(&list2, 5);

    // Display both linked lists before concatenation
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Concatenate list2 at the end of list1
    concatenateLists(&list1, list2);

    // Display the concatenated list
    printf("\nConcatenated List: ");
    printList(list1);

    return 0;
}


/*

Explanation:

We define a structure named Node to represent a node in the linked list. Each node contains an integer data value (data) and a pointer to the next node (next).

The appendNode function adds a new node with the given data to the end of a linked list.

In the main function, we initialize two linked lists (list1 and list2) and add elements to each of them using the appendNode function.

We display both linked lists before concatenation to show their contents.

The concatenateLists function concatenates the second linked list (list2) at the end of the first linked list (list1).

After concatenation, we display the concatenated list to demonstrate the result.

This program allows you to create and manipulate linked lists, including concatenating one linked list to the end of another.


---------------------------------


Let's move on to the sixth exercise: "Write a program to remove the first node of a linked list and insert it at the end."

In this exercise, we'll create a C program that removes the first node of a linked list, inserts it at the end, and then displays the modified linked list.

*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of a linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to remove the first node of a linked list and insert it at the end
void moveFirstToLast(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // No or only one node, nothing to move
        return;
    }

    struct Node* firstNode = *head;
    *head = firstNode->next;

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = firstNode;
    firstNode->next = NULL;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize a linked list
    struct Node* list = NULL;

    // Add elements to the linked list
    appendNode(&list, 1);
    appendNode(&list, 2);
    appendNode(&list, 3);
    appendNode(&list, 4);

    // Display the linked list before moving
    printf("Original List: ");
    printList(list);

    // Move the first node to the end
    moveFirstToLast(&list);

    // Display the modified list
    printf("List after moving first node to the end: ");
    printList(list);

    return 0;
}


/*

Explanation:

We define a structure named Node to represent a node in the linked list. Each node contains an integer data value (data) and a pointer to the next node (next).

The appendNode function adds a new node with the given data to the end of a linked list.

In the main function, we initialize a linked list (list) and add elements to it using the appendNode function.

We display the linked list before performing any operations to show its original contents.

The moveFirstToLast function removes the first node of the linked list and inserts it at the end.

After performing the move operation, we display the modified linked list to demonstrate the result.

This program allows you to remove the first node of a linked list and insert it at the end, effectively rotating the list.

----------------------------------------

Let's proceed with the seventh exercise: "Write a program to count the number of occurrences of an element in the list."

In this exercise, we'll create a C program that counts the number of occurrences of a specified element in a list. We'll define a function to perform this task.


*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of a linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to count the number of occurrences of an element in the linked list
int countOccurrences(struct Node* head, int target) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            count++;
        }
        current = current->next;
    }

    return count;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize a linked list
    struct Node* list = NULL;

    // Add elements to the linked list
    appendNode(&list, 2);
    appendNode(&list, 4);
    appendNode(&list, 6);
    appendNode(&list, 4);
    appendNode(&list, 8);

    // Display the linked list
    printf("Linked List: ");
    printList(list);

    // Specify the element to count
    int targetElement = 4;

    // Count the occurrences of the target element
    int count = countOccurrences(list, targetElement);

    printf("The element %d occurs %d times in the list.\n", targetElement, count);

    return 0;
}



/*

Explanation:

We define a structure named Node to represent a node in the linked list. Each node contains an integer data value (data) and a pointer to the next node (next).

The appendNode function adds a new node with the given data to the end of a linked list.

In the main function, we initialize a linked list (list) and add elements to it using the appendNode function.

We display the linked list to show its contents.

We specify the element (targetElement) whose occurrences we want to count.

The countOccurrences function counts the number of occurrences of the specified element in the linked list.

Finally, we display the count of occurrences of the target element.

This program allows you to count the occurrences of a specified element in a linked list.

------------------------------------------------

Let's proceed with the eighth exercise: "Find the largest and smallest element of a linked list, print the total of all elements, and find the average."

In this exercise, we'll create a C program that finds the largest and smallest elements in a linked list, calculates the total sum of all elements, and computes the average value of the elements.

*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of a linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to find the largest element in the linked list
int findLargestElement(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return 0;
    }

    int largest = head->data;
    struct Node* current = head->next;

    while (current != NULL) {
        if (current->data > largest) {
            largest = current->data;
        }
        current = current->next;
    }

    return largest;
}

// Function to find the smallest element in the linked list
int findSmallestElement(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return 0;
    }

    int smallest = head->data;
    struct Node* current = head->next;

    while (current != NULL) {
        if (current->data < smallest) {
            smallest = current->data;
        }
        current = current->next;
    }

    return smallest;
}

// Function to find the total sum of elements in the linked list
int findTotalSum(struct Node* head) {
    int sum = 0;
    struct Node* current = head;

    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }

    return sum;
}

// Function to find the average of elements in the linked list
float findAverage(struct Node* head) {
    int count = 0;
    int sum = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        sum += current->data;
        current = current->next;
    }

    if (count == 0) {
        return 0.0;
    }

    return (float)sum / count;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize a linked list
    struct Node* list = NULL;

    // Add elements to the linked list
    appendNode(&list, 5);
    appendNode(&list, 10);
    appendNode(&list, 15);
    appendNode(&list, 20);
    appendNode(&list, 25);

    // Display the linked list
    printf("Linked List: ");
    printList(list);

    // Find and print the largest and smallest elements
    int largest = findLargestElement(list);
    int smallest = findSmallestElement(list);

    printf("Largest Element: %d\n", largest);
    printf("Smallest Element: %d\n", smallest);

    // Find and print the total sum of elements
    int totalSum = findTotalSum(list);
    printf("Total Sum: %d\n", totalSum);

    // Find and print the average of elements
    float average = findAverage(list);
    printf("Average: %.2f\n", average);

    return 0;
}


/*

Explanation:

We define a structure named Node to represent a node in the linked list. Each node contains an integer data value (data) and a pointer to the next node (next).

The appendNode function adds a new node with the given data to the end of a linked list.

In the main function, we initialize a linked list (list) and add elements to it using the appendNode function.

We display the linked list to show its contents.

The functions findLargestElement and findSmallestElement find the largest and smallest elements in the linked list, respectively.

The findTotalSum function calculates the total sum of elements in the linked list.

The findAverage function computes the average value of elements in the linked list.

We display the largest and smallest elements, the total sum, and the average value of elements in the linked list.

This program allows you to find the largest and smallest elements, calculate the total sum, and compute the average of elements in a linked list.


-----------------------------------------

Let's move on to the ninth exercise: "Write a program that maintains records of students using a linked list. The structure of a node would be struct node { char name[20]; int rollno; int marks; struct node *link; }. Now search for a particular record based on roll number."

In this exercise, we'll create a C program that maintains records of students using a linked list. Each record includes the student's name, roll number, and marks. We'll implement functions to add records, display records, and search for a specific record based on the roll number.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
struct Student {
    char name[20];
    int rollno;
    int marks;
    struct Student* next;
};

// Function to add a student record to the linked list
void addStudent(struct Student** head, char name[20], int rollno, int marks) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->rollno = rollno;
    newNode->marks = marks;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display all student records in the linked list
void displayStudents(struct Student* head) {
    printf("Student Records:\n");
    printf("Name\tRoll No\tMarks\n");
    struct Student* current = head;
    while (current != NULL) {
        printf("%s\t%d\t%d\n", current->name, current->rollno, current->marks);
        current = current->next;
    }
}

// Function to search for a student record based on roll number
struct Student* searchStudentByRollNo(struct Student* head, int rollno) {
    struct Student* current = head;
    while (current != NULL) {
        if (current->rollno == rollno) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    // Initialize a linked list for student records
    struct Student* studentList = NULL;

    // Add student records
    addStudent(&studentList, "Alice", 101, 85);
    addStudent(&studentList, "Bob", 102, 78);
    addStudent(&studentList, "Charlie", 103, 92);

    // Display all student records
    displayStudents(studentList);

    // Search for a student record based on roll number
    int targetRollNo = 102;
    struct Student* foundStudent = searchStudentByRollNo(studentList, targetRollNo);

    if (foundStudent != NULL) {
        printf("\nStudent Found:\n");
        printf("Name: %s\n", foundStudent->name);
        printf("Roll No: %d\n", foundStudent->rollno);
        printf("Marks: %d\n", foundStudent->marks);
    } else {
        printf("\nStudent with Roll No %d not found.\n", targetRollNo);
    }

    return 0;
}


/*

Explanation:

We define a structure named Student to represent a student record. Each record includes the student's name, roll number, marks, and a pointer to the next record (next) in the linked list.

The addStudent function adds a new student record to the end of the linked list. It allocates memory for the new node, copies the name, roll number, and marks, and links the new node to the list.

In the main function, we initialize a linked list (studentList) to store student records and add several student records using the addStudent function.

The displayStudents function displays all student records in the linked list, showing their names, roll numbers, and marks.

The searchStudentByRollNo function searches for a student record based on the roll number. If a record with the specified roll number is found, it returns a pointer to that record; otherwise, it returns NULL.

In the main function, we search for a specific student record based on the roll number (e.g., 102) and display the details of the found student if they exist.

This program allows you to maintain and search for student records using a linked list data structure.

-------------------------------------------

Let's delve into the ninth exercise in more detail. In this exercise, we are tasked with creating a C program that manages student records using a linked list. Each student record includes the student's name, roll number, and marks. The program allows us to add records, display all records, and search for a specific record based on the roll number.

Here's a step-by-step breakdown of the program:

Define a Structure for Student Records:

*/

struct Student {
    char name[20];
    int rollno;
    int marks;
    struct Student* next;
};


/*

We define a structure called Student to represent a student record. This structure has three fields:

name: An array of characters to store the student's name (up to 20 characters).
rollno: An integer to store the student's roll number.
marks: An integer to store the student's marks.
next: A pointer to the next student record in the linked list.
Add Student Records to the Linked List:


*/

void addStudent(struct Student** head, char name[20], int rollno, int marks) { ... }


/*

The addStudent function adds a new student record to the linked list. It takes four parameters:

head: A pointer to the head of the linked list.
name: The student's name.
rollno: The student's roll number.
marks: The student's marks.
Inside the function, a new node is created, and the provided information is stored in this node. If the linked list is empty, the new node becomes the head. Otherwise, it's added to the end of the list.

Display Student Records:

*/

void displayStudents(struct Student* head) { ... }


/*

The displayStudents function displays all student records in the linked list. It traverses the list from the head to the end, printing the name, roll number, and marks of each student.

Search for a Student by Roll Number:

*/

struct Student* searchStudentByRollNo(struct Student* head, int rollno) { ... }

/*

The searchStudentByRollNo function searches for a student record based on the roll number. It takes two parameters:

head: A pointer to the head of the linked list.
rollno: The roll number to search for.
The function iterates through the list, comparing the roll number of each student with the target roll number. If a match is found, a pointer to that student record is returned. If no match is found, NULL is returned.

In the main function:

We initialize an empty linked list to store student records: struct Student* studentList = NULL;
We add several student records using the addStudent function.
We display all student records using the displayStudents function, showing their names, roll numbers, and marks.
We specify a target roll number (e.g., 102) and search for a student record with that roll number using the searchStudentByRollNo function. If found, we display the details of the found student; otherwise, we indicate that the student was not found.

This program provides a basic example of managing student records using a singly linked list. It allows you to add, display, and search for student records efficiently.

*/
