/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:30:24 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/24 10:57:20 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime_recursive(int nb, int divisor)
{
	if (divisor * divisor > nb)
		return (1);
	return (nb % divisor != 0 && is_prime_recursive(nb, divisor + 2));
}

/*int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	if (nb % 2 == 0)
		return (nb == 2);
	return (is_prime_recursive(nb, 3));
}*/
