/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:28:24 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/17 16:41:42 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
		return (1);
	else
		return ('A' <= *str && *str <= 'Z' && ft_str_is_uppercase(str + 1));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_str_is_uppercase("HOLAAAA"));
	printf("%d\n", ft_str_is_uppercase("daAFADSa"));
	printf("%d\n", ft_str_is_uppercase("OASD91ADSA"));
	printf("%d\n", ft_str_is_uppercase("JDAS\0ASDAS"));
	printf("%d\n", ft_str_is_uppercase("SDASD-*ASD"));
	printf("%d\n", ft_str_is_uppercase("DSA87ASA"));
	printf("%d\n", ft_str_is_uppercase("DASDA\nASDASD"));
	printf("%d\n", ft_str_is_uppercase(""));
	return (0);
}*/
