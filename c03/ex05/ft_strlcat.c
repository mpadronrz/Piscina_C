/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:08:53 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/22 11:27:20 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_src;
	unsigned int	len_dest;
	unsigned int	pos;

	len_src = 0;
	len_dest = 0;
	pos = 0;
	while (src[len_src] != '\0')
		len_src ++;
	while (dest[len_dest] != '\0' && len_dest < size)
		len_dest ++;
	if (len_dest == size)
		return (len_dest + len_src);
	while (pos < size - len_dest - 1 && src[pos] != '\0')
	{
		dest[len_dest + pos] = src[pos];
		pos ++;
	}
	dest[len_dest + pos] = '\0';
	return (len_dest + len_src);
}

int main(void)
{
	char str[4]="HOLA";
	char dest[9] ="Adios\0";

	printf("%d\n", ft_strlcat(dest,str,0));
        char str2[4]="HOLA";
        char dest2[9] ="Adios\0";

        printf("%d\n", strlcat(dest2,str2,0));
	return (0);
}
