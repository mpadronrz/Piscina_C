/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:21:16 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/26 12:47:13 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strcpy(char *dest, char *src)
{
	int	position;

	position = 0;
	while (src[position] != '\0')
	{
		dest[position] = src[position];
		position ++;
	}
	return (position);
}

int	ft_strlen(char *str)
{
	int	char_num;

	char_num = 0;
	while (*str != '\0')
	{
		char_num ++;
		str ++;
	}
	return (char_num);
}

int	count_memory(int size, char **strs, char *sep)
{
	int	i;
	int	memory;

	memory = 0;
	i = 0;
	while (i < size)
	{
		memory += ft_strlen(strs[i]);
		i ++;
	}
	memory += (size - 1) * ft_strlen(sep);
	return (memory);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		memory;
	char	*dest;

	if (size == 0)
	{
		dest = malloc(1 * sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	memory = count_memory(size, strs, sep);
	dest = malloc((memory + 1) * sizeof(char));
	i = 0;
	memory = 0;
	while (i < size)
	{
		memory += ft_strcpy(&dest[memory], strs[i]);
		if (i != size - 1)
			memory += ft_strcpy(&dest[memory], sep);
		i ++;
	}
	dest[memory] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	char *sep = argv[2];
	char **strs = &argv[3];
	char *dest;

	dest = ft_strjoin(atoi(argv[1]), strs, sep);
	printf("%s\n", dest);
	free(dest);
	return (0);
}
