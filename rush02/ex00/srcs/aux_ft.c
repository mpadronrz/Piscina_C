/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:39:01 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/30 18:48:56 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_h.h"

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
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while ('0' <= *str && *str <= '9')
	{
		n = 10 * n + *str - '0';
		str ++;
	}
	return (sign * n);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	position;
	int	size_src;

	size_src = 0;
	while (src[size_src] != '\0')
		size_src ++;
	if (size == 0)
		return (size_src);
	position = 0;
	while (src[position] != '\0' && position < size - 1)
	{
		dest[position] = src[position];
		position ++;
	}
	dest[position] = '\0';
	return (size_src);
}
