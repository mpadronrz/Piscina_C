/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:28:24 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/17 16:18:52 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
		return (1);
	else
		return ('a' <= *str && *str <= 'z' && ft_str_is_lowercase(str + 1));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_str_is_lowercase("daohkldja"));
	printf("%d\n", ft_str_is_lowercase("daAFADSa"));
	printf("%d\n", ft_str_is_lowercase("daohk91ja"));
	printf("%d\n", ft_str_is_lowercase("daoh\0kldja"));
	printf("%d\n", ft_str_is_lowercase("da-+ldja"));
	printf("%d\n", ft_str_is_lowercase("d912ja"));
	printf("%d\n", ft_str_is_lowercase("da\nkldja"));
	printf("%d\n", ft_str_is_lowercase(""));
	return (0);
}*/
