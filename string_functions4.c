#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @stg: input string
 * @z: delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *stg, char *z)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (stg == NULL || stg[0] == 0)
		return (NULL);
	if (!z)
		z = " ";
	for (i = 0; stg[i] != '\0'; i++)
		if (!is_delim(stg[i], z) && (is_delim(stg[i + 1], z) || !stg[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(stg[i], z))
			i++;
		k = 0;
		while (!is_delim(stg[i + k], z) && stg[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = stg[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @stg: inputed string
 * @z: delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *stg, char z)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (stg == NULL || stg[0] == 0)
		return (NULL);
	for (i = 0; stg[i] != '\0'; i++)
		if ((stg[i] != z && stg[i + 1] == z) ||
		    (stg[i] != z && !stg[i + 1]) || stg[i + 1] == z)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (stg[i] == z && stg[i] != z)
			i++;
		k = 0;
		while (stg[i + k] != z && stg[i + k] && stg[i + k] != z)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = stg[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
