#include "monty.h"

/**
 * main - monty function to implement stacks and queues functionality
 * @ac: number of arguments
 * @av: the arguments
 *
 * Return: 0 on success, 1 on error
*/
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	unsigned int line_count, i;
	int *words_count;
	void (*function)(stack_t **, unsigned int);
	int is_exit;

	is_exit = 0;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		is_exit = 1;
		goto HERE;
	}
	words_count = malloc(1024 * sizeof(int));
	tokenize_file(av[1], &line_count, &words_count);
	for (i = 0; i < line_count && lines[i] != NULL; i++)
	{
		if (lines[i][0][0] == '#')
		{
			continue;
		}
		function = get_function(lines[i][0]);
		if (function == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction\n", (i + 1));
			is_exit = 1;
			goto HERE;
		}
		function(&stack, i + 1);
	}
HERE:
	/* // if (stack != NULL) */
		free_stack(stack);
	printf("stack free'd\n");
	/* // if (lines != NULL)  */
		free_lines(line_count, words_count);
	printf("lines free'd\n");
	/* // if (words_count != NULL) */
		free(words_count);
	printf("words_count free'd\n");
	if (is_exit)
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}


/**
 * get_function -> Executes the opcode
 * @word: Opcode
 * Return:Pointer to the respective function to the provided opcode
*/
void (*get_function(char *word))(stack_t **, unsigned int)
{
	int opcodes_count, i;

	instruction_t opcode[] = {
	{"push", f_push},
	{"pall", f_pall},
	{"pint", f_pint},
	{"pop", f_pop},
	{"swap", f_swap},
	{"add", f_add},
	{"nop", f_nop},
	{"mul", f_mul},
	{"div", f_div},
	{"mod", f_mod},
	{"sub", f_sub},
	{"pchar", f_pchar},
	{"pstr", f_pstr},
	{"rotl", f_rotl},
	{"rotr", f_rotr}
	};

	opcodes_count = 15;
	for (i = 0; i < opcodes_count; i++)
	{
		if (strcmp(opcode[i].opcode, word) == 0)
		{
			return (opcode[i].f);
		}
	}
	return (NULL);
}


/**
 * f_exit - frees the memory and then exists
 * 
*/
void f_exit(stack_t *stack, int *words_count, unsigned int line_count)
{
	if (stack != NULL)
		free_stack(stack);
	
	if (lines != NULL)
		free_lines(line_count, words_count);

	if (words_count != NULL)
		free(words_count);
	exit(EXIT_FAILURE);
}