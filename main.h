#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>


/* Functions Prototype */
int _printf(const char *format, ...);
int _strlen(const char *s);
int write_int(int n, int *ptr);
int write_int_long(long int n, int *ptr);
int write_int_short(short int n, int *ptr);
int bin(unsigned int n, int *ptr);
int write_char(char c);
int write_str(char *s);
int check_mode(char c);
void check_func(va_list, char c, int *num_char, int *i);
int write_uint(unsigned int n, int *ptr);
int write_uint_long(unsigned long int n, int *ptr);
int write_uint_short(unsigned short int n, int *ptr);
int octal_write(unsigned int num, int *ptr);
int octal_write_long(unsigned long int num, int *ptr);
int octal_write_short(unsigned short int num, int *ptr);
int hexa_write(unsigned int num, int *ptr);
int hexa_write_long(unsigned long int num, int *ptr);
int hexa_write_short(unsigned short int num, int *ptr);
int hexa_x_write(unsigned int num, int *ptr);
int hexa_x_write_long(unsigned long int num, int *ptr);
int hexa_x_write_short(unsigned short int num, int *ptr);
void check_func2(va_list, char c, int *num_char, int *i);
int str_ascii(char *str);
char *choose_ascii(int i);
int hexa_ulong_write(unsigned long int num, int *ptr);
int wrt_address(void *ptr);
int check_flag(char c);
void check_func_flag(va_list args, char c, char f_spec, int *num_char, int *i);
void length_modifiers(va_list args, char c, int *num_char, int *i, char _c);
void l_modifier(va_list args, char c, int *num_char, int *i, char _c);
void h_modifier(va_list args, char c, int *num_char, int *i, char _c);
#endif
