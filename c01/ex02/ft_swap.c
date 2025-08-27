/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:52:04 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/16 23:49:01 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*#include <unistd.h>
int	main(void)
{
	int	a;
	int	b;
	int	*na;
	int	*nb;

	a = 10;
	na = &a;
	b = 13248;
	nb = &b;

	ft_swap(na, nb);
	if (a == 13248 && b == 10)
		write(1, "success", 7);
	else
		write(1, "fail", 4);
	return (0);
}*/
