#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * convert - converts decimal number to hexadecimal number
 * @num: number to be converted
 * @size: digits in hexadecimal number
 * @base: base to convert to
 * Return: pointer to hexadecimal
 */
char *convert(unsigned int num, unsigned int size, int base)
{
char num_sys[] = "0123456789ABCDEF";
char buffer[100];
char *ptr;

ptr = &buffer[size];
*ptr = '\0';

do {
*--ptr = num_sys[num % base];
num /= base;
} while (num != 0);
return (ptr);
}

/**
*print_rot - prints the rot13'ed string
*@ro: the arguments list
*Return: number of printed characters
*/
int print_rot(va_list ro)
{
char *s = va_arg(ro, char *);
int i, j, count = 0;
char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
for (i = 0; s[i] != '\0'; i++)
{
j = 0;
while ((alpha[j] != '\0') && (s[i] != alpha[j]))
{
j++;
}
if (s[i] == alpha[j])
{
_putchar(rot[j]);
count++;
}
else if (alpha[j] == '\0')
{
_putchar(s[i]);
count++;
}
}
return (count);
}
