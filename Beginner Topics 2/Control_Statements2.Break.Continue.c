#include <stdio.h>
#include <stdlib.h>

//BREAK STATEMENT 

/*
* Break and continue are pain points for every new user in C/C++ programmer.
* They both alter how loops run but in different ways.
* 
* You're looking for a specific file within a stack of documents.
* As soon as you find that file, you don't look at any other document, you grab it and leave.
* That's the break statement. 
*
* If you are looping through a file and want the magic 0xDEADC0DE sequence that specifies the end of a 
* specific data block, you break the loop once you find it. 
*
* You're going through a security checkpoint. The guard finds contraband(if contraband is true).
* They immediately stop you and you're out of the line. 
*
* You're searching for something in a list or array and you find it, boom, no need to keep searching. 
*
* If an unexpected error happens when your app is running eg not enough system memory, you break out of 
* the execution, to go handle it.
*
* You're looping 100 times, but find your data at the 10th iteration, the remaining 90 are pointless. 
*
* Imagine you're swiping through 100 resumes and you find the perfect candidate at #10. You stop there. That's break.
*
*/


//CONTINUE STATEMENT 

/*
* Continue statement - Skip this one. 
* 
* The loop never stops like it did for the break statement. 
* 
* It skips that iteration and moves on to the next one using the loop's update expression eg i++
*
* You want to perform an action on most items in a loop but exclude a few based on certain conditions? Continue is your tool. 
*
* You're parsing a massive log file line by line and if a line starts with # or // indicating a comment,
* you don't need to parse it, just continue to the next line. That means you skip all the comments, 
* but you don't stop reading the log file.
*
* Your antivirus is analysing running processes for suspicious ones, and it encounters system processes
* like explorer.exe and svchost.exe, it might continue in order to avoid scanning legit files and wasting time.
*
* When you're collecting data, some data that doesnt' meet a certain criteria must be skipped. 
*
* You're doing heavy math operations using C, and they are costing your banking transactions app too much time.
* Instead of rewriting, you can skip those operations and pass them to a OOP language that's tied
* to your C backend code for it to be handled. 
* 
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    // --- BREAK DEMO ---
    int i;

    for (i = 0; i < 5; i++) {
        if (i == 3) {
            printf("Breaking loop at i = %d. Loop will now end completely.\n", i);
            break; // Exits the loop entirely
        }
        printf("Break loop iteration: %d\n", i);
    }

    // Fake data for search
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);

    for (i = 0; i < size; i++) {
        if (arr[i] == target) { 
            printf("Found %d at index %d\n", target, i); 
            break; // stops the loop RIGHT HERE
        }
    }

    // --- CONTINUE DEMO ---
    for (i = 0; i < 5; i++) {
        if (i == 2) {
            printf("Skipping remaining code for i = %d. Moving to next iteration.\n", i);
            continue; // Skips current iteration, goes to next
        }
        printf("Continue loop iteration: %d\n", i);
    }

    return 0;
}


