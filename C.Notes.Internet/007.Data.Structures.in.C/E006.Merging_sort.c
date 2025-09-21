#include <stdio.h>

#define MAX 100

// Function prototype for the merge function.
// It takes two sorted arrays, the array to store the result, and the sizes of the first two arrays.
void merge(int arr1[], int arr2[], int arr3[], int n1, int n2);

int main() {
    int arr1[MAX], arr2[MAX], arr3[2 * MAX], n1, n2;

    printf("Enter the number of elements in array 1: ");
    scanf("%d", &n1);
    printf("Enter all the elements in sorted order for array 1:\n");
    for (int i = 0; i < n1; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in array 2: ");
    scanf("%d", &n2);
    printf("Enter all the elements in sorted order for array 2:\n");
    for (int i = 0; i < n2; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    // Call the merge function to combine the two sorted arrays.
    merge(arr1, arr2, arr3, n1, n2);

    // Print the final merged list.
    printf("\nMerged List:\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d\n", arr3[i]);
    }
    
    return 0;
}

// This function merges two sorted arrays (`arr1` and `arr2`) into a third array (`arr3`).
void merge(int arr1[], int arr2[], int arr3[], int n1, int n2) {
    int i, j, k;
    i = 0; // Index for arr1
    j = 0; // Index for arr2
    k = 0; // Index for arr3

    // This loop compares elements from both arrays and adds the smaller one to `arr3`.
    // It continues as long as there are elements in both `arr1` and `arr2`.
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++]; // Add the element from `arr1` and increment both `k` and `i`.
        } else {
            arr3[k++] = arr2[j++]; // Add the element from `arr2` and increment both `k` and `j`.
        }
    }

    // After the first loop, one of the arrays might have remaining elements.
    // These loops add any leftover elements to the end of `arr3`.
    // Add remaining elements from `arr1`.
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    // Add remaining elements from `arr2`.
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}


