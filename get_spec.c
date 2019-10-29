#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
* getspecifier - function for the specifier
* @x: is a character
* Return: pointer to function
*/
int(*getspecifier(char x))(va_list)
{
int i;
fondation p[] = {
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
for (i = 0; p[i].letter; i++)
{
if (p[i].letter == x)
{
return (p[i].func);
}
}
return (0);
}
