#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age = 21;
    int *page = &age;
    float marks = 95.5;
    float *pmarks = &marks;

    printf("You are %d years old, address %u\n", age, &age);
    printf("The old tortoise age is %d\n", *page);
    printf("You got %f in math, address %p\n", marks, &marks);

    //Dereferencing and changing data you've just accessed
    page = 300;
    printf("The new tortoise age is %d", page);

    return 0;
}
