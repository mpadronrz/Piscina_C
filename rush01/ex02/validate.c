/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuneo-o <rcuneo-o@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:21:07 by rcuneo-o          #+#    #+#             */
/*   Updated: 2025/08/24 15:27:59 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_l(char *line, char a, int size, int num)
{
	int	i;
	int	j;
	int	vis;
	int	num_vis;

	num_vis = 1;
	i = 1;
	while (i <= num)
	{
		vis = 1;
		j = i - 1;
		while (j >= 0 && vis)
		{
			if (line[j] > line[i])
				vis = 0;
			j --;
		}
		if (vis)
			num_vis ++;
		i ++;
	}
	if (num < size - 1)
		return (num_vis <= a - '0');
	return (num_vis == a - '0');
}

int	check_r(char *line, char a, int size)
{
	int	i;
	int	j;
	int	vis;
	int	num_vis;

	num_vis = 1;
	i = size - 2;
	while (i >= 0)
	{
		vis = 1;
		j = i + 1;
		while (j < size && vis)
		{
			if (line[j] > line[i])
				vis = 0;
			j ++;
		}
		if (vis)
			num_vis ++;
		i --;
	}
	return (num_vis == a - '0');
}

int	check_row(char config[9][9], int n, char *cond, int size)
{
	int		counter;
	char	aux[9];
	int		i;
	int		j;

	i = n / size;
	j = n % size;
	counter = 0;
	while (counter <= j)
	{
		aux[counter] = config[i][counter];
		counter ++;
	}
	if (j == size - 1)
		return (check_l(aux, cond[4 * size + 2 * i], size, j)
			&& check_r(aux, cond[6 * size + 2 * i], size));
	return (check_l(aux, cond[4 * size + 2 * i], size, j));
}

int	check_col(char config[9][9], int n, char *cond, int size)
{
	int		counter;
	char	aux[9];
	int		i;
	int		j;

	i = n / size;
	j = n % size;
	counter = 0;
	while (counter <= i)
	{
		aux[counter] = config[counter][j];
		counter ++;
	}
	if (i == size - 1)
		return (check_l(aux, cond[2 * j], size, i)
			&& check_r(aux, cond[2 * size + 2 * j], size));
	return (check_l(aux, cond[2 * j], size, i));
}

int	is_valid(char config[9][9], int n, char *cond, int size)
{
	int	counter;
	int	i;
	int	j;

	i = n / size;
	j = n % size;
	counter = 0;
	while (counter < i)
	{
		if (config[counter][j] == config[i][j])
			return (0);
		counter ++;
	}
	counter = 0;
	while (counter < j)
	{
		if (config[i][counter] == config[i][j])
			return (0);
		counter ++;
	}
	return (check_row(config, n, cond, size)
		&& check_col(config, n, cond, size));
}
