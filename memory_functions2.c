#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @poi: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **poi)
{
	if (poi && *poi)
	{
		free(*poi);
		*poi = NULL;
		return (1);
	}
	return (0);
}
