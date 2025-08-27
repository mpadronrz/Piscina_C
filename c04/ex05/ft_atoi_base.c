/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:05:42 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/21 13:53:25 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	is_pm(char c)
{
	return (c == '+' || c == '-');
}

int	num_base(char c, char *base, int len)
{
	int	digit;

	digit = 0;
	while (digit < len)
	{
		if (c == base[digit])
			return (digit);
		digit ++;
	}
	return (-1);
}

int	is_valid_len(char *base)
{
	int	len;
	int	counter;

	len = 0;
	while (base[len] != '\0')
	{
		if (is_space(base[len]) || is_pm(base[len]))
			return (0);
		counter = len + 1;
		while (base[counter] != '\0')
		{
			if (base[len] == base[counter])
				return (0);
			counter ++;
		}
		len ++;
	}
	return (len);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	n;
	int	sign;
	int	digit;

	len = is_valid_len(base);
	if (len <= 1)
		return (0);
	sign = 1;
	n = 0;
	while (is_space(*str))
		str ++;
	while (is_pm(*str))
	{
		sign *= (2 * (*str == '+') - 1);
		str ++;
	}
	digit = num_base(*str, base, len);
	while (digit >= 0)
	{
		n = len * n + digit;
		str ++;
		digit = num_base(*str, base, len);
	}
	return (sign * n);
}

int	main(int argc, char **argv)
{
	printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	return (0);
}
