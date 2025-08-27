/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:37:00 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/16 18:26:11 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	char_num;

	char_num = 0;
	while (*str != '\0')
	{
		char_num ++;
		str ++;
	}
	return (char_num);
}

/*#include <unistd.h>
int	main(void)
{
	if (ft_strlen("holahola") == 8)
		write(1, "success", 7);
	else
		write(1, "fail", 4);
	return (0);
}*/
