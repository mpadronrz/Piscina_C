/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:58:40 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/25 20:35:17 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

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
		splited[i] = malloc(count_size(str, charset));
		j = 0;
		while (! is_separator(*str, charset))
		{
			splited[i][j] = *str;
			str ++;
			j ++;
		}
		i ++;
	}
	splited[i] = NULL;
	return (splited);
}

/*int	main(int argc, char **argv)
{
	char	**prueba;
	int	i = 0;
	int	j;

	prueba = ft_split(argv[1], argv[2]);
	while (prueba[i] != NULL)
	{
		printf("%s\n", prueba[i]);
		free(prueba[i]);
		i++;
	}
	free(prueba);
	return (0);
}*/
