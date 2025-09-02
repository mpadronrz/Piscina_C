/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:25:49 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/01 16:47:46 by mapadron         ###   ########.fr       */
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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	position;

	position = 0;
	while (tab[position + 1] != NULL)
	{
		if (cmp(tab[position], tab[position + 1]) > 0)
		{
			ft_ptrswap(&(tab[position]), &(tab[position + 1]));
			position = 0;
		}
		else
			position ++;
	}
}
