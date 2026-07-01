#include <stdio.h>
/**
 * main - prints number of argument
 * @argc: number of argument
 * @argv: array of arguments
 * Return: 0 on success
 */
int  main(int argc, char *argv[]__attribute__((unused)))
{
	if (argc > 0)
		printf("%d\n", argc - 1);
	return (0);
}
