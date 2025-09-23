#include <stdio.h>

int main() {
    int a, b;
    char op;
    printf("Enter Number, operator, Another Number (e.g., 5*3): ");
    
    // We add a space before %c to ignore any whitespace characters,
    // like the newline from the previous input, making the program more reliable.
    scanf("%d %c%d", &a, &op, &b);
    
    // The switch statement is like a router for an operator. It directs the program
    // to the correct calculation based on the operator entered by the user.
    switch (op) {
        case '+':
            printf("result = %d\n", a + b);
            break;
        case '-':
            printf("result = %d\n", a - b);
            break;
        case '*':
            printf("result = %d\n", a * b);
            break;
        case '%':
            // We should add a check here to prevent division by zero, which would cause a crash.
            if (b == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                printf("result = %d\n", a % b);
            }
            break;
        case '/': // It's a good idea to add division as well.
            if (b == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                printf("result = %.2f\n", (float)a / b);
            }
            break;
        default:
            printf("Enter valid Operator\n");
            break;
    }
    return 0;
}