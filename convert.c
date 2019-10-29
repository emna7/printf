#include "holberton.h"

/**
 * convert - function that converts a character to a string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 * @spec: specifier flags
 * Return: Always 0
 */
int convert(va_list valist, char *buffer, int *pos, int *n_printed, char *spec)
{
unsigned char c = va_arg(valist, int);
(void) spec;
if (c == '\0')
c = ' ';
buffer_full(buffer, pos, n_printed);
buffer[*pos] = c;
(*pos)++;
return (0);
}
