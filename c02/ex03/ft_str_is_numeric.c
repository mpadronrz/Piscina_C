/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:22:28 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/19 17:30:15 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	else
		return ('0' <= *str
			&& *str <= '9'
			&& ft_str_is_numeric(str + 1));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_str_is_numeric("123801792"));
	printf("%d\n", ft_str_is_numeric("123jahsdjh92"));
	printf("%d\n", ft_str_is_numeric("1238017DSAd92"));
	printf("%d\n", ft_str_is_numeric("1238\0a12"));
	printf("%d\n", ft_str_is_numeric("12380-*1792"));
	printf("%d\n", ft_str_is_numeric("123801\n792"));
	printf("%d\n", ft_str_is_numeric(""));
	return (0);
}*/
