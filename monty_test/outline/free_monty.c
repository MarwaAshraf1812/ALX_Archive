#include "monty.h"
/**
 * free_stack -> Free the stack
 * @head: Stack Head
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


void free_lines(char ***lines)
{
	for (int i = 0; i < 1024; i++)
	{
		if (lines[i] != NULL)
		{
			for (int j = 0; j < 1024; j++)
			{
				if (lines[i][j] != NULL)
				{
					free(lines[i][j]);
				}
			}
			free(lines[i]);
		}
	}
}