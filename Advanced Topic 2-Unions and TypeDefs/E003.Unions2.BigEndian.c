#include <stdio.h>

/*
 * This program is a hands-on lab to demystify byte order.
 * It's going to show you, in raw hex, how your machine stores
 * a multibyte integer. The integer we're using is 0x12345678,
 * which is a hexadecimal representation that makes it easy to
 * see the byte order.
 *
 * Think of 0x12345678 as a stack of four boxes, each with a two-digit
 * code: [12] [34] [56] [78].
 *
 * Big-endian says: "I'll put the biggest, most important box (12)
 * at the very beginning of the line." (Address 00: 12, Address 01: 34...)
 *
 * Little-endian says: "Nah, I'll put the smallest, least important box (78)
 * at the very beginning of the line." (Address 00: 78, Address 01: 56...)
 *
 * This code will show you which one your machine is, once and for all.
 */

int main() {
    // We'll use a 4-byte integer (int) and assign a hex value to it.
    // The hex value 0x12345678 is great for this because each byte
    // has a unique and easily identifiable value (12, 34, 56, 78).
    unsigned int x = 0x12345678;

    // We're creating a char pointer, which is a pointer that
    // moves one byte at a time. We cast our integer address
    // to this char pointer. This is the magnifying glass.
    char *p = (char *)&x;

    // We get the size of the integer in bytes on this machine.
    // This is a dynamic way to make our code work on different architectures.
    size_t size = sizeof(unsigned int);

    // Let's get this show on the road. We're about to print a memory map.
    printf("Investigating memory for the integer 0x%X...\n\n", x);

    printf("Memory Address\t\tByte Value (Hex)\n");
    printf("-------------------------------------------\n");

    // This loop is our memory detective in action.
    // It's like a forensics investigator going through a crime scene,
    // byte by byte, to see what's there.
    for (size_t i = 0; i < size; i++) {
        // Here's the magic:
        // `(p+i)` moves our pointer to the next memory address.
        // `*(p+i)` dereferences the pointer to get the value at that address.
        // We print the address and the value in hexadecimal.
        printf("0x%p\t\t0x%02X\n", (void *)(p + i), *(p + i));
    }

    printf("\nBased on the output, your machine is running on ");

    // Now, we make the final determination.
    // We check the first byte. If it's the "biggest" part (0x12), it's big-endian.
    // If it's the "smallest" part (0x78), it's little-endian.
    if (*p == 0x12) {
        printf("a Big-Endian architecture. The most significant byte (0x12) is stored at the lowest memory address.\n");
    } else if (*p == 0x78) {
        printf("a Little-Endian architecture. The least significant byte (0x78) is stored at the lowest memory address.\n");
    } else {
        // This is a fallback for weird, custom architectures.
        printf("an unknown byte order. The first byte is 0x%02X, which doesn't match our test values.\n", *p);
    }

    return 0;
}
