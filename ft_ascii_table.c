/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nige@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:06:29 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/06/02 16:30:58 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ASCII_NBR_MAX 127
#define ASCII_PRINTABLE 33
#define NBR_COLUMNS 6
#define TEN 11
#define STRINGSIZE 103
#define ASCII_DEL 34
#define DEL 127

void	ft_ascii_table(void);
void	ft_printable_ascii(int *column_counter, int ascii_number);
void	ft_non_printable_ascii(int *column_counter, int ascii_number);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);

/**
*	main function calls two functions and prints two tables 
*	non-printable and printable caracters of the ascii table
*/

void	ft_ascii_table(void)
{
	int	ascii_number;
	int	column_counter;

	ascii_number = 1;
	column_counter = 1;
	write(1, "\n\nNon - printable caracters of the ascii table\n\n", 49);
	while (ascii_number < ASCII_PRINTABLE)
	{
		ft_non_printable_ascii(&column_counter, ascii_number);
		ascii_number++;
		column_counter++;
	}
	ft_non_printable_ascii(&column_counter, ASCII_DEL);
	write(1, "\n\nPrintable caracters of the ascii table\n\n", 42);
	column_counter = 1;
	ascii_number = ASCII_PRINTABLE - 1;
	while (ascii_number < ASCII_NBR_MAX)
	{
		ft_printable_ascii(&column_counter, ascii_number);
		ascii_number++;
		column_counter++;
	}
	ft_putchar('\n');
}

/**
*	Prints to screen the printable caracters
*/

void	ft_printable_ascii(int *column_counter, int ascii_number)
{
	ft_putchar(ascii_number);
	write(1, " - ", 3);
	ft_putnbr(ascii_number);
	ft_putchar(' ');
	if (ascii_number < 100)
		ft_putchar(' ');
	write(1, " |  ", 4);
	if (*column_counter == NBR_COLUMNS)
	{
		ft_putchar('\n');
		*column_counter = 0;
	}
}

/**
*	Prints to screen the symbols of non printable caracters
*/

void	ft_non_printable_ascii(int *column_counter, int ascii_number)
{
	int		index;
	char	char_symbol [STRINGSIZE];

	index = 0;
	while ((index++) < STRINGSIZE)
		char_symbol[index] = ("  NULSOHSTXETXEOTENQACKBELBS HT LF VT FF CR SO SI \
DLEDC1DC2DC3DC4NAKSYNETBCANEM SUBESCFS GS RS US    DEL")[index];
	if (ascii_number == ASCII_DEL)
		ft_putnbr(DEL);
	else
		ft_putnbr((ascii_number - 1));
	if (ascii_number < ASCII_DEL)
		ft_putchar(' ');
	ascii_number = ascii_number * 3;
	if ((ascii_number / 3) < TEN)
		ft_putchar(' ');
	write(1, "- ", 2);
	write(1, &char_symbol[(ascii_number -1)], 3);
	write(1, " |  ", 4);
	if (*column_counter == NBR_COLUMNS)
	{
		ft_putchar('\n');
		*column_counter = 0;
	}
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
