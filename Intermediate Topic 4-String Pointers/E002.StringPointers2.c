#include <stdio.h>
#include <stdlib.h>

/*

This code demonstrates a program where you first enter a string, allocate memory for that string dynamically, and then store it in an array of pointers to strings. Here's a step-by-step explanation of the code:

*/
#include<stdio.h>
#include<string.h>

int main() {
    char *arrp[10], str[20]; // Declare an array of pointers and a character array

    int i;

    for (i = 0; i < 10; i++) {
        printf("Enter string %d: ", i + 1);
        gets(str);

        // Allocate memory sufficient to hold the string
        arrp[i] = (char *)malloc(strlen(str) + 1);

        // Copy the entered string into the dynamically allocated memory
        strcpy(arrp[i], str);
    }

    // Print the strings stored in the array of pointers
    for (i = 0; i < 10; i++) {
        printf("%s\t", arrp[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    for (i = 0; i < 10; i++) {
        free(arrp[i]);
    }

    return 0;
}


/*

Now, let's break down the code and clarify some points:

Declaration of Variables:

char *arrp[10]: This declares an array of 10 pointers to characters, which will store the dynamically allocated strings.

char str[20]: This declares a character array to temporarily store the strings entered by the user.

For Loop for Input and Allocation:

The for loop (from i = 0 to i < 10) allows the user to input 10 strings.

gets(str) is used to read a line of text (string) from the user into the str array.

arrp[i] = (char *)malloc(strlen(str) + 1); dynamically allocates memory to store the string entered by the user.

strlen(str) + 1 is used to allocate enough memory to store the string along with its null terminator.

strcpy(arrp[i], str); copies the entered string from str into the dynamically allocated memory pointed to by arrp[i].

Printing Strings:

After input and allocation, the program prints the strings stored in the array of pointers arrp.
Freeing Memory:

Finally, the code deallocates the dynamically allocated memory for each string using free(arrp[i]).

This program illustrates the process of dynamically allocating memory for strings and storing them in an array of pointers, which is a common practice when working with variable-length strings. It addresses the limitations of scanf for directly inputting strings into an array of pointers and shows how to use malloc for memory allocation.

-------------------------------------------

The provided code is designed to take input for ten strings, dynamically allocate memory for each string, store them in an array of pointers, print the strings, and then free the dynamically allocated memory. However, there's an issue with the use of the gets function, which can lead to unexpected behavior, especially when inputting strings with spaces.

Here's what happens:

The program prompts you to enter ten strings, one by one.

When you input a string, gets(str) is used to read the entire line of input, including spaces, into the str array.

Memory is dynamically allocated for each string using malloc, and the entered string is copied into this allocated memory.

The program then prints the strings stored in the array of pointers.

However, due to the use of gets, if you input strings with spaces or if you exceed the size of the str array (which is 20 characters in this code), you may encounter unexpected behavior, including buffer overflows.

To improve the code and avoid potential issues, you can use a safer input function like fgets to read input. Here's a modified version of your code with fgets:


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char *arrp[10], str[20];

    int i;

    for (i = 0; i < 10; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // Remove the newline character

        arrp[i] = (char *)malloc(strlen(str) + 1);
        strcpy(arrp[i], str);
    }

    for (i = 0; i < 10; i++) {
        printf("%s\t", arrp[i]);
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        free(arrp[i]);
    }

    return 0;
}


/*

With these changes, fgets is used for input, and the newline character is removed from the input string before allocating memory and copying it. This makes the code safer and more robust when dealing with user input.

*/

/*

The code below is a program that takes a date input in the format "dd/mm/yy" and then prints the corresponding month based on the input date. It does so by using an array of pointers to strings, where each element of the array holds the name of a month.

*/

#include<stdio.h>

int main() {
    int d, m, y;
    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December" };

    printf("Enter date (dd/mm/yy): ");
    scanf("%d/%d/%d", &d, &m, &y);

    // Print the month based on the input
    printf("Month: %s\n", months[m - 1]);

    return 0;
}


/*

Here's what the code does:

It declares an array of pointers to strings called months. Each element of the array holds the name of a month.

The program prompts the user to enter a date in the format "dd/mm/yy" using printf and reads the input using scanf.

It then prints the name of the month based on the input. Note that months is a zero-based array, so we subtract 1 from the m input to access the correct month name.

For example, if the user enters "2/5/2002," the program will output "Month: May" because May is the 5th month, and it corresponds to months[4] (zero-based index).

The program provides a simple way to convert a numerical month input into its corresponding name using an array of pointers to strings, making it more readable and user-friendly.

*/

// Print the month based on the input
printf("Month: %s\n", months[m - 1]);



/*

This line of code is responsible for printing the month based on the m input, which represents the month as an integer (1 for January, 2 for February, and so on). Here's how it works:

months[m - 1]: This part of the code accesses the months array using the m input. However, because arrays in C are zero-indexed (meaning the first element is at index 0), we need to subtract 1 from m to get the correct index for the month.

printf("Month: %s\n", months[m - 1]);: This line uses the %s format specifier to print a string. It takes the string stored in months[m - 1] and substitutes it into the format string. This effectively prints the name of the month corresponding to the input m.

For example, if the user enters 2 as the month (representing February), months[2 - 1] will be months[1], which is "February." Therefore, the output will be "Month: February."

This code allows you to convert a numerical month input into its corresponding name using an array of month names (months). The subtraction of 1 from m is necessary to account for the zero-based indexing of arrays in C.

*/


/*

The code below is a program that sorts an array of strings represented by an array of pointers using the selection sort technique. While the code may seem a bit dense, let's break it down step by step:

*/

#include <stdio.h>

#define N 5

int main() {
    char *arrp[N] = { "white", "red", "green", "yellow", "blue" };
    int i, j;
    char *temp;

    printf("Before sorting:\n");
    for (i = 0; i < N; i++) {
        printf("%s\t", arrp[i]);
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (strcmp(arrp[i], arrp[j]) > 0) {
                temp = arrp[i];
                arrp[i] = arrp[j];
                arrp[j] = temp;
            }
        }
    }

    printf("After sorting:\n");
    for (i = 0; i < N; i++) {
        printf("%s\t", arrp[i]);
    }
    printf("\n");

    return 0;
}


/*

Now, let's break down the code step by step:

Array of Pointers (arrp):

The code declares an array of pointers to strings, arrp[N], with five elements. Each element points to a string literal.
Initialization:

It initializes arrp with five strings: "white," "red," "green," "yellow," and "blue."
Printing Before Sorting:

It prints the contents of the array before sorting.
Selection Sort:

The nested for loops implement the selection sort algorithm.

The outer loop (i) iterates over each element of the array.

The inner loop (j) iterates over the remaining elements to compare them with the current element (i).

If strcmp(arrp[i], arrp[j]) > 0, it means that arrp[i] should come after arrp[j] in sorted order.

In this case, the temp variable is used to swap the pointers.

Printing After Sorting:

After sorting, it prints the contents of the array again to display the sorted order.
The code is indeed using the selection sort technique to sort the strings in the arrp array alphabetically.

It may appear a bit dense due to the nested loops and pointer swapping, but it effectively demonstrates the sorting process using an array of pointers to strings.

*/