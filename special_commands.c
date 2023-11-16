#include "shell.h"

/**
 * specmds - Check for special commands, such as 'exit' and 'env'
 *
 * @buf: The input buffer
 * @shel: Shell pointer (not used)
 * @av: Argument vector
 *
 * Return: 1 if a special command is found, 0 otherwise.
 */
int specmds(char *buf, char *shel, char *av[])
{
	(void)shel; /* Unused pointer */

	switch (buf[0])
	{
	case 'e':
		/* Check for 'exit' */
		if (buf[1] == 'x' && buf[2] == 'i' && buf[3] == 't' &&
		    (buf[4] == '\0' || buf[4] == ' ' || buf[4] == '\t'))
		{
			return (1);
		}
		break;

	case 'v':
		/* Check for 'env' */
		if (buf[1] == 'n' && buf[2] == 'v' &&
		    (buf[3] == '\0' || buf[3] == ' ' || buf[3] == '\t'))
		{
			current_env(av);
			return (1);
		}
		break;

	default:
		break;
	}

	return (0);
}
