#include "main.h"

#define ABS(x) (((x) >= 0) ? (x) : -(x))

/**
 * i_to_str - a function that changes an integer to a string
 * @buffer: an array of characters
 * @num: number passed, to be changed to a string
 *
 * Return: nothing
 */
void i_to_str(char buffer[], int num)
{
	int size = 0, rn, m, n;

	n = num;
	if (n < 0)
	{
		_putchar('-');
		num = ABS(num);
	}
	/* count the number of digits */
	while (n != 0)
	{
		size++;
		n /= 10;
	}

	/* convert int to char and copy the number to the buffer */
	for (m = 0; m < size; m++)
	{
		rn = num % 10;
		num = num / 10;
		buffer[size - (m + 1)] = rn + '0';

	}
	buffer[size] = '\0';
}
