/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:54:15 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/31 20:36:01 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_h.h" 

int	is_valid_small_num(int n, char **dict)
{
	if (n <= 20)
	{
		if (!(dict[n]))
			return (0);
	}
	else if (n < 100)
	{
		if (!(dict[18 + n / 10]))
			return (0);
		if (n % 10 != 0)
			return (is_valid_small_num(n % 10, dict));
	}
	else if (n < 1000)
	{
		if (!(is_valid_small_num(n / 100, dict)))
			return (0);
		if (!(dict[28]))
			return (0);
		if (n % 100 != 0)
		{
			if (!(is_valid_small_num(n % 100, dict)))
				return (0);
		}
	}
	return (1);
}

int	is_valid_num(char *num, char **dict, int len_dict)
{
	int		len;
	int		i;
	char	aux[4];

	num = remove_zeros(num);
	len = ft_strlen(num);
	if (len < 4)
		return (is_valid_small_num(ft_atoi(num), dict));
	i = 3 * (len % 3 == 0) + len % 3;
	ft_strlcpy(aux, num, i + 1);
	if (!(is_valid_small_num(ft_atoi(aux), dict)))
		return (0);
	if (28 + (len - 1) / 3 > len_dict)
		return (0);
	if (!(dict[28 + (len - 1) / 3]))
		return (0);
	if (*remove_zeros(num + i))
		return (is_valid_num(num + i, dict, len_dict));
	return (1);
}
