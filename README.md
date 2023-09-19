This team project is part of the first year curriculum of ALX. _printf replicates the C standard library printf() function.

What you should learn from this project:

How to use git in a team setting
Applying variadic functions to a big project
The complexities of printf
Managing a lot of files and finding a good workflow
Prototype
int _printf(const char *format, ...);

Usage
Prints a string to the standard output, according to a given format
All files were created and compiled on Ubuntu 14.04.4 LTS using GCC 4.8.4 with the command gcc -Wall -Werror -Wextra -pedantic *.c
Returns the number of characters in the output string on success, -1 otherwise
Call it this way: _printf("format string", arguments...) where format string can contain conversion specifiers and flags, along with regular characters
Examples
_printf("Hello, main\n") prints "Hello, Main", followed by a new line
_printf("%s", "Hello") prints "Hello"
_printf("This is a number: %d", 98) prints "This is a number: 98"
Tasks
These are all the tasks of this project, the ones that are completed link to the corresponding files.

0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
Write a function that produces output according to format.
c : converts input into a character
s : converts input into a string
1. Education is when you read the fine print. Experience is what you get if you don't
Handle the following conversion specifiers:
d : converts input into a base 10 integer
i : converts input into an integer
2. Just because it's in print doesn't mean it's the gospel
Create a man page for your function
3. With a face like mine, I do better in print
Handle the following conversion specifiers:
b : the unsigned int argument is converted to binary
4. What one has not experienced, one will never understand in print
Handle the following conversion specifiers:
u : converts the input into an unsigned integer
o : converts the input into an octal number
x : converts the input into a hexadecimal number
X : converts the input into a hexadecimal number with capital letters
5. Nothing in fine print is ever good news
Use a local buffer of 1024 chars in order to call write as little as possible.
6. My weakness is wearing too much leopard print
Handle the following custom conversion specifier:
S : prints the string
Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
7. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print
Handle the following conversion specifier:
p : int input is converted to a pointer address
8. The big print gives and the small print takes away
Handle the following flag characters for non-custom conversion specifiers:
+ : adds a + in front of signed positive numbers and a - in front of signed negative numbers
space : same as +, but adds a space (is overwritten by +)
# : adds a 0 in front of octal conversions that don't begin with one, and a 0x or 0X for x or X conversions
[9. Sarcasm is lost in print]
Handle the following length modifiers for non-custom conversion specifiers:
l : converts d, i, u, o, x, X conversions in short signed or unsigned ints
h : converts d, i, u, o, x, X conversions in long signed or unsigned ints
[10. Print some money and give it to us for the rain forests]
Handle the field width for non-custom conversion specifiers.
[11. The negative is the equivalent of the composer's score, and the print the performance]
Handle the precision for non-custom conversion specifiers.
[12. It's depressing when you're still around and your albums are out of print]
Handle the 0 flag character for non-custom conversion specifiers.
[13. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection]
Handle the - flag character for non-custom conversion specifiers.
14. Print is the sharpest and the strongest weapon of our party
Handle the following custom conversion specifier:
r : prints the reversed string
15. The flood of print has turned reading into a process of gulping rather than savoring
Handle the following custom conversion specifier:
R : prints the rot13'ed string
[16. * ]
All the above options work well together.
Authors
BECKY ISIJOLA - temmyisijola@gmail.com
GODSWILL KALU - messagelordwill@gmail.com`

ChatGPT
Rewrite of the provided description:

Project Overview

This collaborative project is an integral part of the first-year curriculum at ALX. Our task is to create an implementation of the printf function, replicating the functionality found in the C standard library's printf() function.

Key Learning Objectives

As part of this project, participants will gain experience in several important areas:

Team Collaboration with Git: Learning to use Git effectively within a team setting, managing code versioning, and collaborating on a shared codebase.

Variadic Functions: Applying variadic functions in a substantial software project, exploring how to handle variable numbers of arguments.

Understanding printf Complexity: Gaining insights into the intricacies of the printf function, which involves parsing format specifiers and producing formatted output.

File Management and Workflow: Learning to efficiently manage multiple source files and establishing a productive workflow for development.

Function Prototype

c
Copy code
int _printf(const char *format, ...);
Usage

This custom _printf function is designed to print text to the standard output according to a specified format. Key points to note:

All code and files were developed and compiled using GCC 4.8.4 on Ubuntu 14.04.4 LTS, with the following compilation command: gcc -Wall -Werror -Wextra -pedantic *.c.

The function returns the number of characters in the output string upon success and -1 in case of an error.

To use the function, call it with a format string and any necessary arguments in the following manner: _printf("format string", arguments...), where the format string can contain conversion specifiers and formatting flags.

Examples

Here are some examples of how to use the _printf function:

_printf("Hello, main\n") prints "Hello, Main", followed by a newline.

_printf("%s", "Hello") prints "Hello".

_printf("This is a number: %d", 98) prints "This is a number: 98".

Project Tasks

These are the tasks that constitute this project, with links to the corresponding files where they have been completed:

Implement a function that generates output based on the provided format. This includes support for 'c' and 's' conversion specifiers.

Handle additional conversion specifiers: 'd' and 'i' for base-10 integers.

Create a comprehensive man page for your custom _printf function.

Extend conversion specifier support to include 'b' for binary representation.

Further expansion of conversion specifiers to include 'u' for unsigned integers, 'o' for octal numbers, 'x' for lowercase hexadecimal, and 'X' for uppercase hexadecimal.

Optimize output handling by utilizing a local buffer of 1024 characters to minimize calls to the write function.

Implement a custom conversion specifier 'S' to print strings, including non-printable characters in a specified format.

Add support for the 'p' conversion specifier, which converts an integer input into a pointer address.

Handle flag characters (+, space, #) for non-custom conversion specifiers.

Incorporate length modifiers (l and h) for non-custom conversion specifiers.

Manage field width for non-custom conversion specifiers.

Handle precision for non-custom conversion specifiers.

Implement the '0' flag character for non-custom conversion specifiers.

Manage the '-' flag character for non-custom conversion specifiers.

Introduce a custom conversion specifier 'r' to print reversed strings.

Create a custom conversion specifier 'R' to print strings using the rot13 encoding.

Ensure that all of the above options work seamlessly together.

Authors

Abraham Agortey and
Kayode Daramola
