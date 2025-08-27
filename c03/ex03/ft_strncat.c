/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:02:49 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/20 13:04:40 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	pos_src;
	unsigned int	pos_dest;

	pos_dest = 0;
	pos_src = 0;
	while (dest[pos_dest] != '\0')
		pos_dest ++;
	while (src[pos_src] != '\0' && pos_src < nb)
	{
		dest[pos_dest] = src[pos_src];
		pos_dest ++;
		pos_src ++;
	}
	dest[pos_dest] = '\0';
	return (dest);
}
