#include "main.h"

/**
 * print_last_digit - function that prints the last digit
 * @n: parameter
 * Return: returns output
 */

int print_last_digit(int n)
{
	int digit;

	if (n < 0)
		digit = (n % 10) * -1;
	else
		digit = n % 10;
	_putchar(digit + '0');
	return (digit);
}
