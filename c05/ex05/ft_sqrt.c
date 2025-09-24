/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:24:13 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/24 10:57:10 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sqrt_recur(int nb, int result)
{
	int	n;

	n = result * result;
	if (n == nb)
		return (result);
	if (n > nb)
		return (0);
	return (sqrt_recur(nb, result + 1));
}

/*int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	return (sqrt_recur(nb, 0));
}*/
