#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buff: address of buffer
 * @lenv: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buff, size_t *lenv)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*lenv) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buff, &len_p, stdin);
#else
		r = _getline(info, buff, &len_p);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buff);
			build_history_list(info, *buff, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*lenv = r;
				info->cmd_buff = buff;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buf + i; /* get pointer for return */

		check_chain(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buff: buffer
 * @n: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buff, size_t *n)
{
	ssize_t r = 0;

	if (*n)
		return (0);
	r = read(info->readfd, buff, READ_BUF_SIZE);
	if (r >= 0)
		*n = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @poi: address of pointer to buffer, preallocated or NULL
 * @lent: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **poi, size_t *lent)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *poi;
	if (p && lent)
		s = *lent;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (lent)
		*lent = s;
	*poi = p;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_n: signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_n)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
