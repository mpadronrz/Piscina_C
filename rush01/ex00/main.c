/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuneo-o <rcuneo-o@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:18:12 by rcuneo-o          #+#    #+#             */
/*   Updated: 2025/08/23 16:18:46 by rcuneo-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char config[4][4], int i, int j, char *cond);

void	putchar(char c)
{
	write(1, &c, 1);
}

void	printconfig(char config[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			putchar(config[i][j]);
			if (j < 3)
				putchar(' ');
			j ++;
		}
		putchar('\n');
		i ++;
	}
}

int	recursive_building(char config[4][4], int n, char *cond)
{
	int		i;
	int		j;
	int		found_sol;	
	char	new_building;

	found_sol = 0;
	i = n / 4;
	j = n % 4;
	if (n == 16)
	{
		printconfig(config);
		return (1);
	}
	new_building = '1';
	while (new_building < '5')
	{
		config[i][j] = new_building;
		if (is_valid(config, i, j, cond))
			found_sol += recursive_building(config, n + 1, cond);
		config[i][j] = '\0';
		new_building ++;
		if (found_sol)
			return (found_sol);
	}
	return (found_sol);
}

int	validate_input(char *cond)
{
	int	i;

	i = 0;
	while (cond[i] != '\0')
	{
		if (i % 2 == 0 && (cond[i] > '4' || cond[i] < '1'))
			return (0);
		if (i % 2 == 1 && cond[i] != ' ')
			return (0);
		i ++;
	}
	if (i != 31)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	config[4][4];

	if (argc != 2)
		write(2, "Error\n", 6);
	else if (! validate_input(argv[1]))
		write(2, "Error\n", 6);
	else if (! recursive_building(config, 0, argv[1]))
		write(2, "Error\n", 6);
	return (0);
}
