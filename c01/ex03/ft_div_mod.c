/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:03:01 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/16 14:07:26 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <unistd.h>
int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	r;

	int	*nbr1;
	int	*nbr2;

	a = 10;
	b = 3;
	nbr1 = &c;
	nbr2 = &r;
	ft_div_mod(a, b, nbr1, nbr2);
	if (c == 3 && r == 1)
		write(1, "success", 7);
	else
		write(1, "fail", 4);
	return (0);
}*/
