#include "shell.h"

/**
 * interact_md - interactive mode functionality
 *
 * @shel: Shell pointer
 * @av: Argument vector
 *
 * Return: void.
 */
void interact_md(char *shel, char *av[])
{
	char *buf = NULL;
	size_t t = 0;

	for (;;)
	{
		note("$ "); /* Print the prompt */

		if (getline(&buf, &t, stdin) == -1)
		{
			free(buf);
			exit(0);
		}

		else if (specmds(buf, shel, av))
		{
			free(buf);
			exit(0);
		}

		tiktok(buf, shel);
	}
}

/**
 * non_interact_md - non-interactive mode functionality
 *
 * @shel: Shell pointer
 * @av: Argument vector
 *
 * Return: void
 */
void non_interact_md(char *shel, char *av[])
{
	char *buf = NULL;
	size_t t = 0;

	for (;;)
	{
		if (getline(&buf, &t, stdin) != -1)
		{
			if (specmds(buf, shel, av))
			{
				free(buf);
				exit(0);
			}
			tiktok(buf, shel);
		}
		else
		{
			break;
		}
	}
	free(buf);
}
