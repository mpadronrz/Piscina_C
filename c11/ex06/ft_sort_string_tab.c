/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:56:41 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/01 13:24:56 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_ptrswap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	pos;

	pos = 0;
	while (s1[pos] == s2[pos] && s1[pos] != '\0')
		pos ++;
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}

void	ft_sort_string_tab(char **tab)
{
	int	position;

	position = 0;
	while (tab[position + 1] != NULL)
	{
		if (ft_strcmp(tab[position], tab[position + 1]) > 0)
		{
			ft_ptrswap(&(tab[position]), &(tab[position + 1]));
			position = 0;
		}
		else
			position ++;
	}
}
