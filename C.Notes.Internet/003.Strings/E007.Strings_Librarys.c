#include <stdio.h>
#include <string.h>

int main()
{
    // Our strings are like words written on pieces of paper.
    // `s1` holds "Nayan". `s2` holds " Khade".
    // We've also set aside a larger piece of paper, `s3`, for a bigger word.
    char s1[] = "Nayan";
    char s2[] = " Khade";
    char s3[54];

    // `strcat()`: The Joiner
    // This is like taping the second piece of paper (`s2`) to the end of the first (`s1`).
    // The `s1` paper now has both words on it, "Nayan Khade".
    // A key detail: C assumes `s1` has enough space to hold both words. If not, you get a `buffer overflow`, which is like trying to write a long word on a small piece of paper.
    puts(strcat(s1, s2));

    // `strlen()`: The Character Counter
    // This is like counting the number of letters on a piece of paper.
    // It's smart enough to know where the word ends, so it doesn't count the invisible `\0` character.
    printf("The Length of s2: %d\n", strlen(s2));

    // `strrev()`: The Reverser (a common, non-standard function)
    // This is like taking your piece of paper and writing the word backward, right on the same paper.
    // The original word is gone, replaced by the reversed version.
    printf("The reversed string s2 is: ");
    puts(strrev(s2));

    // `strcpy()`: The Copier
    // This is like making a photocopy. It copies a word from one piece of paper to another.
    // We're doing something tricky here: we're first joining `s1` and `s2` again, then immediately copying the result to `s3`.
    // Since `s1` was already changed by `strcat`, this is a good example of how function calls can be nested.
    strcpy(s3, strcat(s1, s2));
    puts(s3);

    // `strcmp()`: The Word Sorter
    // This is like a librarian comparing two words to decide which one comes first in the dictionary.
    // It returns:
    // - `0` if the words are the same.
    // - A negative number if the first word comes before the second.
    // - A positive number if the first word comes after the second.
    printf("The strcmp for s1, s2 returned %d\n", strcmp(s1, s2));

    return 0;
}

// Don't just fix it with AI; understand why it broke.