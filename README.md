# _printf
 This is a copy of the printf function defined in the stdio.h header file. The printf is used to write to the standard output(STDOUT) which by default is the screen. The printf function makes use of conversion specifiers in writing different data types to the STDOUT combined with flags characters(#, 0, + etc), length modifiers(h, l, hh, ll etc), field width and precision.

# Dependencies
 This _printf was programmed on ubuntu 20.04.1 LTS machine compiled with gcc version 9.4.0

# Description
 _printf is an example of variadic function(The function accepts variable arguments). The arguments can be accessed using the va_list, va_start, va_arg and va_end macros defined in the header file "stdarg.h". To handle the different format specifiers(also custom format specifiers like R for reverse string and r for rot'13 encryption), different functions were written then combine into one, Like:
* **write_int.c handles format specifier d**
* **write_str.c   ""      ""      ""     s**
* **oct_write.c   ""      ""      ""     o**
* **write_char.c  ""      ""      ""     c**
* **u_int.c       ""      ""      ""     u**
* **precision.c   ""      precision(.)**
and so on for other format specifiers
 
 Function Prototype: int _printf(const char *format, ...);

 Return Value: Number of chars printed

# Example:
 ```
 #include "main.h" /* contains function prototypes and header file*/

  int main(void)
  {
      _printf("%s\n", "Hello World");
      return (0);
  }
 ```
Compile:  
```
$ gcc -Wall -pedantic -Werror -Wextra -std-gnu89 *.c -o hello 
```
## Output
  Hello World

# Authors
* **Musa Oluwamayowa**
* **Musti Babasheshu**

# References & Acknowledgements
* **Linux man page for "printf"**
* **Secrets of printf by Professor Don Colton**
* **Stack overflow**
* **ALX**
