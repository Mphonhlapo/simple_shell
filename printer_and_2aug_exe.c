#include "shell.h"

/**
 * note - function to use instead of printf
 *
 * @letter: Input prompt to be displayed
 *
 * Return: void
 */
void note(const char *letter)
{
	int leng = 0;

	while (letter[leng] != '\0')
	{
		leng++;
	}

	/* printing to the standard output */
	while (leng > 0)
	{
		write(STDOUT_FILENO, letter, 1);
		letter++;
		leng--;
	}
}

/**
 * execom - Execute a command with arguments
 *
 * @comm: The command to be executed
 * @aug: Array of arguments for the command
 * @shel: Shell pointer
 *
 * Return: void
 */

void execom(const char *comm, char *const aug[], char *shel)
{
	int status;
	pid_t pikin_pid;

	switch (pikin_pid = fork())
	{
		case -1:
			perror("Fork failed");
			return;

		case 0: /* Child process */
			execve(comm, aug, environ);
			perror(shel);
			exit(1);

		default: /* Parent process */
			while (1)
			{
				if (waitpid(pikin_pid, &status, 0) == -1)
					break;
				else if (WIFEXITED(status) || WIFSIGNALED(status))
					break;
			}
	}
}
