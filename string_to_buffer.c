#include "holberton.h"
/**
 * string_to_buffer - function that Puts a string in the buffer
 * @s: string to put in the buffer
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @num_printed: number of printable characters
 */
void string_to_buffer(char *s, char *bff, int *p, int *num_printed)
{
int y;
for (y = 0; s[y] != '\0'; y++)
{
buffer_full(bff, p, num_printed);
bff[*p] = s[y];
(*p)++;
}
}
