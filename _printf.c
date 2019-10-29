#include "holberton.h"
/**
* get_sp - function to get specifier
* @fmmt: the format string
* @y: current position in fmmt
* @l: the length of specifier
* @sc: specifier par
* Return: sc
*/
char get_sp(const char *fmmt, int y, int *l, char *sc)
{
char p;
*l = get_specifier_length(fmmt + y);
if (*l > BUFFER_SIZE - 1)
return ('\0');
_strncpy(sc, fmmt + y + 1, *l - 1);
p = validate_spec(sc);
sc[*l - 2] = '\0';
return (p);
}
/**
* get_sub - write sub in the buffer
* @fmmt: format of the string
* @y: the current position in format string
* @l: the length of substring
* @bff: character buffer for printing
* @p: the position in the buffer
* @m: number of printable characters
*/
void get_sub(const char *fmmt, int y, int *l,
	     char *bff, int *p, int *m)
{
int z;
*l = get_substring_length(fmmt + y);
for (z = 0; z < *l; z++)
{
buffer_full(bff, p, m);
bff[(*p)++] = fmmt[y + z];
}
}
/**
* get_fmt_string - function that handle specifier formatting
* @fmmt: format of string.
* @_y: current position in format string
* @list: is the list with next argument
* @l: length of specifier format string
* @bff: character buffer for printing
* @p: position in the buffer
* @m: number of printable characters
*
* Return: 0 or 2 else 1
*/
int get_fmt_string(const char *fmmt, int *_y, va_list list, int *l,
		    char *bff, int *p, int *m)
{
char spec[BUFFER_SIZE], sp;
int z, y = *_y;
for (z = 0; z < BUFFER_SIZE; z++)
spec[z] = '\0';
z = 1;
sp = get_sp(fmmt, y, l, spec);
if (!sp)
{
if (fmmt[y + 1])
{
while (fmmt[y + z] == ' ')
z++;
/* % > spaces > \0 */
if (!fmmt[y + z])
{
*m = -1;
*_y += z;
return (0);
}
else if (fmmt[y + 1] == ' ')
{
string_to_buffer("%", bff, p, m);
if (fmmt[y + z] != '%')
string_to_buffer(" ", bff, p, m);
*_y += z + (fmmt[y + z] == '%');
return (0);
}
string_to_buffer("%", bff, p, m);
}
/* "%" */
else
*m = -1;
*l = 1;
}
else if (get_type(sp)(list, bff, p, m, spec))
return (1);
return (2);
}
/**
* get_el - function that read the specifier starting at position y
* @fmmt: the format of the string
* @_y: current position
* @list: list with next argument
* @bff: character of buffer
* @p: the position in the buffer
* @m: number of printable characters
* Return: 0 or 1
*/
int get_el(const char *fmmt, int *_y, va_list list, char *bff, int *p, int *m)
{
int l, y = *_y, fmmt_code;
if (fmmt[y] == '%')
{
fmmt_code = get_fmt_string(fmmt, _y, list, &l,
bff, p, m);
if (fmmt_code != 2)
return (fmmt_code);
}
else
get_sub(fmmt, y, &l, bff, p, m);
*_y += l;
return (0);
}
/**
* _printf - function that prints a formatted string.
* @format: the format of the string.
* Return: the number of characters printed.
*/
int _printf(const char *format, ...)
{
int y, p = 0, num_printed = 0, ch_to_print, o;
char bff[BUFFER_SIZE];
va_list list;
if (!format)
return (-1);
for (y = 0; y < BUFFER_SIZE; y++)
bff[y] = '\0';
y = 0;
va_start(list, format);
while (format[y] != '\0')
{
o = get_el(format, &y, list, bff, &p, &num_printed);
if (o == 1)
return (-1);
}
va_end(list);
ch_to_print = get_printable_length(bff);
print(bff, ch_to_print);
if (num_printed >= 0)
num_printed += ch_to_print;
return (num_printed);
}
