/*

The fputc() function in C is used to write a single character to a specified file at the current file position and then increments the file position pointer. Here's how you can use it:

*/

int fputc(int c, FILE *fptr);


/*

c: This is the character you want to write to the file. It should be an integer representing the character.

fptr: This is the FILE pointer associated with the file you want to write to.

The function returns an integer representing the character written on success, and on error, it returns EOF, which is a special constant representing "End of File" or an error condition.

Here's an example of how to use fputc():

*/

#include <stdio.h>

int main() {
    FILE *fptr;
    int ch;

    fptr = fopen("myfile.txt", "w"); // Open the file for writing

    if (fptr == NULL) {
        printf("File does not exist\n");
        exit(1);
    }

    printf("Enter text:\n");

    // Press Ctrl+z in DOS or Ctrl+d in Unix to stop reading characters
    while ((ch = getchar()) != EOF) {
        fputc(ch, fptr); // Write the character to the file
    }

    fclose(fptr); // Close the file

    return 0;
}


/*

In this program, we open the "myfile.txt" file for writing. If the file doesn't exist, it's created. Then, we read characters from the standard input (keyboard) using getchar(). For each character read, we use fputc() to write it to the file. Finally, we close the file using fclose().

After executing this program, the text you enter from the keyboard will be written to "myfile.txt" along with the Ctrl+z (DOS) or Ctrl+d (Unix) character, indicating the end of the input.

So, if you enter something like:

The woods are lovely, dark and deep.
But I have miles to go before I sleep.

It will be written to "myfile.txt" exactly as you entered it.

-----------------------------------------

The fgetc() function in C is used to read a single character from a specified file and increments the file pointer position. Here's how it works:


*/

int fgetc(FILE *fptr);

/*

fptr: This is the FILE pointer associated with the file you want to read from.

The function returns an integer representing the character read, after converting it to an int without sign extension.

On reaching the end of the file (EOF), or in case of an error, it returns EOF, which is a special constant representing "End of File" or an error condition.

Here's an example of how to use fgetc() to read and print the contents of a file:

*/

#include <stdio.h>

int main() {
    FILE *p;
    char ch;

    if ((p = fopen("myfile.txt", "r")) == NULL) {
        printf("This file doesn't exist\n");
    } else {
        while ((ch = fgetc(p)) != EOF) {
            printf("%c", ch);
        }
        fclose(p);
    }

    return 0;
}


/*

In this program, we open the file "myfile.txt" for reading ("r" mode). If the file doesn't exist, it prints an error message.

Otherwise, it uses a while loop to read characters from the file using fgetc() and prints them until it reaches the end of the file.

The while loop in the program is equivalent to the code you provided:

*/

ch = fgetc(p);
while (ch != EOF) {
    printf("%c", ch);
    ch = fgetc(p);
}


/*

It's important to note that the value returned by fputc() and fgetc() is of type int, not char, because these functions return an integer value of EOF (-1) on reaching the end of the file or in case of an error. So, the variable ch used to store the character read from the file is declared as an int for this reason.

--------------------------------

The getc() and putc() functions in C are similar to fgetc() and fputc(), respectively, with one key difference: getc() and putc() are defined as macros, while fgetc() and fputc() are functions. In practical terms, this means you can use getc() and putc() just like the corresponding functions.

Here's a brief explanation of getc() and putc():

getc(FILE *fptr): This macro reads a single character from the specified file (pointed to by fptr) and increments the file position pointer. It returns an integer representing the character read, after converting it to an int without sign extension. On reaching the end of the file (EOF) or in case of an error, it returns EOF.

putc(int c, FILE *fptr): This macro writes a character specified by the integer c to the specified file (pointed to by fptr) at the current file position. It returns the character written on success and EOF on error.

Here's an example of how to use getc() and putc():

*/

#include <stdio.h>

int main() {
    FILE *p1, *p2;
    int ch;

    p1 = fopen("input.txt", "r");
    p2 = fopen("output.txt", "w");

    if (p1 == NULL || p2 == NULL) {
        printf("Error in opening files\n");
        return 1;
    }

    while ((ch = getc(p1)) != EOF) {
        putc(ch, p2);
    }

    fclose(p1);
    fclose(p2);

    return 0;
}

/*

In this program, we open two files: "input.txt" for reading and "output.txt" for writing. We use getc() to read characters from the input file and putc() to write them to the output file. The loop continues until the end of the input file is reached. Finally, we close both files.

Regarding the putw() and getw() functions, they are used for reading and writing integers to binary files. putw() writes an integer to a binary file, and getw() reads an integer from a binary file.

These functions should not be used with text files, as they may misinterpret certain values (e.g., ASCII 26) as the end of the file. Instead, you should use feof() and ferror() to handle errors and end-of-file conditions when working with text files, as mentioned in your provided text.

---------------------------------------

Sure, let's break it down for a teenager:

getc() and putc()

Imagine you have a file (like a document on your computer).
getc() is like reading a single letter from that file.
putc() is like writing a letter and putting it into the file.
Example

Think of two files, one for reading (let's call it "input.txt") and one for writing (let's call it "output.txt").

We want to copy the content from "input.txt" to "output.txt."

So, we use getc() to read a letter from "input.txt" and putc() to put that letter into "output.txt."

We keep doing this until we've read everything from "input.txt" and written it to "output.txt."

putw() and getw() (for numbers)

These are like putc() and getc() but for numbers instead of letters.
putw() writes a number to a file, and getw() reads a number from a file.
Important Tip

You should be careful when using putw() and getw() with text files because they might not work well with some special characters.

Instead, use feof() and ferror() to check for errors or the end of the file when working with text files.

So, getc() and putc() are like reading and writing letters, while getw() and putw() are for numbers. Remember to be cautious when using them with text files, and use special functions to handle errors and the end of a file when working with text.

-----------------------------------------------

putw() - Writing Numbers

Imagine you have a computer file, and you want to write some numbers to it.
putw() is like taking a number and putting it into that file.
So, you can use putw(5, file) to put the number 5 into the file.
getw() - Reading Numbers

Now, let's say you have a file with numbers in it, and you want to read those numbers.
getw() is like reading the numbers from the file, one by one.
So, you can use getw(file) to read the next number from the file.
Example (Writing and Reading Numbers)

We have a file named "num.dat."
We want to write numbers from 1 to 30 into this file.
We can use putw(1, file) to write 1, then putw(2, file) to write 2, and so on, until we reach 30.
Later, if we want to read these numbers from the file, we can use getw(file) to get each number one by one.
Important Tip

When using getw() with text files, be careful. It might not work well if there are special characters in the file.
Instead, use feof() to check if you've reached the end of the file, and ferror() to check for errors when working with text files.
So, putw() is for writing numbers into a file, and getw() is for reading numbers from a file. Just be cautious when using them with text files.

----------------------------------------------------

EOF - A Special Value.

When you're using functions like getw() to read from a file, there's a special value called EOF, which stands for "End Of File."
When you reach the end of a file, like when you've read all the numbers in it, getw() will return EOF to let you know that there's nothing more to read.
EOF is like a signal that tells your program, "Hey, you've reached the end of the file."
Example with getw()

Imagine you have a file with numbers from 1 to 10, and you're using getw() to read them.
You keep using getw() in a loop until it returns EOF, which means you've read all the numbers.

Be Careful with Text Files.

If you're working with text files (like files with letters and words), using getw() can be tricky because it might stop reading when it encounters certain characters.
For text files, it's safer to use other functions like feof() to check if you've reached the end of the file or ferror() to handle errors.
So, putw() is for writing numbers into a file, getw() is for reading numbers, and EOF is a special value that tells you when you've reached the end of a file. Just remember to be cautious when working with text files, and use the right functions to check for the end of the file or errors.

----------------------------------------------------


Integer I/O in C.

The C standard library provides two functions for reading and writing integers to and from files: putw() and getw().

putw()

The putw() function writes an integer value to the file pointed to by fptr. It returns the integer written to the file on success, and EOF on error.

getw()

The getw() function reads an integer value from the file associated with fptr. It returns the next integer from the input file on success, and EOF on error or end of file.

Example programs

The following example program shows how to use putw() to write integers from 1 to 30 to the file num.dat:

*/

#include <stdio.h>

int main() {
  FILE *fptr;
  int value;

  fptr = fopen("num.dat", "wb");
  if (fptr == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  for (value = 1; value <= 30; value++) {
    putw(value, fptr);
  }

  fclose(fptr);

  return 0;
}


/*

The following example program shows how to use getw() to read and print the integers from the file num.dat:

*/

#include <stdio.h>

int main() {
  FILE *fptr;
  int value;

  fptr = fopen("num.dat", "rb");
  if (fptr == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  while ((value = getw(fptr)) != EOF) {
    printf("%d\t", value);
  }

  fclose(fptr);

  return 0;
}


/*

Using getw() with text files.

The getw() function should not be used with text files, because text files end of file is denoted by ASCII 26, which is also a valid integer value. Therefore, getw() will stop reading if it encounters the integer 26 in a text file.

Using feof() and ferror()

The feof() and ferror() functions can be used to check for end of file and error conditions, respectively. The feof() function returns 1 if the end of the file has been reached, and 0 otherwise. The ferror() function returns 1 if an error has occurred, and 0 otherwise.

The following example program shows how to use feof() and ferror() with getw():

*/

#include <stdio.h>

int main() {
  FILE *fptr;
  int value;

  fptr = fopen("num.dat", "rb");
  if (fptr == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  while ((value = getw(fptr)) != EOF && !ferror(fptr)) {
    printf("%d\t", value);
  }

  if (ferror(fptr)) {
    printf("An error occurred while reading the file.\n");
  }

  fclose(fptr);

  return 0;
}


/*

The program will read and print all of the integers from the file num.dat, unless an error occurs. If an error occurs, the program will print an error message and exit.

These two lines declare the variables fptr and value. The variable fptr will be a pointer to a file, and the variable value will be used to store the integers that are read from the file.

The line opens the file num.dat for reading in binary mode. The fopen() function returns a pointer to the file, or NULL if the file could not be opened.

The code checks if the file was opened successfully. If the file could not be opened, the program prints an error message and exits.

The loop reads integers from the file num.dat and prints them to the console. The getw() function reads an integer from the file. The loop continues to read and print integers until the end of the file is reached (EOF), or an error occurs.

The code checks if an error occurred while reading the file. The ferror() function returns 1 if an error occurred, and 0 otherwise. If an error occurred, the program prints an error message.

This line closes the file num.dat.

-----------------------------------------------

The while loop in the code you provided is a precondition loop. A precondition loop is a loop that continues to iterate as long as a certain condition is met. In this case, the loop will continue to iterate as long as the following two conditions are met:

The end of the file has not been reached (EOF).

No error has occurred.
The getw() function is used to read an integer from the file. If the end of the file has been reached, getw() will return EOF. If an error occurs, getw() will return an error code.

The ferror() function is used to check if an error has occurred while reading the file. If an error has occurred, ferror() will return 1. Otherwise, ferror() will return 0.

The loop will continue to read and print integers until the end of the file is reached (EOF), or an error occurs. If the end of the file is reached, the loop will exit. If an error occurs, the loop will exit and the program will print an error message.

Here is a more detailed explanation of how the loop works:

The loop checks if the end of the file has been reached (EOF). If the end of the file has been reached, the loop exits.
The loop checks if an error has occurred while reading the file. If an error has occurred, the loop exits and the program prints an error message.
The loop reads an integer from the file using the getw() function.
The loop prints the integer to the console.
The loop goes back to step 1 and repeats.
The loop will continue to iterate until the end of the file is reached (EOF), or an error occurs.

==============================================

STRINGS I/O

==============================================

Alright, let's dive into working with strings in C and how to read and write them from and to files.

Writing Strings to a File with fputs()

The fputs() function is like a magic pen that can write strings to a file.
Imagine you have a text in a string, and you want to save it to a file. You can use fputs() to do that.
It takes two arguments: the first is the string you want to write, and the second is the file where you want to write it.
After using fputs(), it returns the last character written, or if something goes wrong, it returns EOF (which means "End Of File" but also indicates an error).
Example: Writing to a File with fputs()

Let's say you have a program that asks you to enter text until you press Ctrl+d in Unix or Ctrl+z in DOS to stop.
It takes the text you enter and saves it to a file named "test.txt" using fputs().
Reading Strings from a File with fgets()

Now, let's say you want to read the text you've saved in "test.txt" back into your program.
You can use fgets() for this task.
It reads characters from a file and stores them in a string.
You tell it how many characters to read (the second argument), and it appends a null character ('\0') at the end to mark the string's end.
If everything goes well, it returns the string you've read. If there's a problem or you reach the end of the file, it returns NULL.
Example: Reading from a File with fgets()

We take our "test.txt" file and read the text we saved in it back into our program using fgets().
It reads line by line until it encounters a newline character or the end of the file.
Difference Between gets() and fgets()

The main difference between gets() and fgets() is how they handle newlines.
gets() removes the newline character and replaces it with a null character. fgets() keeps the newline character.
Also, with fgets(), you can specify the maximum number of characters to read, which helps prevent buffer overflow.
So, think of fputs() as your writing tool, and fgets() as your reading tool when working with strings in C. Just remember that fgets() doesn't hide newline characters, and you can control how many characters it reads.

-----------------------------------------------

Writing Strings to a File with fputs():

*/

#include <stdio.h>

int main() {
    FILE *fptr;
    char str[80];

    fptr = fopen("test.txt", "w");

    printf("Enter the text:\n");
    printf("To stop entering, press Ctrl+d in Unix or Ctrl+z in DOS\n");

    while (gets(str) != NULL) {
        fputs(str, fptr);
    }

    fclose(fptr);
    return 0;
}


/*

Reading Strings from a File with fgets():

*/

#include <stdio.h>

int main() {
    FILE *fptr;
    char str[80];

    fptr = fopen("test.txt", "r");

    while (fgets(str, 80, fptr) != NULL) {
        printf("%s", str);
    }

    fclose(fptr);
    return 0;
}

/*

These programs demonstrate how to use fputs() to write text to a file and fgets() to read it back. You can copy and paste these code examples into your C development environment to try them out.

===========================================

Formatted I/O, such as using fprintf(), allows you to write data in a structured format to a file. Here are some explanations and code examples:

Using fprintf() to Write Formatted Data to a File:

fprintf() is similar to printf(), but it writes formatted data to a file instead of displaying it on the screen. It takes a FILE pointer, a format string, and any number of additional arguments to format and write data to the file.

*/

#include <stdio.h>

int main() {
    FILE *fp;
    char name[10];
    int age;

    fp = fopen("rec.dat", "w");

    printf("Enter your name and age: ");
    scanf("%s%d", name, &age);

    fprintf(fp, "My name is %s and my age is %d", name, age);

    fclose(fp);

    return 0;
}


/*

In this program, user input for name and age is written to the file "rec.dat" using fprintf().

Using fprintf() with Structures:

fprintf() can also be used to write structured data, such as records of students, to a file. Here's an example:

*/

#include <stdio.h>

struct student {
    char name[20];
    float marks;
};

int main() {
    FILE *fp;
    struct student stu;
    int i, n;

    fp = fopen("students.dat", "w");

    printf("Enter the number of records: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter name and marks: ");
        scanf("%s%f", stu.name, &stu.marks);

        fprintf(fp, "%s %f\n", stu.name, stu.marks);
    }

    fclose(fp);

    return 0;
}


/*

Let's dive deeper into the fprintf() function and explore more about its formatting options and capabilities.

Formatted Output with fprintf():

fprintf() is a powerful function for writing formatted data to files. It allows you to control the layout and appearance of the data you write to a file. Here are some key aspects to consider:

Format Specifiers: Like printf(), fprintf() uses format specifiers to indicate how to format the data. Format specifiers begin with a percent sign % and are followed by a character that specifies the data type to be formatted. For example:

%d for integers.
%f for floating-point numbers.
%s for strings.
Using Format Specifiers:

You can include format specifiers in the format string, and fprintf() will replace them with the corresponding values from the arguments. For example:

*/

int age = 25;
fprintf(fp, "My age is %d years.", age);


/*

In this example, %d is a format specifier for integers, and it's replaced by the value of age.

Formatting Options:

Format specifiers can also include additional formatting options. For example:

%6d: This formats an integer with a minimum width of 6 characters. If the integer is shorter, it will be padded with spaces.
%.2f: This formats a floating-point number with 2 decimal places.
%10s: This formats a string with a minimum width of 10 characters. If the string is shorter, it will be padded with spaces.
Field Width and Precision:

You can control the width of the field and the precision of floating-point numbers using the format specifier. For instance:

*/

double pi = 3.14159265359;
fprintf(fp, "Pi: %10.2f", pi);


/*

This code formats the value of pi with a total width of 10 characters and 2 decimal places.

Escape Sequences:

Escape sequences, like \n for a newline or \t for a tab, can be used within the format string to control formatting. For instance:

*/

fprintf(fp, "This is a new line.\n");


/*

This code inserts a newline character to start a new line in the output file.

Appending to a File:

By opening a file in "a" mode (append mode), you can add new data to the end of an existing file without overwriting its contents.

Error Handling:

fprintf() returns the number of characters written on success and EOF on error. You can check its return value to ensure that the data was written correctly.

Example of Using Various Format Specifiers:

*/

int age = 25;
double salary = 50000.50;
char name[] = "John";

fprintf(fp, "Name: %-10s\n", name);   // Left-aligned string with a minimum width of 10
fprintf(fp, "Age: %d\n", age);         // Integer
fprintf(fp, "Salary: %.2f\n", salary); // Floating-point number with 2 decimal places


/*

In this example, we're using different format specifiers and formatting options to write data in various formats to the file pointed to by fp.

These are some of the fundamental aspects of using fprintf() to format and write data to files in C programming.

*/


/*


*/
