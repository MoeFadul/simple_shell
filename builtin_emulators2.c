#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @stg: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *stg)
{
	char *v, a;
	int ret;

	v = _strchr(stg, '=');
	if (!v)
		return (1);
	a = *v;
	*v = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, stg, -1)));
	*v = a;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @stg: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *stg)
{
	char *v;

	v = _strchr(stg, '=');
	if (!v)
		return (1);
	if (!*++v)
		return (unset_alias(info, stg));

	unset_alias(info, stg);
	return (add_node_end(&(info->alias), stg, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *v = NULL, *a = NULL;

	if (node)
	{
		v = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(v + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *v = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		v = _strchr(info->argv[i], '=');
		if (v)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
