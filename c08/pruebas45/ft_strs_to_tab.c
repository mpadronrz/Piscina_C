/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:57:24 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/28 19:20:19 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	else
		return (ft_strlen(str + 1) + 1);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		pos;

	pos = 0;
	while (src[pos] != '\0')
		pos ++;
	dup = malloc((pos + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	pos = 0;
	while (src[pos] != '\0')
	{
		dup[pos] = src[pos];
		pos ++;
	}
	dup[pos] = '\0';
	return (dup);
}

void	free_all(t_stock_str *par, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		free(par[i].str);
		free(par[i].copy);
		i ++;
	}
	free(par);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*par;

	par = malloc((ac + 1) * sizeof(t_stock_str));
	if (!par)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		par[i].size = ft_strlen(av[i]);
		par[i].str = av[i];
		par[i].copy = ft_strdup(av[i]);
		if (!par[i].str || !par[i].copy)
		{
			free_all(par, i);
			return (NULL);
		}
		i ++;
	}
	par[i].str = NULL;
	return (par);
}
