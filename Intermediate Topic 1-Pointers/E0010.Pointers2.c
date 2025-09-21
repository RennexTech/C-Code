#include <stdio.h>
#include <stddef.h> // Required for NULL

/* Each byte has an index number, which is called the address of that byte. The address of these bytes start from zero and the address of last byte is one less than the size of memory. 

Memory Addresses: In a computer's memory, each byte has a unique address. These addresses are usually represented as integers starting from 0. The address of a byte tells you its location in memory. The memory addresses start from 0 and go up to the highest address in the memory, which depends on the computer's architecture (e.g., 32-bit or 64-bit).

Variable Declaration: When you declare a variable in C, you are essentially telling the compiler to set aside a specific amount of memory for that variable's data. This memory allocation is necessary for the program to store and manipulate data.

Data Type: When you declare a variable, you also specify its data type (e.g., int, float, char). The data type indicates how much memory should be reserved for that variable and how the data stored in that memory should be interpreted.

Address of a Variable: Every variable in C has an associated memory address, which points to the location in memory where its data is stored. The address is used to access and manipulate the variable's value.

Size of Data Types: The size of data types, such as int, may vary depending on the computer's architecture. For example, on many systems, an int occupies 4 bytes (32 bits), but on other systems, it might occupy 2 bytes (16 bits) or 8 bytes (64 bits).

Variable Name: When you declare a variable, you give it a name (e.g., age). This name is used in your code to refer to the variable's value.

====================================================

Here's the corrected and formatted explanation:

&j;

Valid: This is used with a variable. j is a variable, and &j represents the address of that variable.
&arr[1];

Valid: This is used with an array element. arr[1] refers to an element of an array, and &arr[1] represents the address of that specific element in the array.
&289;

Invalid: This is used with a constant. 289 is a constant value, and you cannot take the address of a constant value directly using the address operator &.
&(j+k);

Invalid: This is used with an expression. (j+k) represents an expression involving variables j and k. You cannot take the address of an expression like this using the address operator &.

====================================================
*/

/*
Memory Addresses:

In a computer's memory, every byte has a unique number called its "address." These addresses start at 0 and go up to the highest address available in the computer's memory.
When you declare a variable in C, the compiler reserves a block of memory to store its value, and each byte in that block has its own address.
Address Operator (&):

In C, you can use the address operator & to find the address of a variable. For example, &age means "the address of the variable age."
You can't use the address operator with constants or expressions; it only works with variables or specific elements within arrays.
Example Program:

*/

void address_finder()
{
	unsigned int age = 30;
	float salary = 1500.50;
	printf("The value of age is: %d, its address: %p\n", age, &age);
	printf("The value of salary is: %f, its address: %p\n", salary, &salary);
	//Don't use %u, that's for usigned/positive integers 
}


/* Pointer Variables:

Now, let's dive into pointers. A pointer is a variable that stores a memory address. Similar to other variables, it also has a name, must be declared, and occupies memory space. 

However, what sets it apart is that it stores the address of a specific location in memory, which is why it's called a "pointer." 

Like other variables, pointer variables should also be declared before being used. The general syntax for declaration is:

data_type *pointer_name;
int *iptr;
float *fptr;
char *cptr, ch1, ch2;

iptr is a pointer that should point to variables of type int.
fptr is a pointer that should point to variables of type float.
cptr is a pointer that should point to variables of type char.
ch1 and ch2 are declared as simple variables of type char.

Pointers are also variables, so the compiler reserves space for them, and they also have memory addresses. 

Regardless of their base type, all pointers occupy the same amount of space in memory, as they all store addresses. 

Typically, 2 bytes are used to store an address (although this may vary in different computer architectures), so the compiler allocates 2 bytes for a pointer variable.

You might wonder why we need to specify the data type in the declaration statement if all pointers store addresses and occupy the same amount of memory. 

The reason for this will become clearer when we delve into indirection operators and pointer arithmetic in later sections.


*/

/*

In C programming, when you declare a pointer variable, it initially contains a garbage value, which means it could be pointing anywhere in memory.

To use a pointer safely and predictably, it's essential to assign it a valid address before using it in your program. 

Failure to do so can lead to unpredictable behavior or even program crashes.

To assign an address to a pointer variable, you can use the assignment statement. Here's an example:

int *iptr, age = 30;
float *fptr, sal = 1500.50;

iptr = &age;
fptr = &sal;

In this example, iptr is declared as a pointer to an integer (int *), so we assign the address of an integer variable (age) to it. Similarly, fptr is declared as a pointer to a float (float *), so we assign the address of a float variable (sal) to it.

It's crucial to match the data type of the pointer variable with the data type of the variable whose address you're assigning. 

In other words, iptr can only store the address of an integer variable, and fptr can only store the address of a float variable. 

Assigning the wrong data type of variable's address will not result in a compilation error, but it will produce incorrect behavior when you dereference the pointer later in your program.

Initializing Pointers: You can initialize a pointer variable when you declare it. The syntax is to provide the initial value (i.e., an address) enclosed in the assignment operator (=) right after declaring the pointer variable.

int age = 30, *iptr = &age;
float sal = 1500.50, *fptr = &sal;

*/

void play_with_pointers()
{
	//two methods of initializing pointers.

	int *iptr, age = 30;
	float* fptr, salary = 1550.500;

	//or 

	int age2 = 30, *ipointer = &age;
	float salary2 = 1550.50, * fpointer = &salary;
	int* pI = ipointer; //two pointer variables share the same value

	//or this one is more clearer,but similar

	int age3 = 30;
	int *ipointer2 = &age;
	float salary3 = 1550.50;
	float* fpointer2 = &salary;
	//float *fpointer2 = &1550.50; I made the mistake of addressing a constant
}

/*In these examples, iptr is declared as a pointer to an integer and initialized with the address of the age variable. Similarly, fptr is declared as a pointer to a float and initialized with the address of the sal variable.

Assigning Pointers: You can also assign the value of one pointer variable to another if they have the same base data type. 

For instance, if you have an integer pointer iptr and another integer pointer pI, you can assign the value of iptr to pI as shown above.

After this assignment, both pI and iptr will point to the age variable.

This ability to initialize and assign pointers allows you to manage memory addresses effectively in your program. 

Just remember that when you assign pointers, their base data types should match, ensuring you're working with the same type of data when dereferencing them.

*/

/* 

Assigning a null pointer, typically represented as NULL in C (it's defined in <stddef.h> rather than <stdio.h>), is a common practice for initializing or resetting pointers when you don't want them to point to any valid memory location. 

It's especially useful for pointers that haven't been assigned a valid address yet or when you want to indicate that a pointer doesn't currently reference any meaningful data.

Here's how you can use NULL to assign a null pointer:


*/


int null_pointers() {
	int* ptr = NULL; // ptr is now a null pointer

	if (ptr == NULL) {
		printf("ptr is a null pointer.\n");
	}
	else {
		printf("ptr is not a null pointer.\n");
	}

	return 0;
}

/*

In this example, ptr is explicitly assigned the null pointer value using NULL. Then, you can check whether ptr is a null pointer or not using a simple if statement.

Using null pointers can help prevent dereferencing uninitialized or invalid pointers, which can lead to undefined behavior in your program.

TEEN EXPLANATION:

Imagine you have a treasure map, but you're not sure where the treasure is hidden. A "null pointer" is like having a map with no X marks the spot. It means your map doesn't point to any real treasure location yet. It's like saying, "I don't know where the treasure is."

EXPERT EXPLANATION:

In computer programming, a null pointer is a pointer that doesn't point to any memory location or object in the computer's memory. It's a special value (often represented as "NULL" in C and C++ or "nullptr" in modern C++) that indicates the absence of a valid target for the pointer.

When you declare a pointer variable and set it to null, you're essentially saying, "This pointer doesn't currently refer to any specific memory address or object." It's like an empty address book with no names or phone numbers.

Null pointers are essential for safety. They prevent you from accidentally accessing or modifying memory that you shouldn't, which can cause crashes or unpredictable behavior in your programs. 

When you're ready to use a pointer to point to something meaningful, you assign it a valid memory address. Until then, it stays null, indicating it's not pointing anywhere.

So, in essence, a null pointer means "I don't have a valid target yet," and it helps avoid mishaps in your code.

*/

int play_with_pointers2()
{
	int *p1, a, x;
	float* p2, b;
	*p1 = 9;
	(*p1)++;
	x = *p2 + 10;
	printf("%d %f", *p1, *p2);
	scanf_s("%d%f", p1, p2);

	//the equivalencies of the above
	a = 9;        // *p1 is equivalent to a
	a++;          // (*p1)++ is equivalent to a++
	x = b + 10;   // *p2 is equivalent to b
	printf("%d %f", a, b);
	scanf_s("%d%f", &a, &b);

}

/*In the original notes, we have pointer variables p1 and p2 pointing to a and b, respectively. Using the indirection operator *, we can access the values stored at the addresses pointed to by p1 and p2.

The equivalences show that *p1 can be directly replaced with a, and (*p1)++ can be replaced with a++. Similarly, *p2 can be replaced with b.

Finally, when using scanf, you need to provide the addresses of variables a and b, which is done using &a and &b, respectively.*/

int main()
{
	null_pointers();
	address_finder();
}