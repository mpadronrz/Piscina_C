/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:55:50 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/17 12:03:48 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	position;

	position = 0;
	while (src[position] != '\0')
	{
		dest[position] = src[position];
		position ++;
	}
	dest[position] = src[position];
	return (dest);
}

/*#include <unistd.h>
void    ft_putstr(char *str)
{
        while (*str != '\0')
        {
                write(1, str, 1);
                str ++;
        }
}


int	main(void)
{
	char	dest[10];

	ft_strcpy(dest, "prueba");
	ft_putstr(dest);
	return (0);
}*/
