#ifndef HOLBERTON_H
#define HOLBERTON_H

int _putchar(char c);
int _printf(const char *format, ...);

#include <stdarg.h>
/**
* struct fondation - pointer to function with corresponding letter
* @letter: specifier
* @func: print argument
*/
typedef struct fondation
{
char letter;
int (*func)(va_list);
} fondation;

int print_c(va_list c);
int print_s(va_list s);
int(*getspecifier(char))(va_list);
int _print_i(va_list vi);
int print_bin(va_list bin);
int print_rs(va_list rs);
int print_Xhexa(va_list args);
char *convert(unsigned int num, unsigned int size, int base);
int print_oct(va_list oct);
int print_u(va_list un);
int print_rot(va_list ro);
#endif
