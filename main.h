#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _strlen(const char *s);
void write_int(int n);
void bin(unsigned int n);
int write_char(char c);
int write_str(char *s);
int check_mode(char c);

#endif
