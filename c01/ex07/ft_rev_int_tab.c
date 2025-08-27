/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:46:33 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/16 20:28:52 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void	ft_rev_int_tab(int *tab, int size)
{
	if (size >= 2)
	{
		ft_swap(tab, tab + size - 1);
		ft_rev_int_tab(tab + 1, size - 2);
	}
}

/*#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	int myNumbers[] = {1,2,3,4,5};
	int i;

	for (i = 0; i < 5; i++) 
	{
		printf("%d\n", myNumbers[i]);
	}
	ft_rev_int_tab(&myNumbers[0], 5);
	for (i = 0; i < 5; i++)
        {
                printf("%d\n", myNumbers[i]);
        }
	return (0);
}*/
