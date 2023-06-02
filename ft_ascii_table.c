/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nige@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:06:29 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/06/02 09:07:45 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ASCII_NBR_MAX 127
#define ASCII_NBR_START 32
#define NBR_COLUMNS 6


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


void	ft_layout(int *counter, int ascii_number)
{
		ft_putchar(ascii_number);
		ft_putchar(' ');
		ft_putchar('-');
		ft_putchar(' ');
		ft_putnbr(ascii_number);
		ft_putchar(' ');
		if (ascii_number < 100)
			ft_putchar(' ');
		ft_putchar('|');
		ft_putchar(' ');
		ft_putchar(' ');

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
	
	ascii_number = ASCII_NBR_START;
	newline_counter = 1;
	while(ascii_number < ASCII_NBR_MAX)
	{
		
		ft_layout(&newline_counter, ascii_number);

		ascii_number++;
		newline_counter++;
	}




}


