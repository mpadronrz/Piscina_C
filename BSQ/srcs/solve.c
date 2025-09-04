/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:06:18 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/03 02:37:20 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_h.h"

void	free_par(int **par, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(par[i]);
		i ++;
	}
	free(par);
}

int	**init_sol(t_map *map)
{
	int	**par;
	int	i;

	i = 0;
	par = malloc(map->size.x * sizeof(int *));
	if (!(par))
	{
		return (NULL);
	}
	while (i < map->size.x)
	{
		par[i] = malloc(map->size.y * sizeof(int));
		if (!(par[i]))
		{
			free_par(par, i);
			return (NULL);
		}
		i ++;
	}
	return (par);
}

int	calc_par(int **par, t_point pos, t_point size)
{
	if (pos.x == size.x - 1 || pos.y == size.y - 1)
		return (1);
	if (par[pos.x][pos.y + 1] <= par[pos.x + 1][pos.y])
	{
		if (par[pos.x][pos.y + 1] <= par[pos.x + 1][pos.y + 1])
			return (par[pos.x][pos.y + 1] + 1);
		return (par[pos.x + 1][pos.y + 1] + 1);
	}
	if (par[pos.x + 1][pos.y + 1] <= par[pos.x + 1][pos.y])
		return (par[pos.x + 1][pos.y + 1] + 1);
	return (par[pos.x + 1][pos.y] + 1);
}

void	change_sol(t_map *map, t_point pos, int max)
{
	if (max >= map->sq)
	{
		map->max.x = pos.x;
		map->max.y = pos.y;
		map->sq = max;
	}
}

int	solve(t_map *map)
{
	t_point	pos;
	int		**par;

	par = init_sol(map);
	if (!(par))
		return (1);
	pos.x = map->size.x - 1;
	while (pos.x >= 0)
	{
		pos.y = map->size.y - 1;
		while (pos.y >= 0)
		{
			if (map->map[pos.x][pos.y] == map->obs)
				par[pos.x][pos.y] = 0;
			else
			{
				par[pos.x][pos.y] = calc_par(par, pos, map->size);
				change_sol(map, pos, par[pos.x][pos.y]);
			}
			pos.y --;
		}
		pos.x --;
	}
	free_par(par, map->size.x);
	return (write_map(*map));
}
