/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:09:35 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/03 01:40:19 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_h.h"

void	ft_putstr(char *str)
{
	if (*str != '\0')
	{
		write(1, str, 1);
		ft_putstr(str + 1);
	}
}

void	ft_putstrnl(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	position;

	position = 0;
	while (src[position] != '\0')
	{
		dest[position] = src[position];
		position ++;
	}
	dest[position] = src[position];
	return (dest);
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
