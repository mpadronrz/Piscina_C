/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:10:37 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/01 12:47:36 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	sum(int a, int b)
{
	ft_putnbr(a + b);
}

void	substract(int a, int b)
{
	ft_putnbr(a - b);
}

void	multiply(int a, int b)
{
	ft_putnbr(a * b);
}

void	divide(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
}

void	modulo(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
}
