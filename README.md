*This project has been created as part of the 42 curriculum by yben-abd.*

# ft_printf

> Because ft_putnbr() and ft_putstr() aren't enough

## Description

`ft_printf` is a re-implementation of the C standard library function `printf()`, built as a static library named `libftprintf.a`.

**Goal:** learn how variadic functions work in C (`<stdarg.h>`) by writing a function with the prototype

```c
int ft_printf(const char *format, ...);
```

that reads a format string, prints the matching arguments to standard output using only `write()`, and returns the number of characters printed, like the original `printf()`.

### Supported conversions

| Conversion | Output |
|------------|--------|
| `%c` | a single character |
| `%s` | a string |
| `%p` | a `void *` pointer in hexadecimal (`0x...`) |
| `%d` | a signed decimal number |
| `%i` | a signed integer in base 10 |
| `%u` | an unsigned decimal number |
| `%x` | an unsigned number in lowercase hexadecimal |
| `%X` | an unsigned number in uppercase hexadecimal |
| `%%` | a percent sign |

The bonus part (flags `- 0 . # + space` and field width) is **not** implemented.

### Project structure

```
.
├── Makefile          # builds libftprintf.a with cc -Wall -Wextra -Werror and ar
├── ft_printf.h       # prototypes and includes
├── ft_printf.c       # ft_printf(): format-string walker and conversion dispatcher
├── ft_print_char.c   # %c and %%
├── ft_print_str.c    # %s
├── ft_print_nbr.c    # %d %i and %u
└── ft_print_hex.c    # %x %X and %p
```

## Instructions

### Compilation

```bash
make          # builds libftprintf.a at the root of the repository
make clean    # removes the object files
make fclean   # removes the object files and libftprintf.a
make re       # fclean, then all
```

The library is compiled with `cc -Wall -Wextra -Werror` and archived with `ar rcs`. Running `make` a second time does not recompile or relink anything, because each `.o` file depends on its `.c` file and on `ft_printf.h`.

### Usage

Include the header in your code and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    int n;

    n = ft_printf("Hello %s, you are %d years old (0x%x)\n", "42", 42, 42);
    ft_printf("printed %d characters\n", n);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

To check your output against the original function, print the same format with both `printf` and `ft_printf` and compare the output **and** the return value.

## Algorithm and data structure

### Algorithm: a single pass over the format string

`ft_printf` reads the format string once, from left to right (time complexity O(n) in the length of the format, plus the number of digits printed):

1. If the current character is not `%`, it is written as is.
2. If it is `%` followed by a valid conversion character (`cspdiuxX%`), the conversion character is passed to a dispatcher (`handler`) that reads the next argument with `va_arg` using the right type and calls the matching print function. The index then skips the conversion character.
3. At the end of the string, `va_end` is called and the total count is returned.

A single pass is enough because the mandatory grammar is just `%` followed by one character: there are no flags, width or precision to parse, so no backtracking is needed.

**Dispatch.** The dispatcher is an `if / else if` chain on the conversion character. It was chosen because there are only nine conversions, it stays readable, and it is easy to follow during a defense. Adding a conversion means adding one branch and one print function.

**Argument types.** Each conversion reads the type the caller really passed:

| Conversions | `va_arg` type |
|-------------|---------------|
| `%c` | `int` (a `char` is promoted to `int` when passed through `...`) |
| `%s` | `char *` |
| `%p` | `void *` |
| `%d`, `%i` | `int` |
| `%u`, `%x`, `%X` | `unsigned int` (so `%x` of `-1` prints `ffffffff`) |

**Number printing.** Numbers are converted to text by repeated division, using recursion:

- print the digits of `n / base` first (most significant digits), then print `n % base`;
- base 10 uses `'0' + n % 10`;
- base 16 uses a lookup string, `"0123456789abcdef"` for `%x` and `%p`, and `"0123456789ABCDEF"` for `%X`, so one function serves all hexadecimal conversions.

Recursion avoids a buffer and avoids `malloc`, so there is nothing to free and no leak is possible. The recursion depth is small (at most 10 levels for a 32-bit decimal number, at most 16 for a 64-bit hexadecimal one).

**`%p`.** The pointer is cast to `unsigned long` (wide enough for a 64-bit address) and printed as `0x` followed by the address in lowercase hexadecimal.

**Output.** Every character is written directly with `write(1, ...)`. As the subject requires, the buffer management of the original `printf` is not reimplemented. The trade-off is more system calls than the real `printf`, in exchange for simpler code.

### Data structures

No complex data structure is needed for the mandatory part:

- a `va_list` cursor, passed **by pointer** (`va_list *`) to the dispatcher, so every conversion consumes arguments from the same position in the argument list;
- an `int counter` passed **by pointer** to every print function, which increments it for each character written. At the end, `ft_printf` returns it.

Passing the counter by pointer keeps each print function simple (it returns `void`) and makes the total available in one place without summing return values.

## Resources

### References

- `man 3 printf`: behavior of the function being recoded. [Online version](https://man7.org/linux/man-pages/man3/printf.3.html)
- `man 3 stdarg`: `va_start`, `va_arg`, `va_copy`, `va_end`. [Online version](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- `man 2 write`: system call used for all output. [Online version](https://man7.org/linux/man-pages/man2/write.2.html)
- `man ar`: creating static libraries.
- [Variadic functions in C (cppreference)](https://en.cppreference.com/w/c/variadic)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- 42 `ft_printf` subject, version 12.1.

### Use of AI

AI was used for one thing only:
 
**Understanding concepts:** helping me understand the ideas behind the project (variadic functions, how the format string drives argument reading, etc.).
