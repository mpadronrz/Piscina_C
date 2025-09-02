/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:54:15 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/31 20:36:59 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_h.h" 

char	*remove_zeros(char *num)
{
	while (*num == '0')
		num ++;
	return (num);
}

void	print_small_num(int n, char **dict)
{
	if (n <= 20)
		ft_putstr(dict[n]);
	else if (n < 100)
	{
		ft_putstr(dict[18 + n / 10]);
		if (n % 10 != 0)
		{
			ft_putchar('-');
			print_small_num(n % 10, dict);
		}
	}
	else if (n < 1000)
	{
		print_small_num(n / 100, dict);
		ft_putchar(' ');
		ft_putstr(dict[28]);
		if (n % 100 != 0)
		{
			ft_putstr(" and ");
			print_small_num(n % 100, dict);
		}
	}
}

void	print_num(char *num, char **dict)
{
	int		len;
	int		i;
	char	aux[4];

	num = remove_zeros(num);
	len = ft_strlen(num);
	if (len < 4)
	{
		print_small_num(ft_atoi(num), dict);
		return ;
	}
	i = 3 * (len % 3 == 0) + len % 3;
	ft_strlcpy(aux, num, i + 1);
	print_small_num(ft_atoi(aux), dict);
	ft_putchar(' ');
	ft_putstr(dict[28 + (len - 1) / 3]);
	if (*remove_zeros(num + i))
	{
		ft_putchar(' ');
		print_num(num + i, dict);
	}
}

void	print_num_newline(char *num, char **dict)
{
	print_num(num, dict);
	ft_putchar('\n');
}
