/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:10:42 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/26 12:43:02 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		pos;

	pos = 0;
	while (src[pos] != '\0')
		pos ++;
	dup = malloc((pos + 1) * sizeof(char));
	pos = 0;
	while (src[pos] != '\0')
	{
		dup[pos] = src[pos];
		pos ++;
	}
	dup[pos] = '\0';
	return (dup);
}

/*int	main(int argc, char **argv)
{
	char *dest;

	dest = ft_strdup(argv[1]);
	printf("%s\n", dest);
	free(dest);
	return (0);
}*/
