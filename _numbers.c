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
int x, bit, d, o, n, c = 0;
n = va_arg(vi, int);
o = n % 10;
n = n / 10;
if (o < 0)
{
n = -n;
o = -o;
_putchar('-');
c++;
}
bit = n;
d = 1;
if (bit > 0)
{
while ((bit / 10) != 0)
{
bit = bit / 10;
d = d * 10;
}
while (d >= 1)
{
x = n / d;
_putchar(x + '0');
c++;
n = n % d;
d = d / 10;
}
}
_putchar(o + '0');
c++;
return (c);
}
/**
* print_u - Convert a number into an unsigned int and print it
* @un: The number to be converted
*
* Return: The number of digits printed
*/
int print_u(va_list un)
{
unsigned int num, c = 0, div;

num = va_arg(un, int);

if (num == 0)
{
_putchar('0');
c = 1;
}
if (num > 0)
{
for (div = 1; (num / div) > 9; div *= 10)
;
while (div != 0)
{
_putchar((num / div) + '0');
num %= div;
div /= 10;
c++;
}
}
return (c);
}

/**
 * print_oct - Converts a decimal num passed to the argument to an octal
 * num
 * @oct: The num to be converted
 * Return: c of digit in octal num
 */
int print_oct(va_list oct)
{
unsigned int num, c = 0, index = 0;
int arr[100];

num = va_arg(oct, int);
if (num < 9)
{
_putchar(num + '0');
c = 1;
}
else if (num >= 9)
{
while (num > 0)
{
arr[index] = num % 8;
num /= 8;
index++;
}
}
while (index--)
{
_putchar(arr[index] + '0');
c++;
}
return (c);
}

/**
* print_c - prints a char and returns 1
* @c: the list of arguments
* Return: num of printed characters
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
* Return: num of printed characters
*/
int print_s(va_list s)
{
char *string;
int i = 0;
string = va_arg(s, char *);
if (string == NULL)
{
string = "(null)";
}
for (i = 0; string[i]; i++)
{
_putchar(string[i]);
}
return (i);
}
