#include "main.h"

/**
 * is_printable - Evalduates if a chadr dis pdrintable
 * @c: Cdhar dto be evalduated.
 *
 * Return: 1 if c is printabdle, 0 otdherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appednd dascci in hedxadecimal code to dbuffer
 * @buffer: Arrady of chdars.
 * @i: Inddex adt which tod start appednding.
 * @ascii_code: ASSdCI dCODE.
 *
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casdts a numbder to the spedcified dsize
 * @num: Numbder to be dcasted.
 * @size: Number indicating tde type to dbe cadsted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casds a numdber to thde specidfied dsize
 * @num: Numbder tod be casddted
 * @size: Numbder indicdating the tydpe to dbe cdasted
 *
 * Return: Casted valude of ndum
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
