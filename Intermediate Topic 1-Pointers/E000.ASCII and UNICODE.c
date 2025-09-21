#include <stdio.h>

int main()
{
    printf("just ask. 😊");
}

/*


https://qr.ae/py3MoF

The above is the quora link.

I was just trying to print an emoji using codeblocks when I realized I don't know what ASCII means and UNICODE, so, I decided to write it down:

How do programming languages understand ASCII?
If you don’t know the basics of computers, bits, bytes etc, you may find this answer confusing. There must be a good indian somewhere teaching this on YouTube.

ASCII

The fundamental character encoding used in most computers.

American Standard Code for Information Interchange.

Character encoding is a method used to represent characters, symbols, and textual information in computers.

I mean, computers only understand binary’s (1 and 0), so we have to map our whole keyboard to numerical codes that the computer can understand. “We map the characters a, b , c, /, ;” to “binary”.

This mapping is what is called character encoding.

So this is the table, check it first then we continue the discussion:


The character 'A' is represented by the numeric value 65 in ASCII, which is 01000001 in binary.

When you type the letter 'A' on your keyboard, the computer's hardware translates that keystroke into the binary representation 01000001, allowing the computer to understand and process the input.

Hex is another format to represent stuff on the computer, but its just a shorter version of binary. “Binary is too verbose”.

Let’s get a bit deeper according to that table, character encoding standard that was introduced in the early days of computing.

It uses 7 bits to represent characters, allowing for a total of 128 unique combinations (2^7 = 128).


The original ASCII table included control characters (0 to 31) and printable characters (32 to 127).

Control characters (0 to 31): These are non-printable characters used for various control functions in computing, such as carriage return, line feed, tab, etc.

Printable characters (32 to 127): These represent the visible characters that you see on the screen, including letters (uppercase and lowercase), numbers, punctuation marks, and special symbols. In ASCII, the 128th combination (1111111 in binary or 127 in decimal) is used for the "DEL" (delete) control character.
ASCII has 128 characters represented by 7 bits, but modern character encodings like Unicode have significantly expanded the number of supported characters to meet the needs of global communication and computing.

So we’ve said ASCII has 33 control characters (0 to 31 including 127) and 95 printable characters (32 to 126).

UNICODE

When you see this one, you should see “emojis” + “many languages” + “many keyboards”. Its the modern encoding scheme, and uses variable-length encoding.


Unicode represents a very large character set, currently supporting over 144,000+ characters, including characters from multiple writing systems, symbols, emojis, and special characters. ASCII allows a total of 128 characters.

ASCII is primarily for representing English characters, but Unicode can represent characters from all writing systems used in the world. It includes characters from various languages, scripts, and symbols, so its multilingual.

Nepal keyboard unicode:


ASCII uses fixed-length encoding, where each character is represented using 7 bits, Unicode uses variable-length encoding, eg the UTF-8, UTF-16, and UTF-32, to accommodate the larger character set. These variable-length encodings allows the representation of characters using a variable number of bytes.

NB: UTF-8 is the most widely used encoding for Unicode coz it efficiently represents characters using a variable number of bytes, allowing for compact representation and multilingual support.


To finalise, ASCII is a simple and limited character encoding standard primarily used for representing characters in the English language.

Unicode is a more comprehensive and universal character encoding standard that supports characters from various languages and scripts, making it suitable for multilingual applications and global communication.

ANSWER:

(YOU WILL GET MORE KNOWLEDGE AND UNDERSTANDING IF YOU DO COMPILER DESIGN)

So, you write your code using human-readable characters (letters, numbers, symbols) to represent the instructions and logic for your program.

Text in the source code file is encoded using a specific character encoding scheme.

Lexical analysis is like breaking down a sentence or paragraph into smaller pieces, or "tokens," to make it easier to understand. During this process, the compiler or interpreter converts the source code into tokens. Tokens are meaningful chunks of the code, like keywords, identifiers, operators, etc. ASCII or UNICODE is used here to map the characters in the source code to their corresponding numerical values.


When you write code, the programming language's lexical analyzer breaks down your code into smaller pieces or "tokens." These tokens can be things like keywords (like "if" or "while"), variable names, numbers, operators.

By breaking down the code into tokens, the programming language can better understand the structure and meaning of your code, just like breaking down a sentence helps you understand its meaning. "The," "quick," "brown," "fox," "jumps," "over," "the," "lazy," and "dog"


Once the source code is converted into tokens, the compiler (or interpreter in the case of interpreted languages) translates those tokens into machine code or intermediate code, a low-level representation of the program.

Machine code is executed by the computer's CPU, , following the instructions represented by the binary values of the machine code. These binary values are ultimately derived from the ASCII representation of the characters in the source code.

Now you know something new. Not perfect, not full of every detail of the inner workings, but good enough. Bye! That's how i see ascii and unicode and all that, can you reall delve deeper than I have ?


===============================

You've provided an excellent explanation of ASCII and Unicode, and I'll try to delve a bit deeper into the concepts while keeping it accessible. Let's explore further:

ASCII (American Standard Code for Information Interchange):

Binary Mapping: You're right; computers only understand binary (1s and 0s). ASCII is a character encoding scheme that maps human-readable characters, like 'A', 'B', '1', and special symbols, to specific binary values. Specifically, it uses 7 bits, which allows for 128 unique combinations (2^7 = 128).

Control and Printable Characters: ASCII divides these 128 characters into two groups. Control characters (0 to 31) represent non-printable characters used for control functions like line breaks and tabulation. Printable characters (32 to 127) encompass the visible characters we see on the screen.

Limited to English: ASCII is primarily designed for representing English characters and lacks support for characters from other languages or symbols like emojis.

Unicode:

Expanding Horizons: Unicode is a more modern and comprehensive character encoding scheme. It supports over 144,000 characters, including characters from multiple languages, scripts, symbols, and emojis. This makes it suitable for multilingual applications and global communication.

Variable-Length Encoding: Unlike ASCII, which uses fixed-length encoding (7 bits per character), Unicode uses variable-length encoding schemes like UTF-8, UTF-16, and UTF-32. This means that characters can be represented using a variable number of bytes. UTF-8 is the most widely used encoding because it efficiently represents characters, allowing for compact storage and multilingual support.

Global Language Support: Unicode goes beyond English and includes characters from various languages, scripts, and symbols. This makes it truly multilingual and universal.

How Programming Languages Use ASCII and Unicode:

Human-Readable Code: When you write code, you use human-readable characters like letters, numbers, and symbols to express your program's logic and instructions.

Character Encoding: The source code is encoded using a specific character encoding scheme, which can be ASCII, UTF-8 (a variant of Unicode), or others. This encoding ensures that your code can be stored and transmitted digitally.

Lexical Analysis: This process is like breaking down a sentence into smaller words. The compiler or interpreter converts your source code into tokens, such as keywords (like "if" or "while"), variable names, numbers, and operators. ASCII or Unicode encoding is used here to map characters to their numerical values.

Translation to Machine Code: After lexical analysis, the compiler translates these tokens into machine code or intermediate code, which is a low-level representation of your program. Machine code is executed by the computer's CPU, and it's ultimately derived from the binary representation of the characters in your source code.

In summary, ASCII and Unicode are fundamental to how computers interpret and process text. ASCII is a simple character encoding suitable for English, while Unicode is a universal encoding scheme that supports a vast array of characters from different languages and scripts. When you write code, it's essential to choose the appropriate character encoding to ensure your program can handle various characters and symbols correctly.


*/
