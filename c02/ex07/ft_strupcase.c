/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:43:38 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/18 20:29:33 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if ('a' <= str[counter] && str[counter] <= 'z')
			str[counter] += 'A' - 'a';
		counter ++;
	}
	return (str);
}

/*#include <unistd.h>
int	main(void)
{
	char	prueba[15] = "asdhJFHSA897123";

	ft_strupcase(prueba);
	write(1, prueba, 15);
	return (0);
}*/
