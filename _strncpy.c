/**
 * _strncpy - function that Copies n bytes from src string to dest string
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * @n: Maximum number of bytes to be copied from src to dest
 * Return: Pointer to dest string
 */
char *_strncpy(char *dest, const char *src, int n)
{
int y = 0;
char *p = dest;
while (n-- && (*p++ = *(src + y++)))
;
while (n-- > 0)
*p++ = '\0';
return (dest);
}
