/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_h.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:05:29 by mapadron          #+#    #+#             */
/*   Updated: 2025/08/31 21:00:09 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H_H
# define RUSH_H_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	print_num_newline(char *num, char **dict);
char	*read_dict(char *direc);
char	**create_dict(char **list, int *len_dict);
char	**ft_split(char *str, char *charset);
int		ft_strlcpy(char *dest, char *src, int size);
int		buff_size(char **buff);
char	**manual_split(char **list);
char	**format(char **dict);
int		is_valid_num(char *num, char **dict, int len_dict);
char	*remove_zeros(char *num);
int		valid_dict(char **dict);
#endif
