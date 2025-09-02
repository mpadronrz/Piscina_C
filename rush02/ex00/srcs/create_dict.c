/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:59:00 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/31 14:36:00 by mumehmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_h.h"

int	is_pow_thsnd(char *list, int len)
{
	if (len % 3 != 1)
		return (0);
	if (*list != '1')
		return (0);
	list ++;
	while (*list)
	{
		if (*list != '0')
			return (0);
		list ++;
	}
	return (1);
}

void	create_dict_sizeone(char **dict, char **list)
{
	int	aux;

	if (**list == '0')
		dict[0] = *(list + 1);
	else
	{
		aux = ft_atoi(*list);
		if (aux != 0)
			dict[aux] = *(list + 1);
	}
}

char	**dict_init(char **list, int *len_dict)
{
	int		max;
	int		i;
	int		len;
	char	**dict;

	max = 0;
	i = 0;
	while (list[i])
	{
		len = ft_strlen(list[i]);
		if (len > max)
			max = len;
		i += 2;
	}
	*len_dict = 28 + (max - 1) / 3;
	dict = malloc((*len_dict + 1) * sizeof(char *));
	if (!(dict))
		return (NULL);
	i = 0;
	while (i < *len_dict + 1)
	{
		dict[i] = NULL;
		i ++;
	}
	return (dict);
}

char	**create_dict(char **list, int *len_dict)
{
	int		len;
	int		aux;
	char	**dict;

	dict = dict_init(list, len_dict);
	while (*list)
	{
		len = ft_strlen(*list);
		if (len == 1)
			create_dict_sizeone(dict, list);
		else if (len == 2)
		{
			aux = atoi(*list);
			if (10 <= aux && aux <= 20)
				dict[aux] = *(list + 1);
			else if (30 <= aux && aux <= 90 && aux % 10 == 0)
				dict[18 + aux / 10] = *(list + 1);
		}
		else if (len == 3 && atoi(*list) == 100)
			dict[28] = *(list + 1);
		else if (len > 3 && is_pow_thsnd(*list, len))
			dict[28 + len / 3] = *(list + 1);
		list += 2;
	}
	return (dict);
}
