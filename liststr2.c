#include "shell.h"

/**
 * list_len - determines length of linked list
 * @x: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *x)
{
	size_t i = 0;

	while (x)
	{
		x = x->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @hd: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *hd)
{
	list_t *node = hd;
	size_t i = list_len(hd), j;
	char **strs;
	char *str;

	if (!hd || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @x: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *x)
{
	size_t i = 0;

	while (x)
	{
		_puts(convert_number(x->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(x->str ? x->str : "(nil)");
		_puts("\n");
		x = x->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @a: next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char a)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((a == -1) || (*p == a)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @hd: pointer to list head
 * @nd: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *hd, list_t *nd)
{
	size_t i = 0;

	while (hd)
	{
		if (hd == nd)
			return (i);
		hd = hd->next;
		i++;
	}
	return (-1);
}
