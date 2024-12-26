# Mylibft
![Build Status](https://img.shields.io/badge/build-passing-green)
![License](https://img.shields.io/badge/license-MIT-blue)

## Description
Libft is a project at 42 that involves creating a personal C library. The goal is to implement a collection of standard functions from the C standard library, as well as some additional utility functions. As my cursus progresses and new challenges arise, I plan to expand this library by adding additional functions to meet specific project needs or explore a concept in depth. These updates will enhance the functionality and versatility of the library.

**Technologies Used:**
- C

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)

## Installation

To use this project locally:

1. Clone this repository:
   ```bash
   git clone https://github.com/jack-pepper/mylibft.git
   ```

2. Run make to compile the library mylibft.a:
   ```bash
   make
   ```

3. Include the library to your project files:
   ```bash
   #include "mylibft.h"
   ```

## Usage

1. mylibft is designed to be modular, so you can easily add or remove functions and/or libraries depending on your needs.
2. Functions that were part of the libft project at 42 and libraries created as a school project are prefixed with [42].

## Features

### Standard Libraries Implementations

#### LIBCTYPE (From ctype.h)
- [42] ft_isalpha.c - Checks if a character is an alphabetic letter (A-Z or a-z).
- [42] ft_isdigit.c - Checks if a character is a digit (0-9).
- [42] ft_isalnum.c - Checks if a character is either alphabetic or a digit.
- [42] ft_isascii.c - Checks if a character is a valid ASCII character.
- ft_isspace.c - Checks for white-space characters.
- [42] ft_isprint.c - Checks if a character is printable (including space).
- [42] ft_ispunct.c - Checks if a character is a punctuation character.
- ft_isupper.c - Checks if a character is uppercase.
- ft_islower.c - Checks if a character is lowercase.
- [42] ft_toupper.c - Converts a lowercase letter to uppercase.
- [42] ft_tolower.c - Converts an uppercase letter to lowercase.

#### LIBSTRING (From string.h)
- [42] ft_strlen.c - Returns the length of a string (excluding the null terminator).
- [42] ft_memset.c - Fills a block of memory with a specified value.
- [42] ft_bzero.c - Sets a block of memory to zero.
- [42] ft_memcpy.c - Copies a specified number of bytes from one memory location to another.
- [42] ft_memmove.c - Similar to memcpy, but handles overlapping memory areas safely.
- [42] ft_strlcpy.c - Copies a string to a destination buffer, ensuring it is null-terminated.
- [42] ft_strlcat.c - Concatenates two strings, ensuring the result is null-terminated.
- [42] ft_strchr.c - Finds the first occurrence of a character in a string.
- [42] ft_strrchr.c - Finds the last occurrence of a character in a string.
- [42] ft_strncmp.c - Compares two strings up to a specified number of characters.
- [42] ft_memchr.c - Searches for a character in a block of memory.
- [42] ft_memcmp.c - Compares two blocks of memory byte by byte.
- [42] ft_strdel.c - Frees a mallocated string and sets the pointer to null.
- [42] ft_strdup.c - Creates a copy of a string in dynamically allocated memory.
- [42] ft_strnstr.c - Finds the first occurrence of a substring in a string, searching up to a specified length.
- ft_strrev.c - Reverses a string in place.

#### LIBSTDLIB (From stdlib.h)
- [42] ft_calloc.c - Allocates memory for an array and initializes it to zero.
- [42] ft_memdel.c - (Non-standard) Frees allocated memory and sets the pointer to null. 
- [42] ft_atoi.c - Converts a string to an integer, handling whitespace and signs.
- ft_atol.c - Converts a string to a long, handling whitespace and signs.

### LIBUTILS (Additional utility functions)
- [42] ft_itoa.c - Converts an integer to a string representation.
- [42] ft_putchar_fd.c - Writes a single character to a file descriptor.
- [42] ft_putstr_fd.c - Writes a string to a file descriptor.
- [42] ft_putendl_fd.c - Writes a string followed by a newline to a file descriptor.
- [42] ft_putnbr_fd.c - Writes an integer as a string to a file descriptor.
- [42] ft_split.c - Splits a string into an array of substrings, using a delimiter.
- [42] ft_strjoin.c - Concatenates two strings into a new string.
- [42] ft_strmapi.c - Applies a function to each character of a string and returns a new string with the results.
- [42] ft_strtrim.c - Removes leading and trailing whitespace (or specified characters) from a string.
- [42] ft_substr.c - Extracts a substring from a string, starting at a given position and with a specified length.
- [42] ft_striteri.c - Applies a function to each character of a string, passing both the character and its index.

### LIBLIST (Linked lists handling Functions)
- [42] ft_lstnew.c - Creates a new linked list node with a given content.
- [42] ft_lstadd_front.c - Adds a new node at the front of a linked list.
- [42] ft_lstsize.c - Returns the size (number of elements) of a linked list.
- [42] ft_lstlast.c - Returns the last node in a linked list.
- [42] ft_lstadd_back.c - Adds a new node at the end of a linked list.
- [42] ft_lstdelone.c - Deletes a node from a linked list and frees its memory.
- [42] ft_lstclear.c - Clears a linked list by deleting all its nodes and freeing their memory.
- [42] ft_lstmap.c - Applies a function to each element in a linked list and returns a new list with the modified elements.
- [42] ft_lstiter.c - Iterates over a linked list and applies a function to each element.

### [42] LIBPRINTF
- ft_printf.c - Custom version of printf. Handles formatted output and conversion specifiers.
- ft_spec_conv.c - Handles the conversion of specifiers d, i, u, p, x, X, s, c, % and the flags +, <space>, #).
- conv_num.c - Handles numerical conversion specifiers (d, i, u).
- conv_hex.c - Handles hexadecimal notation (p, x, X).
- conv_txt.c - Handles text (s, c, %).
- ft_itohex.c -Converts an integer to its hexadecimal representation in string format.
- hex_set_case.c - Adjusts the case of hexadecimal letters.
- hex_handle_zero.c - Ensures correct output for zero values in hexadecimal conversions (0x0).
- hex_format_string.c - Formats hexadecimal string adding prefixes 0x and 0X.
- ft_putchar_fd_count.c - Outputs a character to a file descriptor and returns the number of characters written.
- ft_putstr_fd_count.c - Outputs a character to a file descriptor and returns the number of characters written.
- ft_putnbr_fd_count.c - Outputs an integer as a string to a file descriptor and returns the numbers of characters written.
- ft_put_ui_fd_count.c - Outputs an unsigned integer as a string to a file descriptor and returns the number of characters written.

### [42] LIBGNL - Get Next Line
- ft_gnl: Reads from a file descriptor and returns one line at a time. 
- read_and_stash: Handles the reading and buffering process until End Of File (EOF) is reached.
- stash_manager: Manages the static buffer stash to preserve the data from previous reads over to the next read.
- seize_line: Extracts and returns the next line from the buffer.
- seize_eof: Handles EOF and returns data in stash if necessary.
- clean_stash: Frees the stash and sets the pointer to null.

### LIBBIN - For bits operations
- ft_show_bin: Displays the int num in binary notation.
- ft_get_bin: Gets the int num in binary notation and stores it in an array send in parameter.
- ft_bin_to_char: Displays the binary as an ASCII char.
// Basic bit operations
- ft_set_bit: Sets the specific bit of num at bit_pos to 1.
- ft_clear_bit: Clears the specific bit of num at bit_pos (sets it to 0).
- ft_toggle_bit: Toggles the specific bit of num at bit_pos (flips between 1 and 0).
- ft_is_bit_set: Checks if the specific bit of num at bit_pos is set (1) or not (0).
// Counting bits
- ft_count_set_bits: Counts the number of bits set to 1.
- ft_count_clear_bits: Counts the number of bits set to 0.
- ft_first_set_bit_pos: Gets the position of the first bit set to 1.
- ft_highest_set_bit_pos: Gets the position of the most significant bit.
// Masking bits
- ft_extract_bits: Extracts a subset of bits from a number (from start_bit to end_bit).
- ft_set_bits: Sets a subset of bits in a number (from start_bit to end_bit) to a given value.
- ft_match_bits: Checks if a subset of bits matches a specific value.
// Shifting and rotating
- ft_rotate_left: Performs a left circular shift (rotates bits left).
- ft_rotate_right: Performs a right circular shift (rotates bits right).
- ft_arithmetic_shift_left: Performs an arithmetic shift left.
- ft_arithmetic_shift_right: Performs an arithmetic shift right.
// Testing and comparison
- ft_is_power_of_two: Tests if a number is a power of 2.
- ft_are_bits_equal: Tests if two numbers have the same bits set.
// Utilities
- ft_reverse_bits: Reverses all bits in a number.
- ft_swap_bits: Swaps two bits in a number.
- ft_count_leading_zeros: Counts the leading zeros in a number.
- ft_count_trailing_zeros: Counts the trailing zeros in a number.
- ft_get_parity: Gets the parity of a number (1 if odd number of bits sets, 0 if even).
// Specialized operations
- ft_pack_two_int: Packs two integers into a single 32-bit value. // To do
- ft_unpack_first_half: Unpacks the first 16 bits of a packed 32-bit value. // To do
- ft_unpack_second_half: Unpacks the second 16 bits of a packed 32-bit value. // To do
// Custom bit patterns
- ft_create_bitmask: Create a bitmask with n least significant bits set to 1.
- ft_create_range_bitmask: Create a bitmask with bits set to 1 between start_bit and end_bit.

## Contributing

Contributions are welcome! If you notice any areas where the implementation can be improved or have suggestions for new features, feel free to contribute. I am always willing to learn.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## Acknowledgments

- Thanks to 42 and to Marvin for being such an inspiration.
