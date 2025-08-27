/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:21:13 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/19 12:12:42 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	pos;

	pos = 0;
	while (s1[pos] == s2[pos] && s1[pos] != '\0')
		pos ++;
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}

/*#include <stdio.h>
int	main(void)
{
	char a[] = "abaa";
	char b[] = "abaaa";

	printf("%d\n", ft_strcmp(a, b));
	printf("%s\n", a);
	printf("%s\n", b);
	return (0);
}*/
