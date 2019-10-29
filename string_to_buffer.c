#include "holberton.h"

/**
 * string_to_buffer - function that Puts a string in the buffer
 * @s: string to put in the buffer
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 */
void string_to_buffer(char *s, char *buffer, int *pos, int *n_printed)
{
int i;
for (i = 0; s[i] != '\0'; i++)
{
buffer_full(buffer, pos, n_printed);
buffer[*pos] = s[i];
(*pos)++;
}
}
