#include <stdio.h> // Standard input/output library for printf

/**
 * @brief Main function demonstrating C assignment operators.
 *
 * This program shows how assignment operators combine an operation
 * (like addition or subtraction) with assignment, making code more concise.
 */
int main()
{
    int a = 10; // Basic assignment: assigns 10 to 'a'
    printf("Initial value of 'a': %d\n", a);

    printf("\n--- Arithmetic Assignment Operators ---\n");

    // += (Add and assign)
    // a = a + 5;
    a += 5;
    printf("After a += 5; 'a' is: %d\n", a); // Expected: 15

    // -= (Subtract and assign)
    // a = a - 3;
    a -= 3;
    printf("After a -= 3; 'a' is: %d\n", a); // Expected: 12

    // *= (Multiply and assign)
    // a = a * 2;
    a *= 2;
    printf("After a *= 2; 'a' is: %d\n", a); // Expected: 24

    // /= (Divide and assign)
    // a = a / 4;
    a /= 4;
    printf("After a /= 4; 'a' is: %d\n", a); // Expected: 6

    // %= (Modulus and assign) - works only with integers
    // a = a % 5;
    a %= 5;
    printf("After a %%= 5; 'a' is: %d\n", a); // Expected: 1 (6 % 5 = 1)

    printf("\n--- Bitwise Assignment Operators (for integers) ---\n");
    int b = 12; // Binary: 0000 1100
    printf("Initial value of 'b': %d (Binary: 0000 1100)\n", b);

    // &= (Bitwise AND and assign)
    // b = b & 7; (7 in binary is 0000 0111)
    b &= 7; // 0000 1100 & 0000 0111 = 0000 0100 (4)
    printf("After b &= 7; 'b' is: %d (Binary: 0000 0100)\n", b); // Expected: 4

    // |= (Bitwise OR and assign)
    // b = b | 3; (3 in binary is 0000 0011)
    b |= 3; // 0000 0100 | 0000 0011 = 0000 0111 (7)
    printf("After b |= 3; 'b' is: %d (Binary: 0000 0111)\n", b); // Expected: 7

    // ^= (Bitwise XOR and assign)
    // b = b ^ 5; (5 in binary is 0000 0101)
    b ^= 5; // 0000 0111 ^ 0000 0101 = 0000 0010 (2)
    printf("After b ^= 5; 'b' is: %d (Binary: 0000 0010)\n", b); // Expected: 2

    // <<= (Left Shift and assign)
    // b = b << 1; (Shift bits left by 1, equivalent to multiplying by 2)
    b <<= 1; // 0000 0010 << 1 = 0000 0100 (4)
    printf("After b <<= 1; 'b' is: %d (Binary: 0000 0100)\n", b); // Expected: 4

    // >>= (Right Shift and assign)
    // b = b >> 2; (Shift bits right by 2, equivalent to dividing by 4)
    b >>= 2; // 0000 0100 >> 2 = 0000 0001 (1)
    printf("After b >>= 2; 'b' is: %d (Binary: 0000 0001)\n", b); // Expected: 1

    printf("\nAssignment operators provide a shorter way to write operations.\n");

    return 0; // Indicates successful program execution.
}
