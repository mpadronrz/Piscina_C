/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:50:14 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/23 22:42:06 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_valid(char *placed, int nb, int new_queen)
{
	int	counter;

	counter = 0;
	while (counter < nb)
	{
		if (placed[counter] - '0' == new_queen)
			return (0);
		counter ++;
	}
	counter = 0;
	while (counter < nb)
	{
		if (placed[counter] - '0' - counter == new_queen - nb)
			return (0);
		counter ++;
	}
	counter = 0;
	while (counter < nb)
	{
		if (placed[counter] - '0' + counter == new_queen + nb)
			return (0);
		counter ++;
	}
	return (1);
}

int	add_queen(char *placed, int nb)
{
	int	new_queen;
	int	number_solutions;

	number_solutions = 0;
	if (nb == 10)
	{
		write(1, placed, 10);
		write(1, "\n", 1);
		return (1);
	}
	new_queen = 0;
	while (new_queen < 10)
	{
		if (is_valid(placed, nb, new_queen))
		{
			placed[nb] = '0' + new_queen;
			number_solutions += add_queen(placed, nb + 1);
			placed[nb] = '\0';
		}
		new_queen ++;
	}
	return (number_solutions);
}

int	ft_ten_queens_puzzle(void)
{
	char	placed[10];

	return (add_queen(placed, 0));
}
