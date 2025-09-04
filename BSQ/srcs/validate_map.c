/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:39 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/03 16:24:08 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_h.h"

int	init_obj(t_map *map)
{
	int		i;

	i = 0;
	while ('0' <= map->map[0][i] && map->map[0][i] <= '9')
		i ++;
	if (map->map[0][i] < 32 || 126 < map->map[0][i])
		return (1);
	map->empty = map->map[0][i];
	i ++;
	if (map->map[0][i] < 32 || 126 < map->map[0][i])
		return (1);
	map->obs = map->map[0][i];
	i ++;
	if (map->map[0][i] < 32 || 126 < map->map[0][i])
		return (1);
	map->full = map->map[0][i];
	i ++;
	if (map->map[0][i])
		return (1);
	if (map->full == map->obs || map->full == map->empty
		|| map->obs == map->empty)
		return (1);
	return (0);
}

int	check_row(t_map *map, int x)
{
	int	y;

	y = 0;
	while (map->map[x][y])
	{
		if (map->map[x][y] != map->obs && map->map[x][y] != map->empty)
			return (1);
		y ++;
	}
	return (y != map->size.y);
}

int	verify_entries(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[x][y])
	{
		if (map->map[x][y] != map->obs && map->map[x][y] != map->empty)
			return (1);
		y ++;
	}
	map->size.y = y;
	x ++;
	while (map->map[x])
	{
		if (check_row(map, x))
			return (1);
		x ++;
	}
	return (x != map->size.x);
}

int	validate_map(t_map *map)
{
	map->size.x = ft_atoi(map->map[0]);
	if (map->size.x <= 0)
	{
		map->map ++;
		return (1);
	}
	if (init_obj(map))
	{
		map->map ++;
		return (1);
	}
	map->map ++;
	if (!(map->map[0]))
		return (1);
	if (verify_entries(map))
		return (1);
	map->max.x = 0;
	map->max.y = 0;
	map->sq = 0;
	return (0);
}
