#include "shell.h"

/**
 * current_env - prints the current environments
 *
 * @envn: Pointer to the array of pointers
 *
 * Return: void
 */
void current_env(char *const envn[])
{
	int w = 0;

	/* Loop through environment variables and print them */
	while (envn[w] != NULL)
	{
		note(envn[w]);
		note("\n");
		w++;
	}
}
