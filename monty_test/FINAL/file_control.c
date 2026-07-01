#include "monty.h"

char ***lines;
/**
 * tokenize_file - tokenizes an entire file and updates global variable lines
 * @filepath: the provided path by the user
 * @count: to be updated with the number of lines in the file
 * @words_num: to be updated array of the number of words per each line
 * Return: nothing.
*/
void tokenize_file(const char *filepath, unsigned int *count, int **words_num)
{
	int numwords, linesCount, lineIndex;
	char buffer[1024];
	char **words;
	FILE *file = fopen(filepath, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filepath);
		exit(EXIT_FAILURE);
	}
	numwords = 0;
	linesCount = count_lines(file);
	lines = (char ***)malloc(linesCount * sizeof(char **));
	lineIndex = 0;
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		words = tokenize_line(buffer, &numwords);
		lines[lineIndex] = words;
		(*words_num)[lineIndex] = numwords;
		lineIndex++;
	}
	*count = linesCount;
	fclose(file);
}

/**
 * tokenize_line - tokenizes the line provided
 * @line: the provided line to be tokenized
 * @numwords: to be updated with the number words
 *
 * Return: an array of the words in the line
*/
char **tokenize_line(char *line, int *numwords)
{
	int len, wordCount;
	char *token, **words;

	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	words = (char **)malloc(MAX_WORDS_PER_LINE * sizeof(char *));
	wordCount = 0;
	token = strtok(line, " ");
	while (token != NULL)
	{
		len = strlen(token);
		words[wordCount] = malloc(len * sizeof(char));
		strcpy(words[wordCount], token);
		wordCount++;
		token = strtok(NULL, " ");
	}
	words[wordCount] = NULL;
	*numwords = wordCount;
	return (words);
}

/**
 * count_lines - counts the number of lines in file
 * @file: the provided file to count the lines from
 * Return: the number of lines in file
*/
int count_lines(FILE *file)
{
	int linesCount;
	int c;

	linesCount = 0;
	while ((c = fgetc(file)) != EOF)
		if (c == '\n')
			linesCount++;

	if (c != '\n' && linesCount > 0)
		linesCount++;

	rewind(file);
	return (linesCount);
}

/**
 * free_lines - frees the global varaible lines
 * @line_count: the number of lines
 * @words_count: array of number of words per line
 * Return: nothing
*/
void free_lines(unsigned int line_count, int *words_count)
{
	int j, word_num;
	unsigned int i;

	if (lines == NULL)
	{
		return;
	}
	for (i = 0; i < line_count; i++)
	{
		printf("\n i is [%d]====", i);
		word_num = words_count[i];
		j = 0;
		while (lines[i][j] != NULL)
		{
			printf("Freeing word at lines[%d][%d]: %s --- ", i, j, lines[i][j]);
			free(lines[i][j]);
			j++;
		}
		/*
		// for (j = 0; j < word_num; j++)
		// {
		// 	if (lines[i][j] != NULL)
		// 	{
		// 		free(lines[i][j]);
		// 	}
		// }
		*/
		free(lines[i]);
	}
			printf("loop done\n");
	free(lines);
}


/**
 * free_stack - frees the stack
 * @top: the pointer to the stack
 * Return: nothing
*/
void free_stack(stack_t *top)
{
	stack_t *next_a;

	while (top != NULL)
	{
		next_a = top->next;
		free(top);
		top = next_a;
	}
}
