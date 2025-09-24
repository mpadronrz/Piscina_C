/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:16:32 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/24 10:51:12 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int				is_str;
	unsigned int	pos_find;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		pos_find = 0;
		is_str = (*str == *to_find);
		while (is_str)
		{
			pos_find ++;
			if (to_find[pos_find] == '\0')
				return (str);
			is_str = (str[pos_find] == to_find[pos_find]);
		}
		str ++;
	}
	return (NULL);
}

/*int main(int argc, char **argv)
{
	printf("%s\n", ft_strstr(argv[1], argv[2]));
	return (0);
}*/
