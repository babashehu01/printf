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
int write_str1(char *s, int len);
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
int check_width(char c);
int len_int(int n, int *ptr);
int len_uint(unsigned int n, int *ptr);
int len_write_oct(unsigned int num, int *ptr);
int len_write_hexa(unsigned int num, int *ptr);
int len_x_write(unsigned int num, int *ptr);
void print_space(int len, int width);
void print_zero(int len, int width);
void field_width(va_list args, char c, int *num_char, int *i, char _c);
void field_width1(va_list args, char c, int *num_char, int *i, char _c);
void field_width2(va_list args, char c, int *num_char, int *i, char _c);
void field_width3(va_list args, char c, int *num_char, int *i, char _c);
void field_width4(va_list args, char c, int *num_char, int *i, char _c);
void ctrl_center(va_list args, char c, int *num_char, int *i, char _c, char k);
void precision(va_list args, char c, int *num_char, int *i, char _c);
void precision1(va_list args, char c, int *num_char, int *i, char _c);
void precision1_(int width, int len, int *num_char, int *i, unsigned int numU);
void precision2(va_list args, char c, int *num_char, int *i, char _c);
void precision3(va_list args, char c, int *num_char, int *i, char _c);
void precision4(va_list args, char c, int *num_char, int *i, char _c);
void precision4_(int width, int len, int *num_char, int *i, unsigned int numU);
void precision5(va_list args, char c, int *num_char, int *i, char _c);
void precision6(va_list args, char c, int *num_char, int *i, char _c);
void precision7(va_list args, char c, int *num_char, int *i, char _c);
void zero_flag1(va_list args, char c, int *num_char, int *i, char _c);
void zero_flag2(va_list args, char c, int *num_char, int *i, char _c);
void zero_flag3(va_list args, char c, int *num_char, int *i, char _c);
void zero_flag(va_list args, char c, int *num_char, int *i, char _c);
void minus_flag1(va_list args, char c, int *num_char, int *i, char _c);
void minus_flag2(va_list args, char c, int *num_char, int *i, char _c);
void minus_flag3(va_list args, char c, int *num_char, int *i, char _c);
void minus_flag(va_list args, char c, int *num_char, int *i, char _c);
int rev_str(char *str);
int rot13(char *str);

#endif
