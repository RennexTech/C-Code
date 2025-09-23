/*

Linkage Types in C:

In C, there are three primary types of linkage:

External Linkage:

Variables and functions with external linkage can be accessed from any file within the program.
These are typically global variables and functions.
Example: Global variables or functions declared in one file can be accessed in other files of the program.
Internal Linkage:

Variables and functions with internal linkage are limited in scope to the file where they are declared.
Static global variables and static functions have internal linkage.
Example: A static variable declared in one file can't be accessed from another file.
No Linkage:

Variables with no linkage are typically local variables declared within a block or function.
These variables are confined to the scope in which they are declared and have no linkage to other parts of the program.
Example: Local variables declared inside a function.
Memory Organization During Program Execution:

When a C program is executed, memory is organized into various segments to hold different types of data:

Code Area:

This area stores the executable code of the program.
The size of this area is fixed and doesn't change during runtime.
Data Area:

The data area is further divided into two parts:
Initialized Data Area: This section stores initialized static and global variables.
Uninitialized Data Area: This section stores uninitialized static and global variables.
The reason for this division is that all uninitialized variables can collectively be assigned the value zero.
The size of the data area is also fixed and doesn't change during runtime.
Heap:

The heap is used for dynamically allocated memory.
Programs can allocate and deallocate memory from the heap as needed.
The size of the heap can change during runtime as memory is allocated and freed.
Stack:

The stack is used to store automatic variables.
Automatic variables are local variables declared within functions and blocks.
The size of the stack can change during program execution as functions are called and return.


============================================

Let's dive deep into the concepts of the stack and heap in C programming.

Stack:

The stack is a critical part of a program's memory management and plays a fundamental role in function calls and local variable storage. Here are detailed notes on the stack:

Function Calls:

When a function is called in a C program, a portion of the stack memory is allocated for that function's execution.
This portion is known as a "stack frame" or "activation record."
Stack Frames:

Each function call creates a new stack frame on top of the previous one.
A stack frame typically includes:
Return address: The address to return to after the function completes.
Local variables: Space for function-specific variables.
Function parameters: Values passed to the function.
Bookkeeping information: Such as the previous frame's base pointer.
LIFO Principle:

The stack follows the "Last-In-First-Out" (LIFO) principle, meaning the most recently called function is the first to finish.
When a function finishes, its stack frame is "popped" from the stack, and control returns to the calling function.
Automatic Variables:

Local variables declared within a function are stored on the stack.
These variables have a limited lifetime, only existing within the function's scope.
When the function exits, the memory used by its automatic variables is reclaimed.
Stack Size:

The size of the stack is finite and usually set by the operating system.
If a program exceeds the stack size, it may result in a stack overflow, causing the program to crash.
Heap:

The heap is a dynamic memory area that allows programs to allocate and deallocate memory during runtime. Here's a deep dive into the heap:

Dynamic Memory Allocation:

The heap is used for dynamic memory allocation, where memory is requested and released as needed during program execution.
Manual Memory Management:

In C, memory allocation and deallocation in the heap are done manually using functions like malloc, calloc, realloc, and free.
Memory Leaks:

Improperly managed memory on the heap can lead to memory leaks, where allocated memory is not properly released, causing the program to consume more and more memory over time.
Heap Fragmentation:

Continuous allocation and deallocation of memory on the heap can lead to heap fragmentation.
Fragmentation can make it challenging to allocate contiguous blocks of memory when needed.
Heap vs. Stack:

Unlike the stack, the heap is not automatically managed by the compiler or the program's execution flow.
It provides flexibility but requires careful management to prevent memory leaks and fragmentation.
Heap Size:

The size of the heap is often limited by the available system memory.
The operating system may allocate more heap memory as needed but with certain limits.
Memory Management:

Effective memory management in C involves understanding when to use the stack for short-lived variables and when to use the heap for dynamically allocated data with a longer lifespan. It also involves responsible use of heap memory allocation functions to avoid memory leaks and fragmentation.

Both the stack and heap are essential components of a C program's memory management, and a good understanding of their intricacies is crucial for writing efficient and reliable code.

===========================================

Let's break down the concepts of the stack and heap in a super simple way:

Stack:

Stack is like a stack of books:

Imagine you have a stack of books, and you can only put or take one book on top at a time.
The book on top is the one you're currently reading.
Function Calls are Like Adding Books:

When you call a function in your program, it's like adding a new book on top of the stack.
The function's job is to read that book (do its work) and then put it away (remove it from the stack).
LIFO - Last In, First Out:

The rule here is "Last In, First Out," just like taking the last book you added off the stack first.
So, the function that was added last is the one that finishes first.
Local Variables:

Inside each function, you have some special bookmarks and notes you use while reading the book.
These are like local variables, and they only exist while you're reading that book.
When you're done with the book (function), you remove the bookmarks and notes (variables).
Stack Size:

The stack can only hold a limited number of books (functions) because it's a physical space.
If you have too many books (functions) on the stack, it might fall over (crash your program).
Heap:

Heap is Like a Magic Bookshelf:

Unlike the stack, the heap is like a magical bookshelf where you can add and remove books anytime.
You don't have to follow any specific order.
Dynamic Memory:

You use the heap when you want to create or destroy books (data) while you're already reading (running) your program.
It's like magically creating new pages in a book or removing them.
Manual Management:

The trick is that you need to keep track of how many pages you've added and when you're done with them.
You do this using special spells (functions like malloc and free) to create and destroy pages (memory).
Memory Leaks:

Forgetting to remove pages (free memory) can be bad; it's like having too many books lying around your room.
It makes your room messy (your program uses too much memory).
Heap Size:

The heap can grow as needed, but there's still a limit based on your computer's memory.

If you use too much, your program might run out of memory.

So, in short, the stack is like a neat stack of books where you follow a strict order, while the heap is like a magical bookshelf where you can create and remove books whenever you want. Just remember to keep your room (memory) clean and organized!


==========================================

Constant Variables:

A const variable is like a rule that says, "Once I'm set, I can't be changed."

You can declare a variable as const by putting const before or after its type, like const int x or int const x. Both are the same.

If you try to change a const variable's value later in your program, you'll get an error.

It's like having a treasure chest that you can only open once. Once you see what's inside, you can't put anything else in or take anything out.

Arrays, Structures, and Unions:

If you make an array, structure, or union const, it means everything inside it is also off-limits for changes.

For example, if you have a const int arr[5], you can't change any of its values like arr[2] = 22. It's like having a box with locks, and you can't change what's inside the box.

Limitations:

const variables aren't super-flexible. You can't use them where the size of something needs to be known at compile-time, like when declaring arrays or case labels in a switch statement.

For example, you can't do const int size = 10; int arr[size];. It's like trying to use a locked box to decide how big another box should be.

Pointers with const:

When you use const with pointers, you're telling the program, "This pointer can't be used to change what it's pointing to."

There are three types of pointer const:

Pointer to const data: You can't change what it points to.
const pointer: You can't make it point to something else.
const pointer to const data: You can't change what it points to, and you can't make it point to something else.
It's like having a map that you can't draw on, a pencil that's stuck in one place, or a map and a pencil that are both locked down.

Cautions:

Be careful when you try to make a regular variable point to a const variable. You need to use a special trick with the & symbol.

If you try to change the value of a const variable using a regular pointer, it's like trying to open a treasure chest with the wrong key. The result is undefined, and your program might crash.

Remember, const is all about making things read-only and locking them down to prevent accidental changes.


*/

//1. const Variable:

#include <stdio.h>

int main() {
    const int x = 9;
    // Trying to change a const variable will result in an error
    // x = 10; // Invalid
    printf("x: %d\n", x);
    return 0;
}

//2. const Array:

#include <stdio.h>

int main() {
    const int arr[5] = {10, 11, 12, 13, 14};
    // Trying to change a const array element is invalid
    // arr[2] = 22; // Invalid
    printf("arr[2]: %d\n", arr[2]);
    return 0;
}

//3. Pointers with const:

#include <stdio.h>

int main() {
    const int a = 2, b = 6;

    // Pointer to const data
    const int *ptr1 = &a;
    // *ptr1 = 9; // Invalid, can't change data through ptr1
    ptr1 = &b; // Valid, ptr1 can point to different const data

    // Const pointer
    int *const ptr2 = &a;
    *ptr2 = 9; // Valid, can change data through ptr2
    // ptr2 = &b; // Invalid, can't make ptr2 point to something else

    // Const pointer to const data
    const int *const ptr3 = &a;
    // *ptr3 = 9; // Invalid, can't change data through ptr3
    // ptr3 = &b; // Invalid, can't make ptr3 point to something else

    printf("a: %d, *ptr2: %d\n", a, *ptr2);
    return 0;
}


//4. Heap Allocation:

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray = (int *)malloc(5 * sizeof(int));
    if (dynamicArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("dynamicArray[%d]: %d\n", i, dynamicArray[i]);
    }

    free(dynamicArray); // Don't forget to release allocated memory

    return 0;
}



//Example 2 of const and pointers:

#include <stdio.h>

int main() {
    int num = 42;
    const int* ptr1 = &num;  // Pointer to constant integer

    // (*ptr1) = 50;  // Invalid, can't modify the value through ptr1
    printf("Value pointed by ptr1: %d\n", *ptr1);

    int anotherNum = 100;
    ptr1 = &anotherNum;  // Valid, can change where ptr1 points
    printf("Value pointed by ptr1 after change: %d\n", *ptr1);

    int* const ptr2 = &num;  // Constant pointer to integer

    (*ptr2) = 55;  // Valid, can modify the value through ptr2
    printf("Value pointed by ptr2 after change: %d\n", *ptr2);

    // ptr2 = &anotherNum;  // Invalid, can't change where ptr2 points

    const int* const ptr3 = &num;  // Constant pointer to constant integer

    // (*ptr3) = 60;  // Invalid, can't modify the value through ptr3
    // ptr3 = &anotherNum;  // Invalid, can't change where ptr3 points

    printf("Value pointed by ptr3: %d\n", *ptr3);

    return 0;
}

/*

In this code:

ptr1 is a pointer to a constant integer, meaning you can't modify the integer it points to, but you can change where the pointer points.

ptr2 is a constant pointer to an integer, meaning you can modify the integer it points to, but you can't change where the pointer points.

ptr3 is a constant pointer to a constant integer, meaning you can't modify the integer it points to, and you can't change where the pointer points.

The comments in the code indicate which operations are valid and which are not for each pointer type.


==========================================

Is there a difference between int *ptr; and int* ptr; and (*ptr)int or and other forms what are the forms of writing pointers that confuse people??

------------------------------------------

Yes, there can be some confusion regarding the placement of the asterisk (*) when declaring pointers in C and C++. Let me clarify the differences:

int *ptr; and int* ptr;:

Both of these declarations are equivalent. They both declare a pointer to an integer. The placement of the asterisk is a matter of style and personal preference. You can use either form, and it's up to you to choose which one you find more readable. Both int *ptr; and int* ptr; declare a pointer named ptr that can point to an integer.

(*ptr) int:
This is not a valid pointer declaration. The (*ptr) syntax is used when you already have a pointer variable declared, and you want to dereference it to access the value it points to. For example:
*/

int x = 10;
int *ptr = &x;
int value = (*ptr); // Dereferencing ptr to get the value it points to (value will be 10)


/*

So, (*ptr) int is not a pointer declaration but rather a usage of a pointer.

Other forms that can confuse people include complex pointer declarations involving arrays and functions, such as:

int (*ptr)[5];: This declares a pointer to an array of integers with a fixed size of 5 elements.

int *ptr[5];: This declares an array of 5 integer pointers.

int (*ptr)(int);: This declares a pointer to a function that takes an integer argument and returns an integer.

These forms can be confusing, especially when dealing with pointers to arrays and functions, so it's essential to understand the specific syntax and semantics associated with each type of declaration.

*/

















