#ifndef _SHELL_H_
#define _SHELL_H_

/*system and function calls*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

/* Function prototypes */

void interact_md(char *shel, char *av[]);
void non_interact_md(char *shel, char *av[]);
int specmds(char *buf, char *shel, char *av[]);
void exeFxn(const char *comm, char *const aug[], char *shel);
void tiktok(const char *letter, char *shel);
void execom(const char *comm, char *const aug[], char *shel);
void note(const char *letter);
void current_env(char *const envn[]);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

extern char **environ;

#endif /* SHELL_H */
