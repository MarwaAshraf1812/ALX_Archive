#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
* read_textfile - check the code for Holberton School students.
* @filename: file to read and write
* @letters: number of letters to read and write.
* Return: letters printed
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fp;
	char *text;
	size_t value_read;

	if (filename == NULL)
		return (0);

	fp = fopen(filename, "r");

	if (fp == NULL)
		return (0);

	text = (char *) malloc(letters + 1);

	if (text == NULL)
	{
		fclose(fp);
		return (0);
	}
	value_read = fread(text, sizeof(char), letters, fp);

	if (value_read == 0)
	{
		fclose(fp);
		free(text);
		return (0);
	}
	if (write(STDOUT_FILENO, text, value_read) != (ssize_t) value_read)
	{
		fclose(fp);
		free(text);
		return (0);
	}
	fclose(fp);
	free(text);
	return (value_read);
}
