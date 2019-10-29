#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * print_Xhexa - Converts decimal to uppercase hexadecimal
 * @args: the list of arguments
 * Return: The number of digits printed
 */

int print_Xhexa(va_list args)
{
long int number, temp, x = 0, i;
char *num;
unsigned int size = 100;
number = va_arg(args, int);
if (number == 0)
{
_putchar('0');
x = 1;
}
else if (number < 0)
{
_putchar('-');
number = -number;
x = 1;
}
temp = number;
while (temp != 0)
{
temp /= 16;
}
num = convert(number, size, 16);
while (temp != 0)
{
temp /= 16;
}
num = convert(number, size, 16);
for (i = 0; num[i] != '\0'; i++)
{
_putchar(num[i]);
x++;
}
return (x);
}
