#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * print_Xhexa - Converts decimal to uppercase hexadecimal
 * @args: the list of arguments
 *
 * Return: The number of digits printed
 */
int print_Xhexa(va_list args)
{
long int n, t, x = 0, i;
char *num;
unsigned int size = 100;
n = va_arg(args, int);
if (n == 0)
{
_putchar('0');
x = 1;
}
else if (n < 0)
{
_putchar('-');
n = -n;
x = 1;
}
t = n;
while (t != 0)
{
t /= 16;
}
num = convert(n, size, 16);
while (t != 0)
{
t /= 16;
}
num = convert(n, size, 16);
for (i = 0; num[i] != '\0'; i++)
{
_putchar(num[i]);
x++;
}
return (x);
}
