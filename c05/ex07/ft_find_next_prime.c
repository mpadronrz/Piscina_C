/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:39:57 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/24 10:57:33 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime_recursive(int nb, int divisor)
{
	if (nb < 2)
		return (0);
	if (divisor * divisor > nb)
		return (1);
	return (nb % divisor != 0 && is_prime_recursive(nb, divisor + 1));
}

/*int	ft_find_next_prime(int nb)
{
	if (is_prime_recursive(nb, 2))
		return (nb);
	return (ft_find_next_prime(nb + 1));
}*/
