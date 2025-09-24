/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:48 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/24 10:59:43 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	is_valid_len(char *base);
int	ft_atoi_base(char *str, char *base, int len);

int	size_int(int n, int len)
{
	int	size;

	size = 0;
	if (n <= 0)
		size ++;
	while (n != 0)
	{
		size ++;
		n /= len;
	}
	return (size);
}

char	*conv_to_base(int n, char *base, int len)
{
	int		size;
	int		is_neg;
	char	*nbr;

	size = size_int(n, len);
	is_neg = (n < 0);
	nbr = malloc(size * sizeof(char));
	if (is_neg)
	{
		nbr[0] = '-';
		size --;
		nbr[size] = base[-(n % len)];
		n /= -len;
	}
	while (size > is_neg)
	{
		size --;
		nbr[size] = base[n % len];
		n /= len;
	}
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len_from;
	int		len_to;
	int		n;
	char	*new_nbr;

	len_from = is_valid_len(base_from);
	len_to = is_valid_len(base_to);
	if (len_to <= 1 || len_from <= 1)
		return (NULL);
	n = ft_atoi_base(nbr, base_from, len_from);
	new_nbr = conv_to_base(n, base_to, len_to);
	return (new_nbr);
}

/*int	main(int argc, char **argv)
{
	char *nbr;
	nbr = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s\n", nbr);
	free(nbr);
	return (0);
}*/
