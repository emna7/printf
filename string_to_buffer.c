#include "holberton.h"

/**
 * string_to_buffer - function that Puts a string in the buffer
 * @s: string to put in the buffer
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @num_printed: number of printable characters
 */
<<<<<<< HEAD
void string_to_buffer(char *s, char *buffer, int *pos, int *n_printed)
=======
void string_to_buffer(char *s, char *bff, int *p, int *num_printed)
>>>>>>> 39bd1d20d4aadde65770b62b10648354847dcc3a
{
int i;
for (i = 0; s[i] != '\0'; i++)
{
<<<<<<< HEAD
buffer_full(buffer, pos, n_printed);
buffer[*pos] = s[i];
(*pos)++;
=======
buffer_full(bff, p, num_printed);
bff[*p] = s[y];
(*p)++;
>>>>>>> 39bd1d20d4aadde65770b62b10648354847dcc3a
}
}
