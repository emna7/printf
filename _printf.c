#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
* _printf - A print function
* @format: pointer to a string
* Return: number of chars
**/
int _printf(const char *format, ...)
{
unsigned int x = 0, a = 0;
int (*f)(va_list);
va_list list;
if (format == '\0')
return (-1);
va_start(list, format);
while (format && format[a])
{
if (format[a] != '%')
{
_putchar(format[a]);
x++;
}
else if (format[a] == '\0')
return (x);
else if (format[a] == '%' && format[a + 1] == '\0')
return (-1);
else if (format[a] == '%')
{
f = getspecifier(format[a + 1]);
a += 1;
if (f == '\0')
{
if (format[a] != '%')
{
_putchar(format[a - 1]);
x += 1;
}
_putchar(format[a]);
x += 1;
}
else
x = x + f(list);
}
a++;
}
va_end(list);
return (x);
}
