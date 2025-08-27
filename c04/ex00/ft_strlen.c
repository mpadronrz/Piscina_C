/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:27:37 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/21 13:59:01 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	else
		return (ft_strlen(str + 1) + 1);
}

int main(int argc, char **argv)
{
	printf("%d\n", ft_strlen(argv[1]));
	return (0);
}
