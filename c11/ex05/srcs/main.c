/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:48:56 by mapadron          #+#    #+#             */
/*   Updated: 2025/09/01 12:43:53 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	op_init(void (*operators[5])(int, int))
{
	operators[0] = sum;
	operators[1] = substract;
	operators[2] = multiply;
	operators[3] = divide;
	operators[4] = modulo;
}

int	select_op(char *op)
{
	if (ft_strlen(op) != 1)
		return (-1);
	if (op[0] == '+')
		return (0);
	if (op[0] == '-')
		return (1);
	if (op[0] == '*')
		return (2);
	if (op[0] == '/')
		return (3);
	if (op[0] == '%')
		return (4);
	return (-1);
}

int	main(int argc, char **argv)
{
	void	(*operators[5])(int, int);
	int		op_num;

	if (argc != 4)
		return (0);
	op_init(operators);
	op_num = select_op(argv[2]);
	if (op_num == -1)
	{
		ft_putstr("0\n");
		return (0);
	}
	operators[op_num](ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putchar('\n');
	return (0);
}
