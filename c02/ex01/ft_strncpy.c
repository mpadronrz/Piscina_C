/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 12:04:39 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/17 13:21:35 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	position;

	position = 0;
	while (src[position] != '\0' && position < n)
	{
		dest[position] = src[position];
		position ++;
	}
	while (position < n)
	{
		dest[position] = '\0';
		position ++;
	}
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

	ft_strncpy(dest, "pruebapruebapreba", 10);
	ft_putstr(dest);
	return (0);
}*/
