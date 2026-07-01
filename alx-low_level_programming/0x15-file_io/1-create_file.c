#include "main.h"
#include <string.h>

/**
  * _strlen - length of a string
  * @s: input char
  * Return: length of a string
**/

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
* create_file - check the code for Holberton School students.
* @filename: file to create.
* @text_content: info to write into the file.
* Return: 1 on success, -1 on failure
*/

int create_file(const char *filename, char *text_content)
{
	int fp;
	ssize_t new_letters;
	mode_t permission;

	if (filename == NULL)
		return (-1);

	permission = S_IRUSR | S_IWUSR;

	fp = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permission);

	if (fp == -1)
		return (-1);
	if (text_content)
	{
		new_letters = write(fp, text_content, strlen(text_content));

		if (new_letters == -1)
		{
			close(fp);
			return (-1);
		}
	}
	close(fp);
	return (1);
}
