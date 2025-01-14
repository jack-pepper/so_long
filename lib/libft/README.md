# Mylibft
![Build Status](https://img.shields.io/badge/build-passing-green)
![License](https://img.shields.io/badge/license-MIT-blue)

## Description
Libft is a project at 42 that involves creating a personal C library by implementing a collection of standard functions from the C standard library, as well as some additional utility functions. As my cursus progresses and new challenges arise, I have decided to expand this library to enhqnce its functionality and versatility by adding additional functions to meet specific project needs or explore some concepts in depth (bitwise operations with LIBBIN, sorting algorithms with LIBSORT...).

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

2. Run make to compile the library libft.a:
   ```bash
   make
   ```

3. Include the library to your project files:
   ```bash
   #include "libft.h"
   ```

## Usage

1. mylibft is designed to be modular, so you can easily add or remove functions and/or libraries depending on your needs.
2. Functions that were part of the libft project at 42 are prefixed with [42].

## Features

### LIBCTYPE (From ctype.h)
- [42] ft_isalpha - Checks if a character is an alphabetic letter (A-Z or a-z).
- [42] ft_isdigit - Checks if a character is a digit (0-9).
- [42] ft_isalnum - Checks if a character is either alphabetic or a digit.
- [42] ft_isascii - Checks if a character is a valid ASCII character.
- ft_isspace - Checks for white-space characters.
- [42] ft_isprint - Checks if a character is printable (including space).
- [42] ft_ispunct - Checks if a character is a punctuation character.
- ft_isupper - Checks if a character is uppercase.
- ft_islower - Checks if a character is lowercase.
- [42] ft_toupper - Converts a lowercase letter to uppercase.
- [42] ft_tolower - Converts an uppercase letter to lowercase.

### LIBSTRING (From string.h)
- [42] ft_strlen - Returns the length of a string (excluding the null terminator).
- [42] ft_memset - Fills a block of memory with a specified value.
- [42] ft_bzero - Sets a block of memory to zero.
- [42] ft_memcpy - Copies a specified number of bytes from one memory location to another.
- [42] ft_memmove - Similar to memcpy, but handles overlapping memory areas safely.
- [42] ft_strlcpy - Copies a string to a destination buffer, ensuring it is null-terminated.
- [42] ft_strlcat - Concatenates two strings, ensuring the result is null-terminated.
- [42] ft_strchr - Finds the first occurrence of a character in a string.
- [42] ft_strrchr - Finds the last occurrence of a character in a string.
- [42] ft_strncmp - Compares two strings up to a specified number of characters.
- [42] ft_memchr - Searches for a character in a block of memory.
- [42] ft_memcmp - Compares two blocks of memory byte by byte.
- [42] ft_strdel - Frees a mallocated string and sets the pointer to null.
- [42] ft_strdup - Creates a copy of a string in dynamically allocated memory.
- [42] ft_strnstr - Finds the first occurrence of a substring in a string, searching up to a specified length.
- ft_strrev - Reverses a string in place.
- ft_strpbrk - Locates the first occurrence in the string s of any of the bytes in the string accept.
- ft_strnopbrk - Locates the first occurrence in the string s of any of the bytes NOT in the string accept.

### LIBSTDLIB (From stdlib.h)
- [42] ft_calloc - Allocates memory for an array and initializes it to zero.
- [42] ft_memdel - (Non-standard) Frees allocated memory and sets the pointer to null. 
- [42] ft_atoi - Converts a string to an integer, handling whitespace and signs.
- ft_atol - Converts a string to a long, handling whitespace and signs.

### LIBUTILS (Additional utility functions)
- [42] ft_itoa - Converts an integer to a string representation.
- [42] ft_putchar_fd - Writes a single character to a file descriptor.
- [42] ft_putstr_fd - Writes a string to a file descriptor.
- [42] ft_putendl_fd - Writes a string followed by a newline to a file descriptor.
- [42] ft_putnbr_fd - Writes an integer as a string to a file descriptor.
- [42] ft_split - Splits a string into an array of substrings, using a delimiter.
- [42] ft_strjoin - Concatenates two strings into a new string.
- [42] ft_strmapi - Applies a function to each character of a string and returns a new string with the results.
- [42] ft_strtrim - Removes leading and trailing whitespace (or specified characters) from a string.
- [42] ft_substr - Extracts a substring from a string, starting at a given position and with a specified length.
- [42] ft_striteri - Applies a function to each character of a string, passing both the character and its index.
- ft_open_file - Opens a file and handles error. Saves some lines.
- ft_read_line - Reads a line from a file descriptor. Saves some lines.

### LIBLIST (Linked lists handling Functions)
- [42] ft_lstnew - Creates a new linked list node with a given content.
- [42] ft_lstadd_front - Adds a new node at the front of a linked list.
- [42] ft_lstsize - Returns the size (number of elements) of a linked list.
- [42] ft_lstlast - Returns the last node in a linked list.
- [42] ft_lstadd_back - Adds a new node at the end of a linked list.
- [42] ft_lstdelone - Deletes a node from a linked list and frees its memory.
- [42] ft_lstclear - Clears a linked list by deleting all its nodes and freeing their memory.
- [42] ft_lstmap - Applies a function to each element in a linked list and returns a new list with the modified elements.
- [42] ft_lstiter.c - Iterates over a linked list and applies a function to each element.

### [42] LIBPRINTF
- ft_printf - Custom version of printf. Handles formatted output and conversion specifiers.
- ft_spec_conv - Handles the conversion of specifiers d, i, u, p, x, X, s, c, % and the flags +, <space>, #).
- conv_num - Handles numerical conversion specifiers (d, i, u).
- conv_hex - Handles hexadecimal notation (p, x, X).
- conv_txt - Handles text (s, c, %).
- ft_itohex -Converts an integer to its hexadecimal representation in string format.
- hex_set_case - Adjusts the case of hexadecimal letters.
- hex_handle_zero - Ensures correct output for zero values in hexadecimal conversions (0x0).
- hex_format_string - Formats hexadecimal string adding prefixes 0x and 0X.
- ft_putchar_fd_count - Outputs a character to a file descriptor and returns the number of characters written.
- ft_putstr_fd_count - Outputs a character to a file descriptor and returns the number of characters written.
- ft_putnbr_fd_count - Outputs an integer as a string to a file descriptor and returns the numbers of characters written.
- ft_put_ui_fd_count - Outputs an unsigned integer as a string to a file descriptor and returns the number of characters written.

### [42] LIBGNL - Get Next Line
- ft_gnl - Reads from a file descriptor and returns one line at a time. 
- read_and_stash - Handles the reading and buffering process until End Of File (EOF) is reached.
- stash_manager - Manages the static buffer stash to preserve the data from previous reads over to the next read.
- seize_line - Extracts and returns the next line from the buffer.
- seize_eof - Handles EOF and returns data in stash if necessary.
- clean_stash - Frees the stash and sets the pointer to null.

### LIBBIN - For bits operations
#### Display
- ft_show_bin - Displays the int num in binary notation.
- ft_get_bin - Gets the int num in binary notation and stores it in an array send in parameter.
- ft_bin_to_char - Displays the binary as an ASCII char.
#### Basic bit operations
- ft_set_bit - Sets the specific bit of num at bit_pos to 1.
- ft_clear_bit - Clears the specific bit of num at bit_pos (sets it to 0).
- ft_toggle_bit - Toggles the specific bit of num at bit_pos (flips between 1 and 0).
- ft_is_bit_set - Checks if the specific bit of num at bit_pos is set (1) or not (0).
#### Counting bits
- ft_count_set_bits - Counts the number of bits set to 1.
- ft_count_clear_bits - Counts the number of bits set to 0.
- ft_first_set_bit_pos - Gets the position of the first bit set to 1.
- ft_highest_set_bit_pos - Gets the position of the most significant bit.
#### Masking bits
- ft_extract_bits - Extracts a subset of bits from a number (from start_bit to end_bit).
- ft_set_bits - Sets a subset of bits in a number (from start_bit to end_bit) to a given value.
- ft_match_bits - Checks if a subset of bits matches a specific value.
#### Shifting and rotating
- ft_rotate_left - Performs a left circular shift (rotates bits left).
- ft_rotate_right - Performs a right circular shift (rotates bits right).
- ft_arithmetic_shift_left - Performs an arithmetic shift left.
- ft_arithmetic_shift_right - Performs an arithmetic shift right.
#### Testing and comparison
- ft_is_power_of_two - Tests if a number is a power of 2.
- ft_are_bits_equal - Tests if two numbers have the same bits set.
#### Utilities
- ft_reverse_bits - Reverses all bits in a number.
- ft_swap_bits - Swaps two bits in a number.
- ft_count_leading_zeros - Counts the leading zeros in a number.
- ft_count_trailing_zeros - Counts the trailing zeros in a number.
- ft_get_parity - Gets the parity of a number (1 if odd number of bits sets, 0 if even).
#### Specialized operations
- ft_pack_two_int - Packs two integers into a single 32-bit value.
- ft_unpack_first_half - Unpacks the first 16 bits of a packed 32-bit value.
- ft_unpack_second_half - Unpacks the second 16 bits of a packed 32-bit value.
#### Custom bit patterns
- ft_create_bitmask - Create a bitmask with n least significant bits set to 1.
- ft_create_range_bitmask - Create a bitmask with bits set to 1 between start_bit and end_bit.

### LIBSORT - Sorting algorithms, utilities and procedures.
- ft_bub_srt - Bubble sort algorithm.
- ft_sel_srt - Select sort algorithm.
- ft_ins_srt - Insert sort algorithm.
- ft_mrg_srt - Merge sort algorithm.
- ft_qck_srt - Quick sort algorithm. (TODO)
- ft_hep_srt - Heap sort algorithm. (TODO)
- ft_rdx_srt - Radix sort algorithm. (TODO)
- ft_cpy_arr_int - Copies size elements of a src array of ints to a dest array of ints.
- ft_rev_arr_int - Reverses an array of int in place.
- ft_swap_ints - Swaps two ints.

## Contributing

Contributions are welcome! If you notice any areas where the implementation can be improved or have suggestions for new features, feel free to contribute. I am always willing to learn.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## Acknowledgments

- Thanks to 42 and to Marvin for being such an inspiration.
