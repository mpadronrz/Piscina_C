/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:16:35 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/19 11:06:32 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	pos;
	int	new_word;

	pos = 0;
	new_word = 1;
	while (str[pos] != '\0')
	{
		if (new_word && 'a' <= str[pos] && str[pos] <= 'z')
			str[pos] += 'A' - 'a';
		if (! new_word && 'A' <= str[pos] && str[pos] <= 'Z')
			str[pos] += 'a' - 'A';
		new_word = !(('a' <= str[pos] && str[pos] <= 'z')
				|| ('A' <= str[pos] && str[pos] <= 'Z')
				|| ('0' <= str[pos] && str[pos] <= '9'));
		pos ++;
	}
	return (str);
}

/*#include <unistd.h>
int   main(void)
{
        char    prueba[61] = "salut, coMmeNt tU Vas ? 
	42Mots quarante-deuX; cinQUAnte+et+un";
        ft_strcapitalize(prueba);
        write(1, &prueba, 61);
        return (0);
}*/
