/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumehmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:27:24 by mumehmed          #+#    #+#             */
/*   Updated: 2025/08/31 08:28:40 by mumehmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_h.h" 

int	count_spaces(char *str, int count)
{
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ' ')
	{
		str++;
		count++;
	}
	str++;
	while (*str == ' ')
	{
		str++;
		count++;
	}
	return (count);
}

int	buff_size(char **buff)
{
	int	count;

	count = 0;
	while (*buff != NULL)
	{
		count++;
		buff++;
	}
	return (count);
}

void	strcpy_no_spaces(char *s1, char *s2)
{
	while (*s2 >= '0' && *s2 <= '9')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	while (*s2 == ' ')
		s2++;
	*s1 = ':';
	s1++;
	s2++;
	while (*s2 == ' ')
		s2++;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

char	**format(char **dict)
{
	char	**new_list;
	int		spaces;
	int		l;
	int		i;

	i = 0;
	new_list = (char **)malloc((buff_size(dict) + 1) * sizeof(char *));
	while (dict[i] != NULL)
	{
		spaces = count_spaces(dict[i], 0);
		l = ft_strlen(dict[i]);
		new_list[i] = (char *)malloc((l - spaces + 1) * sizeof(char));
		strcpy_no_spaces(new_list[i], dict[i]);
		free(dict[i]);
		i++;
	}
	free(dict[i]);
	free(dict);
	new_list[i] = NULL;
	return (new_list);
}
