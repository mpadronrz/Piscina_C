/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:31:28 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/15 11:34:14 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len_int(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len ++;
	while (n != 0)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

void	ft_putnbr(int n)
{
	int		len;
	int		len_copy;
	int		is_neg_n;
	char	printable[11];

	len = len_int(n);
	len_copy = len;
	is_neg_n = (n < 0);
	if (is_neg_n)
	{
		printable[0] = '-';
		len_copy --;
		printable[len_copy] = '0' - n % 10;
		n /= -10;
	}
	while (len_copy > is_neg_n)
	{
		len_copy --;
		printable[len_copy] = '0' + n % 10;
		n /= 10;
	}
	write(1, &printable, len);
}
