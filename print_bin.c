#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
* print_bin - Converts unsigned int argument to binary
* @bin: The decimal number to be converted
* Return: The number of digits printed
*/
int print_bin(va_list bin)
{
unsigned int n, a = 0, i = 0;
int arr[100];
n = va_arg(bin, int);
if (n < 2)
{
_putchar(n + '0');
a = 1;
}
else if (n >= 2)
{
while (n > 0)
{
arr[i] = n % 2;
n /= 2;
i++;
}
}
while (i--)
{
_putchar(arr[i] + '0');
a++;
}
return (a);
}
