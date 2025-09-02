/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:15:11 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/31 21:58:05 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_h.h"

int	liberator(char **list_dict, char *ptr, char **dict)
{
	int	i;

	i = 0;
	free(ptr);
	if (list_dict)
	{
		while (list_dict[i] != NULL)
		{
			free(list_dict[i]);
			i++;
		}
		free(list_dict);
	}
	if (dict)
		free(dict);
	return (0);
}

int	not_valid_num(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int	error(int argc, char **argv, char *ptr)
{
	if (argc == 1 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (not_valid_num(argv[argc - 1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!(ptr))
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}

int	dict_error(int i, char **list_dict, char *ptr, char **dict)
{
	liberator(list_dict, ptr, dict);
	if (i == 1)
		write(2, "Dict Error\n", 11);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*ptr;
	char	**list_dict;
	char	**dict;
	int		len_dict;

	if (argc == 3)
		ptr = read_dict(argv[1]);
	else
		ptr = read_dict("numbers.dict");
	dict = NULL;
	list_dict = NULL;
	if (error(argc, argv, ptr))
		return (dict_error(0, list_dict, ptr, dict));
	list_dict = ft_split(ptr, "\n");
	if (!(valid_dict(list_dict)))
		return (dict_error(1, list_dict, ptr, dict));
	list_dict = manual_split(format(list_dict));
	dict = create_dict(list_dict, &len_dict);
	if (is_valid_num(argv[argc - 1], dict, len_dict))
		print_num_newline(argv[argc - 1], dict);
	else
		return (dict_error(1, list_dict, ptr, dict));
	return (liberator(list_dict, ptr, dict));
}
