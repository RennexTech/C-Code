#include <stdio.h>
#include <stdlib.h>

/*

Let's break down the explanation of pointers and two-dimensional arrays with a rewritten explanation:

In the world of C programming, we often work with two-dimensional arrays, which can be visualized as tables with rows and columns. These arrays allow us to organize data in a structured way. You can access the individual elements of a 2D array using two subscripts: the first subscript represents the row number, and the second subscript represents the column number. For example, arr[i][j] accesses the element at row i and column j of the array.

Now, here's the interesting part: we can also access elements in a 2D array using pointer notation. Imagine you have a 2D array named arr.

To access a specific element, say arr[i][j], you can use the pointer expression *(*(arr + i) + j). Let's dissect this expression to understand how it works:

(arr + i) moves the pointer to the i-th row of the array. Think of it as shifting your focus to a specific row.

*(arr + i) now points to the first element of that row, which itself is an array.

*(arr + i) + j further moves the pointer within that row to the j-th column.

It's like navigating within that row to find the desired column.

Finally, *(*(arr + i) + j) retrieves the value of the element at row i and column j.

Now, let's address an interesting fact about how computers store 2D arrays in memory.

While we often think of 2D arrays in terms of rows and columns, computers organize memory linearly.

This means that they don't neatly store rows and columns as we visualize them. Instead, they use a technique called "row major order."

In row major order, the elements of each row are stored sequentially in memory, one after the other.

To illustrate this concept, consider the 2D array arr[3][4] with the values you provided:

*/

int main()
{
    printf("Hello world!\n");
    return 0;
}



int arr[3][4] = {
    {10, 11, 12, 13},
    {20, 21, 22, 23},
    {30, 31, 32, 33}
};

/*

Here's how this array would be stored in memory: Even though we think of it as rows and columns, the computer stores it as a continuous block of memory with the rows placed one after the other.

The correct term to describe how the elements of a 2D array are stored in memory is "contiguous."

When we say that the elements of a 2D array are stored contiguously in memory, we mean that they are stored one after the other in a continuous block of memory, without any gaps or interruptions.

This allows for efficient memory access and manipulation.

So, to clarify, the elements of a 2D array in C are stored contiguously in memory.

==================================

Array of Arrays: You're absolutely right that a two-dimensional array can be considered as a collection of one-dimensional arrays placed one after another. In your example, arr is an array of 3 elements, and each element is a one-dimensional array containing 4 integers. So, arr is like an array containing three one-dimensional arrays.

Name of an Array: In C, the name of an array is essentially a constant pointer that points to the first element of that array. In the case of a two-dimensional array, the first element is a one-dimensional array.

Pointer Arithmetic: When you perform pointer arithmetic on arr, you're moving the pointer to different one-dimensional arrays within the two-dimensional array. For instance, if arr contains the address 5000, then (arr + 1) will represent the address 5008, and (arr + 2) will represent address 5016. This means that arr points to the first one-dimensional array, (arr + 1) points to the second one-dimensional array, and so on.

So, you have a clear understanding of how two-dimensional arrays are organized in memory and how the name of the array represents a pointer to the first element, which in the case of a 2D array, is a one-dimensional array. This knowledge is fundamental in C programming and will be very useful as you continue to work with arrays and pointers. If you have any more questions or need further clarification, please feel free to ask!

==================================

Let's rewrite the notes you provided with a slightly different wording for better clarity:

In the realm of C programming, a two-dimensional array can be thought of as a collection of one-dimensional arrays, neatly lined up in memory. This view helps us understand the underlying structure. In essence, a 2D array is an "array of arrays." Let's delve into this concept using your example:

Consider the 2D array arr[3][4]:

*/

int arr[3][4] = {
    {10, 11, 12, 13},
    {20, 21, 22, 23},
    {30, 31, 32, 33}
};


/*

Here, arr is an array of 3 elements, and each element is, in turn, a 1D array containing 4 integers. So, arr can be visualized as an array containing three 1D arrays.

Now, let's talk about the name of an array. In C, the name of an array is essentially a constant pointer pointing to the first element of that array. In the case of a 2D array, the first element is a 1D array. For instance, if arr has the memory address 5000, then it points to the first 1D array.

Pointer arithmetic comes into play here. If you increment the arr pointer, you move to the next 1D array within the 2D array. So, (arr + 1) points to the second 1D array (address 5008), and (arr + 2) points to the third 1D array (address 5016).

In essence, arr represents the starting point of the entire 2D array, (arr + 1) points to the next "row" (1D array), and so on. This understanding is vital for navigating and manipulating 2D arrays efficiently in C programming.

=============================

In general, we can express that arr + i points to the i-th element of the arr, which itself points to the i-th 1D array within the 2D array. Since arr + i points to the i-th element of arr, dereferencing it (*(arr + i)) gives us the i-th 1D array.

Now, let's connect this to the base address of the i-th 1D array. We've previously established that the pointer expression *(arr + i) is equivalent to the subscript expression arr[i] in 2D arrays. (DON'T FORGET THIS, IT'S THE MOST CRUCIAL CONCEPT)

So, *(arr + i), which is the same as arr[i], provides us with the base address of the i-th 1D array.

In summary, both *(arr + i) and arr[i] are equivalent expressions, and they give us the base address of the i-th 1D array within the 2D array arr.

This understanding is crucial when working with 2D arrays in C, as it allows you to use both pointer notation and subscript notation interchangeably for accessing elements and navigating through the array's structure. If you have any more questions or need further clarification, please feel free to ask!

==============================

Sure, let's explain the concept of pointer expression *(arr + i) being equivalent to the subscript expression arr[i] in 2D arrays as if you were a teenager:

Alright, imagine you have this thing called a 2D array in C, which is like a grid of numbers. We use it to store lots of data neatly. So, in this grid, you can pick out a specific number using two methods.

Pointer Expression: You can use this fancy pointer thing like *(arr + i). Here, arr is like the big boss that knows where everything is, and i tells it which row you want to look at. So, *(arr + i) is like asking the boss to find the row for you.

Subscript Expression: The other way is easier to write. It's like using square brackets, like arr[i]. Here, i again tells the boss which row you want.

Now, here's the cool part: both of these methods are basically the same thing! Whether you use *(arr + i) or arr[i], they both point to the same number in that row you're interested in.

So, think of it like choosing between two different ways to ask the boss for a number from the grid. You can pick the one you like best, and it'll give you the same result. It's all about making your code easier to read and work with.

Keep up the curiosity, and you're on your way to becoming a great programmer! If you have more questions or want to know more about this or anything else, just ask. 😊

*/


/*

It seems like they are discussing how to access individual elements of a 2D array in C. Let me clarify this concept for you:

In C, a 2D array is essentially an array of arrays. If you have a 2D array arr, you can access its elements using the following notations:

arr[i][j]: This notation directly accesses the element in the ith row and jth column of the 2D array arr. It's the most common and straightforward way to access elements in a 2D array.

*(arr[i] + j): This is an alternative way to access elements. Here, arr[i] represents the ith 1D array within the 2D array, and *(arr[i] + j) accesses the jth element within that 1D array. It's equivalent to arr[i][j].

*(*(arr + i) + j): This is another way to access elements. Here, *(arr + i) gives you a pointer to the ith 1D array within the 2D array, and *(*(arr + i) + j) accesses the jth element within that 1D array. Again, it's equivalent to arr[i][j].

The notes are discussing how *(arr+i) can be thought of as a pointer to the ith 1D array within the 2D array. This is because arr is essentially a pointer to the first row of the 2D array, and when you add i to it, you move to the ith row. Then, by adding j to *(arr+i), you access the jth element within that 1D array.

In summary, these notes are explaining different ways to access elements in a 2D array, emphasizing the use of pointers to navigate through the rows and columns. The notations can look a bit complex, but they are equivalent to the more common arr[i][j] notation and provide a deeper understanding of how 2D arrays are stored in memory.

===================================

*(*(arr + i) + j):
Here we are using a pointer to the first element of the 2D array which has rows and columns too.

*(arr[i] + j):
Here we are using a pointer shortform, coz arr[i] is always considered a pointer to the first element of the 2D array, which is just a 1D array.

===================================

*(*(arr + i) + j): This notation is used to access an element in a 2D array. Here's a step-by-step explanation:

arr is a pointer to the first row of the 2D array.

(arr + i) moves to the ith row of the 2D array.

So, *(arr + i) gives you a pointer to the first element of the ith 1D array within the 2D array.

*(arr[i] + j) then adds j to this pointer, effectively moving j elements forward in the 1D array.

So, it accesses the jth element within the ith 1D array.

Finally, the outer * dereferences this pointer, giving you the actual value of the element at (i, j) in the 2D array.

===================================

*(arr[i] + j):

This notation is a more concise way to access the same element. Here's how it works:

arr is considered a pointer to the first row of the 2D array.

arr[i] is effectively a pointer to the first element of the ith 1D array within the 2D array.

(arr[i] + j) adds j to this pointer, directly accessing the jth element within the ith 1D array.

The outer * then dereferences this pointer, giving you the actual value of the element at (i, j) in the 2D array.

So, both notations essentially do the same thing: they access the element at (i, j) in the 2D array.

The second notation is more concise and often preferred for its readability, but the first notation provides a clearer view of how 2D arrays are stored in memory by emphasizing the use of pointers to navigate through rows and columns.


===================================

Let's explain this in a simpler way, as if you're a teenager who's just getting into programming.

Imagine a 2D array like a big table with rows and columns, just like a spreadsheet. Each cell in this table holds a value, like a number or a piece of information.

Now, you want to get something from a specific cell in this table. To do that, you need two numbers: one for the row and one for the column. These numbers tell you exactly which cell you're interested in.

Here's how you can do it in two different ways:

The Longer Way - *(*(arr + i) + j):

First, you go to the right row. Imagine you're walking to the correct row of the table.

Then, you go to the right column within that row. You're basically pinpointing the exact cell you want.

Finally, you pick up what's in that cell.

The Shorter Way - *(arr[i] + j):

You start at the right row directly. No need to take extra steps.

Then, you move to the right column within that row.

Finally, you grab what's in that cell.

Both ways get you the same result: the value in the cell you wanted. The second way is like taking a shortcut; you skip some extra steps but still get to the same place in the end.

So, when you're working with a 2D array, you use these numbers for rows and columns to find the right cell, and you can do it in either the longer way or the shorter way. It's like finding your way around a big table of information!

===================================

Imagine you have a big grid of numbers arranged in rows and columns. Each number in this grid represents something important. You want to pick a specific number from this grid, and to do that, you need two pieces of information: the row number and the column number.

Now, there are two ways you can do this:

The Longer Way - *(*(arr + i) + j):

First, you look at the row number (let's say it's i). It tells you which row to focus on.

Then, you look at the column number (let's say it's j). It tells you which column within that row to check.

Finally, you pick the number at the intersection of that row and column.
The Shorter Way - *(arr[i] + j):

You start with the row number (again, let's say it's i). It's like finding the right row immediately.

Next, you just look at the column number (j). It tells you which column within that row to check.

Finally, you grab the number you're interested in, right there.

Both ways lead you to the same result: the number you wanted from the grid.

The second way is simpler because you skip a step, but both methods work to get you the right number.

Think of it like finding your way to a specific spot in a large grid of numbers.

You can take a shortcut or follow a longer path, but either way, you end up at the same spot with the number you needed.

===================================

Let's rewrite this stuffs once again:

Alright, imagine you have this thing called a 2D array in C, which is like a grid of numbers. We use it to store lots of data neatly. So, in this grid, you can pick out a specific number using two methods.

Pointer Expression: You can use this fancy pointer thing like *(arr + i). Here, arr is like the big boss that knows where everything is, and i tells it which row you want to look at. So, *(arr + i) is like asking the boss to find the row for you.

Subscript Expression: The other way is easier to write. It's like using square brackets, like arr[i]. Here, i again tells the boss which row you want.

Now, here's the cool part: both of these methods are basically the same thing! Whether you use *(arr + i) or arr[i], they both point to the same number in that row you're interested in.

So, think of it like choosing between two different ways to ask the boss for a number from the grid. You can pick the one you like best, and it'll give you the same result. It's all about making your code easier to read and work with.

Keep up the curiosity, and you're on your way to becoming a great programmer!


================================


Let's explain the *(arr + i + j) part, which involves both rows and columns in a 2D array, as if you were a teenager:

Alright, picture your 2D array like a giant checkerboard filled with numbers. We've got rows going this way and columns going that way. Now, you want to find a specific number at the intersection of a row and a column.

Row Choice: First, you decide which row you're interested in, right? You do this with i. It's like telling someone, "I want to check out row number 2."

Column Choice: Now, you want to move along that row and find the exact spot, which is the column. That's where j comes in. You're saying, "Within that row, I want to go j columns to the right."

Putting It Together: So, *(arr + i + j) is like going to the big checkerboard, picking a row using i, and then counting j spaces to the right to find your number.

Here's the cool part: this is another way to write arr[i][j]. They both do the same thing; they find the number at the intersection of the row you chose (i) and the column you want (j).

Imagine it as a treasure hunt. First, you choose the row you're starting in, then you count the steps to the right to find your treasure, which is the number you're looking for.


==============================

*(*(arr + i) + j) is a correct way to access an element in a 2D array. It's a pointer notation where you first move to the i-th row using *(arr + i) and then navigate to the j-th column within that row by adding j. This expression is equivalent to arr[i][j] in subscript notation.

*(arr[i][j]) is not correct. In this case, you have an extra set of parentheses around arr[i][j]. The correct way to access elements in a 2D array in pointer notation is *(*(arr + i) + j) or in subscript notation as arr[i][j].

So, to summarize, both *(*(arr + i) + j) and arr[i][j] are valid ways to access elements in a 2D array. The first one uses pointer notation, and the second one uses subscript notation. You can choose the one that's more comfortable for you to work with in your code.
*/


void let_me_tell_you()
{
    arr; //points to the 0th 1D array within the 2D array
    *arr; //points to the 0th element of 0th 1D array
    (arr + i); //points to the ith 1D array within that 2D array
    *(arr + i); //points to the 0th element of the i-th 1D array within that 2D array
    *(arr + i) + j; //points to the jth element of ith 1D array
    *(*(arr + i)+ j); //represents the value of jth element of ith 1D array

}

/*

Let's explain these concepts using a simple real-world example:

Imagine you have a classroom with rows and seats. Each row has several seats, and there are multiple rows. This setup is similar to a 2D array.

arr; - Think of this as the entire classroom. When you say arr, you're talking about the whole room, which includes all the rows and seats. It points to the first row.

*arr; - Now, you zoom in on the first row. *arr points to the very first seat in the first row. It's like saying, "Hey, give me the first seat in the first row."

(arr + i); - Suppose you want to move to a different row. You use (arr + i) to move to the i-th row. It's like saying, "Take me to the i-th row."

*(arr + i); - Once you're in a specific row, you can point to the first seat in that row using *(arr + i). It's like saying, "Now, show me the first seat in the i-th row."

*(arr + i) + j; - If you want to move within the row to a specific seat, you use *(arr + i) + j. This points to the j-th seat in the i-th row. It's like saying, "I'm in the i-th row, now move me j seats to the right."

*(*(arr + i) + j); - Finally, this represents the actual person sitting in the j-th seat of the i-th row. It's like asking, "Who's sitting in the j-th seat of the i-th row?"

So, in your classroom (2D array), you can use these notations to navigate from the whole room to specific seats and find out who's sitting in those seats. It's like moving through rows and seats to get the information you want.

I hope this real-world example makes these concepts clearer for you! If you have more questions or need further explanation, feel free to ask.


======================================

Absolutely, let's dive into a detailed explanation of these concepts like a seasoned programmer would:

1. arr; - Think of arr as the blueprint of your entire classroom. It represents your 2D array. It's like having a layout of all the rows and seats in the classroom. When you mention arr, you're talking about the entire classroom, including all the rows and seats.

2. *arr; - Now, you're moving from the blueprint to the real classroom. *arr points to the first row, which is like the first row of actual seats in the classroom. It's like walking into the classroom and looking at the first row.

3. (arr + i); - Let's say you want to move to a different row. Using (arr + i) is like taking a step forward to the i-th row. It's as if you're walking to the i-th row in the classroom.

4. *(arr + i); - Now that you're in a specific row, *(arr + i) points to the first seat in that row. It's like standing in a row and looking at the first seat to your left.

5. *(arr + i) + j; - If you want to go to a specific seat in that row, you can use *(arr + i) + j. It's like taking additional steps within the row to reach the j-th seat. You're moving horizontally within the row.

6. *(*(arr + i) + j); - Finally, this represents the actual person sitting in the j-th seat of the i-th row. It's like looking at the person who's occupying that specific seat. You've zoomed in on a single seat within a single row.

So, you start with the whole classroom (2D array), navigate to a specific row, then pinpoint the first seat in that row, further move to a particular seat within that row, and finally, you get to know who's sitting in that seat.

In programming, these notations are crucial for accessing and manipulating data in 2D arrays efficiently. It's like having a map to explore and interact with complex data structures.

=================================================

Certainly, let's provide a detailed yet straightforward explanation:

1. arr; - Think of arr as the entire classroom. When you mention arr, you're referring to the whole space with all the rows and seats. It's like having a bird's-eye view of the entire classroom.

2. *arr; - Now, you're zooming in on the first row of seats in the classroom. *arr points to the very first seat in that row. It's like walking into the classroom and focusing on the first row.

3. (arr + i); - Suppose you want to move to a different row. Using (arr + i) is like shifting your attention to the i-th row. It's as if you've taken a step forward to a specific row.

4. *(arr + i); - Once you're in a specific row, *(arr + i) points to the first seat in that row. It's like standing in that row and looking at the seat closest to you on the left.

5. *(arr + i) + j; - If you wish to go to a particular seat within that row, you use *(arr + i) + j. It's like moving horizontally within the row to the j-th seat.

6. *(*(arr + i) + j); - Finally, this represents the person sitting in the j-th seat of the i-th row. It's like looking at the occupant of that specific seat.

In programming, these notations are akin to having a map to navigate a complex structure like a classroom with rows and seats. They allow you to access and manipulate data efficiently in a 2D array, whether you're working with classroom layouts or any other type of data organized in rows and columns.

I hope this explanation helps you grasp the concept more clearly. If you have more questions or need further clarification, feel free to ask!

*/

#include <stdio.h>

int main() {
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    printf("Printing values and addresses of elements in the 2D array using pointers:\n");

    int *ptr = &arr[0][0]; // Create a pointer pointing to the first element

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Element at arr[%d][%d] = %d\n", i, j, *(ptr + i * 4 + j));
            printf("Address of arr[%d][%d] = %p\n", i, j, (ptr + i * 4 + j));
        }
    }

    return 0;
}

/*

In this modified program, we use a pointer ptr to access the elements of the 2D array. Here's how it works:

We initialize ptr to point to the address of the first element (&arr[0][0]) in the 2D array.
Inside the nested loops, we use pointer arithmetic to access each element.

*(ptr + i * 4 + j) calculates the address of the element based on the row i and column j and then dereferences the pointer to get the value.

This program will also print the values and addresses of each element in the 2D array, just like the previous version. You can adjust the array dimensions or values as needed.

Feel free to run the program and experiment with it. If you have any questions or need further assistance, please let me know!

*/

for(p = &a[0][0]; p <= &a[row-1][col-1]; p++)
    printf("%d", *p);

//say the program has 2 rows 2 columns in linear form:
//&a[row-1][col-1] - that will mean get the last item in that linearly organized array
//&a[1][1] - that is the last item as shown in that photo called linear arrays and pointers

for(p = &a[0][0]; p <= &a[1][1]; p++)
    printf("%d", *p);

/*

In this code, p is a pointer that starts at the address of a[0][0] and iterates through the memory addresses until it reaches the address of a[1][1]. It prints the values pointed to by p as it goes along.

This loop essentially flattens a 2D array into a linear sequence, allowing you to traverse it using a single loop.

Now, let's look at the code using nested for loops:

*/

//The above replaces two for loops and now we can use 1 loop.

for(i = 0; i < 2; i++)
{
    for(j = 0; j < 2; j++)
    {
        printf("%d", arr[i][j]);
    }
}

//Or

for(i = 0; i < 2; i++)
    for(j = 0; j < 2; j++)
        printf("%d", arr[i][j]);



/*

In this code, we have two nested for loops. The outer loop (i) runs through the rows, and the inner loop (j) runs through the columns of the 2D array. It prints the elements of the array arr in a row-wise fashion.

The key difference is in the traversal order:

The pointer-based approach (p) traverses the 2D array linearly, going from the first element to the last element in a single loop.

The nested loop approach (i and j) traverses the 2D array row by row, then column by column.

Both methods achieve the same result of printing all the elements in a 2x2 2D array, but they do it in different orders. The choice between them depends on your specific use case and how you want to access the elements in your program.

*/


#include <stdio.h>

int main()
{
    int arr[3][4] = {{10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}};
    int i, j;
    for(i = 0; i < 3; i++)
    {
        printf("The address of %dth array = %u %u\n", i, arr[i], *(arr+i));
        for(j = 0; j < 4; j ++)
            printf("%d %d",  arr[i][j],  *(*(arr+i)+j) );
    }
    printf("\n");
}

/*

In this loop, you're iterating over the rows of a 2D array arr[3][4].

The goal is to print the addresses of each row.

arr[i]: This expression accesses the i-th row of the 2D array.

In C, when you use arr[i], it gives you a pointer to the first element of that row.

So, arr[i] is equivalent to &arr[i][0], which is the address of the first element of the i-th row.

*(arr+i): This is another way to access the i-th row of the 2D array.

Here, you're using pointer arithmetic.

arr is already a pointer to the beginning of the 2D array, and arr + i calculates the address of the i-th row. This is equivalent to &arr[i][0], just like arr[i].

So, both arr[i] and *(arr+i) effectively give you the same result, which is the address of the i-th row of the 2D array.

Here's how the loop works for each iteration:

When i is 0, it prints the address of the first row: The address of 0th array = 6421984 6421984.

When i is 1, it prints the address of the second row: The address of 1th array = 6422000 6422000.

When i is 2, it prints the address of the third row: The address of 2th array = 6422016 6422016.

Both arr[i] and *(arr+i) yield the same address, which is the starting address of each row in the 2D array.

These addresses are sequential in memory because C stores arrays in contiguous memory locations.

This output demonstrates that the addresses of the rows increase by the size of a row (in this case, the size of a row is 4 integers) as you move from one row to the next.


=======================================
Explanation after adding j loop with pointer:

In this code, you have a 2D array arr[3][4] initialized with values. You're using nested loops to iterate through the rows and columns of this array.

The outer loop (for(i = 0; i < 3; i++)) iterates over the rows of the 2D array, where i represents the row index.

Within the outer loop, you print the addresses of the rows using both arr[i] and *(arr + i). As explained in the previous response, these two expressions yield the same result, which is the address of the i-th row.

After printing the addresses of the rows, you have an inner loop (for (j = 0; j < 4; j++)) that iterates over the columns of each row, where j represents the column index.

Inside the inner loop, you print both the value of the element at arr[i][j] and the value obtained using pointer arithmetic *(*(arr + i) + j). These two expressions also yield the same result, which is the value of the element at the i-th row and j-th column.

Here's a brief overview of what the code does:

It prints the addresses of each row in the 2D array, just as before.
Then, it prints the values of each element in the 2D array, row by row, column by column.

The output of this code will include the addresses of the rows and the values of each element in the 2D array. It will help you see the relationship between the addresses, the elements, and the layout of the 2D array in memory.

===================================

So this, arr[i][j] is same as this: *(*(arr+i)+j) ? one is in subscript notation(which i don't know what it means?) and the other is in pointer notation?

Yes, you're absolutely right. arr[i][j] and *(*(arr + i) + j) are equivalent expressions, but they use different notations. Let's break down both notations:

------------------------------------

arr[i][j] (Subscript Notation):

This is the more common and intuitive way to access elements in a 2D array.

i represents the row index, and j represents the column index.

When you use arr[i][j], you are directly referencing the element at the i-th row and j-th column of the 2D array.

------------------------------------

*(*(arr + i) + j) (Pointer Notation):

This notation involves pointer arithmetic.
arr + i calculates the address of the i-th row of the 2D array.

This is equivalent to &arr[i][0], which is the address of the first element in the i-th row.

*(arr + i) dereferences this address, giving you a pointer to the first element of the i-th row.

*(arr + i) + j calculates the address of the j-th element within the i-th row.

Finally, *(*(arr + i) + j) dereferences this address to obtain the value of the element at the i-th row and j-th column.

Both notations achieve the same result: they allow you to access the elements of a 2D array.

Subscript notation is often preferred for its readability and simplicity, especially when working with multidimensional arrays.

However, pointer notation can be useful in some situations, especially when dealing with dynamic memory allocation or more complex data structures.

In practice, you can use the notation that you find most comfortable and readable for a given situation.

*/












