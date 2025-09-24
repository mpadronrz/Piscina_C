/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:40:10 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/24 10:48:24 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*funcion que impreime por pantalla un entero positivo (printable) 
de a lo sumo n dígitos (con ceros delante en caso de ser necesario)*/
void	print_num(int n, int printable)
{
	char	a[11];
	int		n_copy;

	n_copy = n;
	while (n_copy > 0)
	{
		n_copy --;
		a[n_copy] = '0' + printable % 10;
		printable /= 10;
	}
	write(1, &a, n);
}

int	is_valid(int n, int printable)
{
	int	valid;

	valid = 1;
	while (n > 1 && valid)
	{
		n --;
		if (printable % 10 <= (printable / 10) % 10)
			valid = 0;
		printable /= 10;
	}
	return (valid);
}

void	ft_print_combn(int n)
{
	int	printable;
	int	num_max;
	int	n_aux;

	printable = 0;
	n_aux = 10 - n;
	num_max = 0;
	while (n_aux <= 9)
	{
		num_max = 10 * num_max + n_aux;
		n_aux ++;
	}
	while (printable < num_max)
	{
		if (is_valid(n, printable))
		{
			print_num(n, printable);
			write(1, ", ", 2);
		}
		printable ++;
	}
	print_num(n, num_max);
}
