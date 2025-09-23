/*

Enumerations are indeed a useful feature in C, allowing you to define custom data types with a set of named values. Let's delve deeper into the concept of enumerations in C.

Enumeration Basics:

Enumerations, often referred to as enums, are user-defined data types in C that consist of a list of named integer constants. These named constants make your code more readable and self-documenting, as you mentioned. Enumerations can be created using the enum keyword, and they follow this general syntax:

*/

enum enum_name {
    enumerator1,
    enumerator2,
    // Add more enumerators as needed
};

/*

Here's a breakdown of the elements:

enum_name: This is the name you give to your new enumeration data type.
enumerator1, enumerator2, etc.: These are the named integer constants within the enumeration.

Default Values:

By default, the enumerators in an enum start with the value 0 for the first enumerator, and each subsequent enumerator is assigned a value one greater than the previous one.

For example, if you define an enum like this:

*/

enum month {
    Jan,  // Jan = 0
    Feb,  // Feb = 1
    Mar,  // Mar = 2
    // and so on...
};

//You can explicitly assign values to some or all of the enumerators if you wish, like this:

enum month {
    Jan,     // Jan = 0
    Feb = 4, // Feb = 4
    Mar,     // Mar = 5 (one greater than the previous)
    // and so on...
};

//Using Enumerations: Once you've defined an enumeration, you can declare variables of that enum type and assign values from the list of enumerators. For example:

enum month current_month;
current_month = Mar; // Assigning the value "Mar" to the variable

//You can also compare variables of the same enum type or use them in expressions just like regular integers. Here are some more examples of enums:

enum suit { Spades, Hearts, Clubs, Diamonds };
enum position { Ace = 1, King, Queen, Jack, Ten, Nine, Eight, Seven, Six, Five };
enum day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
enum color { white, black, red, green, blue, yellow, pink, brown };
enum boolean { true, false };
enum switch_state { off, on };
enum subject { Hindi, English, Maths, Physics, Chemistry, Biology, History };
enum base { Binary = 2, Octal = 8, Decimal = 10, Hexadecimal = 16 };

//Enumeration in C: Enumerations in C are a way to define custom data types with a set of named integer constants. They enhance code readability and documentation.

enum color { walls, floor };

if (walls == pink)
    floor = blue;
else
    floor = white;

enum day today;
today = Monday;

if (today == Sunday)
    printf("Holiday\n");
else if (today == Saturday)
    printf("Half working day\n");
else
    printf("Full working day\n");

enum subject s;
int passmarks;

switch (s) {
    case hindi:
    case english:
        passmarks = 25;
        break;
    case maths:
        passmarks = 40;
        break;
    case physics:
    case chemistry:
        passmarks = 35;
        break;
    default:
        passmarks = 33;
}

//Function Using Enums. Here's a function that returns the number of days in a month:

enum month m;
int days;

if (m == Apr || m == Jun || m == Sep || m == Nov)
    days = 30;
else if (m == Jan || m == Mar || m == May || m == Jul || m == Aug || m == Oct || m == Dec)
    days = 31;
else
    days = 28;


//Input and Output. When working with enums, it's important to note that input and output are done in terms of their integer values, not their names.

enum month ml;
int m2;

ml = Mar;
printf("ml = %d\n", ml);

printf("Enter value for m2: ");
scanf("%d", &m2);

printf("m2 = %d\n", m2);

//Naming Conventions. Enum names should be distinct from other identifiers in the scope to avoid conflicts.

enum group1 { physics, chemistry, maths };
enum group2 { zoology, botany, chemistry }; // Invalid (conflict with chemistry)

//Also, avoid using enum names as variable names:
float maths; // Invalid (conflict with enum name)

//Typedef with Enums. You can use typedef to simplify the use of enums:
typedef enum { false, true } boolean;
boolean flag = true;

/*

Comparison with #define:

Comparing enums with #define:

Enums create new data types with named constants, whereas #define only creates named constants.

Enums are part of the C language, while #define is a preprocessor directive.
#define constants are global, while enums obey scope rules.

Enums automatically assign values, while #define requires explicit value assignment.
Conclusion:

Enums in C are a valuable tool for improving code readability and organization. They provide a structured way to define custom data types with meaningful names for constants. When used effectively, enums can make your code more understandable and maintainable.

-----------------------------------------

Let's illustrate these comparisons between enums and #define with code examples:

Enums vs. #define:


*/

---------------------------------------------------------

//Enums create new data types with named constants:
// Enum example
enum color { RED, GREEN, BLUE };
enum color myColor = RED;

// #define example
#define RED 0
#define GREEN 1
#define BLUE 2
int myColor = RED; // No new data type created

---------------------------------------------------------

//Enums are part of the C language, while #define is a preprocessor directive:
// Enum example
enum color { RED, GREEN, BLUE };

// #define example
#define RED 0
#define GREEN 1
#define BLUE 2

---------------------------------------------------------

//#define constants are global, while enums obey scope rules:
// Enum example
enum color { RED, GREEN, BLUE };

void myFunction() {
    enum color insideColor = GREEN;
}

// #define example
#define GREEN 1

void myFunction() {
    int insideColor = GREEN; // No scope isolation
}

---------------------------------------------------------

//Enums automatically assign values, while #define requires explicit value assignment:
// Enum example
enum color { RED, GREEN, BLUE }; // Automatically assigns values: RED=0, GREEN=1, BLUE=2

// #define example
#define RED 0
#define GREEN 1
#define BLUE 2 // Requires explicit value assignment


