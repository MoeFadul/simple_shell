#include "shell.h"

/**
 * _strcpy - copies a string
 * @dst: destination
 * @soc: source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dst, char *soc)
{
	int i = 0;

	if (dst == soc || soc == 0)
		return (dst);
	while (soc[i])
	{
		dst[i] = soc[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

/**
 * _strdup - duplicates a string
 * @stg: string to duplicate
 *
 * Return: pointer to duplicated string
 */
char *_strdup(const char *stg)
{
	int length = 0;
	char *ret;

	if (stg == NULL)
		return (NULL);
	while (*stg++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--stg;
	return (ret);
}

/**
 *_puts - prints an input string
 *@stg: string to be printed
 *
 * Return: Nothing
 */
void _puts(char *stg)
{
	int i = 0;

	if (!stg)
		return;
	while (stg[i] != '\0')
	{
		_putchar(stg[i]);
		i++;
	}
}

/**
 * _putchar - writes the character a to stdout
 * @a: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char a)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (a != BUF_FLUSH)
		buf[i++] = a;
	return (1);
}
