#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: pointer to the number to change
 * @index: index of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int cle;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	cle = ~(1UL << index);
	*n &= cle;
	return (1);
}
