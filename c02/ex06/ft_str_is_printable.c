/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:28:47 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/17 16:40:36 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	else
		return (32 <= *str && *str <= 126 && ft_str_is_printable(str + 1));
}
/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_str_is_printable("HOLAAAA"));
        printf("%d\n", ft_str_is_printable("daAFADSa"));
        printf("%d\n", ft_str_is_printable("Ohguy867/-*+DSA"));
        printf("%d\n", ft_str_is_printable("JDAS\0ASDAS"));
        printf("%d\n", ft_str_is_printable("SDASDASD"));
        printf("%d\n", ft_str_is_printable("DSA8¿¿7"));
        printf("%d\n", ft_str_is_printable("DASDA\nASDASD"));
        printf("%d\n", ft_str_is_printable(""));
        return (0);
}*/
