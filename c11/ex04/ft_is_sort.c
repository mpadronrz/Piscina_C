/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:40:30 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/01 19:01:53 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sign;

	i = 0;
	if (length <= 1)
		return (1);
	while (i < length - 1 && f(tab[i], tab[i + 1]) == 0)
		i ++;
	if (i == length - 1)
		return (1);
	sign = (2 * (f(tab[i], tab[i + 1]) > 0) - 1);
	i ++;
	while (i < length - 1)
	{
		if (sign * f(tab[i], tab[i + 1]) < 0)
			return (0);
		i ++;
	}
	return (1);
}

/*int	compare(int x, int y)
{
	if (x > y)
	       return (1);
	if (x == y)
		return (0);
	return (-1);
}

int	main()
{
	int	tab[] = {100, 20};

	printf("%d\n", ft_is_sort(tab, 2, compare));
	return (0);
}*/
