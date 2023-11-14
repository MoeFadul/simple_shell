#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@z: pointer to the memory area
 *@y: byte to fill *z with
 *@x: amount of bytes to be filled
 *Return: (z) a pointer to the memory area z
 */
char *_memset(char *z, char y, unsigned int x)
{
	unsigned int i;

	for (i = 0; i < x; i++)
		z[i] = y;
	return (z);
}

/**
 * ffree - frees a string of strings
 * @ss: string of strings
 */
void ffree(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @poi: pointer to previous malloc'ated block
 * @first_s: byte size of previous block
 * @second_s: byte size of new block
 *
 * Return: pointer to block name.
 */
void *_realloc(void *poi, unsigned int first_s, unsigned int second_s)
{
	char *p;

	if (!poi)
		return (malloc(second_s));
	if (!second_s)
		return (free(poi), NULL);
	if (second_s == first_s)
		return (poi);

	p = malloc(second_s);
	if (!p)
		return (NULL);

	first_s = first_s < second_s ? first_s : second_s;
	while (first_s--)
		p[first_s] = ((char *)poi)[first_s];
	free(poi);
	return (p);
}
