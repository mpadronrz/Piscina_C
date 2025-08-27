/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:20:26 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/15 14:11:43 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*funcion que impreime por pantalla un entero (positivo) 
de a lo sumo dos dígitos (con ceros delante en caso de ser necesario)*/
void	print_num(int n)
{
	char	a[2];

	a[1] = '0' + n % 10;
	a[0] = '0' + n / 10;
	write(1, &a, 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_num(a);
			write(1, " ", 1);
			print_num(b);
			if (a != 98)
				write(1, ", ", 2);
			b ++;
		}
		a ++;
	}
}
