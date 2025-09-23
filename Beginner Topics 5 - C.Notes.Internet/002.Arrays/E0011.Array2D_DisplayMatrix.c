#include <stdio.h>

// We're using #define to create constants for the dimensions of our matrix.
// This is a crucial practice. It makes the code way cleaner and easier to change.
// Think of it as setting the dimensions of a spreadsheet before you start filling it out.
#define ROW 3
#define COL 4

int main()
{
    // This is a fixed-size array. To the computer, it's just a single, continuous
    // block of memory, but to us, it's a grid with `ROW` rows and `COL` columns.
    // The memory for this is allocated on the program's "stack" as soon as it starts.
    int mat[ROW][COL];
    
    // This part of the code handles the user input.
    printf("Enter matrix mat1(%dx%d) row-wise: \n", ROW, COL);
    
    // The nested `for` loops are a classic pattern for working with grids.
    // The outer loop (`i`) handles the rows, moving down one row at a time.
    // The inner loop (`j`) handles the columns, moving across each row.
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            // `scanf` reads an integer from the user and stores it.
            // The `&mat[i][j]` part is a pointer to the specific memory address
            // where that number needs to be stored. It's how the program knows
            // exactly which cell of the grid to write to.
            scanf("%d", &mat[i][j]);
        }
    }
    
    // This block handles printing the matrix back to the user.
    printf("The matrix that you have entered is: \n");
    
    // We use the same nested `for` loop structure to read the values back out.
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            // Here, we're not using the `&` operator because we want the
            // **value** stored at that location, not the address.
            // `printf` formats the output neatly.
            printf("%d ", mat[i][j]);
        }
        // After each row is printed, we add a newline character to make the
        // output look like a proper grid.
        printf("\n");
    }
    
    return 0;
}

// These snippets aren't that big, coz coding isn't about the size of the code, but about making an idea come to life. 

// I used to do 200+ lines per file, but now I realized, even 70 lines is good to teach people these concepts. 

// Good small comments + simple code => Better than knowing all the edge cases or applications.