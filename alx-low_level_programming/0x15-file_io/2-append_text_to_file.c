#include "main.h"

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
* append_text_to_file - appends text at the end of a file.
* @filename: file to append.
* @text_content: info to append into the file.
* Return: 1 on success, -1 on failure
*/

int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t new_letters;
	int fp;

	if (filename == NULL)
		return (-1);
	fp = open(filename, O_WRONLY | O_APPEND);
	if (fp == -1)
		return (-1);
	if (text_content)
	{
		new_letters = write(fp, text_content, _strlen(text_content));
			if (new_letters == -1)
			{
				close(fp);
				return (-1);
			}
	}
	close(fp);
	return (1);
}
