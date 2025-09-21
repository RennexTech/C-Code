#include <stdio.h>
#include <stdlib.h>

/*

----------------------------------------

Dynamic Memory Allocation

----------------------------------------

Static memory allocation is the process of allocating memory at compile time. The size of the memory that can be used by the program is fixed and cannot be increased or decreased during the execution of the program.

Dynamic memory allocation is the process of allocating memory at runtime. The size of the memory that can be used by the program is not fixed and can be increased or decreased during the execution of the program.

Dynamic memory allocation is useful in situations where the amount of memory required by the program is not known at compile time.

For example, if we are writing a program to sort an array of numbers, we may not know how many numbers will be in the array until the program is running.

In this case, we can use dynamic memory allocation to allocate an array of the appropriate size at runtime.

---------------------------------------

Static vs. Dynamic Memory Allocation: In C, you're familiar with static memory allocation, where the memory size is fixed at compile-time.

For example, when you declare an array like int emp_no[200];, you allocate memory for 200 integers, which might be wasteful if you don't use all of it.

---------------------------------------

Need for Dynamic Memory Allocation: Dynamic memory allocation solves the problems of wastage and inflexibility.

With dynamic allocation, you can request memory as needed during the program's execution.

---------------------------------------

malloc() Function: The primary function for dynamic memory allocation in C is malloc().

Its declaration is void *malloc(size_t size);. It takes the number of bytes you want to allocate as an argument and returns a pointer to the allocated memory.

---------------------------------------

Type Casting: The pointer returned by malloc() is of type void*, which is a generic pointer type.

To use it effectively, you should cast it to the appropriate data type.

For example, int* ptr = (int*)malloc(10); allocates memory for 10 integers and assigns a pointer to that memory to the ptr variable, treating it as an array of integers.

----------------------------------------

Advantages of dynamic memory allocation:

It allows us to allocate memory at runtime, which is useful in situations where the amount of memory required by the program is not known at compile time.

It allows us to deallocate memory when it is no longer needed, which helps to prevent memory leaks.

It allows us to create more complex data structures, such as linked lists and trees.

----------------------------------------


Disadvantages of dynamic memory allocation:

It can be more complex to write and debug programs that use dynamic memory allocation.
If we do not deallocate memory when it is no longer needed, we can create memory leaks.

----------------------------------------

Dynamic memory allocation in C.

----------------------------------------

The following C functions are used for dynamic memory allocation:

malloc(): Allocates a block of memory of the specified size.

calloc(): Allocates a block of memory of the specified size and initializes it to zero.

realloc(): Resizes an existing block of memory.

free(): Deallocates a block of memory.

----------------------------------------

Example:

The following example shows how to use dynamic memory allocation to create an array of integers:

*/
#include <stdlib.h>

int main() {
  int *ptr;
  int size;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Allocate memory for the array.
  ptr = (int *)malloc(sizeof(int) * size);

  // Check if memory allocation was successful.
  if (ptr == NULL) {
    printf("Error allocating memory.\n");
    exit(1);
  }

  // Use the array.
  // ...

  // Deallocate the memory.
  free(ptr);

  return 0;
}

/*
ptr = (datatype *)malloc(specified size);
void *malloc(size_t size);

Important notes:

It is important to deallocate all dynamically allocated memory when it is no longer needed. This can be done using the free() function.

If we do not deallocate dynamically allocated memory, we can create memory leaks. A memory leak is a situation where memory is allocated but never deallocated. This can lead to performance problems and even crashes.

It is also important to note that dynamic memory allocation can be complex. It is important to understand how to use the malloc(), calloc(), realloc(), and free() functions correctly.

Remember to always check if the memory allocation was successful by verifying if malloc() returns a non-null pointer, as shown in the code above. Also, don't forget to release the allocated memory using free() when you're done with it to avoid memory leaks.

*/

int *ptr;
ptr = (int *) malloc (10);

/*

The statement int *ptr; ptr = (int *) malloc (10); allocates 10 contiguous bytes of memory space and the address of the first byte is stored in the pointer variable ptr. This space can hold 5 integers. The allocated memory contains garbage value.

It is important to note that the size of the allocated memory is specified in bytes. To make the program portable and more readable, we can use the sizeof operator to determine the size of the data type we are allocating memory for. For example, to allocate memory for 5 integers, we would use the following statement:

*/

ptr = (int *) malloc (5 * sizeof (int));


/*

If there is not sufficient memory available in the heap, malloc() will return NULL. Therefore, it is always a good idea to check the value returned by malloc(). For example:

*/

ptr = (float *) malloc(10*sizeof(float));
if (ptr == NULL) {
  printf("Sufficient memory not available");
}

/*

Unlike memory allocated for variables and arrays, dynamically allocated memory has no name associated with it.

So it can be accessed only through pointers. We can use pointer arithmetic to access the subsequent bytes of the allocated memory.

For example, to access the second integer in the array, we would use the following statement:

*/

*(ptr + 1)

/*

It is important to deallocate all dynamically allocated memory when it is no longer needed. This can be done using the free() function.

If we do not deallocate dynamically allocated memory, we can create memory leaks.

A memory leak is a situation where memory is allocated but never deallocated. This can lead to performance problems and even crashes.

Continued:

*/

int* ptr = (int*)malloc(5 * sizeof(int));

// Accessing the first integer in the allocated memory
int firstValue = *ptr;

// Accessing the second integer using pointer arithmetic
int secondValue = *(ptr + 1);


/*

Accessing Dynamically Allocated Memory: Dynamically allocated memory doesn't have a name like variables or arrays. Instead, you access it through pointers. The pointer you receive from malloc() points to the first byte of the allocated memory block. You can use pointer arithmetic to access subsequent bytes. (as shown above)

Remember that dynamically allocated memory doesn't automatically get initialized with zero. It contains whatever values were in that memory location before, so it's good practice to initialize it explicitly if needed.


---------------------------------


Your program is correct and well-written. It is a good practice to typecast the pointer returned by malloc() to the appropriate type. This makes the code more readable and maintainable. It also helps to prevent errors.

Here is a brief explanation of your program:

*/

#include <stdio.h>
#include <stdlib.h> // This header is required for `malloc()` and `free()`.

int main() {
    // `p` is a pointer to an integer. It will store the memory address of the first element of our dynamically allocated array.
    int *p, n, i;

    printf("Enter the number of integers to be entered: ");
    scanf("%d", &n);

    // Dynamic memory allocation using `malloc()`.
    // `malloc(n * sizeof(int))` requests a block of memory large enough to hold `n` integers.
    // `(int *)` is a cast that converts the generic pointer returned by `malloc` to an integer pointer.
    p = (int *)malloc(n * sizeof(int));

    // Always check if the memory allocation was successful. `malloc()` returns `NULL` on failure.
    if (p == NULL) {
        printf("Error: Memory not available.\n");
        return 1; // Exit the program with an error code.
    }

    // Now we can treat `p` like an array. The loop prompts the user to enter integers and stores them in the allocated memory block.
    // `p + i` is pointer arithmetic, which calculates the address of the i-th integer.
    // `scanf` requires a pointer to where the data should be stored.
    for (i = 0; i < n; i++) {
        printf("Enter an integer: ");
        scanf("%d", p + i);
    }

    printf("\nThe integers you entered are:\n");

    // This loop prints the integers from the dynamically allocated memory.
    // `*(p + i)` dereferences the pointer, which gives us the value stored at that memory address.
    for (i = 0; i < n; i++) {
        printf("%d\t", *(p + i));
    }
    printf("\n");

    // Free the memory. This is crucial!
    // `free(p)` deallocates the memory block pointed to by `p`, returning it to the system.
    // Failing to do this causes a "memory leak," where the memory remains unavailable for other programs.
    free(p);

    return 0;
}

/*

First, you declare two pointers, p and n. The pointer p will store the address of the dynamically allocated memory, and the pointer n will store the number of integers to be entered by the user.

Next, you prompt the user to enter the number of integers. You then use the malloc() function to allocate memory for an array of n integers. You check if the memory allocation was successful. If it was not successful, you print an error message and exit the program.

Next, you read the integers from the user and store them in the dynamically allocated array. You then print the integers to the console.

Finally, you deallocate the dynamically allocated memory using the free() function.

This is a good example of how to use dynamic memory allocation in C.

Let's add two more explanations of the above code:

-------------------------------------

Here's what each part of the code does:

You include the necessary header files for standard input and output and memory allocation.

You prompt the user to enter the number of integers they want to store.

You use malloc() to allocate memory dynamically for an array of n integers. The sizeof(int) is used to ensure that the correct amount of memory is allocated for an integer on your system.

You check if the memory allocation was successful by testing if p is NULL. If it's NULL, it means that there's not enough memory available, and you print an error message and exit the program with a status code of 1.

You then use a loop to input n integers from the user and store them in the dynamically allocated memory, accessed using pointer arithmetic.

Finally, you use another loop to print the values stored in the allocated memory.

The typecasting of the pointer returned by malloc() to (int *) is indeed a good practice and helps ensure compatibility with C++ as well. Modern C code often uses malloc() with typecasting like this.

-----------------------------------------

First, you're using a computer program to do some math stuff with numbers. But before you start, you need to tell the program how many numbers you want to work with.

To store these numbers, you need a place in the computer's memory. Think of this like a bunch of boxes where you can put your numbers.

But here's the cool part: you can decide how many boxes you want based on the number you told the program in step 1. So, if you say you want to work with 5 numbers, it creates 5 boxes for you.

The program uses a special command called malloc() to make these boxes. It's like telling the computer, "Hey, I need this many boxes for my numbers."

But what if the computer doesn't have enough space for all the boxes you want? That's why there's a check to see if the computer can give you the boxes. If it can't, it says, "Sorry, not enough space," and you can't continue.

If you get the boxes (which are like slots in memory), you then go ahead and put your numbers into those slots, one by one.

Finally, you use another loop to look inside each box (slot) and see what numbers are in there. You print them out on the screen so you can see the results of your math.

So, in a nutshell, this code lets you tell the computer how many numbers you want to work with, creates boxes in memory for those numbers, stores your numbers in those boxes, and then shows you what you've got. It's like organizing your stuff in labeled boxes and then checking what's inside each one.

--------------------------------------------


*/


p = (int *) malloc(n * sizeof(int));


/*

Here's what each part of that line does:

p: This is like a special pointer that points to the first spot in the newly created memory space. We use it to keep track of where our memory starts.

malloc(): This is the magic box that makes space in memory for us. It's like saying, "Hey computer, I need some space, can you give me some?"

(int *): This part is like telling the computer what kind of stuff we plan to put in our space. In this case, we're saying we want to store integers (whole numbers).

n * sizeof(int): This part tells the computer how much space we need. n is the number of integers you want to store, and sizeof(int) is like asking the computer, "Hey, how many bytes does one integer need?" It helps ensure we get enough space for all our numbers.

So, when you put it all together, you're saying, "Computer, I need a bunch of space to store n integers, and each integer takes up this much space." Then, the computer finds that space, and p points to the beginning of it.

It's like asking for a shelf in your room to store your books. You tell the room how many books you have (n) and how much space each book needs (sizeof(int)). Then, the room gives you a shelf (p) where you can put your books (integers).

Remember, this shelf (p) is in the computer's memory, not in your room, but the idea is similar. You use p to access and organize your integers on that computer shelf.

------------------------------------------

I want us to understand malloc fully, so I'll be repeating:

The malloc() syntax is as follows:

*/

void *malloc(size_t size);

/*

The malloc() function takes a single argument, which is the size of the memory to be allocated in bytes. It returns a pointer to the allocated memory. If the allocation fails, malloc() returns NULL.

To use malloc(), you first need to declare a pointer to the type of data that you want to allocate memory for. For example, to allocate memory for an array of integers, you would declare a pointer to int.

*/

int *p;


/*

Next, you can use the malloc() function to allocate memory for the array. The following statement allocates memory for an array of 10 integers:

*/

p = (int *)malloc(10 * sizeof(int));

/*

The sizeof() operator returns the size of the data type in bytes. In this case, the sizeof() operator returns the size of an integer, which is 4 bytes. Therefore, the malloc() function allocates 40 bytes of memory for the array.

After the malloc() function has allocated memory, you can use the pointer p to access the array. For example, the following statement prints the first integer in the array to the console:

*/

printf("%d\n", *p);

/*

When you are finished using the dynamically allocated memory, you must deallocate it using the free() function.

The following statement deallocates the memory that was allocated by the malloc() function above:

*/

free(p);

/*

It is important to note that malloc() returns a pointer of type void. This means that the pointer can be cast to any other type of pointer.

However, it is generally a good practice to typecast the pointer to the appropriate type. This makes the code more readable and maintainable.

It also helps to prevent errors.

Here is an example of a complete program that uses dynamic memory allocation again:

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p;
  int n, i;

  printf("Enter the number of integers to be entered: ");
  scanf("%d", &n);

  // Allocate memory for the array.
  p = (int *)malloc(n * sizeof(int));

  // Check if memory allocation was successful.
  if (p == NULL) {
    printf("Memory not available.\n");
    exit(1);
  }

  // Read the integers from the user.
  for (i = 0; i < n; i++) {
    printf("Enter an integer: ");
    scanf("%d", p + i);
  }

  // Print the integers.
  for (i = 0; i < n; i++) {
    printf("%d\t", *(p + i));
  }

  // Deallocate the memory.
  free(p);

  return 0;
}

/*


This program prompts the user to enter the number of integers. It then uses the malloc() function to allocate memory for an array of n integers. It checks if the memory allocation was successful. If it was not successful, it prints an error message and exits the program.

Next, the program reads the integers from the user and stores them in the dynamically allocated array. It then prints the integers to the console.

Finally, the program deallocates the dynamically allocated memory using the free() function.

*/

