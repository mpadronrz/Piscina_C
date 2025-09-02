/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:17:33 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/28 19:20:55 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (*str != '\0')
	{
		ft_putchar(*str);
		ft_putstr(str + 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < -9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(- (nb % 10));
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str != NULL)
	{
		ft_putstr((*par).str);
		ft_putchar('\n');
		ft_putnbr((*par).size);
		ft_putchar('\n');
		ft_putstr((*par).copy);
		ft_putchar('\n');
		par ++;
	}
}
