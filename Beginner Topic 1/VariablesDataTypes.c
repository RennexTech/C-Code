#include <stdio.h>
#include <stdlib.h>

int main()
{
    char answer[500];
    printf("What is the difference between keyword and reserved words in C?\n");
    scanf("%[^\n]", &answer); //note this format specifier - placeholder %s does not work here, it will only take the first word in your answer

    printf("\n");
    printf("\n");

    printf("Your answer: %s\n", answer);

    printf("\n");
    printf("\n");

    printf("The best definition is: \n");

    printf("\n");
    printf("\n");

    printf("-------------------------\n");
    sleep(1);
    printf("Keyword: Keywords are reserved words in a programming language. They have predefined meanings and are used to perform specific tasks or operations. \n");
    printf("-------------------------\n");

    printf("\n");
    printf("\n");

    printf("-------------------------\n");
    printf("An identifier is essentially a label that you give to a program entity. Rules for naming identifiers include: They must start with a letter (uppercase or lowercase) or an underscore. After the first character, they can include letters, digits, and underscores. Identifiers are case-sensitive; for example, count and Count, would be treated as different identifiers. They cannot be the same as keywords.\n");
    printf("-------------------------\n");

    printf("\n");
    printf("\n");

    printf("-------------------------\n");
    printf("THESE ARE THE MAIN RULES FOR IDENTIFIERS IN C PROGRAMMING\n");
    printf("~READ ADN RE-READ FOR YOU TO NEVER FORGET~\n");
    printf("-------------------------\n");

    printf("Identifiers should only contain alphabets, digits, and only symbol allowed is underscore\n");
    sleep(1);
    printf("The first character of an identifier should be either an alphabet letter or an underscore\n");
    sleep(1);
    printf("Identifiers should not be the same as C keywords\n");
    sleep(1);
    printf("C is case-sensitive, so check out on that when dealing with C identifiers\n");
    sleep(1);
    printf("Identifiers can be arbitrarily long, but some implementations of C might recognize only the first 8 characters to 31 characters.\n");
    sleep(1);
    printf("Give meaningful names for your identifiers for clean and maintainable code\n");
    sleep(1);
    printf("Blank space is not allowed!\n");

    printf("-------------------------\n");

    return 0;
}
