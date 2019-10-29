#include "holberton.h"
/**
* get_sp - function to get specifier
* @fmt: format string
* @i: current position in fmt
* @current_len: length of specifier
* @spec: specifier flags
* Return: a specifier
*/
char get_sp(const char *fmt, int i, int *current_len, char *spec)
{
char sp;
*current_len = get_specifier_length(fmt + i);
if (*current_len > BUFFER_SIZE - 1)
return ('\0');
_strncpy(spec, fmt + i + 1, *current_len - 1);
sp = validate_spec(spec);
spec[*current_len - 2] = '\0';
return (sp);
}

/**
* get_sub - function that write substring into buffer
* @fmt: format string containing strings and specifiers
* @i: current position in format string
* @current_len: length of substring
* @buf: character buffer for printing
* @pos: position in the buffer
* @n_p: the number of printable characters
*/
void get_sub(const char *fmt, int i, int *current_len,
	     char *buf, int *pos, int *n_p)
{
int y;
*current_len = get_substring_length(fmt + i);
for (y = 0; y < *current_len; y++)
{
buffer_full(buf, pos, n_p);
buf[(*pos)++] = fmt[i + y];
}
}
/**
* get_fmt_string - function that handle specifier formatting
* @fmt: format string containing strings and specifiers
* @_i: current position in format string
* @vl: list with next argument
* @current_len: length of specifier format string
* @buf: character buffer for printing
* @pos: position in the buffer
* @n_p: number of printable characters
* Return: 0 or 2, else 1.
*/
int get_fmt_string(const char *fmt, int *_i, va_list vl, int *current_len,
		    char *buf, int *pos, int *n_p)
{
char spec[BUFFER_SIZE], sp;
int y, i = *_i;
for (y = 0; y < BUFFER_SIZE; y++)
spec[y] = '\0';
y = 1;
sp = get_sp(fmt, i, current_len, spec);
if (!sp)
{
if (fmt[i + 1])
{
while (fmt[i + y] == ' ')
y++;
/* % > spaces > \0 */
if (!fmt[i + y])
{
*n_p = -1;
*_i += y;
return (0);
}
else if (fmt[i + 1] == ' ')
{
string_to_buffer("%", buf, pos, n_p);
if (fmt[i + y] != '%')
string_to_buffer(" ", buf,
pos, n_p);
*_i += y + (fmt[i + y] == '%');
return (0);
}
string_to_buffer("%", buf, pos, n_p);
}
/* "%" */
else
*n_p = -1;
*current_len = 1;
}
else if (get_type(sp)(vl, buf, pos, n_p, spec))
return (1);
return (2);
}
/**
* get_el - function that reads the specifier or string starting at position i
* @fmt: format string containing strings and specifiers
* @_i: current position in format string
* @vl: list with next argument
* @buf: character buffer for printing
* @pos: position in the buffer
* @n_p: number of printable characters
* Return: 0 or 1.
*/
int get_el(const char *fmt, int *_i, va_list vl, char *buf, int *pos, int *n_p)
{
int current_len, i = *_i, fmt_code;
if (fmt[i] == '%')
{
fmt_code = get_fmt_string(fmt, _i, vl, &current_len,
 buf, pos, n_p);
if (fmt_code != 2)
return (fmt_code);
}
else
get_sub(fmt, i, &current_len, buf, pos, n_p);
*_i += current_len;
return (0);
}

/**
* _printf - function that prints a formatted string
* @format: format string
* Return:  the number of bytes printed or negative number on error
*/
int _printf(const char *format, ...)
{
int y, pos = 0, n_printed = 0, chars_to_print, ok;
char buffer[BUFFER_SIZE];
va_list valist;
if (!format)
return (-1);
for (y = 0; y < BUFFER_SIZE; y++)
buffer[y] = '\0';
y = 0;
va_start(valist, format);
while (format[y] != '\0')
{
ok = get_el(format, &y, valist, buffer, &pos, &n_printed);
if (ok == 1)
return (-1);
}
va_end(valist);
chars_to_print = get_printable_length(buffer);
print(buffer, chars_to_print);
if (n_printed >= 0)
n_printed += chars_to_print;
return (n_printed);
}
