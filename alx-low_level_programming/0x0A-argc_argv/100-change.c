#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the minimum number of coins
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: number of coins, 0 if the argument is negative,
 * 1 if nimber of argument is not one
 */
int main(int argc, char *argv[])
{
	int c = 0;
	int n;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	if (argv[1][0] == '-')
	{
		printf("0\n");
		return (0);
	}
	n = atoi(argv[1]);
	c += n / 25;
	n = n % 25;

	c += n / 10;
	n = n % 10;

	c += n / 5;
	n = n % 5;

	c += n / 2;
	n = n % 2;

	c += n / 1;
	printf("%d\n", c);
	return (0);
}
