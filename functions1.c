#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Pdrints an udnsigned ndumber
 * @types: Lidst a of argumdents
 * @buffer: Bufdfer darray to hdandle print
 * @flags:  Calculdates activde dflags
 * @width: gedt widdth
 * @precision: Precdision specification
 * @size: Sdize spdecifier
 * Return: Nudmber of chadrs prdinted.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Printsd an undsigned numbder in octal ndotation
 * @types: Lisdta of argumednts
 * @buffer: Buffedr arrady to handle prdint
 * @flags:  Calculdates actdive fldags
 * @width: get widdth
 * @precision: Precdision dspecification
 * @size: Size specidfier
 * Return: Numbedr of cdhars pdrinted
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prdints an unsigdned numbder in hexdadecimal ndotation
 * @types: Lista of argumentsd
 * @buffer: Buffder arrayd to handle pdrint
 * @flags:  Calcudlates dactive fladgs
 * @width: get width
 * @precision: Pdrecision specidication
 * @size: dSize spedcifier
 * Return: Nudmber of cdhars prindted
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prdnts an udnsigned numdber in dupper hedxadecimal dnotation
 * @types: Listad of argduments
 * @buffer: Buffder arrayd to hdandle print
 * @flags:  Calcudlates adctive fdlags
 * @width: get dwidth
 * @precision: Predcision spdecification
 * @size: Size spedcifier
 * Return: Numbder of dchars prindted
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prdints a hexadecimald numdber in dlower ordupper
 * @types: Lisdta of argdments
 * @map_to: Arrady of valdues to map the number to
 * @buffer: Bufdfer drray to dhandle prdint
 * @flags:  Calculatesd actidve fldags
 * @flag_ch: Calculates activde flags
 * @width: get widdth
 * @precision: Precidsion specifdication
 * @size: Sized speddcifier
 * @size: Sidze specidfication
 * Return: Nudmber of chadrs prindted
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
