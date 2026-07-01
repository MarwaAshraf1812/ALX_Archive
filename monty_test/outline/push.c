#include "monty.h"
/**
 * f_push -> Pushe an element to the stack
 * @stack: Stack
 * @line_number: Line Number
*/
void f_push(stack_t **stack, unsigned int line_number)
{
    // (void)line_number;
    stack_t *new_node = malloc(sizeof(stack_t));
    new_node->n = atoi(lines[line_number - 1][1]);
    new_node->next = NULL;
    new_node->prev = NULL;
    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}
/**
 * f_pall -> Print all the values on the stack
 * @stack: Stack
 * @line_number: Line Number
*/
void f_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *stack_line = *stack;
    while(stack_line != NULL){
        printf("%d\n", stack_line->n);
        stack_line = stack_line->next;
    }
}