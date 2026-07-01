#include<stdio.h>
/**
 * main - entry point
 *
 * Return: always 0 (success)
 */
int main(void)
{
	int num;
	int alpha;

	for (num = 48; num < 58; num++)
	{
		putchar(num);
	}
	for (alpha = 97; alpha < 103; alpha++)
	{
		putchar(alpha);
	}
	putchar('\n');
	return (0);
}
