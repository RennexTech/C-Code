#include <stdio.h>

// This is the function that will receive a pointer to our array.
// For a beginner, think of it as a function that is given a map
// to a collection of data. It doesn't get a copy of the data,
// just the directions to find it.
//
// For an advanced user, this is a function that takes a pointer to
// the first element of a one-dimensional array. This is a common
// pattern in low-level code because it's incredibly efficient.
// The pointer itself is just a memory address, which is typically
// 4 or 8 bytes, no matter how big the array is.
void func(int *a) {
    printf("## Inside func()\n");
    printf("-----------------------------------------\n");
    // We use a simple for loop to walk through the array using the pointer.
    // The loop condition `i < 5` means we'll access the first 5 elements.
    for (int i = 0; i < 5; i++) {
        // We use pointer arithmetic here. The expression `*(a + i)` is the
        // same as `a[i]`. It means "go to the memory address `a` and then
        // move `i` integer-sized steps forward to get the value."
        printf("Element %d: Value = %d\n", i, *(a + i));
    }
    printf("-----------------------------------------\n\n");
}

int main() {
    // The main function's array, just like in your diagram.
    int arr[5] = {3, 6, 2, 7, 1};

    printf("## Inside main()\n");
    printf("-----------------------------------------\n");
    // We can print the original values and their memory addresses to prove
    // that they live here, in main's memory space.
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] at address %p with value %d\n", i, (void*)&arr[i], arr[i]);
    }
    printf("-----------------------------------------\n\n");

    // We call the `func` function and pass it the address of the first
    // element of `arr`. We're not passing the whole array, just a pointer.
    // This is the "pass-by-reference" concept in action.
    func(arr); // `arr` decays to a pointer to its first element here.

    /*
     *
     * ## The Pro's Analysis
     *
     * Notice how `func()` can access the elements of `arr` even though it
     * was never given the array itself. It only received a single pointer
     * to the start of the data. In malware analysis, this is the pattern you
     * need to recognize when a piece of code is trying to access or modify
     * data from another part of the program.
     *
     * This is a core part of the C programming language and a foundation for
     * understanding how functions operate on data efficiently. It's also the
     * same mechanism used for `WinAPI` functions that need to work on large
     * buffers. For example, a function like `ReadProcessMemory` takes a pointer
     * to a buffer to write the data into, not the entire buffer itself.
     *
     */
    
    return 0;
}
