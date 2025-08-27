/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:02:59 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/19 19:48:16 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	position;
	unsigned int	size_src;

	size_src = 0;
	while (src[size_src] != '\0')
		size_src ++;
	if (size == 0)
		return (size_src);
	position = 0;
	while (src[position] != '\0' && position < size - 1)
	{
		dest[position] = src[position];
		position ++;
	}
	dest[position] = '\0';
	return (size_src);
}

/*int main(void)
{
	char src[] = "Prueba del codigo";
	char dest[12];
	unsigned int l;

	l = ft_strlcpy(dest, src, 0);
	printf("%s\n", dest);
	printf("%i", l);
	return (0);
}*/
