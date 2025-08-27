/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:35:31 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/16 20:29:25 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	position;

	position = 0;
	while (position < size - 1)
	{
		if (*(tab + position) > *(tab + position + 1))
		{
			ft_swap(tab + position, tab + position + 1);
			position = 0;
		}
		else
			position ++;
	}
}

/*#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	int myNumbers[] = {1,2,6,5,9,3,8,7,4};
	int i;

	for (i = 0; i < 9; i++)
	{
		printf("%d\n", myNumbers[i]);
	}
	ft_sort_int_tab(myNumbers, 8);
	for (i = 0; i < 9; i++)
        {
                printf("%d\n", myNumbers[i]);
        }
	return (0);
}*/
