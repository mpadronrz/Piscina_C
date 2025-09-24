/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:47:45 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/24 10:50:12 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_hexadecimal(char c)
{
	unsigned char	unsign_c;
	char			fs_dgt;
	char			sc_dgt;

	unsign_c = (unsigned char)c;
	if (unsign_c / 16 < 10)
		fs_dgt = '0' + unsign_c / 16;
	else
		fs_dgt = 'a' - 10 + unsign_c / 16;
	if (unsign_c % 16 < 10)
		sc_dgt = '0' + unsign_c % 16;
	else
		sc_dgt = 'a' - 10 + unsign_c % 16;
	write(1, "\\", 1);
	write(1, &fs_dgt, 1);
	write(1, &sc_dgt, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (32 <= *str && *str <= 126)
			write(1, str, 1);
		else
			print_hexadecimal(*str);
		str ++;
	}
}
