/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:23:05 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/25 12:58:37 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	pos;

	if (min >= max)
		return (NULL);
	pos = 0;
	array = malloc((max - min) * sizeof(int));
	while (pos < max - min)
	{
		array[pos] = min + pos;
		pos ++;
	}
	return (array);
}
