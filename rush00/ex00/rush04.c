/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:37:08 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/16 13:07:45 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	first_line(int x)
{
	if (x == 1)
		ft_putchar('A');
	else
	{
		ft_putchar('A');
		while (x > 2)
		{
			ft_putchar('B');
			x --;
		}
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	last_line(int x)
{
	if (x == 1)
		ft_putchar('C');
	else
	{
		ft_putchar('C');
		while (x > 2)
		{
			ft_putchar('B');
			x --;
		}
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	mid_line(int x)
{
	if (x == 1)
		ft_putchar('B');
	else
	{
		ft_putchar('B');
		while (x > 2)
		{
			ft_putchar(' ');
			x --;
		}
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (y == 1 && x >= 1)
		first_line(x);
	else if (y >= 2 && x >= 1)
	{
		first_line(x);
		while (y > 2)
		{
			mid_line(x);
			y--;
		}
		last_line(x);
	}
	else
		write(1, "Error: parameters must be positive.\n", 36);
}
