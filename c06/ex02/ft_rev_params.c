/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:44:50 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/24 13:46:11 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str ++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	counter;

	counter = argc - 1;
	while (counter > 0)
	{
		ft_putstr(argv[counter]);
		counter --;
	}
	return (0);
}
