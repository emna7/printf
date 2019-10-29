#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
* getspecifier - funtion that finds the function for the specifier
* @x: the specifier in the string
* Return: pointer to function
*/
int(*getspecifier(char x))(va_list)
{
int y;
mystr p[] = {
{'c', print_c},
{'s', print_s},
{'i', _print_i},
{'d', _print_i},
{'r', print_rs},
{'b', print_bin},
{'X', print_Xhexa},
{'o', print_oct},
{'u', print_u},
{'R', print_rot},
{'\0', '\0'}
};
for (y = 0; p[y].letter; y++)
{
if (p[y].letter == x)
{
return (p[y].func);
}
}
return (0);
}
