#include <stdio.h>
#include <ctype.h>

void copyFileWithoutBlankLines(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file '%s'\n", inputFileName);
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error creating output file '%s'\n", outputFileName);
        fclose(inputFile);
        return;
    }

    char line[256];  // Adjust the buffer size as needed
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Check if the line is not blank (contains at least one non-whitespace character)
        int nonWhitespaceFound = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (!isspace((unsigned char)line[i])) {
                nonWhitespaceFound = 1;
                break;
            }
        }

        // If the line is not blank, write it to the output file
        if (nonWhitespaceFound) {
            fputs(line, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File '%s' copied to '%s' without blank lines.\n", inputFileName, outputFileName);
}

void convertToLowerToUpper(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file '%s'\n", inputFileName);
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error creating output file '%s'\n", outputFileName);
        fclose(inputFile);
        return;
    }

    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(toupper(ch), outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Lowercase characters in '%s' converted to uppercase and saved in '%s'.\n", inputFileName, outputFileName);
}

int main() {
    // Task 1: Copy a file without blank lines
    copyFileWithoutBlankLines("input.txt", "output_no_blank_lines.txt");

    // Task 2: Convert lowercase characters to uppercase
    convertToLowerToUpper("input.txt", "output_uppercase.txt");

    return 0;
}


/*

In this program:

copyFileWithoutBlankLines function reads an input file, line by line, and copies it to an output file while omitting blank lines (lines containing only whitespace characters). The input and output file names are provided as arguments.

convertToLowerToUpper function reads an input file character by character, converts lowercase characters to uppercase using the toupper function, and writes the result to an output file.

In main, you can see how these functions are called to accomplish the two tasks. Replace "input.txt", "output_no_blank_lines.txt", "output_uppercase.txt" with your desired file names.

Make sure you adjust the buffer size (e.g., char line[256];) in the copyFileWithoutBlankLines function as needed for your input file's expected line length

======================================

The code you provided has two functions:

copyFileWithoutBlankLines(): This function copies a file to another file, but it removes all blank lines from the output file.

convertToLowerToUpper(): This function converts all lowercase characters in a file to uppercase characters and saves the output to another file.

The main() function in the code calls both of these functions to copy the file input.txt to two new files: output_no_blank_lines.txt and output_uppercase.txt.

Here is a more detailed explanation of what each function does:

copyFileWithoutBlankLines()

This function first opens the input file and output file. If either file cannot be opened, the function prints an error message and returns.

The function then creates a buffer to store the lines that are read from the input file. The buffer size is set to 256 characters, but you can adjust this as needed.

The function then reads a line from the input file and stores it in the buffer. If the line is not blank (contains at least one non-whitespace character), the function writes the line to the output file.

The function continues to read and write lines until the end of the input file is reached.

convertToLowerToUpper()

This function also first opens the input file and output file. If either file cannot be opened, the function prints an error message and returns.

The function then reads a character from the input file and stores it in a variable. If the character is not the end of file (EOF), the function converts the character to uppercase and writes it to the output file.

The function continues to read and write characters until the end of the input file is reached.

================================================

*/

#include <stdio.h>
#include <stdbool.h>

int countAlphabetsAndNumbers(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", fileName);
        return -1; // Error code
    }

    int alphabetCount = 0;
    int numberCount = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            alphabetCount++;
        } else if (isdigit(ch)) {
            numberCount++;
        }
    }

    fclose(file);
    printf("Total alphabets: %d\n", alphabetCount);
    printf("Total numeric characters: %d\n", numberCount);

    return 0; // Success
}

void removeComments(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file '%s'\n", inputFileName);
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error creating output file '%s'\n", outputFileName);
        fclose(inputFile);
        return;
    }

    int ch;
    bool inComment = false;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (inComment) {
            if (ch == '\n') {
                inComment = false;
                fputc(ch, outputFile);
            }
        } else {
            if (ch == '/') {
                int nextChar = fgetc(inputFile);
                if (nextChar == '/') {
                    inComment = true;
                } else {
                    fputc(ch, outputFile);
                    fputc(nextChar, outputFile);
                }
            } else {
                fputc(ch, outputFile);
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Comments removed from '%s' and saved in '%s'.\n", inputFileName, outputFileName);
}

int main() {
    // Task 1: Count alphabets and numeric characters in a file
    countAlphabetsAndNumbers("input.txt");

    // Task 2: Remove comments from a file
    removeComments("input_with_comments.txt", "output_no_comments.txt");

    return 0;
}


/*

In this program:

countAlphabetsAndNumbers function reads an input file character by character and counts the total number of alphabets and numeric characters. It then prints the counts to the console.

removeComments function reads an input file character by character and removes comments that start with double slashes (//) and continue until the end of the line. The cleaned content is saved to an output file.

In main, you can see how these functions are called to accomplish the two tasks. Replace "input.txt", "input_with_comments.txt", "output_no_comments.txt" with your desired file names.

Make sure you adjust the file paths and names accordingly to match your input files and desired output files.


----------------------------------------

This function takes a file name as input, opens the file for reading ("r" mode), and counts the total number of alphabetic characters (letters) and numeric characters (digits) in the file.

It initializes counters for alphabetCount and numberCount to keep track of the counts.
It uses a while loop to read each character from the file using fgetc(file) until it reaches the end of the file (EOF).

Inside the loop, it checks whether the character ch is an alphabet using isalpha(ch) or a digit using isdigit(ch), and increments the respective counter accordingly.

After processing the entire file, it closes the file using fclose(file) and prints the counts to the console.

------------------------------------------

Remove Comments from a File:


This function takes two file names as input: inputFileName for the input file with comments and outputFileName for the output file without comments.

It opens the input file for reading ("r" mode) and the output file for writing ("w" mode).

Inside a while loop, it reads each character ch from the input file until the end of the file (EOF).

If it encounters a double slash (//) while not already in a comment (inComment is false), it sets inComment to true, indicating that it's inside a comment.

If it's inside a comment, it checks for a newline character ('\n') to detect the end of the comment. Once it finds the newline, it sets inComment to false and writes the newline to the output file.

If it's not inside a comment, it checks if the character is a forward slash ('/'). If so, it checks the next character (nextChar). If nextChar is also a forward slash, it sets inComment to true, indicating the start of a comment. Otherwise, it writes both characters to the output file.

If none of the above conditions apply, it simply writes the character to the output file.

After processing the entire input file, it closes both input and output files and prints a message indicating that comments have been removed and the cleaned content is saved in the output file.

In main, you can see how these functions are called to perform both tasks.

======================================

Certainly, here's a C program that concatenates any number of files and writes the output to a destination file. The program takes the names of the source files as command-line arguments and creates a destination file where the concatenated content is saved.

*/

#include <stdio.h>
#include <stdlib.h>

void concatenateFiles(const char *outputFileName, int numFiles, char *fileNames[]) {
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error creating output file '%s'\n", outputFileName);
        return;
    }

    for (int i = 0; i < numFiles; i++) {
        FILE *inputFile = fopen(fileNames[i], "r");
        if (inputFile == NULL) {
            printf("Error opening input file '%s'\n", fileNames[i]);
            continue;  // Skip this file and proceed with the next
        }

        int ch;
        while ((ch = fgetc(inputFile)) != EOF) {
            fputc(ch, outputFile);
        }

        fclose(inputFile);
    }

    fclose(outputFile);
    printf("Files concatenated and saved in '%s'.\n", outputFileName);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <outputFile> <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    char *outputFileName = argv[1];
    int numFiles = argc - 2;  // Subtract 2 for program name and output file name
    char **fileNames = argv + 2;  // Start from the third argument

    concatenateFiles(outputFileName, numFiles, fileNames);

    return 0;
}


/*

Here's an explanation of the program:

The concatenateFiles function takes the output file name, the number of source files (numFiles), and an array of source file names (fileNames[]) as input.

It opens the output file in write mode ("w").

It iterates through the source file names and for each file:

It opens the source file in read mode ("r").

It reads characters from the source file and writes them to the output file until it reaches the end of the source file (EOF).

It then closes the source file.

After processing all source files, it closes the output file and prints a message indicating that the files have been concatenated and saved in the output file.

In main, the program checks if the correct number of command-line arguments is provided (at least 3, including the program name, output file name, and at least one source file).

It extracts the output file name and the source file names from the command-line arguments.

It calls the concatenateFiles function to concatenate the source files into the output file.

You can run the program like this:

./program output.txt file1.txt file2.txt file3.txt

Replace "program" with the name of your compiled executable and provide the appropriate file names for concatenation.

=============================================

Write a program to insert line numbers and page numbers in a file. Adding line numbers and page numbers to a file can be a bit complex, as it requires keeping track of line breaks and page breaks. Here's a simplified C program that inserts line numbers and page numbers into a text file:

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256  // Maximum line length, adjust as needed

void insertLineAndPageNumbers(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file '%s'\n", inputFileName);
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error creating output file '%s'\n", outputFileName);
        fclose(inputFile);
        return;
    }

    int lineNumber = 1;
    int pageNumber = 1;
    char line[MAX_LINE_LENGTH];
    int linesPerPage = 40;  // Adjust as needed for the number of lines per page

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Check for page break
        if (lineNumber % linesPerPage == 0) {
            fprintf(outputFile, "Page %d\n", pageNumber);
            pageNumber++;
        }

        fprintf(outputFile, "%4d: %s", lineNumber, line);
        lineNumber++;
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Line and page numbers inserted into '%s' and saved in '%s'.\n", inputFileName, outputFileName);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <inputFile> <outputFile>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];

    insertLineAndPageNumbers(inputFileName, outputFileName);

    return 0;
}

/*

This program inserts line numbers and page numbers into a text file based on a fixed number of lines per page (linesPerPage). Here's how it works:

The insertLineAndPageNumbers function takes two file names as input: inputFileName for the input file and outputFileName for the output file.

It opens the input file for reading ("r" mode) and the output file for writing ("w" mode).

Inside a loop, it reads each line from the input file using fgets and checks if it's time for a page break based on the current lineNumber and linesPerPage.

If it's a page break, it writes the page number to the output file and increments the pageNumber.

It then inserts the line number and the content of the line into the output file, with appropriate formatting.

After processing all lines from the input file, it closes both input and output files and prints a message indicating that line and page numbers have been inserted.

In main, the program checks if the correct number of command-line arguments is provided (exactly 3: program name, input file name, and output file name).

It extracts the input and output file names from the command-line arguments.

It calls the insertLineAndPageNumbers function to insert line and page numbers into the input file and save the result in the output file.

You can run the program like this:

./program input.txt output.txt

Replace "program" with the name of your compiled executable and provide the appropriate file names. Adjust linesPerPage as needed for your desired number of lines per page.


========================================
Consider this structure-
    struct {
        char name;
        int age;
        int sal;
    }

Write a program to store 10 records of this structure in the file and sort them on the basis of name and age, where name· is the primary key and age is secondary key.

To store and sort records of the given structure in a file based on name as the primary key and age as the secondary key, you can follow these steps:

Define the structure for the records.
Create a function to input data for each record.
Create a function to write records to a file.
Create a function to read records from the file.
Create a function to sort the records based on the specified keys.
In the main function, input data for 10 records, write them to a file, read them back, sort them, and finally, display the sorted records.

Here's a C program to accomplish this task:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define the structure for records
struct Record {
    char name[MAX_NAME_LENGTH];
    int age;
    int sal;
};

// Function to input data for a record
void inputData(struct Record *record, int recordNumber) {
    printf("Enter details for Record %d:\n", recordNumber);
    printf("Name: ");
    scanf("%s", record->name);
    printf("Age: ");
    scanf("%d", &(record->age));
    printf("Salary: ");
    scanf("%d", &(record->sal));
}

// Function to write records to a file
void writeRecordsToFile(const char *fileName, struct Record records[], int numRecords) {
    FILE *file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error opening file '%s' for writing\n", fileName);
        return;
    }
    fwrite(records, sizeof(struct Record), numRecords, file);
    fclose(file);
}

// Function to read records from a file
void readRecordsFromFile(const char *fileName, struct Record records[], int numRecords) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file '%s' for reading\n", fileName);
        return;
    }
    fread(records, sizeof(struct Record), numRecords, file);
    fclose(file);
}

// Comparator function for qsort to sort records by name and age
int compareRecords(const void *a, const void *b) {
    const struct Record *recordA = (const struct Record *)a;
    const struct Record *recordB = (const struct Record *)b;

    int nameComparison = strcmp(recordA->name, recordB->name);
    if (nameComparison != 0) {
        return nameComparison;
    }

    return recordA->age - recordB->age;
}

int main() {
    const char *fileName = "records.dat";
    const int numRecords = 10;

    // Allocate an array to store the records
    struct Record records[numRecords];

    // Input data for each record
    for (int i = 0; i < numRecords; i++) {
        inputData(&records[i], i + 1);
    }

    // Write records to a file
    writeRecordsToFile(fileName, records, numRecords);

    // Read records from the file
    readRecordsFromFile(fileName, records, numRecords);

    // Sort records based on name and age
    qsort(records, numRecords, sizeof(struct Record), compareRecords);

    // Display the sorted records
    printf("\nSorted Records:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, Age: %d, Salary: %d\n", records[i].name, records[i].age, records[i].sal);
    }

    return 0;
}


/*

In this program:

The struct Record defines the structure for the records, which includes a name (as a string), age, and salary.
The inputData function is used to input data for a single record.
The writeRecordsToFile function writes the records to a binary file.
The readRecordsFromFile function reads the records from the binary file.
The compareRecords function is a comparator function used by qsort to sort the records first by name and then by age.
In the main function, 10 records are input, written to a file, read back, sorted, and finally displayed.
Make sure to adjust MAX_NAME_LENGTH and the file name as needed.

===================================

I'll explain the program step by step using notes:

Step 1: Define the Structure

We start by defining a structure called struct Record to represent each record.
Each record has three fields: name (a string), age, and sal (salary).
Step 2: Input Data for Records

We create a function called inputData to input data for a single record.
This function asks the user for the name, age, and salary for a record and stores them in the corresponding fields of the struct Record.
Step 3: Write Records to a File

Another function called writeRecordsToFile is used to write records to a binary file.
It opens the specified file in write-binary mode ("wb") for writing.
Then, it writes the records (an array of struct Record) to the file using fwrite.
Step 4: Read Records from a File

We have a function named readRecordsFromFile to read records from the binary file.
It opens the specified file in read-binary mode ("rb") for reading.
It reads the records from the file into the array using fread.
Step 5: Sorting Records

A comparator function called compareRecords is defined.
It's used by the qsort function to sort records first by name and then by age.
The function compares two records and returns a negative value if the first should come before the second, a positive value if the first should come after, and zero if they are equal.
Step 6: Main Function

In the main function:
We specify the file name ("records.dat") and the number of records (10).
We declare an array to store the records.
We input data for each record using the inputData function.
We write the records to a file using writeRecordsToFile.
We read the records from the file using readRecordsFromFile.
We sort the records using qsort with the compareRecords function.
Finally, we display the sorted records to the user.
Note: Ensure you adjust the MAX_NAME_LENGTH (maximum name length allowed) and the file name ("records.dat") as needed for your application.

=====================================

I can help you modify the program to mark records for deletion and create a function to physically delete those marked records from the file. Here's an updated version of the program:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define the structure for records
struct Record {
    char name[MAX_NAME_LENGTH];
    int age;
    int sal;
    int isDeleted;  // Flag to mark deleted records
};

// Function to input data for a record
void inputData(struct Record *record, int recordNumber) {
    printf("Enter details for Record %d:\n", recordNumber);
    printf("Name: ");
    scanf("%s", record->name);
    printf("Age: ");
    scanf("%d", &(record->age));
    printf("Salary: ");
    scanf("%d", &(record->sal));
    record->isDeleted = 0;  // Initialize the deleted flag to 0 (not deleted)
}

// Function to write records to a file
void writeRecordsToFile(const char *fileName, struct Record records[], int numRecords) {
    FILE *file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error opening file '%s' for writing\n", fileName);
        return;
    }
    fwrite(records, sizeof(struct Record), numRecords, file);
    fclose(file);
}

// Function to read records from a file
void readRecordsFromFile(const char *fileName, struct Record records[], int numRecords) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file '%s' for reading\n", fileName);
        return;
    }
    fread(records, sizeof(struct Record), numRecords, file);
    fclose(file);
}

// Function to mark a record as deleted
void markRecordAsDeleted(struct Record *record) {
    record->isDeleted = 1;
}

// Function to physically delete marked records from a file
void deleteMarkedRecordsFromFile(const char *fileName, struct Record records[], int numRecords) {
    FILE *file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error opening file '%s' for writing\n", fileName);
        return;
    }

    for (int i = 0; i < numRecords; i++) {
        if (!records[i].isDeleted) {
            fwrite(&records[i], sizeof(struct Record), 1, file);
        }
    }

    fclose(file);
}

int main() {
    const char *fileName = "records.dat";
    const int numRecords = 10;

    // Allocate an array to store the records
    struct Record records[numRecords];

    // Input data for each record
    for (int i = 0; i < numRecords; i++) {
        inputData(&records[i], i + 1);
    }

    // Write records to a file
    writeRecordsToFile(fileName, records, numRecords);

    // Mark a record as deleted (you can do this as needed)
    markRecordAsDeleted(&records[2]); // Marking the third record as deleted

    // Physically delete marked records from the file
    deleteMarkedRecordsFromFile(fileName, records, numRecords);

    // Read the updated records from the file
    readRecordsFromFile(fileName, records, numRecords);

    // Display the records, including marked ones
    printf("\nRecords:\n");
    for (int i = 0; i < numRecords; i++) {
        if (!records[i].isDeleted) {
            printf("Name: %s, Age: %d, Salary: %d\n", records[i].name, records[i].age, records[i].sal);
        }
    }

    return 0;
}

/*

In this updated program:

We added an isDeleted field to the struct Record to mark records as deleted (0 for not deleted, 1 for deleted).

We created two new functions: markRecordAsDeleted to mark a specific record as deleted and deleteMarkedRecordsFromFile to physically delete marked records from the file.

In main, we marked a record as deleted (you can do this as needed), and then we used deleteMarkedRecordsFromFile to physically delete marked records.

The program reads and displays the records, including marked ones, to show the updated state.

Please note that this program does not handle reclaiming space efficiently, and it might not be suitable for extremely large datasets. More advanced file handling techniques would be needed for such cases.

*/




