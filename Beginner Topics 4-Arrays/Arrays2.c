

/*
Multiplication of matrices requires that the number of columns in first matrix should be equal to the number of rows in second matrix.
*/

/* This is the wrong code from the book, doesn't work, corrected version is found below 
#define ROW1 3
#define COL1 4
#define ROW2 COL1
#define COL2 2

int main()
{
	int mat1[ROW1][COL1], mat2[ROW2][COL2], mat3[ROW1][COL2];
	int i, j, k; 
	printf("Enter the matrix mat1(%d*%d) row-wise: \n", ROW1, COL1);
	for (i = 0; i < ROW1; i++)
	{
		for (j = 0; j < COL1; j++)
			scanf_s("%d", &mat1[i][j]);
	}
	printf("Enter the matrix mat2(%d*%d) row-wise: \n", ROW2, COL2);
	for (i = 0; i < ROW2; i++)
	{
		for (j = 0; j < COL2; j++)
			scanf_s("%d", &mat2[i][j]);
	}
	//multiplication
	for (i = 0; i < ROW1; i++)
	{
		mat3[i][j] = 0;
		for (k = 0; k < COL1; k++)
			mat3[i][j] = mat1[i][k] * mat2[k][j];
	}
	printf("The Resultant matrix mat3 is: \n");
	for (j = 0; j < COL2; j++)
	{
		printf("%5d", mat3[i][j]);
	}
	printf("\n");
	return 0;
}

*/

#include <stdio.h>

#define ROW1 3
#define COL1 4
#define ROW2 COL1
#define COL2 2

int main() {
    int mat1[ROW1][COL1], mat2[ROW2][COL2], mat3[ROW1][COL2];
    int i, j, k;

    printf("Enter the matrix mat1(%d*%d) row-wise: \n", ROW1, COL1);
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL1; j++)
            scanf_s("%d", &mat1[i][j]);
    }

    printf("Enter the matrix mat2(%d*%d) row-wise: \n", ROW2, COL2);
    for (i = 0; i < ROW2; i++) {
        for (j = 0; j < COL2; j++)
            scanf_s("%d", &mat2[i][j]);
    }

    // Multiplication
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) { // Initialize mat3 element to 0
            mat3[i][j] = 0;
            for (k = 0; k < COL1; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("The Resultant matrix mat3 is: \n");
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            printf("%5d", mat3[i][j]);
        }
        printf("\n"); // Add a newline after each row
    }

    return 0;
}

/*
You need to use scanf instead of scanf_s for input unless you are specifically working with secure functions.

In the multiplication part, I've fixed the loop variables and the logic for multiplying matrices. The outer loops iterate through the rows of mat1 and mat3, and the inner loops iterate through the columns of mat3 and mat2. The multiplication and addition are done correctly to calculate the elements of mat3.

I've added a newline character (\n) after each row in the output loop to format the mat3 matrix properly.

This code reads two matrices from the user, multiplies them, and prints the resultant matrix mat3.
*/

#define ROW 3
#define COL 4
void transpose()
{
    int mat1[ROW][COL], mat2[COL][ROW]; //Define 2 matrices

    //Read the elements of the mat1 from the user
    printf("Enter matrix mat1 (%d x %d) row-wise:\n", ROW, COL);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            scanf_s("%d", &mat1[i][j]);
        }
    }
    // Calculate the transpose of mat1 and store it in mat2
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++) {
            mat2[i][j] = mat1[j][i]; //note this is the main line
        }
    }

    // Print the transpose of mat1 (mat2)
    printf("Transpose of matrix is:\n");
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++) {
            printf("%5d", mat2[i][j]);
        }
        printf("\n"); // Move to the next row after printing each row
    }
    return 0;
}

/*

The program you've posted finds the transpose of a matrix. The transpose of a matrix is obtained by interchanging its rows and columns. Here's a breakdown of how the program works:

You've defined the dimensions of the matrices using #define ROW 3 and #define COL 4. These macros define the number of rows and columns in your matrices.

The program reads the elements of the original matrix mat1 row-wise using nested for loops. It scans the values into the mat1 matrix.

The program then calculates the transpose of mat1 and stores it in mat2. It uses two sets of nested for loops to iterate through the elements of both matrices and perform the transposition.

After finding the transpose, the program prints the transposed matrix mat2 using another set of nested for loops.

Here's a summary of the major parts of the code:

mat1 is the original matrix of size ROW x COL.
mat2 is the transposed matrix of size COL x ROW.
The program reads the elements of mat1 and calculates mat2 by interchanging rows and columns.
Finally, it prints the transposed matrix mat2.
The code demonstrates how to find the transpose of a matrix and provides the result in a user-readable format.

*/

#include <stdio.h>

void func(int num, int b) {
    int i = 0, rem;
    char arr[20];

    while (num > 0) {
        rem = num % b;
        num /= b;

        if (rem > 9 && rem < 16)
            arr[i++] = rem - 10 + 'A';
        else
            arr[i++] = rem + '0';
    }

    // Print the result in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%c", arr[j]);

    printf("\n");
}

int binary_dec_hex_oct_converter() {
    int num, opt;

    printf("Enter a decimal number: ");
    scanf_s("%d", &num);

    printf("1. Binary\n2. Octal\n3. Hexadecimal\n");
    printf("Enter your option: ");
    scanf_s("%d", &opt);

    switch (opt) {
    case 1:
        printf("Binary equivalent is ");
        func(num, 2);
        break;
    case 2:
        printf("Octal equivalent is ");
        func(num, 8);
        break;
    case 3:
        printf("Hexadecimal equivalent is ");
        func(num, 16);
        break;
    default:
        printf("Invalid option!\n");
        break;
    }

    return 0;
}

/*
Write a program for searching an element in an array through binary search. The prerequisite for binary search is that the array should be' sorted.' Firstly we compare th be searched with the middle element of the array. If the item is same as the middle elemen search is successful otherwise the array is divided into two portions, first portion contains all to the left of the middle element and the other one consists of all the elements on the right side of the element. Since the array is sorted, all the elements in the left portion will be smaller than the middle element and the elements in the right portion will be greater than the middle element. Now if the item to be searched is less than the middle element then we search it in the left portion of the array and if it is greater than the middle element then search will be in the right portion of the array. Now we will take one portion only for search and compare the item with middle element of that portion. . This process will continue until we fi~d the required item or middle element has no left or right portion to search. To implement this procedure we will take 3 variables viz. low, up and mid that will keep track of the status of lower limit, upper limit and middle value of that portion of the array, in which we will search the element. The value of the mid will lie calculated as- mid = ( low+up) / 2 If item> arr[mid], search will resume in right portion low = rpid+1 , up will remain same If item < arr[mid] , search will resume in left portion up = mid-I, low will remain same If item = = arr[mid] , search is succe~sful item found at mid position If low> up , search is unsuccessful item not found in array Let us take a sorted array of10 elements. Suppose the element that we are searching is 49. The portion of array in which the element is searched is shown with a bold boundary in the figure.
*/

#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, up = size - 1;

    while (low <= up) {
        int mid = (low + up) / 2;

        if (arr[mid] == target) {
            return mid; // Element found, return its index
        }
        else if (arr[mid] < target) {
            low = mid + 1; // Search in the right portion
        }
        else {
            up = mid - 1; // Search in the left portion
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 49;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    }
    else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}

/*This program defines a binarySearch function that takes an array, its size, and the target element as input and returns the index of the target element if found, or -1 if not found. In the main function, we define a sorted array and call the binarySearch function to search for the target element (in this case, 49). It then prints whether the element was found and its index or if it wasn't found.

Certainly, here's the explanation rewritten:

Binary search is an algorithm used to search for a specific element in a sorted array. It takes advantage of the fact that the array is sorted to efficiently locate the desired item. The binary search process begins by comparing the target element to the middle element of the array. If they match, the search is successful, and the index of the element is returned. However, if the target element is not equal to the middle element, the array is divided into two portions.

The left portion contains all the elements to the left of the middle element, and the right portion contains all the elements to the right. Since the array is sorted, all the elements in the left portion are smaller than the middle element, while all the elements in the right portion are greater.

The search process continues by selecting one of the two portions based on whether the target element is smaller or larger than the middle element. This process of dividing the array and comparing with the middle element is repeated until either the target element is found, in which case its index is returned, or it is determined that the element does not exist in the array.

To implement binary search, you need three variables: low, up, and mid. These variables keep track of the lower limit, upper limit, and middle value of the portion of the array being searched. The middle value is calculated as:

mid = (low + up) / 2

The search continues as follows:

If item > arr[mid], the search moves to the right portion, updating low to mid + 1.
If item < arr[mid], the search moves to the left portion, updating up to mid - 1.
If item == arr[mid], the search is successful, and the item is found at the mid position.
If low > up, the search is unsuccessful, and the item is not found in the array.
This binary search algorithm efficiently locates elements in a sorted array, dramatically reducing the number of comparisons required compared to a linear search.

*/


/* Sure, here's a C program to sort the elements of a 1-D array in ascending order using the selection sort algorithm: */

#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

/*This program defines a selectionSort function that performs selection sort on the array, and the sorted array is printed in ascending order in the main function. You can input the elements of the array, and the program will sort them in ascending order using selection sort.*/


/* Certainly, here's a C program to sort the elements of a 1-D array in ascending order using the bubble sort algorithm: */

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp, swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to check if any swapping is done in this pass

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1] if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the flag to true
            }
        }

        // If no two elements were swapped in inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

/*Here's a C program to insert an element into a sorted 1-D array at the proper place to maintain the sorted order:*/

#include <stdio.h>

int main() {
    int size = 10; // Size of the array
    int arr[size]; // Declare an array of size 10
    int n; // Number of elements initially in the array
    int element; // Element to be inserted
    int i, j;

    // Input the number of elements initially in the array
    printf("Enter the number of elements (up to %d): ", size - 1);
    scanf("%d", &n);

    if (n >= size) {
        printf("Array is full, cannot insert more elements.\n");
        return 1; // Exit with an error code
    }

    // Input the sorted elements
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to be inserted
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    // Find the proper place to insert the element while maintaining sorted order
    for (i = 0; i < n; i++) {
        if (element < arr[i]) {
            // Shift the elements to the right to make space for the new element
            for (j = n; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i] = element; // Insert the element at the proper place
            n++; // Increase the count of elements in the array
            break;
        }
    }

    // Print the sorted array after insertion
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    
    printf("\n");

    return 0;
}

/*This program first takes the number of elements initially in the array, then takes the sorted elements, and finally, it takes the element to be inserted. It inserts the element at the correct position in the sorted array while maintaining the order and then prints the updated array.*/


#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


/*Program to merge arrays into  a third one.*/
#include <stdio.h>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int arr3[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        arr3[k++] = arr1[i++];
    }

    while (j < size2) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = { 1, 3, 5, 7 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = { 2, 4, 6, 8 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[size1 + size2];

    mergeSortedArrays(arr1, size1, arr2, size2, arr3);

    printf("Merged Sorted Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}

/*Printing a spiral matrix can be achieved by simulating the spiral pattern and filling the matrix as you go along. Here's a C program to print a spiral matrix for a given value of n:*/

#include <stdio.h>

#define MAX 10

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input. Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    int matrix[MAX][MAX];
    int num = 1;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;

    while (row_start <= row_end && col_start <= col_end) {
        // Traverse from left to right (top row)
        for (int col = col_start; col <= col_end; col++) {
            matrix[row_start][col] = num++;
        }
        row_start++;

        // Traverse from top to bottom (rightmost column)
        for (int row = row_start; row <= row_end; row++) {
            matrix[row][col_end] = num++;
        }
        col_end--;

        // Traverse from right to left (bottom row)
        if (row_start <= row_end) {
            for (int col = col_end; col >= col_start; col--) {
                matrix[row_end][col] = num++;
            }
            row_end--;
        }

        // Traverse from bottom to top (leftmost column)
        if (col_start <= col_end) {
            for (int row = row_end; row >= row_start; row--) {
                matrix[row][col_start] = num++;
            }
            col_start++;
        }
    }

    // Print the spiral matrix
    printf("Spiral Matrix for n = %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*It seems you have provided a list of programming challenges or questions. Here are the rewritten versions of these questions:

Find Sum of Highest and Lowest Numbers
Write a program that accepts 'n' numbers and displays the sum of the highest and lowest numbers in the list.

Sum of Even and Multiplication of Odd Numbers
Write a program to accept 'n' numbers in an array and display the sum of all even numbers and the multiplication of all odd numbers.

Sorting in Descending Order
Write three programs to sort numbers in a one-dimensional array in descending order using:
(i) Selection Sort
(ii) Bubble Sort
(iii) Insertion Sort

Reverse First 'n' Elements of an Array
Write a function to reverse only the first 'n' elements of an array.

Rotate Array Elements
Write a program to modify the elements of an array such that the last element becomes the first element of the array, and all other elements are shifted to the right. Extend the program to allow rotating the array by any number of elements.

Determinant of a Matrix
Write a program to find the determinant of a matrix.

Count Occurrences in a Matrix
Write a program to count the occurrences of a number in a matrix.

2-D to 1-D Array
Write a program to store all the elements of a 2-D array in a 1-D array row-wise.

Symmetric Matrix
Write a program to find out whether a matrix is symmetric or not. A matrix is symmetric if its transpose is equal to the original matrix.

Check Distinct Elements in an Array
Write a program to check that the elements of an array are distinct.

Check Distinct Elements in a Matrix
Write a program to check that the elements of a matrix are distinct.

Sum of Diagonals in a Square Matrix
Write a program to find out the sum of elements of principal and secondary diagonals of a square matrix.

Magic Square
Write a program to enter a square matrix of odd size and then check whether it is a magic matrix or not. A matrix is magic if all its elements are distinct, and the sum of elements in each row, column, and diagonal is equal.

Print Matrix Elements Spirally
Write a program to print the elements of a matrix spirally.

Reverse Rows of a Matrix
Write a program to reverse the rows of a matrix.

Reverse Columns of a Matrix
Write a program to reverse the columns of a matrix.

These rewritten questions should clarify the tasks or challenges you need to address in your programming practice. You can refer to appropriate resources or textbooks on C programming and data structures to help you tackle these challenges effectively.*/