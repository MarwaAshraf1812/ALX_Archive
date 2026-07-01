#include "3-calc.h"
/**
 * main - performs simple operation
 * @argc: number of arguments
 * @argv: array of argument
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int a, b;
	int (*op_f)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);

	op_f = get_op_func(argv[2]);
	if (!op_f)
	{
		printf("Error\n");
		exit(99);
	}
	printf("%d\n", op_f(a, b));
	return (0);
}
