/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nige@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:06:29 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/06/02 11:39:58 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ASCII_NBR_MAX 127
#define ASCII_PRINTABLE 32
#define NBR_COLUMNS 6
#define TEN 11

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar((nbr % 10) + '0');
}

void	ft_layout_printable_char(int *counter, int ascii_number)
{
	ft_putchar(ascii_number);
	write(1, " - ", 3);
	ft_putnbr(ascii_number);
	ft_putchar(' ');
	if (ascii_number < 100)
		ft_putchar(' ');
	write(1, " |  ", 4);
	if (*counter == NBR_COLUMNS)
	{
		ft_putchar('\n');
		*counter = 0;
	}
}

void	ft_non_printable_char(int *counter, int ascii_number)
{
	char	array[][33] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", \
"BEL", "BS ", "HT ", "LF ", "VT ", "FF ", "CR ", "SO ", "SI ", "DLE", \
"DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM ", "SUB", \
"ESC", "FS ", "GS ", "RS ", "US ", "SPC", "DEL" };

	if (ascii_number == 34)
		ft_putnbr(127);
	else
	{
		ft_putnbr((ascii_number - 1));
		ft_putchar(' ');
	}
	if (ascii_number < TEN)
		ft_putchar(' ');
	ft_putchar('-');
	ft_putchar(' ');
	write(1, &array[(ascii_number - 1)], 3);
	write(1, " |  ", 4);
	if (*counter == NBR_COLUMNS)
	{
		ft_putchar('\n');
		*counter = 0;
	}
}

void	ft_ascii_table(void)
{
	int	ascii_number;
	int	newline_counter;
	int	count;

	ascii_number = ASCII_PRINTABLE;
	newline_counter = 1;
	count = 1;
	write(1, "\n\nNon - printable caracters of the ascii table\n\n", 49);
	while (count <= ASCII_PRINTABLE)
	{
		ft_non_printable_char(&newline_counter, count);
		count++;
		newline_counter++;
	}
	ft_non_printable_char(&newline_counter, 34);
	write(1, "\n\nPrintable caracters of the ascii table\n\n", 42);
	newline_counter = 1;
	while (ascii_number < ASCII_NBR_MAX)
	{
		ft_layout_printable_char(&newline_counter, ascii_number);
		ascii_number++;
		newline_counter++;
	}
	ft_putchar('\n');
}
