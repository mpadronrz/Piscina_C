/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuneo-o <rcuneo-o@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:19:17 by rcuneo-o          #+#    #+#             */
/*   Updated: 2025/08/23 23:54:37 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_l(char *line, char a)
{
	int	i;
	int	j;
	int	vis;
	int	num_vis;

	num_vis = 1;
	i = 1;
	while (i < 4)
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
	return (num_vis == a - '0');
}

int	check_r(char *line, char a)
{
	int	i;
	int	j;
	int	vis;
	int	num_vis;

	num_vis = 1;
	i = 2;
	while (i >= 0)
	{
		vis = 1;
		j = i + 1;
		while (j < 4 && vis)
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

int	check_row(char config[4][4], int i, int j, char *cond)
{
	int		counter;
	char	aux[4];

	if (j == 3)
	{
		counter = 0;
		while (counter < 4)
		{
			aux[counter] = config[i][counter];
			counter ++;
		}
		return (check_l(aux, cond[16 + 2 * i])
			&& check_r(aux, cond[24 + 2 * i]));
	}
	return (1);
}

int	check_col(char config[4][4], int i, int j, char *cond)
{
	int		counter;
	char	aux[4];

	if (i == 3)
	{
		counter = 0;
		while (counter < 4)
		{
			aux[counter] = config[counter][j];
			counter ++;
		}
		return (check_l(aux, cond[2 * j]) && check_r(aux, cond[8 + 2 * j]));
	}
	return (1);
}

int	is_valid(char config[4][4], int i, int j, char *cond)
{
	int	counter;

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
	return (check_row(config, i, j, cond) && check_col(config, i, j, cond));
}
