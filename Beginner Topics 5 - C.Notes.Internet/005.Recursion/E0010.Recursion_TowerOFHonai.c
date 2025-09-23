#include <stdio.h>

// This is the function prototype for `tofh` (Tower of Hanoi). It takes the number of
// disks and the names of the source, temporary, and destination pegs. It doesn't
// return a value.
void tofh(int ndisk, char source, char temp, char dest);

int main()
{
    // The names of our three pegs.
    char source = 'A', temp = 'B', dest = 'C';
    int ndisk; // The number of disks the user wants to play with.

    printf("Enter the number of disks: ");
    scanf("%d", &ndisk);

    printf("The sequence of moves is:\n");

    // We call our recursive function with the initial setup.
    // The problem is to move `ndisk` from 'A' to 'C' using 'B' as temporary.
    tofh(ndisk, source, temp, dest);

    return 0;
}

// This is the recursive function that solves the Tower of Hanoi puzzle.
// It breaks the problem down into three simple steps.
void tofh(int ndisk, char source, char temp, char dest)
{
    // This is the **base case**. It's the simplest part of the puzzle.
    // If there is only one disk, the solution is straightforward: just move it
    // from the source peg to the destination peg.
    if (ndisk == 1)
    {
        printf("Move Disk %d from %c --> %c\n", ndisk, source, dest);
        return;
    }

    // ### The Recursive Steps: The Core Logic

    // **Step 1: Move `ndisk - 1` disks from the `source` to the `temporary` peg.**
    // We treat the top `ndisk - 1` disks as a single unit. We need to get them
    // out of the way to move the largest disk. The `dest` peg now acts as our temporary.
    // Analogy: We're clearing the path to move the biggest item.
    tofh(ndisk - 1, source, dest, temp);

    // **Step 2: Move the single largest disk (`ndisk`) from the `source` to the `destination` peg.**
    // With the other disks out of the way, we can now move the largest disk.
    printf("Move Disk %d from %c --> %c\n", ndisk, source, dest);

    // **Step 3: Move `ndisk - 1` disks from the `temporary` to the `destination` peg.**
    // Now we need to move the group of smaller disks from where we stashed them
    // back onto the largest disk on the destination peg. The `source` peg is now
    // our temporary peg for this final move.
    // Analogy: We're now putting the items back in their final place.
    tofh(ndisk - 1, temp, source, dest);
}



/*

You need to move N disks from Peg A to Peg C using Peg B as temporary storage.

You call on your Magical Assistant to move the top N-1 disks from Peg A to Peg B, using Peg C as temporary storage.

With the smaller disks out of the way, you move the largest disk (the Nth disk) from Peg A to Peg C directly.

You then ask your Magical Assistant again to move the N-1 disks from Peg B to Peg C, placing them on top of the largest disk, using Peg A as temporary storage.

The assistant uses the same logic recursively, breaking down the task until only one disk needs to be moved — the simplest case.

This chain of delegation continues until the whole puzzle is solved step-by-step.

The beauty of recursion is that each assistant solves a smaller version of the same problem in the same way.

*/