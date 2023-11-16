#include "shell.h"

/**
 * specmds - Checks or special commands, such as 'exit' and 'env'
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
	{
		int i;

		for (i = 0; buf[i] != '\0' && buf[i] != '\t'; i++)
		{
			if (buf[i] != "exit"[i])
				break;
		}

		if (buf[i] == '\0' || buf[i] == '\t')
		{
			/* Handle the exit command */
			return (1);
		}
	}
	break;
	case 'v':
		/* checking for the 'env' command */
		if (buf[1] == 'e' && buf[2] == 'n' &&
		    buf[3] == 'v' && (buf[4] == '\t' || buf[4] == '\0'))
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
