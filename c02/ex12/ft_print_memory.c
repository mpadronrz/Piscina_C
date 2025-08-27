/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:44:59 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/20 18:10:05 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	pt_direction(unsigned char *addr)
{
	unsigned char			printable[16];
	int						pos;
	int						aux;
	unsigned long long int	int_addr;

	int_addr = (unsigned long long int)addr;
	pos = 15;
	while (pos >= 0)
	{
		aux = int_addr % 16;
		if (aux < 10)
			printable[pos] = '0' + aux;
		else
			printable[pos] = 'a' - 10 + aux;
		int_addr /= 16;
		pos --;
	}
	write(1, &printable, 16);
	write(1, ": ", 2);
}

void	pt_chr_hex(unsigned char c)
{
	unsigned char	printable[2];

	if (c % 16 < 10)
		printable[1] = '0' + c % 16;
	else
		printable[1] = 'a' - 10 + c % 16;
	if (c / 16 < 10)
		printable[0] = '0' + c / 16;
	else
		printable[0] = 'a' - 10 + c / 16;
	write(1, printable, 2);
}

void	pt_cnt_hex(unsigned char *addr, unsigned int size, unsigned int pos)
{
	int	i;

	i = 0;
	while (i < 16 && pos < size)
	{
		pt_chr_hex(addr[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		i ++;
		pos ++;
	}
	while (i < 16)
	{
		if (i % 2 == 1)
			write(1, " ", 1);
		write(1, "  ", 2);
		i ++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	pos;
	unsigned char	*new_addr;

	new_addr = (unsigned char *)addr;
	pos = 0;
	while (pos < size)
	{
		if (pos % 16 == 0)
		{
			if (pos != 0)
				write(1, "\n", 1);
			pt_direction(new_addr + pos);
			pt_cnt_hex(new_addr + pos, size, pos);
		}
		if (32 <= new_addr[pos] && new_addr[pos] <= 126)
			write(1, &new_addr[pos], 1);
		else
			write(1, ".", 1);
		pos ++;
	}
	if (size > 0)
		write(1, "\n", 1);
	return (addr);
}

/*int	main(void)
{
	char	*prueba = "Hola:)!jashdjashdj\0hadasdfdfajfkjf";
	ft_print_memory(prueba, 23);
	return (0);
}*/
