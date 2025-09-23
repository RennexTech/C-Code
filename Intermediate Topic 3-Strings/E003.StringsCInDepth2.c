#include <stdio.h>
#include <stdlib.h>

/*


Yes, the two methods of initializing strings in C are:

Initializing a string array with individual characters:

This can be done by assigning individual characters to the elements of the string array. For example:

*/

char str[ ] = {'N', 'e', 'w', ' ', 'Y', 'o', 'r', 'k', '\0'};

/*

The null character (\0) at the end of the string array is important, as it marks the end of the string.

Initializing a string array with a string literal:

This can be done by assigning a string literal to the string array. For example:

*/

char str[ ] = "New York";


/*

In this case, the compiler will automatically append a null character (\0) to the end of the string array.

Both of these methods are equivalent, and the one you choose to use is a matter of personal preference.

---------------------------------------

Here is a breakdown of the two methods:

Initializing a string array with individual characters:

This method is more explicit, as you are explicitly assigning each character to the string array.

This method can be useful if you need to initialize the string array with a specific sequence of characters.

This method can also be useful if you need to initialize the string array to a specific size.

---------------------------------------

Initializing a string array with a string literal:

This method is more concise, as you are simply assigning a string literal to the string array.

This method is useful if you need to initialize the string array to a common string, such as a name or address.

This method is also useful if you do not need to specify the size of the string array, as the compiler will automatically allocate enough memory to store the string.

*/

int main()
{
    char str[] = "JesusChrist";
    char *p = str;
    while(*p != '\0')
    {
        printf("Character = %c\t", *p); //print the data that's pointed by p
        printf("Address = %u\n", p); //print the address the pointer is pointing to.
        p++;
    }
    printf("Hello world!\n");
    return 0;
}


/*

If you forget to increment the pointer to point to the next address, ie, p++, your program will show you fire without smoke!

Character = J	Address = 1589268524
Character = e	Address = 1589268525
Character = s	Address = 1589268526
Character = u	Address = 1589268527
Character = s	Address = 1589268528
Character = C	Address = 1589268529
Character = h	Address = 1589268530
Character = r	Address = 1589268531
Character = i	Address = 1589268532
Character = s	Address = 1589268533
Character = t	Address = 1589268534

The shortcut way for entering and printing strings using the %s format specifier is a convenient way to work with strings in C. However, it is important to understand how to use pointers to manipulate strings directly, as this can be useful in some cases.

*/

void print_string()
{
    char name[20];
    printf("Enter your first name: ");
    scanf("%s", name);//name of string array is the pointer, so we don't need &
    printf("You're called: %s\n", name);


}

int string_printer()
{
  char str[] = "JesusChrist";
  char *p = str;
  while(*p != '\0' && p < str + strlen(str))
  {
    printf("Character = %c\t", *p); //print the data that's pointed by p
    printf("Address = %u\n", p); //print the address the pointer is pointing to.
   p++;

  }
  printf("Hello world!\n");
  return 0;
}


/*

The second program works as follows:

The variable str is declared as a character array and initialized to the string "JesusChrist".

The pointer variable p is declared and initialized to the address of the first element of the array str.

The while loop iterates over the characters in the string str until it reaches the null character (\0) or the end of the string.

Inside the while loop, the following steps are performed:

The character at the current address pointed to by p is printed to the console.

The address pointed to by p is printed to the console.

The pointer p is incremented to point to the next character in the string.

After the while loop terminates, the message "Hello world!\n" is printed to the console.

Here is a breakdown of the while loop:

------------------------------------

The expression *p != '\0' means that the loop will continue to execute as long as the character at the current address pointed to by p is not the null character (\0).

The expression p < str + strlen(str) means that the loop will continue to execute as long as the pointer p is pointing to a character that is within the string str.

The strlen(str) function returns the length of the string str, including the null character (\0).

The while loop will terminate when it reaches the null character (\0) at the end of the string or when it reaches the end of the string array.

The second program is more robust than the first program because it can handle strings that do not contain a null character.

For example, if the string str is initialized to "JesusChrist\0", the second program will print all of the characters in the string and their addresses, including the null character.

------------------------------------

Yes, the output of your program is the same as the output of the previous program. Both programs use a pointer variable to iterate over the characters in the string and print them to the console.

The only difference between the two programs is that the first program uses a while loop with the expression *p != '\0' to terminate the loop, while the second program uses a while loop with the expression *p != '\0' && p < str + strlen(str) to terminate the loop.

The expression p < str + strlen(str) ensures that the loop will terminate when the pointer p reaches the end of the string, even if the string does not contain a null character (\0).

Both programs are valid ways to print all of the characters in a string to the console. However, the second program is more robust because it can handle strings that do not contain a null character.

The second program is more robust because it can handle strings that do not contain a null character. For example, if the string str is initialized to "JesusChrist\0", the first program will only print the character J and its address. The second program will print all of the characters in the string and their addresses, including the null character.

*/

//This is just a repeat code:
int string_printer()
{
  char str[] = "JesusChrist"; //name of array is a pointer to the first character's address
  char *p = str;//assign that same address to a pointer variable(stores addresses only).
  while(*p != '\0' && p < str + strlen(str))
  {
    printf("Character = %c\t", *p); //print the data that's pointed by p
    printf("Address = %u\n", p); //print the address the pointer is pointing to.
   p++;

  }
  printf("Hello world!\n");
  return 0;
}

/*

------------------------------------

p < str + strlen(str): This condition checks whether the pointer p is within the bounds of the string. It compares the current memory address p is pointing to with the memory address of the end of the string (determined using strlen(str)). This condition prevents the loop from accessing memory beyond the end of the string. explain again, I'm still confused. str is array of characters, strlen(str) gets us the length of the array. then why do < to a memory address p??

------------------------------------

str is indeed an array of characters, and strlen(str) returns the length of the string (excluding the null terminator '\0') stored in that character array.

p is a pointer to a character that initially points to the beginning of the str array.

str + strlen(str) is a pointer expression. It adds the length of the string to the memory address of the start of the str array. This results in a memory address that points to one position past the end of the string.

Now, let's break down the condition p < str + strlen(str):

p is the current memory address pointed to by the pointer p.

str + strlen(str) is the memory address one position past the end of the string stored in the str array.

The purpose of this condition is to ensure that the loop iterates over the characters within the bounds of the string and does not access memory beyond the end of the string.

Here's a simplified example:

*/

char str[] = "Hello";  // The string "Hello" has a length of 5, including the null terminator.

char *p = str;         // Initialize pointer p to point to the start of the string.

while (*p != '\0' && p < str + strlen(str)) {
    // ... loop logic ...
    p++;  // Move p to the next character.
}


/*

In this example, the loop will iterate over the characters "H," "e," "l," "l," and "o," but it will stop before attempting to access memory beyond the end of the string.

So, in summary, the condition p < str + strlen(str) ensures that the loop only operates within the bounds of the string by comparing the current memory address pointed to by p with the memory address just past the end of the string.

In short:

p will give us the memory address of the first character.

str + strlen(str) will give memory address of str which i told you points to the first item, and adds the length of the string, so we get a memory address that is +1 of the array's allocated memory.

so if p is not more than that new memory, that's the end of the looping, stop it right there.

Note, the expression str + strlen(str) does not consider the sentinel character (null terminator '\0'). It points to the memory address immediately after the end of the string, and it doesn't include the null terminator in its calculation.  If you want to include the null terminator in your bounds checking, you can modify the condition like this:

*/

p < str + strlen(str) + 1


/*

The printf( ) takes the base address of a string and continues to display the characters until it encounters the character '\0'. When we enter the string using %s, the null character is automatically stored at the end of the array. We haven't used the '&' sign in the scanf( ) since the name of the array is itself the address of the array.

In the first run when we entered a string with spaces, we could not get the required result. This is because scanf( ) stops reading as soon as it encounters a whitespace. So for entering strings with whitespaces, we can use the function gets( ). It stops reading only when it encounters a newline and replaces this newline by the null character. We have another function puts( ) which can output a string and replaces the null character by a newline.

/* Program to understand the use of gets() and puts() */
#include <stdio.h>

int main2() {
    char name[20];
    printf("Enter name: ");
    gets(name);
    printf("Entered name is: ");
    puts(name);
    return 0;
}


int main3()
{
    char name[80];
    printf("Enter all your names: ");
    gets(name);
    printf("You're called: %s", name);

    return 0;
}

// warning: the 'gets' function is dangerous and should not be used due to buffer overflow attacks on your program. Use fgets()









































