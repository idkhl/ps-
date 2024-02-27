/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:14:10 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/27 17:48:30 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublons(int ac, char **args)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
	{
		return (0);
	}
	while (i < ac - 1)
	{
		j = 0;
		while (j < ac - 1)
		{
			if (ft_atol(args[i]) == ft_atol(args[j]) && i != j)
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_max(char **args)
{
	int	i;
	int	j;
	int	zero;

	i = 0;
	zero = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] == '0')
		{	
			if (args[i][j] == '0')
				zero++;
			j++;
		}
		if (j > 12 + zero)
			return (write(2, "Error\n", 6), -1);
		printf("%ld", ft_atol(args[i]));
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (write(2, "Error\n", 6), -1);
		i++;
	}
	return (0);
}

int	check_int(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] != '-'
			&& (args[i][j] < '0' || args[i][j] > '9')
			&& args[i][j] != ' '
			&& args[i][j] != '+')
				return (write(2, "Error\n", 6), -1);
			j++;
		}
		i++;
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	check_doublons(ac, av);
// 	check_int(av);
// 	check_max(av);
// }
