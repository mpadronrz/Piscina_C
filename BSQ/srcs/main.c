/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:49:05 by danjose-          #+#    #+#             */
/*   Updated: 2025/09/03 17:29:42 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_h.h"

int	read_from_stdin(char *name)
{
	int	i;

	i = 0;
	read(0, name, 4096);
	while (name[i] != '\n')
		i++;
	name[i] = '\0';
	return (1);
}

int	main(int argc, char **argv)
{
	char	name[4096];
	int		i;
	t_map	map;

	i = 1;
	if (argc == 1)
		argc += read_from_stdin(name);
	else
		ft_strcpy(name, argv[1]);
	while (i < argc)
	{
		if (i > 1)
		{
			ft_putstr("\n");
			ft_strcpy(name, argv[i]);
		}
		if (create_map(name, &map) || solve(&map))
			ft_putstr("map error\n");
		i ++;
	}
	return (0);
}
