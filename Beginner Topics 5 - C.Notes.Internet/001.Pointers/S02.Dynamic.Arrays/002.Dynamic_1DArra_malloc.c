#include <stdio.h>
#include <stdlib.h> // This is for `malloc` and `free`.

int main()
{
    int n, *p;

    // We're asking the user how much memory they need. This makes our program flexible.
    printf("Enter number of integers to be entered: ");
    scanf("%d", &n);

    // This is the dynamic allocation. We're telling the OS, "Yo, give me a chunk of memory
    // big enough to hold `n` integers." The `malloc` function hands back a pointer
    // to the start of that memory block.
    p = (int*)malloc(n * sizeof(int));

    // A crucial check. If `malloc` fails (e.g., no memory is available), it returns `NULL`.
    // It's like checking if the landlord actually gave you a key to the apartment.
    if (p == NULL)
    {
        printf("Memory not available\n");
        return 1; // Exit the program with an error.
    }

    // We can now use our pointer `p` just like a regular array name.
    for (int i = 0; i < n; i++)
    {
        printf("Enter an integer [%d]: ", i);
        scanf("%d", &p[i]);
    }

    printf("\nYour entered integers are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", p[i]);
    }
    printf("\n");

    // This is the most important part of dynamic memory. We're telling the OS
    // "I'm done with this memory. You can have it back." Forgetting to do this
    // leads to a memory leak, which is a major problem in long-running programs.
    free(p);

    return 0;
}
