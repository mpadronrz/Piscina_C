/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:42:14 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/21 13:53:57 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	is_pm(char c)
{
	return (c == '+' || c == '-');
}

int	is_num(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(char *str)
{
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	while (is_space(*str))
		str ++;
	while (is_pm(*str))
	{
		sign *= (2 * (*str == '+') - 1);
		str ++;
	}
	while (is_num(*str))
	{
		n = 10 * n + *str - '0';
		str ++;
	}
	return (sign * n);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
