/* Program to find the type and area of triangle */

#include <stdio.h>
#include <math.h>

void type(float a, float b, float c);
void area(float a, float b, float c);

int main() {
    float a, b, c;
    printf("Enter the sides of triangle \n");
    scanf("%f%f%f", &a, &b, &c);

    // This is the fundamental rule of triangles: the sum of the lengths
    // of any two sides of a triangle must be greater than the third side.
    if (a + b > c && a + c > b && b + c > a) {
        type(a, b, c);
        area(a, b, c);
    } else {
        printf("No triangle possible with these sides \n");
    }
    return 0;
}

// We check for the most specific types first, like a flowchart.
// You have to check if it's a specific kind of triangle before
// moving on to the more general categories.
void type(float a, float b, float c) {
    if (a == b && b == c) {
        printf("Equilateral Triangle\n");
    } else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
        printf("Right Angle Triangle\n");
    } else if (a == b || b == c || c == a) {
        printf("Isosceles Triangle\n");
    } else {
        printf("Scalene Triangle\n");
    }
}

// We use Heron's formula here, which is a classic way to find the area
// of a triangle when you know the lengths of all three sides.
void area(float a, float b, float c) {
    float s, area;
    s = (a + b + c) / 2; // 's' is the semi-perimeter.
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("Area Of Triangle = %.2f\n", area);
}