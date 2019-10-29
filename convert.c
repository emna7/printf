#include "holberton.h"
/**
* ctoa - function taht converts a character to a string
* @valist: list with next argument
* @buffer: character buffer for printing
* @pos: position in the buffer
* @n_printed: number of printable characters
* @spec: specifier flags
* Return: Always 0
*/
int convert(va_list list, char *bff, int *p, int *num_printed, char *sc)
{
unsigned char c = va_arg(list, int);
(void) sc;
if (c == '\0')
c = ' ';
buffer_full(bff, p, num_printed);
bff[*p] = c;
(*p)++;
return (0);
}
