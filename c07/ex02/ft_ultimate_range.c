/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:59:15 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/25 13:20:41 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	counter;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	counter = 0;
	*range = malloc((max - min) * sizeof(int));
	while (counter < max - min)
	{
		(*range)[counter] = min + counter;
		counter ++;
	}
	return (max - min);
}
