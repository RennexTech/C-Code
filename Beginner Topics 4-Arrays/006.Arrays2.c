#include <stdio.h>
#include <string.h> // We'll need this for string manipulation.

// These are like the blueprint for our matrices. Using #define makes it easy
// to change the size of the matrices later without having to go through
// every single line of code. It's a clean way to keep your logic flexible.
#define ROW1 3
#define COL1 4
#define ROW2 4
#define COL2 2
#define MAX_SIZE 10 // For the spiral matrix, we'll use a max value.

// --- Function Prototypes: The Game Plan ---
// Think of these as a playbook for a sports team. They tell the compiler,
// "Hey, these are the plays we're going to run later. Get ready for them."
// This lets us put the full functions after our main logic, which makes the
// code flow a lot better and easier to read from top to bottom.
void matrixMultiplicationExample();
void matrixTransposeExample();
void numberConverterExample();
void binarySearchExample();
void selectionSortExample();
void bubbleSortExample();
void insertionSortExample();
void arrayInsertionExample();
void mergeArraysExample();
void spiralMatrixExample();

// --- Main Function: The Control Center ---
// This is the nerve center of our program. It's like the main menu on a website.
// The user picks an option, and the main function directs them to the right
// block of code (function) to handle that specific task. It keeps everything
// clean and organized.
int main() {
    int choice;

    // This is our interactive menu. It's a bit like a hacker's toolkit—
    // you choose the exploit you want to run.
    printf("--- C Algorithm Toolkit ---\n");
    printf("1. Matrix Multiplication\n");
    printf("2. Matrix Transpose\n");
    printf("3. Number Base Converter\n");
    printf("4. Binary Search\n");
    printf("5. Selection Sort\n");
    printf("6. Bubble Sort\n");
    printf("7. Insertion Sort\n");
    printf("8. Insert Element into Sorted Array\n");
    printf("9. Merge Two Sorted Arrays\n");
    printf("10. Print a Spiral Matrix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // The switch statement acts like a router, sending the user to the
    // function they selected. It's a clean way to handle multiple choices.
    switch (choice) {
        case 1:
            matrixMultiplicationExample();
            break;
        case 2:
            matrixTransposeExample();
            break;
        case 3:
            numberConverterExample();
            break;
        case 4:
            binarySearchExample();
            break;
        case 5:
            selectionSortExample();
            break;
        case 6:
            bubbleSortExample();
            break;
        case 7:
            insertionSortExample();
            break;
        case 8:
            arrayInsertionExample();
            break;
        case 9:
            mergeArraysExample();
            break;
        case 10:
            spiralMatrixExample();
            break;
        default:
            printf("Invalid choice. Run the program again and choose a number from 1 to 10.\n");
            break;
    }
    return 0;
}

// --------------------------------------------------------------------------------------------------
// --- Function Definitions: Where the magic happens ---
// This is where we define what each function actually does.
// Each function is self-contained and focused on a single task, which
// is a key principle of good programming. It makes the code easier to
// debug and reuse.

// --- Matrix Multiplication ---
// The user's original code had a bug where the innermost loop for multiplication was not
// properly accumulating the sum. I've fixed that by using a nested loop structure
// and `+=` to add up the results correctly. The `scanf_s` is a secure function
// but can cause issues on some compilers. I've kept it as it's relevant to your
// security studies, but in some environments, you might use `scanf`.
void matrixMultiplicationExample() {
    int mat1[ROW1][COL1], mat2[ROW2][COL2], mat3[ROW1][COL2];
    int i, j, k;

    printf("\n--- Matrix Multiplication ---\n");
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

    // This is the core logic. Think of it like this:
    // The first loop (`i`) picks a row from the first matrix (`mat1`).
    // The second loop (`j`) picks a column from the second matrix (`mat2`).
    // The innermost loop (`k`) is the engine that does the heavy lifting.
    // It's like a a dot product. It multiplies each element from the chosen row
    // of `mat1` with the corresponding element from the chosen column of `mat2` and
    // adds it all up. This sum becomes a single element in the final `mat3`.
    // 
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            mat3[i][j] = 0; // It's crucial to initialize the element to zero before summing.
            for (k = 0; k < COL1; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("The Resultant matrix is: \n");
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            printf("%5d", mat3[i][j]);
        }
        printf("\n");
    }
}

// --- Matrix Transpose ---
// The original code had a logical bug: it was a `void` function but had `return 0;`.
// `void` functions don't return anything. I've fixed this and integrated it into the menu.
void matrixTransposeExample() {
    #define ROWS_T 3
    #define COLS_T 4
    int mat1[ROWS_T][COLS_T], mat2[COLS_T][ROWS_T];

    printf("\n--- Matrix Transpose ---\n");
    printf("Enter matrix mat1 (%d x %d) row-wise:\n", ROWS_T, COLS_T);
    for (int i = 0; i < ROWS_T; i++) {
        for (int j = 0; j < COLS_T; j++) {
            scanf_s("%d", &mat1[i][j]);
        }
    }

    // This is like taking a spreadsheet and flipping it sideways.
    // The rows become columns, and the columns become rows.
    // The key line is `mat2[i][j] = mat1[j][i];`. It's a simple but powerful
    // trick that swaps the row and column indices.
    for (int i = 0; i < COLS_T; i++) {
        for (int j = 0; j < ROWS_T; j++) {
            mat2[i][j] = mat1[j][i];
        }
    }

    printf("Transpose of matrix is:\n");
    for (int i = 0; i < COLS_T; i++) {
        for (int j = 0; j < ROWS_T; j++) {
            printf("%5d", mat2[i][j]);
        }
        printf("\n");
    }
}

// --- Number Base Converter ---
// This is a neat function that uses the logic of division and remainder
// to convert a number from decimal to binary, octal, or hexadecimal.
void numberConverterExample() {
    int num, opt;

    // The inner `func` handles the heavy lifting of the conversion.
    // It's a reusable piece of code. This is good design.
    void func(int number, int base) {
        int i = 0, rem;
        char arr[20];

        // This loop keeps dividing the number by the base until it hits zero.
        // The remainder is the next digit in the new number, and we store it
        // in our character array.
        while (number > 0) {
            rem = number % base;
            number /= base;
            if (rem > 9 && rem < 16)
                arr[i++] = rem - 10 + 'A';
            else
                arr[i++] = rem + '0';
        }
        
        // Since we got the digits in reverse order, we have to print the
        // array backward to get the correct result.
        for (int j = i - 1; j >= 0; j--)
            printf("%c", arr[j]);
        printf("\n");
    }

    printf("\n--- Number Base Converter ---\n");
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
}

// --- Binary Search ---
// This is a classic algorithm that's way faster than a simple loop for finding
// something in a sorted array. It's used everywhere, from databases to
// searching a file system.
void binarySearchExample() {
    int binarySearch(int arr[], int size, int target) {
        int low = 0, up = size - 1;

        // The loop is our search boundary. As long as `low` is less than or
        // equal to `up`, there's still a portion of the array to check.
        while (low <= up) {
            int mid = (low + up) / 2; // Find the middle element.

            if (arr[mid] == target) {
                return mid; // Found it! Return the index.
            } else if (arr[mid] < target) {
                low = mid + 1; // It's like flipping a book. The target is larger,
                               // so we only need to look in the right half.
            } else {
                up = mid - 1;  // Target is smaller, so we only need to look
                               // in the left half.
            }
        }
        return -1; // We looked everywhere and couldn't find it.
    }

    int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("\n--- Binary Search ---\n");
    printf("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the element to search for: ");
    scanf_s("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
}

// --- Selection Sort ---
// This is a straightforward sorting algorithm. It's like having a deck of cards
// and finding the smallest one, putting it at the beginning, then finding the
// next smallest from the rest, and so on. It's simple but not the most efficient.
void selectionSortExample() {
    void selectionSort(int arr[], int n) {
        int i, j, minIndex, temp;

        for (i = 0; i < n - 1; i++) {
            minIndex = i; // Assume the first unsorted element is the smallest.
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j; // Found a new smallest element, so update the index.
                }
            }
            // Swap the smallest element with the first element of the unsorted part.
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    int n, i;
    printf("\n--- Selection Sort ---\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n); // Note: using scanf, as scanf_s requires size parameter for strings
    int arr[n]; // C99 feature: Variable Length Array

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
}

// --- Bubble Sort ---
// The most basic sort. It's like air bubbles rising in a soda. Each pass through
// the list, the largest unsorted element "bubbles" up to its correct position
// at the end. It's simple to understand but not very fast.
void bubbleSortExample() {
    void bubbleSort(int arr[], int n) {
        int i, j, temp, swapped;

        for (i = 0; i < n - 1; i++) {
            swapped = 0; // A flag to optimize. If no swaps happen, the list is sorted.
            for (j = 0; j < n - i - 1; j++) {
                // If the current element is bigger than the next, swap them.
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = 1;
                }
            }
            // If we made a pass without swapping anything, we're done.
            if (swapped == 0) {
                break;
            }
        }
    }
    int n, i;
    printf("\n--- Bubble Sort ---\n");
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
}

// --- Insertion Sort ---
// This is like organizing a hand of playing cards. You go through your cards
// one by one, and for each new card, you put it in the right spot relative
// to the cards you've already sorted. It's great for lists that are almost sorted.
void insertionSortExample() {
    void insertionSort(int arr[], int n) {
        int i, j, key;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            // This while loop shifts elements to make space for the key.
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key; // Insert the element here.
        }
    }
    int n, i;
    printf("\n--- Insertion Sort ---\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// --- Insert Element into Sorted Array ---
// This function doesn't use a sort, but a smart insertion method.
// It's like finding the right spot for a new book on an already sorted shelf.
void arrayInsertionExample() {
    #define MAX_SIZE_INSERT 10
    int arr[MAX_SIZE_INSERT];
    int n, element, i, j;

    printf("\n--- Insert Element into Sorted Array ---\n");
    printf("Enter the number of elements (up to %d): ", MAX_SIZE_INSERT - 1);
    scanf("%d", &n);
    if (n >= MAX_SIZE_INSERT) {
        printf("Array is full, cannot insert more elements.\n");
        return;
    }

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    for (i = 0; i < n; i++) {
        if (element < arr[i]) {
            // Find the spot and shift all subsequent elements to the right.
            for (j = n; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i] = element;
            n++; // Increase the element count.
            break;
        }
    }
    
    // If the element is larger than all others, insert it at the end.
    if (i == n) {
        arr[n] = element;
        n++;
    }

    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// --- Merge Two Sorted Arrays ---
// This is like combining two already-sorted playlists into a single,
// master playlist that's also sorted.
void mergeArraysExample() {
    int arr1[] = { 1, 3, 5, 7 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = { 2, 4, 6, 8 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[size1 + size2];
    int i = 0, j = 0, k = 0;

    printf("\n--- Merge Two Sorted Arrays ---\n");
    printf("Array 1: ");
    for(i=0; i<size1; i++) printf("%d ", arr1[i]);
    printf("\nArray 2: ");
    for(i=0; i<size2; i++) printf("%d ", arr2[i]);
    printf("\n");
    
    // This is the core merge logic.
    // It's like having two lines of people waiting. You always take the
    // person at the front of the line who's next in alphabetical order.
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    // After one line is empty, you just add the rest of the other line.
    while (i < size1) {
        arr3[k++] = arr1[i++];
    }
    while (j < size2) {
        arr3[k++] = arr2[j++];
    }

    printf("Merged Sorted Array: ");
    for (int l = 0; l < size1 + size2; l++) {
        printf("%d ", arr3[l]);
    }
    printf("\n");
}

// --- Spiral Matrix ---
// This is a cool algorithm for printing a matrix. It's like navigating a maze
// with a set of rules: go right until you hit a wall, then go down, then left,
// then up, and repeat, shrinking the walls as you go.
void spiralMatrixExample() {
    int n;
    printf("\n--- Spiral Matrix ---\n");
    printf("Enter the value of n (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input. Please enter a value between 1 and %d.\n", MAX);
        return;
    }

    int matrix[MAX][MAX];
    int num = 1;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;

    // This loop keeps running as long as there's a "spiral" to trace.
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

    printf("Spiral Matrix for n = %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
