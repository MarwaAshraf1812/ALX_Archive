#include <stdio.h>
#include <stdlib.h>
/**
 * main - print producet of argument
 * @argc: number of argument
 * @argv: array of argument
 * Return: 0 on success, 1 if not
 */
int main(int argc, char *argv[])
{
	int sum;

	if (argc == 3)
	{
		sum = atoi(argv[1]) * atoi(argv[2]);
		printf("%d\n", sum);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
