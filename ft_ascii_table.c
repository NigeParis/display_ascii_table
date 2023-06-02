/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nige@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:06:29 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/06/02 18:37:10 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ASCII_NBR_MAX 126
#define PRINTABLE_CHAR 32
#define NBR_COLUMNS 6
#define STRINGSIZE 103
#define ASCII_DEL 34
#define DEL 127

void	ft_ascii_table(void);
void	ft_print_printable_ascii(int *column_nbr, int current_char);
void	ft_print_non_printable_ascii(int *column_nbr, int current_char);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);

/**
*	main function calls two functions and prints two tables 
*	non-printable and printable caracters of the ascii table
*/

void	ft_ascii_table(void)
{
	int	current_char;
	int	column_counter;

	current_char = 0;
	column_counter = 1;
	write(1, "\n\nNon - printable caracters of the ascii table\n\n", 49);
	while (current_char < PRINTABLE_CHAR)
	{
		ft_print_non_printable_ascii(&column_counter, (current_char));
		current_char++;
		column_counter++;
	}
	ft_print_non_printable_ascii(&column_counter, ASCII_DEL);
	write(1, "\n\nPrintable caracters of the ascii table\n\n", 42);
	column_counter = 1;
	current_char = PRINTABLE_CHAR;   /**/
	while (current_char  <= ASCII_NBR_MAX)
	{
		ft_print_printable_ascii(&column_counter, current_char);
		current_char++;
		column_counter++;
	}
	ft_putchar('\n');
}

/**
*	Prints to screen the printable caracters
*/

void	ft_print_printable_ascii(int *column_nbr, int current_char)
{
	ft_putchar((current_char));
	write(1, " - ", 3);
	ft_putnbr((current_char));
	ft_putchar(' ');
	if ((current_char) < 'd')
		ft_putchar(' ');
	write(1, " |  ", 4);
	if (*column_nbr == NBR_COLUMNS)
	{
		ft_putchar('\n');
		*column_nbr = 0;
	}
}

/**
*	Prints to screen the symbols of non printable caracters
*/

void	ft_print_non_printable_ascii(int *column_nbr, int current_char)
{
	int		index;
	char	char_symbol [STRINGSIZE];

	index = 0;
	while ((index++) < STRINGSIZE)
		char_symbol[index] = ("   NULSOHSTXETXEOTENQACKBELBS HT LF VT FF CR SO SI \
DLEDC1DC2DC3DC4NAKSYNETBCANEM SUBESCFS GS RS US    DEL")[index];
	if ((current_char) == ASCII_DEL)
		ft_putnbr(DEL);
	else
		ft_putnbr(current_char);
	if (current_char < ASCII_DEL)
		ft_putchar(' ');
	if (current_char < 10)
		ft_putchar(' ');
	current_char = (current_char + 1) * 3;
	write(1, "- ", 2);
	write(1, &char_symbol[current_char], 3);
	write(1, " |  ", 4);
	if (*column_nbr == NBR_COLUMNS)
	{
		ft_putchar('\n');
		*column_nbr = 0;
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
