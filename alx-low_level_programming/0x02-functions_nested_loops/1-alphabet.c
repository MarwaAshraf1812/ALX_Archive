#include "main.h"

/**
 * print_alphabet - entry point
 *
 */

void print_alphabet(void)
{
	int  alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
	{
		_putchar(alpha);
	}

	_putchar('\n');
}
