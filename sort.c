/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:43:33 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/26 11:18:08 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = tmp->content;
	while (tmp)
	{
		if (i > tmp->content)
			return (0);
		i = tmp->content;
		tmp = tmp->next;
	}
	return (1);
}

void	push_lower(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*a);
	pushed = 0;
	i = 0;
	while (i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
}

void	push_higher(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;

	size = stack_size(*a);
	pushed = 0;
	while (size - pushed > 3)
	{
		pb(b, a);
		pushed++;
	}
}
