/* Input a number and a digit, and count the number of time the digit occurs in the number */

#include <stdio.h>
int main() {
    int num, digit, rem, tNum, count = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    printf("Enter a digit : ");
    scanf("%d", &digit);

    // We store the original number in `tNum` because we're going to
    // mess with its value in the loop. This ensures we can still
    // print the original number at the end. It's like making a copy of a file
    // before you edit it.
    tNum = num;
    
    // This loop breaks down the number digit by digit, from right to left.
    // It's like a deconstruction process, checking each piece for a match.
    while (tNum > 0) {
        // We get the last digit of the number using the modulo operator.
        rem = tNum % 10;
        
        // If that last digit matches our target digit, we increment our counter.
        if (rem == digit)
            count++;
        
        // We then chop off that last digit by dividing by 10,
        // so the loop can move on to the next digit.
        tNum = tNum / 10;
    }
    
    printf("Total occurrence of digit is : %d in number : %d", count, num);
    return 0;
}