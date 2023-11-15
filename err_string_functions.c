#include "shell.h"

/**
 *_eputs - prints an input string
 * @stg: string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *stg)
{
	int i = 0;

	if (!stg)
		return;
	while (stg[i] != '\0')
	{
		_eputchar(stg[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @a: character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char a)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (a != BUF_FLUSH)
		buff[i++] = a;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @a: character to print
 * @fd: filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char a, int fd)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buff, i);
		i = 0;
	}
	if (a != BUF_FLUSH)
		buff[i++] = a;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @stg: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *stg, int fd)
{
	int i = 0;

	if (!stg)
		return (0);
	while (*stg)
	{
		i += _putfd(*stg++, fd);
	}
	return (i);
}
