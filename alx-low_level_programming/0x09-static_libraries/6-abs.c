#include "main.h"

/**
 * _abs - function that prints the absolute value of a number
 * @n: paramater to test
 * Return: n if n >= 0, (n * -1) if n < 0
 */

int _abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}
