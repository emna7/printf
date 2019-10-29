#include "holberton.h"
/**
 * string_to_buffer - function that Puts a string in the buffer
 * @s: string to put in the buffer
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 */
void string_to_buffer(char *s, char *buffer, int *p, int *n_printed)
{
int y;
for (y = 0; s[y] != '\0'; y++)
{
buffer_full(buffer, pos, n_printed);
buffer[*p] = s[y];
(*p)++;
}
}
