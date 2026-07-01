#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int value = 0;
	int i = 0, len;

	if (b == NULL)
	{
		return (0);
	}
	len = strlen(b);
	for (i = 0; i < len; i++)
	{
		if (b[i] == '1' || b[i] == '0')
		{
			value =  2 * value + (b[i] - '0');
		}
		else
			return (0);
	}
	return (value);
}
