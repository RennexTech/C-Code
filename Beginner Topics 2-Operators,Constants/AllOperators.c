#include <stdio.h>   // Standard input/output library for printf, scanf
#include <stdlib.h>  // Standard library for general utilities
#include <math.h>    // For M_PI and pow in circle calculations
#include <string.h>  // For strcspn in input handling
#include <stdbool.h> // For bool type

// --- Function Prototypes ---
// Declare all demonstration functions so main can call them.
void demonstrate_undefined_behavior_with_increment();
void demonstrate_pre_post_increments();
void demonstrate_logical_operators_comparison();
void demonstrate_complex_arithmetic();
void demonstrate_comparison_logical();
void demonstrate_logical_ternary();
void demonstrate_operator_precedence();
void demonstrate_pre_post_mixed();
void demonstrate_invalid_increment();
void demonstrate_complex_expression_order();
void demonstrate_modulo_division();
void demonstrate_operator_precedence_complex();
void demonstrate_comma_operator();
void demonstrate_char_arithmetic();
void demonstrate_chained_assignment();
void demonstrate_variable_swap();
void demonstrate_ternary_operator();
void demonstrate_logical_assignment_side_effects();

// --- Functions for "QUESTIONS ANSWERED" section ---
double celsiusToFahrenheit(double celsius);
void calculateCircleAreaPerimeter();
void convertDecimalToOctalHex();
void findRemainderByThree();
void sumOrDifferenceTernary();
void calculateSimpleInterest();
void calculateTotalPercentageMarks();

/**
 * @brief Clears the standard input buffer.
 *
 * Reads and discards characters from stdin until a newline or EOF.
 * Prevents leftover characters from affecting subsequent input calls.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Prompts for and reads a double value from the user.
 * @param prompt Message to display.
 * @return The double value entered.
 */
double get_double_input(const char* prompt) {
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1) {
        printf("Invalid input. Please enter a number: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

/**
 * @brief Prompts for and reads an integer value from the user.
 * @param prompt Message to display.
 * @return The integer value entered.
 */
int get_integer_input(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

/**
 * @brief Demonstrates undefined behavior with post-increment/decrement.
 *
 * Modifying a variable multiple times within a single expression without
 * a sequence point leads to UNDEFINED BEHAVIOR. Result can vary.
 */
void demonstrate_undefined_behavior_with_increment() {
    printf("\n--- Undefined Behavior Example (DO NOT RELY ON THIS) ---\n");
    int a = 10;
    printf("Initial 'a': %d\n", a);
    // 'a' is modified twice here without a sequence point.
    // The order of operations is not guaranteed by the C standard.
    a = a++ * a--;
    printf("Result of a = a++ * a--; (Undefined Behavior): %d\n", a);
    printf("The actual value of 'a' might be different on other compilers or runs.\n");
}

/**
 * @brief Demonstrates pre-increment (++x) and post-increment (x++).
 *
 * Pre-increment updates value BEFORE use. Post-increment uses value THEN updates.
 */
void demonstrate_pre_post_increments() {
    printf("\n--- Pre- vs. Post-Increment/Decrement ---\n");

    int x_post = 5;
    int y_post = x_post++; // y_post gets 5, then x_post becomes 6
    printf("Post-increment (y = x++): x_post = %d, y_post = %d\n", x_post, y_post);

    int x_pre = 5;
    int y_pre = ++x_pre; // x_pre becomes 6, then y_pre gets 6
    printf("Pre-increment (y = ++x): x_pre = %d, y_pre = %d\n", x_pre, y_pre);

    int x_post_dec = 5;
    int y_post_dec = x_post_dec--; // y_post_dec gets 5, then x_post_dec becomes 4
    printf("Post-decrement (y = x--): x_post_dec = %d, y_post_dec = %d\n", x_post_dec, y_post_dec);

    int x_pre_dec = 5;
    int y_pre_dec = --x_pre_dec; // x_pre_dec becomes 4, then y_pre_dec gets 4
    printf("Pre-decrement (y = --x): x_pre_dec = %d, y_pre_dec = %d\n", x_pre_dec, y_pre_dec);

    // Complex pre-increment example
    int a_val = 2;
    // a_val becomes 3. Expression: 4 * (3 * 2 + 3) = 4 * (6 + 3) = 4 * 9 = 36
    int result_x = 4 * (++a_val * 2 + 3);
    printf("Complex pre-increment: a_val = %d, result_x = %d\n", a_val, result_x);
}

/**
 * @brief Demonstrates logical AND (&&) and logical OR (||) operators.
 *
 * Shows how these operators evaluate conditions and return 0 (false) or 1 (true).
 */
void demonstrate_logical_operators_comparison() {
    printf("\n--- Logical Operators (&& and ||) ---\n");
    int a = 3, b = 4, c = 3, d = 4;
    int x_and, y_or;

    // Logical AND (&&): True if BOTH conditions are true
    // (3 == 5) is false, (4 == 7) is false. Result: 0 (false)
    x_and = (a == 5) && (b == 7);
    printf("x = (a == 5) && (b == 7); -> x = %d\n", x_and);

    // Logical OR (||): True if AT LEAST ONE condition is true
    // (3 == 5) is false, (4 == 8) is false. Result: 0 (false)
    y_or = (c == 5) || (d == 8);
    printf("y = (c == 5) || (d == 8); -> y = %d\n", y_or);

    // Reset variables for another example
    a = 6, b = 9, c = 6, d = 10;

    // (6 == 6) is true, (9 == 9) is true. Result: 1 (true)
    x_and = (a == 6) && (b == 9);
    printf("x = (a == 6) && (b == 9); -> x = %d\n", x_and);

    // (6 == 6) is true, (10 == 10) is true. Result: 1 (true)
    y_or = (c == 6) || (d == 10);
    printf("y = (c == 6) || (d == 10); -> y = %d\n", y_or);
}

/**
 * @brief Demonstrates a complex arithmetic expression with logical NOT (!).
 *
 * Shows how different operators are evaluated in an expression.
 */
void demonstrate_complex_arithmetic() {
    printf("\n--- Complex Arithmetic Expression ---\n");
    int a = -3;
    printf("Initial 'a': %d\n", a);

    // Breakdown: a *= -a - a + !a;
    // !a: Logical NOT of -3 (non-zero) is 0.
    // -a: Negation of -3 is 3.
    // Expression becomes: a *= (3) - (-3) + (0)
    // a *= 3 + 3 + 0
    // a *= 6
    // a = -3 * 6 = -18
    a *= -a - a + !a;
    printf("Result of a *= -a - a + !a; : %d\n", a); // Expected: -18
}

/**
 * @brief Demonstrates comparison and logical operators.
 */
void demonstrate_comparison_logical() {
    printf("\n--- Comparison and Logical Operators ---\n");
    int a = 2, b = 1, c_res, d_res;
    c_res = a < b; // 2 < 1 is false. c_res = 0
    d_res = (a > b) && (c_res < b); // (2 > 1) is true (1), (0 < 1) is true (1). 1 && 1 is true. d_res = 1
    printf("c_res=%d, d_res=%d\n", c_res, d_res);
}

/**
 * @brief Demonstrates logical NOT and the ternary operator.
 */
void demonstrate_logical_ternary() {
    printf("\n--- Logical NOT and Ternary Operator ---\n");
    int a = 9, b = 15, c = 16, e_res, f_res;

    // e_res = !(a < b && b < c);
    // (9 < 15) is true, (15 < 16) is true. true && true is true.
    // !true is false. e_res = 0
    e_res = !(a < b && b < c);
    printf("e_res = !(a < b && b < c); -> e_res=%d\n", e_res);

    // f_res = (a > b) ? a - b : b - a;
    // (9 > 15) is false. So, evaluate b - a.
    // 15 - 9 = 6. f_res = 6
    f_res = (a > b) ? a - b : b - a;
    printf("f_res = (a > b) ? a - b : b - a; -> f_res=%d\n", f_res);
}

/**
 * @brief Demonstrates operator precedence with mixed arithmetic.
 */
void demonstrate_operator_precedence() {
    printf("\n--- Operator Precedence ---\n");
    int a = 5;
    a = 6; // 'a' is now 6
    // a = a + (5 * a); Multiplication before addition
    // a = 6 + (5 * 6) = 6 + 30 = 36
    a = a + 5 * a;
    printf("a = a + 5 * a; -> a=%d\n", a); // Expected: 36
}

/**
 * @brief Demonstrates mixed pre- and post-increment/decrement.
 */
void demonstrate_pre_post_mixed() {
    printf("\n--- Mixed Pre/Post Increment/Decrement ---\n");
    int a = 5, b = 5;
    printf("Initial a=%d, b=%d\n", a, b);
    printf("printf(\"%%d\\t\", ++a); -> %d\t", ++a); // a becomes 6, prints 6
    printf("printf(\"%%d\\t\", b--); -> %d\t", b--); // prints 5, then b becomes 4
    printf("printf(\"%%d\\t\", a); -> %d\t", a);     // prints 6
    printf("printf(\"%%d\\n\", b); -> %d\n", b);   // prints 4
    printf("Final a=%d, b=%d\n", a, b);
}

/**
 * @brief Demonstrates invalid increment/decrement operations (lvalue required).
 *
 * These lines are commented out because they cause compile-time errors.
 * Increment/decrement operators require a modifiable variable (lvalue).
 */
void demonstrate_invalid_increment() {
    printf("\n--- Invalid Increment/Decrement Operations (Compile-time Errors) ---\n");
    int x, y, z;
    // x = 8++;   // ERROR: 8 is a constant (rvalue), not a variable (lvalue)
    // y = ++x++; // ERROR: Cannot apply increment twice in this way (lvalue needed for second op)
    // z = (x + y)--; // ERROR: (x+y) is a temporary value (rvalue), not a variable (lvalue)
    printf("These operations would cause compile-time errors.\n");
    printf("Increment/decrement operators must be used on variables.\n");
}

/**
 * @brief Demonstrates a complex expression with operator precedence and side effects.
 *
 * This expression has undefined behavior due to multiple modifications of 'a', 'c', 'd'
 * without sequence points. The result can vary.
 */
void demonstrate_complex_expression_order() {
    printf("\n--- Complex Expression Order (Potential Undefined Behavior) ---\n");
    int a = 4, b = 8, c = 3, d = 9, z_res;
    printf("Initial: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

    // This expression has undefined behavior due to multiple side effects
    // on 'a', 'b', 'c', 'd' within a single expression without sequence points.
    // The order of evaluation of operands for +, *, - is not guaranteed.
    // Example breakdown (one possible interpretation, NOT guaranteed):
    // a++: use 4, a becomes 5
    // ++b: b becomes 9, use 9
    // c--: use 3, c becomes 2
    // --d: d becomes 8, use 8
    // Expression: 4 + 9 * 3 - 8 (assuming left-to-right evaluation within operators)
    // 4 + 27 - 8 = 31 - 8 = 23
    z_res = a++ + ++b * c-- - --d; // Original had `--d` which is invalid. Changed to `- --d` for demonstration.
    printf("Result of z = a++ + ++b * c-- - --d; (Undefined Behavior): %d\n", z_res);
    printf("Final values: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    printf("Note: The result and final values may vary due to undefined behavior.\n");
}

/**
 * @brief Demonstrates modulo and division operators with negative numbers.
 */
void demonstrate_modulo_division() {
    printf("\n--- Modulo and Division ---\n");
    int a = 14, b_res, c_res;
    // a = a % -5; Modulo operator result sign depends on the dividend (14 % -5 = 4)
    a = a % -5; // 14 % -5 = 4
    b_res = a / 3; // 4 / 3 = 1 (integer division)
    c_res = a / 5 % 3; // (4 / 5) = 0. 0 % 3 = 0
    printf("a=%d, b_res=%d, c_res=%d\n", a, b_res, c_res);
}

/**
 * @brief Demonstrates complex operator precedence with potential division by zero.
 *
 * The original code had a division by zero. This version fixes it.
 */
void demonstrate_operator_precedence_complex() {
    printf("\n--- Complex Operator Precedence (Fixed Division by Zero) ---\n");
    int a = 15, b = 13, c = 16, x_res, y_res;

    // Original: x = a - 3 % 2 + c * 2 / 4 % 2 + b / 4;
    // (c * 2 / 4 % 2) -> (16 * 2 / 4 % 2) -> (32 / 4 % 2) -> (8 % 2) -> 0
    // (3 % 2) -> 1
    // (b / 4) -> (13 / 4) -> 3
    // x = 15 - 1 + 0 + 3 = 17
    x_res = a - 3 % 2 + c * 2 / 4 % 2 + b / 4;
    printf("x = a - 3 %% 2 + c * 2 / 4 %% 2 + b / 4; -> x_res=%d\n", x_res);

    // y = a = b + 5 - b + 9 / 3;
    // (b + 5 - b) -> 5
    // (9 / 3) -> 3
    // a = 5 + 3 = 8. Then y = a.
    y_res = a = b + 5 - b + 9 / 3;
    printf("y = a = b + 5 - b + 9 / 3; -> y_res=%d (a is now %d)\n", y_res, a);
}

/**
 * @brief Demonstrates the comma operator.
 *
 * The comma operator evaluates expressions from left to right and
 * the result of the entire expression is the value of the rightmost expression.
 */
void demonstrate_comma_operator() {
    printf("\n--- Comma Operator ---\n");
    int x, y, z, k = 10;
    // k += (x = 5, y = x + 2, z = x + y);
    // x = 5 (x is 5)
    // y = x + 2 (y is 7)
    // z = x + y (z is 5 + 7 = 12)
    // The entire expression evaluates to 12.
    // k += 12 -> k = 10 + 12 = 22
    k += (x = 5, y = x + 2, z = x + y);
    printf("k += (x = 5, y = x + 2, z = x + y); -> x=%d, y=%d, z=%d, k=%d\n", x, y, z, k);
}

/**
 * @brief Demonstrates arithmetic operations involving char and int.
 *
 * Characters are treated as their ASCII integer values in arithmetic expressions.
 */
void demonstrate_char_arithmetic() {
    printf("\n--- Character Arithmetic ---\n");
    int a = 9;
    char ch = 'A'; // ASCII for 'A' is 65
    printf("Initial: a=%d, ch='%c' (ASCII %d)\n", a, ch, ch);

    // a = a + ch + 24;
    // a = 9 + 65 + 24 = 98
    a = a + ch + 24;
    printf("After a = a + ch + 24;: a=%d\n", a);

    // %d prints the integer value, %c prints the character representation.
    printf("ch as int: %d, ch as char: %c\t", ch, ch);
    printf("a as int: %d, a as char: %c\n", a, a); // 98 is ASCII for 'b'
}

/**
 * @brief Demonstrates chained assignments and compound assignments.
 */
void demonstrate_chained_assignment() {
    printf("\n--- Chained and Compound Assignments ---\n");
    int a, b, c, d;

    // Chained assignment: assigns 4 to d, then c, then b, then a.
    a = b = c = d = 4;
    printf("Initial: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

    // a *= b + 1; Equivalent to a = a * (b + 1)
    // a = 4 * (4 + 1) = 4 * 5 = 20
    a *= b + 1;
    printf("After a *= b + 1;: a=%d\n", a);

    // c += d *= 3; Evaluates d *= 3 first, then c += result.
    // d *= 3 -> d = 4 * 3 = 12. (d is now 12)
    // c += 12 -> c = 4 + 12 = 16. (c is now 16)
    c += d *= 3;
    printf("After c += d *= 3;: c=%d, d=%d\n", c, d);
}

/**
 * @brief Demonstrates swapping two integer variables using a temporary variable.
 */
void demonstrate_variable_swap() {
    printf("\n--- Variable Swapping ---\n");
    int a = 5, b = 10, temp;
    printf("Before swap: a=%d, b=%d\n", a, b);

    // Swap values using a temporary variable
    temp = a; // Store 'a's value in temp
    a = b;    // Assign 'b's value to 'a'
    b = temp; // Assign temp's value (original 'a') to 'b'
    printf("After swap: a=%d, b=%d\n", a, b);
}

/**
 * @brief Demonstrates the ternary conditional operator.
 *
 * Syntax: condition ? value_if_true : value_if_false;
 */
void demonstrate_ternary_operator() {
    printf("\n--- Ternary Conditional Operator ---\n");
    int a = 10, b = 3, max_val;

    // If (a > b) is true, max_val = a. Else, max_val = b.
    max_val = (a > b) ? a : b; // 10 > 3 is true, so max_val = 10
    printf("Max of %d and %d is: %d\n", a, b, max_val);
}

/**
 * @brief Demonstrates logical operators with assignment side effects.
 *
 * Shows how assignments within logical expressions affect variable values.
 */
void demonstrate_logical_assignment_side_effects() {
    printf("\n--- Logical Operators with Assignment Side Effects ---\n");
    int a = 3, b = 4, c = 3, d = 4, x_res, y_res;

    // x = (a = 5) && (b = 7);
    // (a = 5) evaluates to 5 (true), a becomes 5.
    // (b = 7) evaluates to 7 (true), b becomes 7.
    // true && true is true (1). x_res = 1.
    x_res = (a = 5) && (b = 7);
    y_res = (c = 5) || (d = 8);
    printf("After first set: a=%d, b=%d, c=%d, d=%d, x_res=%d, y_res=%d\n", a, b, c, d, x_res, y_res);

    // x = (a == 6) && (b = 9);
    // (a == 6) is (5 == 6), which is false (0).
    // Due to short-circuiting, (b = 9) is NOT evaluated. b remains 7.
    // false && ... is false (0). x_res = 0.
    x_res = (a == 6) && (b = 9);
    // y = (c == 6) || (d = 10);
    // (c == 6) is (5 == 6), which is false (0).
    // (d = 10) is evaluated, d becomes 10.
    // false || true is true (1). y_res = 1.
    y_res = (c == 6) || (d = 10);
    printf("After second set: a=%d, b=%d, c=%d, d=%d, x_res=%d, y_res=%d\n", a, b, c, d, x_res, y_res);
}

// --- Functions for "QUESTIONS ANSWERED" section ---

/**
 * @brief Converts Celsius to Fahrenheit.
 * @param celsius Temperature in Celsius.
 * @return Temperature in Fahrenheit.
 */
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

/**
 * @brief Prompts for Celsius, converts to Fahrenheit, and prints.
 */
void convertCelsiusToFahrenheit() {
    printf("\n--- Celsius to Fahrenheit Converter ---\n");
    double celsius = get_double_input("Enter temperature in Celsius: ");
    double fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
}

/**
 * @brief Calculates and prints the area and perimeter of a circle.
 */
void calculateCircleAreaPerimeter() {
    printf("\n--- Circle Area and Perimeter ---\n");
    double radius = get_double_input("Enter the radius of the circle: ");
    double area = M_PI * pow(radius, 2);
    double perimeter = 2 * M_PI * radius;
    printf("Area of the circle: %.2lf square units\n", area);
    printf("Perimeter of the circle: %.2lf units\n", perimeter);
}

/**
 * @brief Converts a decimal number to its octal and hexadecimal representations.
 */
void convertDecimalToOctalHex() {
    printf("\n--- Decimal to Octal and Hexadecimal Converter ---\n");
    int decimalNumber = get_integer_input("Enter a decimal number: ");
    printf("Octal representation: %o\n", decimalNumber);
    printf("Hexadecimal representation: %X\n", decimalNumber);
}

/**
 * @brief Accepts a number and prints its remainder when divided by 3.
 */
void findRemainderByThree() {
    printf("\n--- Remainder by 3 ---\n");
    int number = get_integer_input("Enter a number: ");
    int remainder = number % 3;
    printf("Remainder after dividing by 3: %d\n", remainder);
}

/**
 * @brief Accepts two numbers and prints their sum or difference using the ternary operator.
 */
void sumOrDifferenceTernary() {
    printf("\n--- Sum or Difference (Ternary Operator) ---\n");
    int num1 = get_integer_input("Enter first number: ");
    int num2 = get_integer_input("Enter second number: ");
    int result = (num1 > num2) ? num1 + num2 : num1 - num2;
    printf("Result: %d\n", result);
}

/**
 * @brief Calculates and prints simple interest.
 */
void calculateSimpleInterest() {
    printf("\n--- Simple Interest Calculator ---\n");
    double principal = get_double_input("Enter principal amount: ");
    double rate = get_double_input("Enter annual interest rate (in percentage): ");
    double time = get_double_input("Enter time (in years): ");
    double simpleInterest = (principal * rate * time) / 100;
    printf("Simple Interest: %.2lf\n", simpleInterest);
}

/**
 * @brief Accepts marks in five subjects and calculates total percentage.
 */
void calculateTotalPercentageMarks() {
    printf("\n--- Total Percentage Marks ---\n");
    int marks[5];
    int totalMarks = 0;

    printf("Enter marks in five subjects (0-100):\n");
    for (int i = 0; i < 5; i++) {
        marks[i] = get_integer_input("Subject %d: ", i + 1);
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Marks must be between 0 and 100. Please re-enter for Subject %d.\n", i + 1);
            i--; // Decrement to re-enter marks for the current subject
            continue;
        }
        totalMarks += marks[i];
    }

    float percentage = (float)totalMarks / 5;
    printf("Total Percentage Marks: %.2f%%\n", percentage);
}


/**
 * @brief Main function to run various C operator demonstrations and exercises.
 *
 * This program serves as a comprehensive set of examples for different C operators,
 * including increment/decrement, logical, arithmetic, and more complex expressions.
 * It also includes solutions to common beginner programming exercises.
 */
int main()
{
    printf("--------------------------------------------------\n");
    printf("Welcome to C Operators & Beginner Exercises\n");
    printf("--------------------------------------------------\n");

    // --- Operator Demonstrations ---
    printf("\n--- Operator Demonstration Section ---\n");
    demonstrate_undefined_behavior_with_increment();
    demonstrate_pre_post_increments();
    demonstrate_logical_operators_comparison();
    demonstrate_complex_arithmetic();
    demonstrate_comparison_logical();
    demonstrate_logical_ternary();
    demonstrate_operator_precedence();
    demonstrate_pre_post_mixed();
    demonstrate_invalid_increment();
    demonstrate_complex_expression_order();
    demonstrate_modulo_division();
    demonstrate_operator_precedence_complex();
    demonstrate_comma_operator();
    demonstrate_char_arithmetic();
    demonstrate_chained_assignment();
    demonstrate_variable_swap();
    demonstrate_ternary_operator();
    demonstrate_logical_assignment_side_effects();

    // --- Beginner Exercises Solutions ---
    printf("\n\n--------------------------------------------------\n");
    printf("--- Beginner Programming Exercises Solutions ---\n");
    printf("--------------------------------------------------\n");
    convertCelsiusToFahrenheit();
    calculateCircleAreaPerimeter();
    convertDecimalToOctalHex();
    findRemainderByThree();
    sumOrDifferenceTernary();
    calculateSimpleInterest();
    calculateTotalPercentageMarks();

    printf("\n--------------------------------------------------\n");
    printf("End of Demonstrations and Exercises.\n");
    printf("--------------------------------------------------\n");

    return 0; // Indicates successful program execution
}
