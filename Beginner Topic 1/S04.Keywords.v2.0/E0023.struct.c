/**
 * 
 * struct is like creating your own customized 'profile card' or 'data packet'. 
 * 
 * You know how a person has a name (text), an age (number), and a height (decimal)? 
 * 
 * Instead of keeping these as separate, loose pieces of info, 
 * 
 * struct lets you bundle them all up under one single, neat label, like 'Person'. 
 * 
 * It's super useful for organizing related bits of data into one logical unit, 
 * 
 * making your code way cleaner and easier to manage complex information.
 * 
 */

#include <stdio.h>
#include <string.h> // For strcpy
#include <unistd.h> // For sleep

// Defining the struct (blueprint for a Car's details)
struct Car {
    char brand[50]; // Like the car's name
    int year;       // When it was made
    float price;    // How much it costs
};

int main() {
    printf("--------------------------------------------\n");
    printf("25. struct\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'struct' is like creating your own customized 'profile card' or 'data packet'... It's super useful for organizing related bits of data into one logical unit, making your code way cleaner and easier to manage complex information.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    // Creating a 'struct Car' instance (building an actual car from the blueprint)
    struct Car myCar;

    // Filling the struct (giving the car its details)
    strcpy(myCar.brand, "Toyota"); // Copying string for brand
    myCar.year = 2010;
    myCar.price = 8999.99f;

    // Creating another car
    struct Car yourCar;
    strcpy(yourCar.brand, "Honda");
    yourCar.year = 2018;
    yourCar.price = 15500.00f;

    // Printing the car details
    printf("🚗 My Car Info:\n");
    printf("Brand: %s\n", myCar.brand);
    printf("Year: %d\n", myCar.year);
    printf("Price: $%.2f\n", myCar.price);

    printf("\n🚗 Your Car Info:\n");
    printf("Brand: %s\n", yourCar.brand);
    printf("Year: %d\n", yourCar.year);
    printf("Price: $%.2f\n", yourCar.price);

    printf("Size of a Car struct: %zu bytes\n", sizeof(struct Car));
    sleep(5);
    return 0;
}