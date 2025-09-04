/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:29:44 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/03 16:26:37 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_h.h" 

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

char	*copy_chars(char **splited, char *str, char *charset, int i)
{
	int	j;

	j = 0;
	while (!(is_separator(*str, charset)))
	{
		splited[i][j] = *str;
		j ++;
		str ++;
	}
	splited[i][j] = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**splited;
	int		num;
	int		i;

	i = 0;
	num = split_num(str, charset);
	splited = malloc((num + 1) * sizeof(char *));
	if (!(splited))
		return (NULL);
	while (i < num)
	{
		while (is_separator(*str, charset))
			str ++;
		splited[i] = malloc(count_size(str, charset) + 1);
		if (!(splited[i]))
			return (free_split(splited, i));
		str = copy_chars(splited, str, charset, i);
		i ++;
	}
	splited[i] = NULL;
	return (splited);
}
