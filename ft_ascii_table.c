/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nige@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:06:29 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/06/02 15:29:23 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ASCII_NBR_MAX 127
#define ASCII_PRINTABLE 32
#define NBR_COLUMNS 6
#define TEN 11
#define STRINGSIZE 103

void	ft_ascii_table(void);
void	ft_printable_ascii(int *counter, int ascii_number);
void	ft_non_printable_ascii(int *counter, int ascii_number);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);

void	ft_ascii_table(void)
{
	int	ascii_number;
	int	newline_counter;
	int	counter;

	ascii_number = ASCII_PRINTABLE;
	newline_counter = 1;
	counter = 1;
	write(1, "\n\nNon - printable caracters of the ascii table\n\n", 49);
	while (counter <= ASCII_PRINTABLE)
	{
		ft_non_printable_ascii(&newline_counter, counter);
		counter++;
		newline_counter++;
	}
	ft_non_printable_ascii(&newline_counter, 34);
	write(1, "\n\nPrintable caracters of the ascii table\n\n", 42);
	newline_counter = 1;
	while (ascii_number < ASCII_NBR_MAX)
	{
		ft_printable_ascii(&newline_counter, ascii_number);
		ascii_number++;
		newline_counter++;
	}
	ft_putchar('\n');
}

void	ft_printable_ascii(int *counter, int ascii_number)
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

void	ft_non_printable_ascii(int *counter, int ascii_number)
{
	char array[STRINGSIZE];	
	int i;

	i = 0;

	while ((i++) < STRINGSIZE)
		array[i] = ("  NULSOHSTXETXEOTENQACKBELBS HT LF VT FF CR SO SI \
DLEDC1DC2DC3DC4NAKSYNETBCANEM SUBESCFS GS RS US    DEL")[i];


	if (ascii_number == 34)
		ft_putnbr(127);
	else
	{
		ft_putnbr((ascii_number - 1));
		ft_putchar(' ');
	}
	ascii_number = ascii_number * 3;
	if ((ascii_number / 3) < TEN)
		ft_putchar(' ');
	write(1, "- ", 2);
	write(1, &array[(ascii_number -1)], 3);
	write(1, " |  ", 4);
	if (*counter == NBR_COLUMNS)
	{
		ft_putchar('\n');
		*counter = 0;
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
