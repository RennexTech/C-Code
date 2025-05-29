/**
 * 
 * Alright, buckle up, because we’re about to get into some mind-blowing string behavior in C. 🧠💥 
 * 
 * You know how when you’re typing stuff on your phone and it’s like 
 * 
 * "Hey, did you mean to type this emoji? 🤔", well, 
 * 
 * in C strings, the null terminator \0 is kinda like that emoji—it’s the “end-of-string” marker that tells C where your string stops. Let's break this down with Gen Z-style commentary and some real-world analogies to help you visualize it. 👾🔥
 * 
 * What the heck is the \0 Null Terminator?
 * 
 * In C, strings are just arrays of characters. But C strings are not fancy objects like in Python or JavaScript, they’re just plain arrays. 
 * 
 * So, to tell C where your string ends (because C doesn’t “know” the length of an array), we use this special character, called the null terminator.
 * 
 * When you type "hello", C actually stores it like this in memory:
 * 
 * ✅ 'h' 'e' 'l' 'l' 'o' '\0'
 * 
 * 
 * 
 * 
 * ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅
 * 
 * Why Does It Matter?
 * 
 * ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅
 * 
 * Imagine you're at a party, and you’re giving a speech, but you didn’t tell people when to clap. 
 * 
 * Without a clear endpoint, your audience is confused and keeps clapping forever. 
 * 
 * That’s what happens in C if you forget the \0. The program can’t know where your string ends, 
 * 
 * so it might accidentally grab extra memory and break things (hello, buffer overflow). 😱
 * 
 * 
 * 
 * 
 * ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅
 * 
 * How Does strcspn() Help Us Remove It?
 * 
 * ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅
 * 
 * Alright, now comes the cool part. 😎 
 * 
 * When you use functions like fgets to get input, you’re often left with an annoying newline (\n) character 
 * 
 * at the end of the string because fgets reads the newline too (but we don’t want it!).
 * 
 * Here’s how you strip that newline (and make it disappear) using strcspn:
 * 
 * userName[strcspn(userName, "\n")] = '\0';
 * 
 * 
 * 
 * 
 * ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅
 * 
 * What’s happening here?
 * 
 * ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅
 * 
 * strcspn(userName, "\n"): This function scans the string userName and returns the index of the first occurrence
 * 
 * of the character \n (the newline).
 * 
 * It’s like telling your program: “Hey, find the first \n in this string.”
 * 
 * userName[strcspn(userName, "\n")] = '\0';: Now, we’re replacing that newline with the null terminator \0. 
 * 
 * So, the string is no longer cluttered with that extra \n at the end. 
 * 
 * Basically: "Forget about the newline, let’s mark the end of the string properly."
 * 
 * 
 * 
 * ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅
 * 
 * Real-Life Analogy: 
 * 
 * ✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅
 * 
 * 
 * Imagine you’re walking into a party, and you’re wearing a hat that you don’t want. 
 * 
 * But you keep walking, not noticing the hat (because it’s behind you). 
 * 
 * Then, your friend tells you, “Hey, that hat’s still on you!” — strcspn() is like that friend. 
 * 
 * It says, "Yo, there’s a newline hanging out at the end of your string!" 
 * 
 * and then you can strip it off by setting the position to \0.
 * 
 * Without strcspn(), the fgets input would look like this:
 *
 * 
 * 
 * ❌ "Nick Nicky\n" becomes ✅ "Nick Nicky\0"
 *
 * The \0 is the OG terminator that marks the end of your string (it’s like saying, “Yo, stop here!”).
 * 
 * strcspn() is the hype friend who helps you find and remove unnecessary characters (like that annoying newline) and replace it with the null terminator. 🎤👑
 * 
 * Without the null terminator, C would be like, "Yo, what’s this string?" — so we always use \0 to make sure it knows when to stop reading.
 * 
 * 
 *    */



#include <stdio.h>
#include <string.h>

int main() {
    char userName[80];

    // Get input from user
    printf("Enter your username: ");
    fgets(userName, sizeof(userName), stdin);

    // Remove the newline if it exists (because fgets includes it)
    userName[strcspn(userName, "\n")] = '\0';  // Strips the newline

    printf("Your username is: %s\n", userName);  // No newline here!
    return 0;
}