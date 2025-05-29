#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*

    This is assigment operator chaining.
    In assignment operator, the variable is the operand on the left always.

    */
    int x, y, z, f, g, h;
    x = y = z = f = g = h = 200;
    printf("x is: %d\n", x);
    printf("y is: %d\n", y);
    printf("z is: %d\n", z);
    printf("f is: %d\n", f);
    printf("g is: %d\n", g);
    printf("h is: %d\n", h);

    x = x + 65; // can also be x+= 65;
    y += 64;
    printf("The new x is: %d\n", x);
    printf("The new y is: %d\n", y);

    /*

    Here are the operators in C, along with their precedence and associativity:

    Parentheses (): Function call, array subscript. Parentheses have the highest precedence and are evaluated first.
    Unary operators +, -, !, ~: Unary plus, unary minus, logical NOT, bitwise NOT. Unary operators have the next highest precedence and are evaluated from right to left.
    Cast operator (datatype): Type cast. Cast operator has the same precedence as unary operators and is evaluated from right to left.
    Size of operator sizeof(): Size in bytes. Size of operator has the same precedence as unary operators and is evaluated from right to left.
    Multiplication *, /, %: Multiplication, division, modulus. These operators have the same precedence and are evaluated from left to right.
    Addition +, -: Addition, subtraction. These operators have the same precedence and are evaluated from left to right.
    Shift operators <<, >>: Left shift, right shift. These operators have the same precedence and are evaluated from left to right.
    Relational operators <, <=, >, >=: Less than, less than or equal to, greater than, greater than or equal to. These operators have the same precedence and are evaluated from left to right.
    Equality operators ==, !=: Equal to, not equal to. These operators have the same precedence and are evaluated from left to right.
    Bitwise AND &: Bitwise AND.
    Bitwise XOR \|: Bitwise XOR.
    Bitwise OR |: Bitwise OR.
    Logical AND &&: Logical AND.
    Logical OR \|\|: Logical OR.
    Conditional operator ?:: Conditional operator.
    Assignment operators =, *=, /=, %=, +=, -=: Assignment operators. Assignment operators have the lowest precedence and are evaluated from right to left.

    =========================================

    Here are some expressions and how they will be evaluated:

    x = a + b < c:
    The + operator has higher precedence than the < operator, so a + b will be evaluated first.
    The result of a + b will then be compared to c.
    If the result is less than c, then the value of x will be 1. Otherwise, the value of x will be 0.

    x *= a + b:
    The + operator has higher precedence than the *= operator, so a + b will be evaluated first.
    The result of a + b will then be multiplied by the current value of x.
    The new value of x will be assigned to x.

    x = a <= b && b == c:
    The <= operator has higher precedence than the == operator, so a <= b will be evaluated first.
    The result of a <= b will then be compared to c.
    If the result is true, then the value of x will be 1. Otherwise, the value of x will be 0.
    In the above examples, the operators are evaluated in the following order:

    Operators with the highest precedence
    Operators with the same precedence, from left to right
    If two operators with the same precedence are next to each other, the order of evaluation is determined by the associativity of the operators.

    The associativity of an operator tells us whether it is evaluated from left to right or from right to left. The associativity of the following operators is:

    +, -: Left to right
    *, /, %: Left to right
    <, <=, >, >=: Left to right
    ==, !=: Left to right
    &&: Left to right
    ||: Left to right
    ?:: Right to left


    */

    return 0;
}
