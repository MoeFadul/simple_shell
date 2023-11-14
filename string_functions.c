#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @x: string whose length to check
 *
 * Return: int length of string
 */
int _strlen(char *x)
{
	int i = 0;

	if (!x)
		return (0);

	while (*x++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strings.
 * @a1: first string
 * @a2: second string
 *
 * Return: negative if a1 < a2, positive if a1 > a2, zero if a1 == a2
 */
int _strcmp(char *a1, char *a2)
{
	while (*a1 && *a2)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		a1++;
		a2++;
	}
	if (*a1 == *a2)
		return (0);
	else
		return (*a1 < *a2 ? -1 : 1);
}

/**
 * starts_with - checks if book starts with love
 * @love: string to search
 * @book: substring to find
 *
 * Return: address of next char of love or NULL
 */
char *starts_with(const char *love, const char *book)
{
	while (*book)
		if (*book++ != *love++)
			return (NULL);
	return ((char *)love);
}

/**
 * _strcat - concatenates two strings
 * @dst: destination buffer
 * @soc: source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dst, char *soc)
{
	char *ret = dst;

	while (*dst)
		dst++;
	while (*soc)
		*dst++ = *soc++;
	*dst = *soc;
	return (ret);
}
