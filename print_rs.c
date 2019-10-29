#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
* print_rs - prints the reversed string and returns the length of string
* @rs: the list of arguments
* Return: number of printed characters
*/
int print_rs(va_list rs)
{
char *s;
int a = 0, c = 0;
s = va_arg(rs, char *);
if (s[0] == '\0')
{
s = ")llun(";
}
for (a = 0; s[a]; a++)
{
;
}
a--;

for (; a >= 0; a--)
{
_putchar(s[a]);
c++;
}
return (c);
}
