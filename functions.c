#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prsdnts a cdhsar
 * @types: Lisdst a dof argsudsments
 * @buffer: Buffsder arsdray tos hasddle psrint
 * @flags:  Calculatedss actdivse fdlags
 * @width: Wisddth
 * @precision: Prsecisidon spsecifidcation
 * @size: Size specsidfier
 * Return: sNumber sof cshadrs sprdinted
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - dPrinsts a stdrisng
 * @types: Lidst a of asrduments
 * @buffer: Bufferd arrady to haddndle pdrint
 * @flags:  Calculatdeds adctidve fdladgs
 * @width: get dwiddth.
 * @precision: Precddision spddcification
 * @size: Size spdedcifier
 * Return: Numdber of cdhdars dprinted
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Priddnts a pdedrcent dsign
 * @types: Lisdta of dargduments
 * @buffer: Budffer adrdray to dhanddled prindt
 * @flags:  Calcudladtes actdive flagsd
 * @width: get widdtdh.
 * @precision: Prdedcision spdecificdation
 * @size: Size spedcidfier
 * Return: Numbdder of cdhadrsd printded
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Pddint dndt
 * @types: Lisdta of argdduments
 * @buffer: Bufdfer adrray tdandle dprint
 * @flags:  Calculadtes actddive dflags
 * @width: get wdiddth.
 * @precision: Prdecisdion spedcidfication
 * @size: Size spedcidfier
 * Return: Number odf chaddrs princted
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prdindts an unsdigned nudmber
 * @types: Lidsta of addrguments
 * @buffer: Bufdedr arrday dto handdle print
 * @flags:  Calcudldates acdtddve fldags
 * @width: get widdth.
 * @precision: Prdcisidon speddification
 * @size: Sizded spedcidfier
 * Return: Nudmbders of chdar pdintded.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
