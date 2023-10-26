#include "main.h"

/**
 * get_endianness - Checks the endianness.
 *
 * Return: 0 for big endian, otherwise 1 for little endian.
 */

int get_endianness(void)
{
	unsigned int num;
	char *c;

	num = 1;
	c = (char *) &num;

	/** for little endian**/

	if (*c == 1)
		return (1);

	/**Otherwise,it's big endian**/
	return (0);
}
