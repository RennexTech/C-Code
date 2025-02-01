#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("--------------------------------------------\n");
    printf("I will be printing you the 32 C Keywords\n");
    printf("--------------------------------------------\n");

    sleep(1);
    printf("\n");
    printf("\n");

    printf("1. auto\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The auto keyword is a storage class specifier used within a function to declare variables with automatic storage duration. These variables are created when the block containing the declaration is entered and destroyed when the block is exited. It's the default storage class for local variables.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("2. break\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The break keyword is used within loops (like for, while, do-while) and switch statements to immediately exit the loop or switch when the break statement is encountered. It's often used to terminate a loop prematurely or to exit a switch case.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("3. case\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The case keyword is used within a switch statement to specify different cases that match a particular value. It's followed by a constant expression and represents a particular branch of execution based on the value being tested.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("4. char\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The char keyword is used to declare a variable that can hold a single character. It's often used to represent characters or small integers.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("5. const\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The const keyword is used to indicate that a variable's value cannot be changed after initialization. It's used for declaring constants and improving code safety.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("6. continue\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The continue keyword is used within loops to skip the current iteration and move to the next iteration of the loop.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("7. default\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf(" The default keyword is used within a switch statement as a fallback case when none of the other case statements match the given value.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("8. do\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The do keyword is the starting point of a do-while loop. It's used to repeatedly execute a block of code while a condition is true, with the condition checked after each iteration.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("9. double\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The double keyword is used to declare a variable that can hold a floating-point number with double precision. It's commonly used to store decimal values.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("10. else\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The else keyword is used in conjunction with if statements to specify a block of code that should be executed when the condition of the if statement is false.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("11. enum\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The enum keyword is used to define an enumeration, which is a set of named integer constants. Enums provide a way to create more meaningful and self-documenting code.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("12. extern\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The extern keyword is used to declare a variable or function as being defined externally, meaning it's defined in a separate file. It's often used for global variables and functions shared across multiple files.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("13. float\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The float keyword is used to declare a variable that can hold a floating-point number with single precision.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("14. for\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The for keyword is used to initiate a for loop, which is used to repeatedly execute a block of code for a specific number of times.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("15. goto\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The goto keyword is used to transfer control to a labeled statement elsewhere in the code. It's considered bad practice in most cases due to its potential to make code difficult to understand and maintain.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("16. if\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The if keyword is used to create a conditional statement, allowing different blocks of code to be executed based on whether a given condition is true or false.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("17. int\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The int keyword is used to declare a variable that can hold an integer value.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("18. long\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The long keyword is used to declare a variable that can hold a larger range of integer values compared to int.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("19. register\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The register keyword is used to suggest that a variable should be stored in a CPU register for faster access. However, modern compilers often optimize variable storage without explicit use of register.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("20. return\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf(" The return keyword is used within functions to indicate the value that the function should return. It also terminates the function's execution and transfers control back to the calling function.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("21. short\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The short keyword is used to declare a variable that can hold a smaller range of integer values compared to int.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("22. signed\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The signed keyword is used to indicate that a variable can hold both positive and negative values. It's used to specify the sign representation for integer types.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("23. sizeof\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The sizeof keyword is used to determine the size in bytes of a particular data type or variable.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("24. static\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The static keyword is used to declare a variable or function as having static storage duration. For variables, it means the variable retains its value between function calls. For functions, it limits the scope of the function to the current file.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("25. struct\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The struct keyword is used to define a structure, which is a composite data type that groups together variables of different data types under a single name.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("26. switch\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The switch keyword is used to create a switch statement, which allows branching to different parts of code based on the value of a variable.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("27. typedef\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The typedef keyword is used to create an alias or synonym for a data type, making it easier to use complex types or to enhance code readability.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("28. union\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The union keyword is used to define a union, which is a data structure that can store different data types in the same memory location.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("29. unsigned\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The unsigned keyword is used to indicate that a variable can hold only positive values. It's used to specify the sign representation for integer types.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("30. void\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The void keyword is used to declare that a function does not return a value or to indicate the absence of a data type in certain contexts.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("31. volatile\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The volatile keyword is used to indicate to the compiler that a variable's value may change at any time, even if the compiler cannot detect such changes.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("32. while\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The while keyword is used to initiate a while loop, which repeatedly executes a block of code as long as a specified condition is true.\n");
    printf("--------------------------------------------\n");
    sleep(5);

    printf("\n");
    printf("\n");

    printf("--------------------------------------------\n");
    printf("That's all you need to learn to use in C programming.\n");
    printf("--------------------------------------------\n");

    printf("\n");
    printf("\n");

    return 0;
}
