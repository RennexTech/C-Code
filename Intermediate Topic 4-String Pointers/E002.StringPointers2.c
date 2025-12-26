#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * STORY: 
 * We have a temporary notebook (temp_buffer) where we scribble down names.
 * But we want to store these names permanently in a "Filing Cabinet" (arr_pointers).
 * Since we don't know how long each name is, we use 'malloc' to build a custom-sized
 * folder for every single name we receive.
 */

int main() {
    // 1. The Filing Cabinet: An array that can hold 10 "addresses" (pointers)
    char *arr_pointers[10]; 
    
    // 2. The Temporary Notebook: A place to hold the raw input briefly
    char temp_buffer[50]; 

    int i;

    printf("--- Name Entry System ---\n");

    for (i = 0; i < 10; i++) {
        printf("Enter name %d: ", i + 1);

        // SECURITY FIX: We use fgets instead of gets. 
        // It tells the program: "Stop reading if the name is longer than the notebook!"
        fgets(temp_buffer, sizeof(temp_buffer), stdin);

        // Clean up: fgets often keeps the "Enter" key (\n) at the end. Let's remove it.
        temp_buffer[strcspn(temp_buffer, "\n")] = 0;

        // 3. Measure & Build: Calculate length and request exactly that much RAM (+1 for the 'null' end)
        arr_pointers[i] = (char *)malloc(strlen(temp_buffer) + 1);

        // 4. File it away: Copy the name from the notebook to its new custom home
        if (arr_pointers[i] != NULL) {
            strcpy(arr_pointers[i], temp_buffer);
        }
    }

    // 5. Reviewing the Files: Print everything back out
    printf("\nDisplaying all stored names:\n");
    for (i = 0; i < 10; i++) {
        printf("[%d] %s\n", i + 1, arr_pointers[i]);
    }

    // 6. Shredding the Files: Always clean up your RAM when finished!
    for (i = 0; i < 10; i++) {
        free(arr_pointers[i]);
    }

    return 0;
}


✅✅✅✅✅✅✅✅✅✅✅✅✅✅
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * STORY: 
 * We have a "Master List" of months stored in a cabinet.
 * The user gives us a date string. We act like a parser—we slice 
 * the string to find the month number, then we look up that 
 * number in our Master List to find the name.
 */

int main() {
    // 1. The Master List: A fixed array of pointers to month names.
    // We add a "Dummy" at index 0 so that Month 1 = January.
    const char *months[] = {
        "Invalid", "January", "February", "March", "April", 
        "May", "June", "July", "August", "September", 
        "October", "November", "December"
    };

    char date_input[15];
    int month_index;

    printf("Enter date (dd/mm/yyyy): ");
    
    // 1. THE SECURITY GATE (fgets)
    // We only have room for 15 characters. 
    // fgets is like a gate that only lets 15 people in at a time. 
    // This prevents "Memory Overspill" (Buffer Overflow).
    if (fgets(date_input, sizeof(date_input), stdin)) {

        /* 2. THE STARTING POINT TRICK
        date_input    = "1 2 / 0 8 / 2 0 2 5"
        Index (Count) =  0 1 2 3 4 5 6 7 8 9
        
        We want the month ("08"). It starts at index 3.
        By writing '&date_input[3]', we are telling the computer:
        "Ignore carriages 0, 1, and 2. Start reading from carriage 3 onwards."
        */

        // 3. THE TRANSLATOR (atoi)
        // The computer sees "08" as text (like a picture). 
        // atoi is a translator that turns the text "08" into the actual NUMBER 8.
        month_index = atoi(&date_input[3]);

        // 4. THE SANITY CHECK
        // What if the user typed "12/99/2025"? 
        // A Security Analyst never trusts the user. 
        // We check if the number is actually a real month (between 1 and 12).
        if (month_index >= 1 && month_index <= 12) {
            printf("That date is in: %s\n", months[month_index]);
        } else {
            printf("Error: That is not a valid month!\n");
        }
    }

✅✅✅✅✅✅✅✅✅✅✅✅✅✅

#include <stdio.h>

int main() {
    // 1. THE LOOKUP TABLE
    // We store the names in an array of pointers. 
    // Think of this as a row of 12 locked boxes, each containing a month name.
    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December" 
    };

    int d, m, y;

    // 2. THE PATTERN MATCH
    // We tell scanf to look for a specific pattern: "number / number / number"
    // The '/' characters in the quotes tell the computer to skip the slashes in the input.
    printf("Enter date (dd/mm/yy): ");
    scanf("%d/%d/%d", &d, &m, &y);

    // 3. THE INDEX CALCULATION
    // Remember: In C, we start counting at 0. 
    // If a user types month '1' (January), it is actually at index 0 in our array.
    // So we use [m - 1] to get the correct box.
    
    /* SECURITY WARNING: 
       If the user enters month 13 or 0, this program will look outside 
       the array and potentially crash! (Array Out of Bounds) 
    */
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

This program acts like a Lookup Table: it takes a month number (1-12) and translates it into a name (January-December). Because C starts counting at zero, we subtract 1 from the user's input (m - 1) to find the correct index in our list. It’s a fast, efficient way to turn raw data into something human-readable.

⚠️ Security Note: This version is fast but assumes the user enters a valid number. In a production environment, I would add an if statement to check that the month is between 1 and 12 to prevent an Array Out of Bounds memory error. 

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


✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/*

The code below is a program that sorts an array of strings represented by an array of pointers using the selection sort technique. The code may seem a bit dense, let's break it down step by step:

*/

#include <stdio.h>
#include <string.h> // Needed for strcmp (string comparison)

#define N 5 // We are dealing with 5 colors

int main() {
    // 1. THE LIST: An array of pointers (labels) pointing to colors in memory.
    char *arrp[N] = { "white", "red", "green", "yellow", "blue" };
    int i, j;
    char *temp; // A temporary "holder" for swapping labels

    // 2. SHOW THE MESS: Print the list before we fix it
    printf("Before sorting:\n"); 
    for (i = 0; i < N; i++) {
        printf("%s\t", arrp[i]);
    }
    printf("\n\n");

    // 3. THE SORTING MACHINE (Selection Sort)
    // We pick one color (i) and compare it to every color after it (j).
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            
            // Does "Color A" come after "Color B" in the alphabet?
            // strcmp returns a number > 0 if the first string is "bigger" (later in alphabet)
            if (strcmp(arrp[i], arrp[j]) > 0) {
                
                // SWAP THE LABELS: We don't move the actual words in memory.
                // We just swap which "label" points to which "word."
                temp = arrp[i];
                arrp[i] = arrp[j];
                arrp[j] = temp;
            }
        }
    }

    // 4. SHOW THE RESULTS: Print the list now that it's alphabetical
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