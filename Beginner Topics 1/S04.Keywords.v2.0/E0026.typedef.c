/**
 * 
 * typedef is like creating your own custom, easy-to-remember nicknames for complex data types. 
 * 
 * Imagine you have a super long, complicated title like 'Unsigned Long Long Integer'. 
 * 
 * Instead of writing that out every single time, typedef lets you say: 
 * 
 * 'From now on, let's just call that BigNumber.' 
 * 
 * It makes your code way more readable and easier to manage, 
 * 
 * especially when dealing with fancy data structures or pointers. 
 * 
 * It's all about making your code look cleaner and more professional.
 * 
 */

#include <stdio.h>
#include <string.h> // For strcpy
#include <unistd.h> // For sleep

// 1. Giving a nickname to a simple type
typedef int Count; // 'Count' is now another name for 'int'
typedef float Price; // 'Price' is now another name for 'float'

// 2. Nicknaming a struct (where typedef truly shines!)
// Define the struct first
struct Book_Internal {
    char title[50];
    int pages;
};
// Then, create a nickname for it!
typedef struct Book_Internal Book; // Now you can just use 'Book' instead of 'struct Book_Internal'

int main() {
    printf("--------------------------------------------\n");
    printf("27. typedef\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'typedef' is like creating your own custom, easy-to-remember nicknames for complex data types... It's all about making your code look cleaner and more professional.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    Count apples = 5; // Using our new 'Count' type
    Count oranges = 3;
    Count total_fruit = apples + oranges;
    printf("Total fruit count: %d\n", total_fruit);

    Price soda_price = 1.50f; // Using our new 'Price' type
    Price burger_price = 4.75f;
    Price total_price = soda_price + burger_price;
    printf("Total meal price: $%.2f\n", total_price);

    // Using our nicknamed struct
    Book my_book;
    strcpy(my_book.title, "The C Programming Guide");
    my_book.pages = 420;
    printf("My book: \"%s\" has %d pages.\n", my_book.title, my_book.pages);

    sleep(5);
    return 0;
}

