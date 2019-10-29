/**
 * _strlen - function that Returns the length of a string
 * @s: The string to check
 * Return: The length of the string
 */
int _strlen(char *s)
{
int y;
for (y = 0; s[y] != '\0'; y++)
;
return (y);
