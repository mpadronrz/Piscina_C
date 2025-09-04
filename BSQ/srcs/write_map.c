/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:23:11 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/03 16:27:18 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_h.h"

char	**free_split(char **splited, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(splited[j]);
		j ++;
	}
	free(splited);
	return (NULL);
}

int	free_map(t_map *map)
{
	int	i;

	i = 0;
	map->map --;
	while (map->map[i])
	{
		free(map->map[i]);
		i ++;
	}
	free(map->map);
	return (0);
}

int	write_map(t_map map)
{
	t_point	pos;

	pos.x = 0;
	while (pos.x < map.max.x)
	{
		ft_putstrnl(map.map[pos.x]);
		pos.x ++;
	}
	while (pos.x < map.max.x + map.sq)
	{
		pos.y = map.max.y;
		while (pos.y < map.max.y + map.sq)
		{
			map.map[pos.x][pos.y] = map.full;
			pos.y ++;
		}
		ft_putstrnl(map.map[pos.x]);
		pos.x ++;
	}
	while (pos.x < map.size.x)
	{
		ft_putstrnl(map.map[pos.x]);
		pos.x ++;
	}
	return (free_map(&map));
}
