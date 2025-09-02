/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:32:49 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/01 12:41:25 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	else
		return (ft_strlen(str + 1) + 1);
}

void	ft_putstr(char *str)
{
	if (*str != '\0')
	{
		write(1, str, 1);
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

int	ft_atoi(char *str)
{
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str ++;
	while (*str == '+' || *str == '-')
	{
		sign *= (2 * (*str == '+') - 1);
		str ++;
	}
	while ('0' <= *str && *str <= '9')
	{
		n = 10 * n + *str - '0';
		str ++;
	}
	return (sign * n);
}
