/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:55:14 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/27 16:18:02 by mapadron         ###   ########.fr       */
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
