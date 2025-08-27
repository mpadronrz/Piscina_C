/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:28:24 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/19 17:27:42 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
		return (1);
	else
		return ((('a' <= *str && *str <= 'z')
				|| ('A' <= *str && *str <= 'Z'))
			&& ft_str_is_alpha(str + 1));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_str_is_alpha("daohkldja"));
	printf("%d\n", ft_str_is_alpha("daAFADSa"));
	printf("%d\n", ft_str_is_alpha("daohk91ja"));
	printf("%d\n", ft_str_is_alpha("daoh\0kld!-+-ja"));
	printf("%d\n", ft_str_is_alpha("da-+ldja"));
	printf("%d\n", ft_str_is_alpha("d912ja"));
	printf("%d\n", ft_str_is_alpha("da\nkldja"));
	printf("%d\n", ft_str_is_alpha(""));
	return (0);
}*/
