#include<stdio.h>
int main()
{
    int matrix[2][3]; //to declare the 1st matrix
    // int matrix[2][3]={{10,20,30},{40,50,60}}; //to initialize the matrix
    // matrix[0][0]=10;
    printf("enter 6 elements :\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("the matrix is :\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d \t",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*

Let's break down this C program that deals with a 2x3 matrix. I'll explain it both like an expert and in simpler terms for a teenager.

Expert Explanation:

We start by including the standard input/output library (<stdio.h>), which provides functions like printf and scanf.

In the main function, we declare a 2x3 matrix using int matrix[2][3];. This means we have a table with 2 rows and 3 columns to store integers.

We use nested for loops to take input from the user. The outer loop runs for i from 0 to 1 (representing the rows), and the inner loop runs for j from 0 to 2 (representing the columns).

Inside the loops, we use scanf to read integers from the user and store them in the matrix[i][j] cell.

After taking all the inputs, we display the matrix by iterating through it again with another set of nested loops and use printf to print each element.

The program ends by returning 0, indicating successful execution.

Teen-Friendly Explanation:

We're writing a computer program that deals with a special type of table called a matrix. Imagine it like a grid in a game, with 2 rows and 3 columns.

We need to get some numbers from you to fill this grid. So, we ask you to enter 6 numbers, one by one.

We use two sets of counting steps, like when you play a game. The first set (rows) goes from 1 to 2, and the second set (columns) goes from 1 to 3.

Each time, we ask for a number and put it into a specific spot in the grid. Like when you put chess pieces on a board.

Once you've entered all 6 numbers, we show you the whole grid, like showing your completed game board.

Finally, we say "the game is done," which is like telling you that our program has finished running.

This program is a basic example of how computers can store and work with data. You can use matrices like this for lots of cool stuff in programming!

*/
