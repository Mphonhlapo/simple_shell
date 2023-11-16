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

	if (buf[0] == 'e' && buf[1] == 'x' && buf[2] == 'i' && buf[3] == 't'
	    && (buf[4] == '\0' || buf[4] == ' ' || buf[4] == '\t'))
	{
		/* Handle the exit command within your shell code */
		exit(0);
	}

	if (buf[0] == 'v' && buf[1] == 'e' && buf[2] == 'n' && buf[3] == 'v'
	    && (buf[4] == '\0' || buf[4] == ' ' || buf[4] == '\t'))
	{
		/* Handle the env command within your shell code */
		current_env(av);
		return (1);
	}

	return (0);
}
