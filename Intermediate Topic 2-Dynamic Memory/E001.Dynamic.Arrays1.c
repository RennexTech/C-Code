#include <stdio.h>
#include <stdlib.h>


/*

Covers all the images. This is the main dynamic arrays file, the other 2 are just additions from those images 2 and 3. 

Dynamic arrays in C using subscript notation. Here is a breakdown of the code:

Program to access dynamically allocated memory as a 1D array.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p, n, i;

  // Get the number of integers to be entered.
  printf("Enter the number of integers to be entered: ");
  scanf("%d", &n);

  // Allocate memory for the array.
  p = (int *)malloc(n * sizeof(int));

  // Check if memory allocation was successful.
  if (p == NULL) {
    printf("Memory not available\n");
    exit(1);
  }

  // Get the integers from the user.
  for (i = 0; i < n; i++) {
    printf("Enter an integer: ");
    scanf("%d", &p[i]);
  }

  // Print the integers.
  for (i = 0; i < n; i++) {
    printf("%d\t", p[i]);
  }

  // Free the memory allocated for the array.
  free(p);

  return 0;
}

/*

In this code, we first declare a pointer to an integer variable, p. We then use the malloc() function to allocate memory for an array of n integers. The malloc() function returns a pointer to the allocated memory, which we store in the p variable.

Next, we check if the memory allocation was successful. If it was not successful, we print an error message and exit the program.

If the memory allocation was successful, we use a for loop to get the integers from the user and store them in the array. We then use another for loop to print the integers from the array.

Finally, we use the free() function to free the memory allocated for the array.

This is just a simple example of how to use dynamic arrays in C. Dynamic arrays can be used to create a variety of data structures, such as linked lists, stacks, and queues.


*/


/*
* Program to dynamically allocate a 2D array using pointer to an array
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows;
  int (*a)[4];

  // Get the number of rows.
  printf("Enter number of rows: ");
  scanf("%d", &rows);

  // Allocate memory for the 2D array.
  a = (int (*)[4])malloc(rows * 4 * sizeof(int));

  // Check if memory allocation was successful.
  if (a == NULL) {
    printf("Memory not available\n");
    exit(1);
  }

  // Get the elements of the 2D array from the user.
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      printf("Enter a[%d][%d]: ", i, j);
      scanf("%d", &a[i][j]);
    }
  }

  // Print the 2D array.
  printf("The matrix is:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%5d", a[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the 2D array.
  free(a);

  return 0;
}

/*

In this code, we first declare a pointer to an array of integers, a. We then use the malloc() function to allocate memory for an array of rows arrays of 4 integers each. The malloc() function returns a pointer to the allocated memory, which we store in the a variable.

Next, we check if the memory allocation was successful. If it was not successful, we print an error message and exit the program.

If the memory allocation was successful, we use a for loop to get the elements of the 2D array from the user and store them in the array. We then use another for loop to print the 2D array.

Finally, we use the free() function to free the memory allocated for the 2D array.

The following figure shows how the dynamically allocated memory is accessed using a pointer to an array:

*/

    +--------+--------+--------+--------+
    | a[0][0] | a[0][1] | a[0][2] | a[0][3] |
    +--------+--------+--------+--------+
    | a[1][0] | a[1][1] | a[1][2] | a[1][3] |
    +--------+--------+--------+--------+
    | a[2][0] | a[2][1] | a[2][2] | a[2][3] |
    +--------+--------+--------+--------+


 /*

The a pointer points to the first element of the first row of the 2D array. To access an element of the 2D array, we use the following syntax:

 */

 a[row][column];


 /*

For example, to access the element at row 1, column 2 of the 2D array, we would use the following code:

 */

 int element = a[1][2];


/*
* Program to dynamically allocate a 2D array using array of pointers
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int cols;
  int *a[3];

  // Get the number of columns.
  printf("Enter number of columns: ");
  scanf("%d", &cols);

  // Allocate memory for each row of the 2D array.
  for (int i = 0; i < 3; i++) {
    a[i] = (int *)malloc(cols * sizeof(int));
  }

  // Check if memory allocation was successful.
  for (int i = 0; i < 3; i++) {
    if (a[i] == NULL) {
      printf("Memory not available\n");
      exit(1);
    }
  }

  // Get the elements of the 2D array from the user.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter a[%d][%d]: ", i, j);
      scanf("%d", &a[i][j]);
    }
  }

  // Print the 2D array.
  printf("The matrix is:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%5d", a[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the 2D array.
  for (int i = 0; i < 3; i++) {
    free(a[i]);
  }

  return 0;
}

/*

In this code, we first declare an array of pointers to integers, a. Each element of the a array will point to a row of the 2D array.

We then use a for loop to allocate memory for each row of the 2D array. We use the malloc() function to allocate memory for a row of cols integers. We then store the address of the allocated memory in the corresponding element of the a array.

Next, we check if the memory allocation was successful. If it was not successful, we print an error message and exit the program.

If the memory allocation was successful, we use a for loop to get the elements of the 2D array from the user and store them in the array. We then use another for loop to print the 2D array.

Finally, we use a for loop to free the memory allocated for each row of the 2D array. We use the free() function to free the memory pointed to by each element of the a array.

Dynamically allocating a 2D array using an array of pointers has the advantage that the rows of the 2D array do not need to be allocated consecutively in memory. This can be useful in some cases, such as when the 2D array is very large and the rows need to be allocated in different parts of memory.

However, it is important to note that dynamically allocating a 2D array using an array of pointers is also more complex than dynamically allocating a 2D array using a single pointer.

This is because you need to keep track of the individual pointers to each row of the array.

*/


/*
* Program to dynamically allocate a 2D array
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows, cols;
  int **a;

  // Get the number of rows and columns.
  printf("Enter number of rows and columns: ");
  scanf("%d%d", &rows, &cols);

  // Allocate a one-dimensional array of int pointers.
  a = (int **)malloc(rows * sizeof(int *));

  // Check if memory allocation was successful.
  if (a == NULL) {
    printf("Memory not available\n");
    exit(1);
  }

  // Allocate a one-dimensional array of integers for each row pointer.
  for (int i = 0; i < rows; i++) {
    a[i] = (int *)malloc(cols * sizeof(int));

    // Check if memory allocation was successful.
    if (a[i] == NULL) {
      printf("Memory not available\n");
      exit(1);
    }
  }

  // Get the elements of the 2D array from the user.
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter a[%d][%d]: ", i, j);
      scanf("%d", &a[i][j]);
    }
  }

  // Print the 2D array.
  printf("The matrix is:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%5d", a[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the 2D array.
  for (int i = 0; i < rows; i++) {
    free(a[i]);
  }

  free(a);

  return 0;
}


/*

In this code, we first declare a double pointer to an integer, a. We then use the malloc() function to allocate memory for an array of rows pointers to integers. We then use another malloc() function to allocate memory for an array of cols integers for each row pointer.

Next, we check if the memory allocation was successful. If it was not successful, we print an error message and exit the program.

If the memory allocation was successful, we use a for loop to get the elements of the 2D array from the user and store them in the array. We then use another for loop to print the 2D array.

Finally, we use a for loop to free the memory allocated for each row of the 2D array. We then use the free() function to free the memory allocated for the array of row pointers.

This is a more flexible way to dynamically allocate a 2D array, because it allows you to enter the number of rows and columns at run time.

*/

