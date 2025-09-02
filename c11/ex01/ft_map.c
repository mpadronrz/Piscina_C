/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:35:57 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/01 18:57:00 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(length * sizeof(int));
	if (!(res))
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i ++;
	}
	return (res);
}
