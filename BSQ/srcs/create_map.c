/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:33:57 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/03 17:14:46 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_h.h"

int	count_chars(char *direc)
{
	int		fd;
	int		count;
	char	*z;

	count = 0;
	fd = open(direc, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &z, 1) != 0)
		count++;
	close(fd);
	return (count);
}

char	*read_map(char *name)
{
	int		fd;
	int		memory;
	char	*buffer;

	memory = count_chars(name);
	if (memory <= 0)
		return (NULL);
	buffer = malloc((memory + 1) * sizeof(char));
	if (!(buffer))
		return (NULL);
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}
	read(fd, buffer, memory);
	buffer[memory] = '\0';
	close(fd);
	return (buffer);
}

int	create_map(char *name, t_map *map)
{
	char	*buffer;

	buffer = read_map(name);
	if (!(buffer))
		return (1);
	map->map = ft_split(buffer, "\n");
	free(buffer);
	if (!(map->map))
		return (1);
	if (!(map->map[0]))
	{
		free(map->map);
		return (1);
	}
	if (validate_map(map))
		return (1 + free_map(map));
	return (0);
}
