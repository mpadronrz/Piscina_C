/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:03:57 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/24 16:37:52 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	pos;

	pos = 0;
	while (s1[pos] == s2[pos] && s1[pos] != '\0')
		pos ++;
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str ++;
	}
	write(1, "\n", 1);
}

int	print_empty(int argc, char **argv)
{
	int	i;
	int	printed;

	i = 1;
	printed = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr(argv[i]);
			printed ++;
		}
		i ++;
	}
	return (printed);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	printed;

	printed = print_empty(argc, argv);
	while (printed < argc - 1)
	{
		i = 1;
		while (argv[i][0] == '\0')
			i ++;
		j = i + 1;
		while (j < argc)
		{
			if (argv[j][0] != '\0' && ft_strcmp(argv[j], argv[i]) < 0)
				i = j;
			j ++;
		}
		ft_putstr(argv[i]);
		argv[i][0] = '\0';
		printed ++;
	}
	return (0);
}
