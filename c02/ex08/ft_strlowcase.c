/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:57:53 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/19 17:37:49 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if ('A' <= str[counter] && str[counter] <= 'Z')
			str[counter] += 'a' - 'A';
		counter ++;
	}
	return (str);
}

/*#include <unistd.h>
int	main(void)
{
	char	prueba[15] = "asdhJFHSA897123";

	ft_strlowcase(prueba);
	write(1, prueba, 15);
	return (0);
}*/
