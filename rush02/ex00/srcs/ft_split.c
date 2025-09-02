/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:58:40 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/31 11:11:10 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_h.h"

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset ++;
	}
	return (c == '\0');
}

int	split_num(char *str, char *charset)
{
	int	num;
	int	is_new_split;

	num = 0;
	is_new_split = 1;
	while (*str != '\0')
	{
		if (is_new_split && ! is_separator(*str, charset))
			num ++;
		is_new_split = is_separator(*str, charset);
		str ++;
	}
	return (num);
}

int	count_size(char *str, char *charset)
{
	int	size;

	size = 0;
	while (! is_separator(str[size], charset))
		size ++;
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	char	**splited;
	int		num;
	int		i;
	int		j;

	i = 0;
	num = split_num(str, charset);
	splited = malloc((num + 1) * sizeof(char *));
	while (i < num)
	{
		while (is_separator(*str, charset))
			str ++;
		splited[i] = malloc((count_size(str, charset) + 1) * sizeof(char));
		j = 0;
		while (! is_separator(*str, charset))
		{
			splited[i][j] = *str;
			str ++;
			j ++;
		}
		splited[i][j] = '\0';
		i ++;
	}
	splited[i] = NULL;
	return (splited);
}
