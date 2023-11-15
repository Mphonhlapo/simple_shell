#include "shell.h"

/**
 * main - Shell entry point
 *
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 if successful
 */
int main(int ac, char *av[])
{
	char *shel = av[0];

	(void)ac;

	/* Checking if it's an interactive mode */
	if (isatty(STDIN_FILENO))
		interact_md(shel, av);
	else
		non_interact_md(shel, av);

	return (0);
}
