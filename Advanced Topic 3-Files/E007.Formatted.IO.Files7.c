#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program is a practical guide to file I/O operations in C.
 * It's structured as a toolkit, with functions demonstrating the use
 * of `fgetc`, `fputc`, `fgets`, `fputs`, `fscanf`, `fprintf`, `fread`,
 * and `fwrite`, all of which are listed in your notes.
 *
 * Each function is like a different tool in your toolbox, designed for
 * a specific job. You wouldn't use a wrench to hammer a nail, and you
 * wouldn't use `fread` to read a single character when `fgetc` is perfect for the job.
 * This code will show you which tool to use and how.
 */

// Function prototypes to keep the compiler happy.
void character_io_demo(const char *filename);
void string_io_demo(const char *filename);
void formatted_io_demo(const char *filename);
void record_io_demo(const char *filename);

int main() {
    printf("Welcome to the C File I/O Toolkit!\n");
    printf("This program will demonstrate various file operations.\n\n");

    // The functions are called in a logical order.
    // We create files, then we read from them.
    character_io_demo("character_demo.txt");
    string_io_demo("string_demo.txt");
    formatted_io_demo("formatted_demo.txt");
    record_io_demo("record_demo.bin"); // For binary data

    printf("All demonstrations complete. Check the directory for the generated files.\n");

    // Quick check on the predefined file pointers.
    // These are like default communication channels built into every program.
    // stdin: The keyboard. Your program reads from it.
    // stdout: The screen. Your program writes to it.
    // stderr: The screen, but specifically for error messages.
    // These are already open when your program starts. You never need to open them yourself.
    fprintf(stdout, "\nPredefined file pointers demo:\n");
    fprintf(stdout, "This message is printed using stdout.\n");
    fprintf(stderr, "This is an error message, printed to stderr.\n");
    fprintf(stdout, "They both show up on the screen, but in some cases, you can redirect them separately.\n");
    
    return 0;
}

/*
 * Tool #1: Character I/O (`fputc` and `fgetc`)
 *
 * This is the most basic, byte-by-byte file operation. It's like writing
 * a letter by hand, character by character. It's slow for large amounts
 * of data, but it's perfect for when you need to process a file one
 * character at a time, like counting vowels or finding a specific symbol.
 *
 * Analogy: A child learning to write.
 * fputc is placing a single letter on the page.
 * fgetc is pointing a finger at a single letter on the page.
 */
void character_io_demo(const char *filename) {
    printf("--- Demo: Character I/O (`fputc`, `fgetc`) ---\n");
    printf("Creating and writing to a file one character at a time...\n");
    
    // Step 1: Open the file for writing.
    // "w" means "write". If the file exists, it's overwritten. If not, it's created.
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    const char *message = "Hello, world! This is a character-based demo.";
    int i = 0;
    while (message[i] != '\0') {
        fputc(message[i], file);
        i++;
    }

    // A crucial step! Always close the file to save changes and free up system resources.
    // It's like closing and sealing the envelope on your letter.
    fclose(file);

    // Step 2: Open the file for reading.
    // "r" means "read". We can't write to it anymore.
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("Reading from the file one character at a time...\n");
    int c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    printf("\n\n");

    fclose(file);
}

/*
 * Tool #2: String I/O (`fputs` and `fgets`)
 *
 * This is a level up. Now we're dealing with whole sentences, not just
 * individual characters. It's much faster and more convenient for handling
 * text. This is what you'd use for reading a log file line by line or
 * writing out paragraphs of text.
 *
 * Analogy: A writer using a typewriter.
 * fputs is typing a full sentence.
 * fgets is reading a full line from the page.
 */
void string_io_demo(const char *filename) {
    printf("--- Demo: String I/O (`fputs`, `fgets`) ---\n");
    printf("Writing multiple lines to a file...\n");
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    fputs("This is the first line of text.\n", file);
    fputs("And this is the second line.\n", file);
    fputs("fgets will handle the whole line for us.\n", file);

    fclose(file);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("Reading the file line by line (up to 256 characters per line)...\n");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    printf("\n");

    fclose(file);
}

/*
 * Tool #3: Formatted I/O (`fprintf` and `fscanf`)
 *
 * This is like using a form or a template. You don't just write raw text;
 * you write data in a specific format (e.g., "Name: %s, Age: %d"). When you
 * read it back, you're not just reading a line; you're scanning that line
 * for the data that matches your template.
 *
 * Analogy: A librarian using a standardized cataloging system.
 * fprintf is filling out a new library card.
 * fscanf is finding a card and extracting the name and age.
 */
void formatted_io_demo(const char *filename) {
    printf("--- Demo: Formatted I/O (`fprintf`, `fscanf`) ---\n");
    printf("Writing structured data to a file...\n");

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    const char *name1 = "Alice";
    int age1 = 30;
    fprintf(file, "Name: %s, Age: %d\n", name1, age1);

    const char *name2 = "Bob";
    int age2 = 25;
    fprintf(file, "Name: %s, Age: %d\n", name2, age2);

    fclose(file);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("Reading structured data back from the file...\n");
    char read_name[50];
    int read_age;
    while (fscanf(file, "Name: %49s, Age: %d\n", read_name, &read_age) == 2) {
        printf("Found: Name: %s, Age: %d\n", read_name, read_age);
    }
    printf("\n");

    fclose(file);
}

// A simple data structure to demonstrate record I/O.
// Think of this as a single "record" in a database.
typedef struct {
    char name[20];
    int id;
    float gpa;
} Student;

/*
 * Tool #4: Record I/O (`fwrite` and `fread`)
 *
 * This is the most powerful and low-level tool for working with binary data.
 * Instead of dealing with text, you're dealing with raw bytes. You're telling
 * the program, "Read this many bytes from memory and write them to the file,"
 * or vice versa. This is how you read and write things like images, executable
 * files, and custom data formats. It's blazing fast because there's no text
 * formatting or parsing involved.
 *
 * Analogy: A programmer making a backup of their entire hard drive.
 * fwrite is making an exact copy of a block of data.
 * fread is restoring that exact copy, bit for bit.
 */
void record_io_demo(const char *filename) {
    printf("--- Demo: Record I/O (`fwrite`, `fread`) ---\n");
    printf("Writing a whole data structure to a binary file...\n");

    FILE *file = fopen(filename, "wb"); // "wb" for "write binary"
    if (file == NULL) {
        perror("Error opening binary file for writing");
        return;
    }

    Student student1 = {"Abdi", 101, 3.8};
    Student student2 = {"Mercy", 102, 4.0};

    // The fwrite function writes a block of memory to the file.
    // Syntax: fwrite(data, size of each item, number of items, file pointer)
    fwrite(&student1, sizeof(Student), 1, file);
    fwrite(&student2, sizeof(Student), 1, file);

    fclose(file);

    file = fopen(filename, "rb"); // "rb" for "read binary"
    if (file == NULL) {
        perror("Error opening binary file for reading");
        return;
    }

    printf("Reading a whole data structure from the binary file...\n");
    Student read_student;

    // The fread function reads a block of memory from the file.
    // Syntax: fread(destination, size of each item, number of items, file pointer)
    while (fread(&read_student, sizeof(Student), 1, file) == 1) {
        printf("Record found: Name: %s, ID: %d, GPA: %.1f\n",
               read_student.name, read_student.id, read_student.gpa);
    }
    printf("\n");
    
    fclose(file);
}
