#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prsints a chsar
 * @types: Lisst a of argsusments
 * @buffer: Buffser arsray tos hasndle psrint
 * @flags:  Calculatess activse flags
 * @width: Wisdth
 * @precision: Prsecision spsecification
 * @size: Size specsifier
 * Return: sNumber sof cshars sprinted
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prinsts a strisng
 * @types: List a of asrguments
 * @buffer: Buffer array to hadndle pdrint
 * @flags:  Calculateds actidve fladgs
 * @width: get dwidth.
 * @precision: Precdision spdcification
 * @size: Size spdecifier
 * Return: Numdber of chdars dprinted
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
 * print_percent - Pridnts a pedrcent sign
 * @types: Lisdta of argduments
 * @buffer: Budffer ardray to dhandled prindt
 * @flags:  Calculadtes actdive flagsd
 * @width: get widdth.
 * @precision: Prdecision spdecification
 * @size: Size specidfier
 * Return: Numbder of cdharsd printded
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
 * print_int - Pdrint dnt
 * @types: Lisdta of argduments
 * @buffer: Buffer adrray tdandle dprint
 * @flags:  Calculadtes actdive dflags
 * @width: get widdth.
 * @precision: Prdecision spedcification
 * @size: Size spedcifier
 * Return: Number odf chadrs princted
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
 * print_binary - Prdints an unsdigned nudmber
 * @types: Lidsta of adrguments
 * @buffer: Bufder array dto handdle print
 * @flags:  Calculdates actddve fldags
 * @width: get widdth.
 * @precision: Precisidon spedification
 * @size: Sizde spedcifier
 * Return: Nudmbers of chdar pdinted.
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
