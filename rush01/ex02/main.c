/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuneo-o <rcuneo-o@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:19:46 by rcuneo-o          #+#    #+#             */
/*   Updated: 2025/08/24 12:19:59 by rcuneo-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char config[9][9], int n, char *cond, int size);

void	putchar(char c)
{
	write(1, &c, 1);
}

void	printconfig(char config[9][9], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			putchar(config[i][j]);
			if (j < size - 1)
				putchar(' ');
			j ++;
		}
		putchar('\n');
		i ++;
	}
}

int	recursive_building(char config[9][9], int n, char *cond, int size)
{
	int		i;
	int		j;
	int		found_sol;	
	char	new_building;

	found_sol = 0;
	i = n / size;
	j = n % size;
	if (n == size * size)
	{
		printconfig(config, size);
		return (1);
	}
	new_building = '1';
	while (new_building <= '0' + size)
	{
		config[i][j] = new_building;
		if (is_valid(config, n, cond, size))
			found_sol += recursive_building(config, n + 1, cond, size);
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
	int	size;

	i = 0;
	while (cond[i] != '\0')
		i ++;
	i = i / 2 + 1;
	if (i % 4 != 0 || i > 36)
		return (0);
	size = i / 4;
	while (cond[i] != '\0')
	{
		if (i % 2 == 0 && (cond[i] > '0' + size || cond[i] < '1'))
			return (0);
		if (i % 2 == 1 && cond[i] != ' ')
			return (0);
		i ++;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	char	config[9][9];
	int		size;

	if (argc != 2)
		write(2, "Error\n", 6);
	size = validate_input(argv[1]);
	if (size == 0)
		write(2, "Error\n", 6);
	else if (! recursive_building(config, 0, argv[1], size))
		write(2, "Error\n", 6);
	return (0);
}
