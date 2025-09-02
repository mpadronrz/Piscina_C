/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:25:50 by mumehmed          #+#    #+#             */
/*   Updated: 2025/08/31 14:38:02 by mumehmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_h.h" 

int	count_num(char *str)
{
	int	count;

	count = 0;
	while (*str != ':')
	{
		count++;
		str++;
	}
	return (count);
}

void	strcpy_num(char *s1, char *s2)
{
	while (*s2 != ':')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

void	strcpy_val(char *s1, char *s2)
{
	while (*s2 != ':')
		s2++;
	s2++;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

int	count_val(char *str)
{
	int	count;

	count = 0;
	while (*str != ':')
		str++;
	str++;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	**manual_split(char **list)
{
	char	**new_list;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_list = (char **)malloc((buff_size(list) * 2 + 1) * sizeof(char *));
	while (list[i] != NULL)
	{
		new_list[j] = (char *)malloc((count_num(list[i]) + 1) * sizeof(char));
		strcpy_num(new_list[j], list[i]);
		j++;
		new_list[j] = (char *)malloc((count_val(list[i]) + 1) * sizeof(char));
		strcpy_val(new_list[j], list[i]);
		j++;
		free(list[i]);
		i++;
	}
	new_list[j] = NULL;
	free(list[i]);
	free(list);
	return (new_list);
}
