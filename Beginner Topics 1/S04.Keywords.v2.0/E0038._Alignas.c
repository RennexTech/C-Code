/**
 *
 * _Alignas sets how a variable is aligned in memory.
 *
 * It's like choosing the parking spot that fits your car perfectly in a crowded lot.
 *
 * Useful in low-level systems or when interfacing with hardware or SIMD instructions.
 *
 */

#include <stdio.h>
#include <stdalign.h>

int main() {
    printf("--------------------------------------------\n");
    printf("38. _Alignas\n");
    printf("--------------------------------------------\n");
    printf("'_Alignas' lets you manually set memory alignment of variables. Useful in hardware or performance-critical code.\n");
    printf("--------------------------------------------\n");

    struct {
        _Alignas(16) char aligned_char;
    } example;

    printf("Address of aligned_char: %p\n", (void*)&example.aligned_char);
    printf("Alignment requirement of aligned_char: %zu bytes\n", alignof(example.aligned_char));

    return 0;
}


//=================================== ANOTHER EXAMPLE ============================

#include <stdio.h>    // For printf
#include <stdalign.h> // For _Alignas, _Alignof
#include <unistd.h>   // For sleep

/**
 * * _Alignas is like telling your data: 'Park here, but make sure you're perfectly aligned with this memory boundary!' 
 * * It's for performance in super specific scenarios, like when hardware needs data to start at a certain memory address. 
 * * Think of it as reserving a parking spot that's exactly lined up for a big truck.
 * */

// Example struct with _Alignas
// We're telling the compiler to align this 'data' member to an 8-byte boundary.
// This means its memory address will be a multiple of 8 (e.g., 0x...0, 0x...8, 0x...10, etc.)
typedef struct {
    char id;
    _Alignas(8) int aligned_data; // This int will be aligned to an 8-byte boundary
    char status;
} AlignedPacket;

int main() {
    printf("--------------------------------------------\n");
    printf("38. _Alignas (C11)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("Like telling your data: 'Park here, but make sure you're perfectly aligned with this memory boundary!' It's for performance in super specific scenarios, like when hardware needs data to start at a certain memory address.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    AlignedPacket packet;

    printf("Size of AlignedPacket: %zu bytes\n", sizeof(AlignedPacket));
    sleep(1);
    printf("Alignment requirement of AlignedPacket: %zu bytes\n", _Alignof(AlignedPacket)); // How many bytes it needs to be aligned to
    sleep(1);
    printf("Address of packet.id: %p\n", (void*)&packet.id);
    sleep(1);
    printf("Address of packet.aligned_data: %p\n", (void*)&packet.aligned_data); // Notice this address will be a multiple of 8
    sleep(1);
    printf("Address of packet.status: %p\n", (void*)&packet.status);
    sleep(1);

    printf("Note: This is for low-level memory control, often used in embedded systems or high-performance computing where memory access speed is critical. Don't sweat the details unless you're deep diving into hardware.\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
