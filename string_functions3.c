#include "shell.h"

/**
 **_strncpy - copies a string
 *@dst: destination string to be copied to
 *@soc: source string
 *@x: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dst, char *soc, int x)
{
	int i, j;
	char *s = dst;

	i = 0;
	while (soc[i] != '\0' && i < x - 1)
	{
		dst[i] = soc[i];
		i++;
	}
	if (i < x)
	{
		j = i;
		while (j < x)
		{
			dst[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dst: first string
 *@soc: second string
 *@x: amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dst, char *soc, int x)
{
	int i, j;
	char *s = dst;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (soc[j] != '\0' && j < x)
	{
		dst[i] = soc[j];
		i++;
		j++;
	}
	if (j < x)
		dst[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@a: string to be parsed
 *@b: character to look for
 *Return: (a) a pointer to the memory area a
 */
char *_strchr(char *a, char b)
{
	do {
		if (*a == b)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}
