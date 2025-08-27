/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:17:51 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/16 16:22:12 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aux;

	aux = *a / *b;
	*b = *a % *b;
	*a = aux;
}

/*#include <unistd.h>
int	main(void)
{
	int	a = 45;
	int	b = 7;

	ft_ultimate_div_mod(&a, &b);
	if (a == 6 && b == 3)
		write(1, "success", 7);
	else
		write(1, "fail", 4);
	return (0);
}*/
