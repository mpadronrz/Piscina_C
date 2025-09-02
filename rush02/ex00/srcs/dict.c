/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:46:20 by mumehmed          #+#    #+#             */
/*   Updated: 2025/08/31 20:56:17 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_h.h"

int	valid_dict(char **dict)
{
	char	*ptr;

	while (*dict != NULL)
	{
		ptr = *dict;
		if (*ptr < '0' || *ptr > '9')
			return (0);
		while (*ptr >= '0' && *ptr <= '9')
			ptr++;
		while (*ptr == ' ')
			ptr++;
		if (*ptr != ':')
			return (0);
		while (*ptr == ' ')
			ptr++;
		if (*ptr < 32 || *ptr > 126)
			return (0);
		while (*ptr >= 32 && *ptr <= 126)
			ptr++;
		if (*ptr != '\0')
			return (0);
		dict++;
	}
	return (1);
}

int	reserve_memory(char *direc)
{
	int		fd;
	int		count;
	char	*z;

	count = 0;
	fd = open(direc, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &z, 1) != 0)
		count++;
	close(fd);
	return (count);
}

char	*read_dict(char *direc)
{
	int		memory;
	char	*dict;
	int		fd;

	memory = reserve_memory(direc);
	if (!(memory))
		return (NULL);
	dict = malloc((memory + 1) * sizeof(char));
	if (!(dict))
		return (NULL);
	fd = open(direc, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read(fd, dict, memory);
	dict[memory] = '\0';
	close (fd);
	return (dict);
}
