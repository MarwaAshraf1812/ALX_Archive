#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS_PER_LINE 100

char ***lines;

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void (*get_function(char *line))(stack_t **, unsigned int);
void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *top);
void free_lines(char ***lines, unsigned int line_count, int is_last, int *words_count);

int count_lines(FILE* file)
{
    int linesCount = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            linesCount++;
        }
    }
    if (c != '\n' && linesCount > 0) {
        linesCount++;
    }
    rewind(file);
    return (linesCount);
}

char **tokenize_line(char *line, int *numwords)
{
    int len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    char **words = (char**)malloc(MAX_WORDS_PER_LINE * sizeof(char*));
    int wordCount = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        words[wordCount] = strdup(token);
        wordCount++;
        token = strtok(NULL, " ");
    }
    *numwords = wordCount;
    return (words);
}

void tokenize_file(const char* filepath, unsigned int *count, int *line_end, int *wordsCount[]) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    int numwords = 0;
    int linesCount = count_lines(file);
    lines = (char***)malloc(linesCount * sizeof(char**));
    int lineIndex = 0;
    char buffer[1024];
    char last, lastlast;
    last = lastlast = 'a';
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        last = buffer[0];
        char **words = tokenize_line(buffer, &numwords);
        lines[lineIndex] = words;
        (*wordsCount)[lineIndex] = numwords;
        lineIndex++;
    }
    if (last == '\n')
        *line_end = 1;

    *count = linesCount;
    fclose(file);
}

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

void free_lines(char ***lines, unsigned int line_count, int is_last, int words_count[])
{
    if (lines == NULL) {        
        return;
    }
    int i;
	for (i = 0; i < line_count; i++)
	{
        int word_num = words_count[i];
        for (int j = 0; j < word_num; j++)
        {
            if (lines[i][j] != NULL)
            {
                free(lines[i][j]);
            }
        }
        free(lines[i]);
	}
    if (is_last == 1) {
        free(lines[i]);
    }
    free(lines);
}

void (*get_function(char *word))(stack_t **, unsigned int)
{
    instruction_t opcode[] = {
    {"push", f_push},
    {"pall", f_pall}};
    int opcodes_count = 6;
    for (int i = 0; i < opcodes_count; i++)
    {
        if (strcmp(opcode[i].opcode, word) == 0)
        {
            return (opcode[i].f);
        }
    }
    return (NULL);
}

void f_push(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    stack_t *new_node = malloc(sizeof(stack_t));
    new_node->n = 1;
    if (lines != NULL && lines[line_number - 1] != NULL)
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


void f_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *stack_line = *stack;
    while(stack_line != NULL){
        printf("%d\n", stack_line->n);
        stack_line = stack_line->next;
    }
}


int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("not enough arguments.\n");
        return 1;
    }
    unsigned int line_count;
    int is_last = 0;
    int *words_count = malloc(1024 * sizeof(int));
    tokenize_file(av[1], &line_count, &is_last, &words_count);
    stack_t *stack = NULL;
    int check;
    void (*function)(stack_t **, unsigned int);
    for(int i = 0; i < line_count && lines[i] != NULL; i++)
    {
        if (lines[i][0][0] == '#')
        {
            continue;
        }   
        function = get_function(lines[i][0]);
        if (function == NULL)
        {
            printf("wrong opcode.\n");
            break;
        }
        function(&stack, i + 1);
    }
    free_stack(stack);
    free_lines(lines, line_count, is_last, words_count);
    free(words_count);
    return (0);
}