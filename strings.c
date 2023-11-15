#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 *
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int longi = 0;

	while (s[longi] != '\0')
	{
		longi++;
	}

	return (longi);
}

/**
 * _strcpy - Copies the string pointed to by src to dest.
 *
 * @dest: The destination buffer.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;

	while (src[l] != '\0')
	{
		dest[l] = src[l];
		l++;
	}

	dest[l] = '\0'; /* Null-terminate the destination buffer */
	return (dest);
}
