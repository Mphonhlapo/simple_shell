#include "shell.h"

/**
 * exeFxn - Execute a command with arguments
 *
 * @comm: command to be executed
 * @aug: Array of arguments for the command
 * @shel: Shell pointer
 *
 * Return: void
 */
void exeFxn(const char *comm, char *const aug[], char *shel)
{
	if (access(comm, X_OK) == 0)
	{
		pid_t pikin_pid = fork();

		if (pikin_pid == -1)
		{
			perror("Fork failed");
			return;
		}

		/* The child process */
		else if (pikin_pid == 0)
		{
			execve(comm, aug, NULL);
			perror("command execution failed");
			exit(1);
		}
		else /* The parent process */
		{
			int status;

			waitpid(pikin_pid, &status, 0);
		}
	}
	else
	{
		execom(comm, aug, shel);
	}
}
