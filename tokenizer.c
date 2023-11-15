#include "shell.h"

/**
 * tiktok - Tokenize the input string and execute the command
 *
 * @letter: The string to be tokenized
 * @shel: The shell pointer
 *
 * Return: void
 */
void tiktok(const char *letter, char *shel)
{
	const char *delimtr = " \n";
	char *tok = strdup(letter);
	char *nex_commd = NULL;
	char **next_token = NULL;
	int w;
	int count = 0;

	if (tok == NULL)
	{
		perror("Failed to allocate memory");
		return;
	}
	next_token = (char **)malloc(10 * sizeof(char *));
	if (next_token == NULL)
	{
		perror("memory allocation failed");
		free(tok);
		return;
	}
	nex_commd = strtok(tok, delimtr); /* Tokenize the input */


	for (count = 0; count < 10 && nex_commd != NULL; count++)
	{
		next_token[count] = strdup(nex_commd);
		nex_commd = strtok(NULL, delimtr); /* move to the next token */
	}
	if (count > 0)
	{
		next_token[count] = NULL;
		exeFxn(next_token[0], next_token, shel); /* Execute a function */

		for (w = 0; w < count; w++)
		{
			free(next_token[w]);
		}
	}
	free(next_token);
	free(tok);
}
