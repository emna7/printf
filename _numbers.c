#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
/**
*_print_i - prints an integer
*@vi: the list of arguments
* Return: number of printed characters
*/
int _print_i(va_list vi)
{
int x, num, div, o, n, count = 0;
n = va_arg(vi, int);
o = n % 10;
n = n / 10;
if (o < 0)
{
n = -n;
o = -o;
_putchar('-');
count++;
}
num = n;
div = 1;
if (num > 0)
{
while ((num / 10) != 0)
{
num = num / 10;
div = div * 10;
}
while (div >= 1)
{
x = n / div;
_putchar(x + '0');
count++;
n = n % div;
div = div / 10;
}
}
_putchar(o + '0');
count++;
return (count);
}

/**
* print_u - Convert a number into an unsigned int and print it
* @un: The number to be converted
* Return: The number of digits printed
*/
int print_u(va_list un)
{
unsigned int number, count = 0, divisor;

number = va_arg(un, int);

if (number == 0)
{
_putchar('0');
count = 1;
}
if (number > 0)
{
for (divisor = 1; (number / divisor) > 9; divisor *= 10)
;
while (divisor != 0)
{
_putchar((number / divisor) + '0');
number %= divisor;
divisor /= 10;
count++;
}
}
return (count);
}

/**
 * print_oct - Converts a decimal number passed to the argument to an octal
 * number
 * @oct: The number to be converted
 * Return: count of digit in octal number
 */
int print_oct(va_list oct)
{
unsigned int number, count = 0, index = 0;
int arr[100];

number = va_arg(oct, int);
if (number < 9)
{
_putchar(number + '0');
count = 1;
}
else if (number >= 9)
{
while (number > 0)
{
arr[index] = number % 8;
number /= 8;
index++;
}
}
while (index--)
{
_putchar(arr[index] + '0');
count++;
}
return (count);
}

/**
* print_c - prints a char and returns 1
* @c: the list of arguments
* Return: number of printed characters
*/
int print_c(va_list c)
{
char ch = (char)va_arg(c, int);
_putchar(ch);
return (1);
}

/**
* print_s - prints a string and returns the length of string
* @s: the list of arguments
* Return: number of printed characters
*/
int print_s(va_list s)
{
char *string;
int i = 0;
string = va_arg(s, char *);
if (string == '\0')
{
string = "(null)";
}
for (i = 0; string[i]; i++)
{
_putchar(string[i]);
}
return (i);
}
