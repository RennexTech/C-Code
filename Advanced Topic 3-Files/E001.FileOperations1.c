/*

It seems like you're interested in learning about file handling in C programming. File handling is crucial for storing and retrieving data on permanent storage devices like disks. There are two main types of file handling in C: high-level (standard files or stream-oriented) and low-level (system-oriented).

High-Level File Handling:
High-level file handling is managed through library functions, making it easier to work with files. It abstracts many of the low-level details from the programmer. To use high-level file handling, you should include the stdio.h header file in your program.

Low-Level File Handling:
Low-level file handling is more system-oriented and is managed through system calls. It offers greater control but involves more complexity. We'll focus on high-level file handling in this discussion.

In C, high-level file handling provides functions similar to those used for screen and keyboard input/output. Here are some key functions:

fscanf() and fprintf(): These functions are similar to scanf() and printf(), but they work with files.

fgets() and fputs(): These are used to read and write strings to/from files.

Now, let's get started with some code examples for file handling in C:

*/

#include <stdio.h>

int main() {
    FILE *file; // Declare a file pointer

    // Opening a file for writing (creates a new file or overwrites an existing one)
    file = fopen("example.txt", "w");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Writing to the file
    fprintf(file, "Hello, File Handling in C!\n");
    fprintf(file, "This is a sample text.\n");

    // Closing the file
    fclose(file);

    // Opening the file for reading
    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Reading and printing the contents of the file
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    // Closing the file
    fclose(file);

    return 0;
}



/*

Step 1: We begin by including the stdio.h header, which provides functions for file handling. We also declare a pointer to a file called file. This pointer will be used to work with files.

*/

// Opening a file for writing (creates a new file or overwrites an existing one)
file = fopen("example.txt", "w");


/*

Step 2: We use the fopen function to open a file named "example.txt" for writing. The "w" mode indicates that we are opening the file in write mode. If the file does not exist, it will be created. If it does exist, its previous contents will be deleted, and it will start as an empty file. If there's an error opening the file, fopen returns NULL, so we check for that in the next lines.

*/

if (file == NULL) {
    printf("Unable to open the file.\n");
    return 1;
}


/*

Step 3: Here, we check if the file pointer file is NULL. If it is, it means there was an issue opening the file, so we print an error message and exit the program with a status code of 1.

*/

    // Writing to the file
    fprintf(file, "Hello, File Handling in C!\n");
    fprintf(file, "This is a sample text.\n");


/*

Step 4: We use the fprintf function to write data to the file. In this case, we're writing two lines of text to the file. fprintf works similarly to printf, but it writes to the file specified by the file pointer.

Step 5: After writing to the file, we close it using fclose. This is important to ensure that any buffered data is flushed to the file and that system resources are released.

*/

    // Closing the file
    fclose(file);


/*

Step 6: Now, we open the same file, "example.txt," but this time for reading using "r" mode. This allows us to read the contents of the file.

*/

// Opening the file for reading
file = fopen("example.txt", "r");

//Step 7: Again, we perform error checking to make sure the file was opened successfully for reading.
if (file == NULL) {
    printf("Unable to open the file.\n");
    return 1;
}

// Reading and printing the contents of the file
char line[100];
while (fgets(line, sizeof(line), file)) {
    printf("%s", line);
}

// Closing the file
fclose(file);


/*

Step 8: Here, we use a while loop to read the contents of the file line by line using fgets. The fgets function reads up to sizeof(line) characters (in this case, 100 characters) or until it encounters a newline character, whichever comes first. We then print each line using printf.

Step 9: Finally, after reading and printing the file's contents, we close the file using fclose to release system resources.
This code demonstrates the complete process of opening, writing, reading, and closing a file using high-level file handling in C. Proper error handling ensures that the program behaves gracefully even in case of file-related issues.

--------------------------------------

It seems you're interested in understanding the differences between storing data in binary format and text format in files. Let's break down the key points:

TEXT FORMAT:

Human Readable: Data is stored as lines of characters, and each line is terminated by a newline character ('\n'). Text files are human-readable and can be created and read using any text editor.

Size: Text files tend to be larger in size compared to binary files because data is represented as characters, and each character typically occupies one byte. For example, the integer 1679 will occupy 4 bytes in a text file ('1', '6', '7', '9').

End of File: In text files, the end of the file can be detected when a special character with value 26 is encountered. All input functions stop reading when this character is found.

Newline: In text files, newline characters are typically stored as a combination of a carriage return ('\r', ASCII 13) and a linefeed ('\n', ASCII 10).

Portability: Text files are more portable because the data is represented as characters, and there are no byte order or size issues between different systems.

--------------------------------------

BINARY FORMAT:

Not Human Readable: Data is stored on the disk exactly as it is represented in computer memory. Binary files are not human-readable and require specific programs to create and read them.

Size: Binary files are generally smaller in size because data is stored in a more compact form. For example, the integer 1679 will take only 2 bytes in a binary file.

End of File: In binary files, there is no specific character to represent the end of the file. The length of the file is used to identify the end.

Newline: In binary files, newline characters are stored only as '\n' (ASCII 10), without the combination of '\r' and '\n'.

Speed: Input and output operations in binary files are generally faster than in text files because no conversions are required.

Portability: Binary data is less portable because the size of data types and byte order may vary between different machines.

In summary, text files are human-readable, larger in size, have a clear end-of-file marker, and are more portable. Binary files are not human-readable, smaller in size, don't have a specific end-of-file marker, and are faster but less portable.

The choice between them depends on your specific requirements, such as readability, size constraints, and portability considerations.

---------------------------------------------

SUMMARY:

Specific examples of the differences:

Integer storage: An integer value of 1679 will take 2 bytes in a binary file, but 4 bytes in a text file. This is because the integer is stored as a sequence of 4 characters in a text file, while it is stored as a single value in a binary file.

Newline storage: A newline character is stored as a combination of carriage return ('\r') and linefeed ('\n') in a text file, but only as a linefeed character ('\n') in a binary file.

Data transfer: When transferring data between memory and a binary file, no conversions need to take place. However, when transferring data between memory and a text file, some conversions need to take place, such as converting newlines to carriage return-linefeed combinations.

Input/output operations: Input and output operations on binary files are generally faster than input/output operations on text files, because no conversions need to take place.

Portability: Binary files are less portable than text files, because the size of data types and byte order may be different on different machines.

------------------------------------------

Buffer Concept:

A buffer is an area in memory where data is temporarily stored before being written to a file or read from a file.
When you open a file in C, a buffer is automatically associated with the file pointer. Any data you send to the file is not immediately written to the actual file on disk but is first stored in this buffer.
When the buffer becomes full, its contents are written to the file. Additionally, when you close the file, any remaining data in the buffer is automatically flushed (written) to the file, even if the buffer is not full.
Flushing the buffer refers to the process of writing its contents to the file.
The concept of buffering is used to improve efficiency. Without buffering, writing each byte of data to a file would require accessing the disk every time, which can be slow because accessing the disk involves repositioning the read/write head. Buffering allows multiple bytes of data to be collected in the buffer and then written to the file in a single operation, reducing the number of disk accesses and improving efficiency.

Steps for File Operations in C Programming:

Open a File: The first step in working with files is to open them. In C, you typically use the fopen() function for this purpose. You specify the file's name and the mode (e.g., read, write, append) in which you want to open it.

Read or Write Data in the File: After opening the file, you can perform read or write operations on it using functions like fprintf(), fscanf(), fread(), or fwrite(). When you write data, it is stored in the buffer associated with the file.

Close the File: It's essential to close the file when you're done working with it. You do this using the fclose() function. Closing the file ensures that any remaining data in the buffer is flushed to the file, and system resources are released.

Here's a simplified example of opening, writing, and closing a file with buffering in C:

*/

#include <stdio.h>

int main() {
    FILE *file; // Declare a file pointer

    // Opening a file for writing (creates a new file or overwrites an existing one)
    file = fopen("example.txt", "w");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Writing to the file
    fprintf(file, "Hello, Buffering in C!\n");

    // Closing the file
    fclose(file);

    return 0;
}


/*

In this example, the data "Hello, Buffering in C!\n" is first stored in a buffer associated with the file, and when the file is closed, the buffer's contents are flushed to the actual file on disk.

Buffers play a crucial role in optimizing file I/O operations in C by reducing the number of costly disk accesses.

-----------------------------------

In your notes on opening a file in C programming, you've covered several important aspects of file handling, but there are a few key points that haven't been addressed yet:

Error Handling: While you mentioned that fopen() returns a pointer to a FILE structure on success and NULL on error, it's essential to emphasize the importance of error handling when dealing with file operations. Checking the return value of fopen() and other file-related functions for errors is crucial to ensure your program behaves gracefully in case of issues like file not found or permission problems.

File Closing: While you mentioned the importance of closing a file with fclose(), it's worth emphasizing that failing to close files properly can lead to resource leaks and data corruption. Always close files when you're done with them.

Buffering Modes: In the context of file handling, you discussed buffering but didn't cover the different buffering modes explicitly. It might be beneficial to explain that C standard I/O library uses buffering for both input and output operations. For instance, stdout is usually line-buffered, while stderr is unbuffered, and stdin is typically fully buffered. You can control the buffering behavior using functions like setvbuf().

Binary and Text Modes: You touched on opening files in binary and text modes but didn't go into detail about the differences. It's important to clarify that opening a file in binary mode ('b' appended to the mode) ensures that no translations (such as newline conversions) are performed, making it suitable for binary data. Text mode ('t' appended to the mode) is the default for most systems and is used for text files, where newline conversions are applied. Explaining these differences in more detail could be helpful.

File Position: You haven't discussed how to move the file pointer within a file, which is essential for reading or writing data at specific positions in a file. Functions like fseek() and ftell() are used to manipulate the file position.

Other File Operations: File handling involves more than just opening, reading, and writing files. It also includes operations like checking if a file exists, renaming or deleting files, and handling directories. Covering these aspects can provide a more comprehensive understanding of file manipulation in C.

Including these points in your notes will give a more comprehensive overview of file handling in C programming and help readers grasp the full scope of working with files in C.

-----------------------------------------------

Opening a File in C Programming:

Before any input/output (I/O) operations can be performed on a file, the file must be opened. This process is known as "opening the file."

In C, file handling is facilitated through a structure named FILE, which is defined in the stdio.h header. This structure contains information about the file, such as its status, buffer size, current position, and end-of-file status. The operating system handles these details transparently.

A file pointer is a pointer to a structure of type FILE. When a file is opened, a FILE structure is associated with it, and a file pointer points to this structure, identifying the file.

The fopen() function is used to open a file and is declared as follows:


*/

FILE *fopen(const char *filename, const char *mode);

/*

It takes two strings as arguments: the first is the file's name, and the second is the mode, which specifies the operations to be performed on the file.

On success, fopen() returns a pointer of type FILE. On error, it returns NULL. The return value of fopen() should be assigned to a FILE pointer declared previously.

File names are limited to FILENAME_MAX characters. However, once a file is opened with fopen(), the name of the file is not used in the program for any operations. Instead, we work with the file using the file pointer returned by fopen().

The second argument to fopen() represents the mode in which the file is to be opened. Some possible values of the mode are:

"w" (write): Creates a new file for writing. If the file already exists, its previous data is erased.
"a" (append): Creates a new file for writing. If the file exists, new data is appended at the end without erasing existing data.
"r" (read): Opens an existing file for reading without erasing previous data.
"w+" (write+read): Similar to "w" mode but allows both reading and modification of data. Erases previous data.
"r+" (read+write): Similar to "r" mode but allows both reading and modification of data without erasing previous data.
"a+" (append+read): Similar to "a" mode but allows reading of data. Existing data cannot be modified.
To open a file in binary mode, you can append 'b' to the mode, and for text mode, you can append 't'. However, text mode is typically the default mode for most systems.

These are the fundamental aspects of opening files in C programming, which lay the foundation for various file operations such as reading, writing, and manipulation.

--------------------------------------------

Opening a File in C Programming for Teens:

Before you can do anything with a file in a computer program, you need to "open" it. Think of it like opening a book before you can read it. This is what we call "opening the file."

In C programming, we use a special tool called "fopen()" to open files. This tool works like a magic key that unlocks a file so we can work with it. When you use fopen(), you give it two important things:

The File's Name: You tell it which file you want to open. This is like telling it the name of the book you want to read, like "myessay.txt."

The Mode: You also tell it what you want to do with the file. Do you want to write new stuff, read what's inside, or do both? It's like saying, "I want to read this book" or "I want to write something in this book."

Now, when you use fopen() and everything goes well, it gives you a special ticket, like getting a library card. But this ticket is a bit different. It's called a "FILE pointer." It's like a magic wand that lets you do things with the file.

If everything doesn't go well (for example, if you try to open a file that doesn't exist), fopen() will say, "Sorry, no ticket for you," and it gives you a special value called "NULL," which means nothing. So, you need to check if you got a ticket (FILE pointer) or NULL to make sure everything's okay.

Now, here's the cool part: once you have that FILE pointer (your magic wand), you don't really need to remember the file's name anymore. It's like you have the book, and you don't need to keep saying its name. You just use your magic wand to talk to the book.

The mode you pick for fopen() decides what you can do with the file:

"w" (write): You can create a new file or erase an existing one and put new stuff in it.
"a" (append): You can create a new file or add new data to the end of an existing one.
"r" (read): You can open an existing file just to read from it.
"w+" (write+read): You can create a new file, put stuff in it, and also read from it.
"r+" (read+write): You can open an existing file to both read and write without erasing what's already there.
"a+" (append+read): You can read from an existing file or add more data to the end.
Sometimes, you might want to deal with the file as it is (like a book), or you might want to work with it in a special way. You can add 'b' for binary (original form) or 't' for text (characters) if needed.

That's the basics of opening files in C programming! You get a magic wand (FILE pointer) to talk to the file, and you can do different things with it depending on the mode you choose.

-------------------------------------------

Certainly, let's simplify the explanation of errors in opening and closing files in C programming:

Handling Errors When Opening and Closing Files in C for Teens:

Opening a File Errors: When you try to open a file using fopen(), sometimes things can go wrong. In those cases, fopen() doesn't give you a FILE pointer like it should; instead, it says, "Sorry, no ticket for you," and gives you a special value called NULL, which means nothing.

Here's an example of checking for errors when opening a file:

*/

FILE *fp;
fp = fopen("text.dat", "w");
if (fp == NULL) {
    printf("Error in opening file");
    exit(1); // This is like saying, "I give up, let's stop the program."
}


/*

Reasons for opening errors can be things like:

Trying to open a file for reading, and the file doesn't exist, or you don't have permission.
Trying to create a file, but there's not enough space on your computer or you don't have permission.
Trying to create a file that already exists and you can't delete it.
Opening too many files at once, more than your computer allows.
Sometimes, you might need to use the full path to a file, especially in DOS (a type of computer system). So you'd write it like this:

*/

fp = fopen("E:\\booksdir\\names.dat", "r");


/*

We use double backslashes because a single backslash in a string has a special meaning.

Closing a File: When you're done with a file and don't want to do anything more with it, you should "close" it. This is like putting a book back on the shelf when you're done reading.

Here's how you close a file:

*/

int result = fclose(fp);
if (result == EOF) {
    printf("Could not close the file.");
}


/*

Closing a file does two important things: it saves any unsaved changes to the file (like saving your progress in a game), and it frees up resources so you can open more files.

You can close multiple files by calling fclose() for each of them, or you can close all open files at once using fcloseall().

End of File: When you're reading a file and reach the end, the computer sends a signal saying, "Hey, we're done here." This signal is like an "end-of-file" signal, and it's represented by a special value called EOF, which is like -1.

When you see EOF, it means you've reached the end of the file and there's nothing more to read.
Remember, errors can happen when opening, closing, or reading files, and it's important to check for them so your program can handle them gracefully.

------------------------------------------

File reading functions need to know the end of the file so that they can stop reading. When the end of the file is reached, the operating system sends an end-of-file signal to the program. When the program receives this signal, the file reading functions return EOF, which is a constant defined in the file header stdio.h and has the value -1.

EOF is an integer value, so make sure that the return value of the file reading function is assigned to an integer variable. Note that the value EOF is not present at the end of the file; it is returned by the file reading functions when the end of the file is reached.

Here are some examples of how to check for the end of the file:

*/

// Read a line from the file.
char line[1024];
fgets(line, sizeof(line), my_file);

// Check if the end of the file has been reached.
if (feof(my_file)) {
  // The end of the file has been reached.
} else {
  // The end of the file has not been reached.
}


=======================================================

// Read a character from the file.
char c = fgetc(my_file);

// Check if the end of the file has been reached.
if (c == EOF) {
  // The end of the file has been reached.
} else {
  // The end of the file has not been reached.
}

/*

The fgets() function reads a line from a file and stores it in a buffer. The fgetc() function reads a single character from a file. Both functions return the character EOF when the end of the file is reached.

The sizeof() operator is used to get the size of the line buffer. This is necessary to ensure that the fgets() function does not read more characters than the buffer can hold. Here is an example of how to use the code above:

*/

#include <stdio.h>

int main() {
  FILE *my_file = fopen("myfile.txt", "r");
  if (my_file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  // Read a line from the file.
  char line[1024];
  fgets(line, sizeof(line), my_file);

  // Check if the end of the file has been reached.
  if (feof(my_file)) {
    printf("The end of the file has been reached.\n");
  } else {
    printf("The line is: %s\n", line);
  }

  // Read a character from the file.
  char c = fgetc(my_file);

  // Check if the end of the file has been reached.
  if (c == EOF) {
    printf("The end of the file has been reached.\n");
  } else {
    printf("The character is: %c\n", c);
  }

  fclose(my_file);
  return 0;
}

/*

Defines the main() function, which is the entry point for all C programs.

Opens the file myfile.txt for reading. The fopen() function returns a pointer to the file, which is stored in the variable my_file.

Checks if the file was opened successfully. If the file could not be opened, the program prints an error message and exits.

Reads a line from the file my_file and stores it in the buffer line. The fgets() function reads up to sizeof(line) characters from the file, or until it encounters a newline character (\n).

Checks if the end of the file has been reached. The feof() function returns 1 if the end of the file has been reached, and 0 otherwise. If the end of the file has not been reached, the program prints the line that was read from the file to the console.

Reads a character from the file my_file and stores it in the variable c. The fgetc() function reads a single character from the file.

Checks if the end of the file has been reached. The fgetc() function returns EOF if the end of the file has been reached. If the end of the file has not been reached, the program prints the character that was read from the file to the console.

Closes the file my_file.

This line returns 0 from the main() function, which indicates that the program terminated successfully.

To compile and run this program, you can use the following commands:

gcc -o my_program_name my_program_name.c , then:

./my_program

If the file myfile.txt exists, the program will read the first line from the file and print it to the console. Then, it will read the next character from the file and print it to the console. If the end of the file is reached, the program will print a message to the console.
*/


#include <stdio.h>

int main() {
    FILE *fp; // Declare a FILE pointer
    fp = fopen("filename", "mode"); // Open the file with a specific mode
    // Perform operations on the file using fp
    fclose(fp); // Close the file
    return 0;
}

/*

In this structure:

FILE *fp;: This declares a FILE pointer named fp, which is like a tool for working with files.

fp = fopen("filename", "mode");: You use fopen() to open a file named "filename" with a specific mode, determining what you can do with it (e.g., reading, writing).

Perform operations on the file using fp.
fclose(fp);: Finally, when done, you close the file with fclose().

Predefined File Pointers:
Predefined constant file pointers are automatically available when your program starts:

stdin: Represents the standard input device (usually the keyboard). You can read data from it.

stdout: Represents the standard output device (usually the screen). You can write data to it.

stderr: Represents the standard error output device (usually the screen). You can write error messages to it.

These predefined pointers are handy for basic input and output without explicitly opening or closing files. You can use them like regular file pointers to interact with standard input, output, or error channels.

Common File I/O Functions:
Here are some commonly used file I/O functions:

Character I/O:

fgetc(): Read a single character from a file.
fputc(): Write a single character to a file.
getc(): Same as fgetc().
putc(): Same as fputc().

Line I/O:

fgets(): Read a line (a series of characters until a newline) from a file.
fputs(): Write a line (a series of characters) to a file.

Binary I/O:

getw(): Read a binary value from a file.
putw(): Write a binary value to a file.

Formatted I/O:

fscanf(): Read data from a file using a specified format.
fprintf(): Write data to a file using a specified format.

Block I/O:

fread(): Read a block of data from a file.
fwrite(): Write a block of data to a file.
These functions allow you to perform various operations when working with files. For example, you can use fscanf() to read data in a specific format from a file, or fputs() to write lines of text to a file.

Let's go on with these functions in the next lecture....
