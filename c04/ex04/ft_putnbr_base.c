/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:21:31 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/21 13:49:44 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	str_len(char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '+' || base[len] == '-' || is_space(base[len]))
			return (0);
		len ++;
	}
	return (len);
}

int	is_valid(char *base, int len)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (counter1 < len - 1)
	{
		counter2 = counter1 + 1;
		while (counter2 < len)
		{
			if (base[counter1] == base[counter2])
				return (0);
			counter2 ++;
		}
		counter1 ++;
	}
	return (1);
}

void	ft_putnbr_base_valid(int n, char *base, int len)
{
	if (n <= -len)
	{
		ft_putnbr_base_valid(n / len, base, len);
		ft_putnbr_base_valid(- (n % len), base, len);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_valid(-n, base, len);
	}
	else if (n >= len)
	{
		ft_putnbr_base_valid(n / len, base, len);
		ft_putnbr_base_valid(n % len, base, len);
	}
	else
		write(1, &base[n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = str_len(base);
	if (len <= 1 || ! is_valid(base, len))
		return ;
	ft_putnbr_base_valid(nbr, base, len);
}

/*int	main(int argc, char **argv)
{
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}*/
