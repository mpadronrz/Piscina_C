/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_h.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:36:48 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/03 13:26:00 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H_H
# define BSQ_H_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	t_point	size;
	char	**map;
	char	obs;
	char	full;
	char	empty;
	t_point	max;
	int		sq;
}	t_map;
void	ft_putstr(char *str);
void	ft_putstrnl(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
char	**ft_split(char *str, char *charset);
int		create_map(char *name, t_map *map);
int		solve(t_map *map);
int		write_map(t_map map);
int		validate_map(t_map *map);
int		free_map(t_map *map);
char	**free_split(char **splited, int i);
#endif
