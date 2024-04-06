/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:14:10 by idakhlao          #+#    #+#             */
/*   Updated: 2024/03/13 13:38:41 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_entry(int ac, char **av)
{
	if (check_doublons(ac, av) == -1)
		return (-1);
	if (check_max(av) == -1 || check_int(av) == -1)
		return (-1);
	if (!*av)
		return (write(2, "Error\n", 6), -1);
	else
		return (0);
}

int	check_doublons(int ac, char **args)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
	{
		return (-1);
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
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (write(2, "Error\n", 6), -1);
		i++;
		zero = 0;
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
			if (args[i][j] != '-' && (args[i][j] < '0' || args[i][j] > '9')
			&& args[i][j] != ' ' && args[i][j] != '+')
				return (write(2, "Error\n", 6), -1);
			if ((args[i][j] == '-' || args[i][j] == '+')
			&& j != 0)
				return (write(2, "Error\n", 6), -1);
			if ((args[i][j] == '-' || args[i][j] == '+')
			&& ft_strlen2(args[i]) == 1)
				return (write(2, "Error\n", 6), -1);
			j++;
		}
		i++;
	}
	return (0);
}
