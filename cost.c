/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:03:03 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/26 10:51:01 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_target(t_stack **a, int b_index, int tindex, int tpos)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < tindex)
		{
			tindex = tmp->index;
			tpos = tmp->position;
		}
		tmp = tmp->next;
	}
	if (tindex != 2147483647)
		return (tpos);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < tindex)
		{
			tindex = tmp->index;
			tpos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (tpos);
}

int	find_lowest(t_stack **stack)
{
	t_stack	*a;
	int		lowest_index;
	int		lowest_position;

	a = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_position = a->position;
	while (a)
	{
		if (a->index < lowest_index)
		{
			lowest_index = a->index;
			lowest_position = a->position;
		}
		a = a->next;
	}
	return (lowest_position);
}

void	replacing(t_stack **a)
{
	int	low_nbr;
	int	taille_s;

	taille_s = stack_size(*a);
	low_nbr = find_lowest(a);
	if (low_nbr > taille_s / 2)
	{
		while (low_nbr < taille_s)
		{
			rra(a);
			low_nbr++;
		}
	}
	else
	{
		while (low_nbr > 0)
		{
			ra(a);
			low_nbr--;
		}
	}
}
