#include "holberton.h"
/**
 * buffer_full - funtion that checks if buffer is full and print if it is
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 */
void buffer_full(char *bff, int *p, int *n_printed)
{
int ch_to_print, y;
if (*p == BUFFER_SIZE - 1)
{
ch_to_print = get_printable_length(buffer);
print(buffer, ch_to_print);
*n_printed += ch_to_print;
*p = 0;
for (y = 0; y < BUFFER_SIZE; y++)
buffer[y] = '\0';
}
}
