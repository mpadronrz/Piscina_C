/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:03:28 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/19 17:48:42 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	pos;

	pos = 0;
	while (s1[pos] == s2[pos] && s1[pos] != '\0' && pos < n)
		pos ++;
	if (pos == n)
		return (0);
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}

/*#include <stdio.h>
int	main(void)
{
	char a[] = "abb";
	char b[] = "aba";

	printf("%d\n", ft_strncmp(a, b, 2));
	printf("%s\n", a);
	printf("%s\n", b);
	return (0);
}*/
