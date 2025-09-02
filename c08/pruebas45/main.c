/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:36:33 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/28 19:28:58 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	main(int argc, char **argv)
{
	t_stock_str	*par;
	int			i;

	par = ft_strs_to_tab(argc, argv);
	ft_show_tab(par);
	i = 0;
	while (i < argc)
	{
		free(par[i].copy);
		i ++;
	}
	free(par);
	return (0);
}
