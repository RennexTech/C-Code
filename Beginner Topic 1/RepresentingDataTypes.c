#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
I want to learn to use these datatypes

char - 1 byte[-128 to 127]
short - 2 bytes	[-32,768 to 32,767]
int - 4 bytes[-2,147,483,648 to 2,147,483,647]
long - 4 bytes[-2,147,483,648 to 2,147,483,647]
long long - 8 bytes[-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807]
unsigned char - [1 byte	0 to 255]
unsigned short - [2 bytes	0 to 65,535]
unsigned int - [4 bytes	0 to 4,294,967,295]
unsigned long - [4 bytes	0 to 4,294,967,295]
unsigned long long - [8 bytes	0 to 18,446,744,073,709,551,615]

so a short is 2 bytes , that means its 2 power 8 the first byte,
and 2 power 8 the second byte which equals?

No, that is not correct.
A short is 2 bytes, which means that it can store a value between
-32,768 and 32,767.
The first byte of a short stores the most significant byte of the value,
and the second byte stores the least significant byte of the value.

The expression 2^8 is equal to 256. So, if a short were 2 bytes,
and each byte were 2^8, then the short would be able to store
a value between -256,000 and 256,000.
However, as I mentioned before, a short is actually 2 bytes,
and each byte can store a value between 0 and 255.
So, a short can store a value between -32,768 and 32,767.

*/

int main()
{
    int num; //int is 4 bytes
    long num1; //8 bytes, twice the size of a normal integer
    long long num2; //
    unsigned short num3;
    unsigned long num4;
    unsigned long long num5;
    short int num7;
    unsigned int num8;
    unsigned short int num9;
    long int num10;
    unsigned long int num11;
    long long int num12;
    unsigned long long int num13;

    printf("int is the most common data type in C. It is used to store integers of any size.\n");
    printf("short int is used to store integers that are half the size of ints.\n");
    printf("unsigned int is used to store unsigned integers, which can only store positive values.\n");
    printf("unsigned short int is used to store unsigned integers that are half the size of unsigned ints.\n");
    printf("long int is used to store integers that are twice the size of ints.\n");
    printf("unsigned long int is used to store unsigned integers that are twice the size of unsigned ints.\n");
    printf("long long int is used to store integers that are four times the size of ints.\n");
    printf("unsigned long long int is used to store unsigned integers that are four times the size of unsigned ints.\n");

    printf("Let's calculate stuff using these datatypes: \n");
    printf("The size of an integer is: %d\n", sizeof(int));
    printf("The size of an float is: %d\n", sizeof(float));
    printf("The size of an double is: %d\n", sizeof(double));
    printf("The size of an long int is: %d\n", sizeof(long int));
    printf("The size of an long long int is: %d\n", sizeof(long long int));
    printf("The size of an short int is: %d\n", sizeof(short int));
    printf("The size of an char is: %d\n", sizeof(char));

    return 0;
}
