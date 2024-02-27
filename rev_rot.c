/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:17:16 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/27 10:49:06 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_stack **a)
{
	rev_rot(a);
	if (bonus(0) == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rot(b);
	if (bonus(0) == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rot(a);
	rev_rot(b);
	if (bonus(0) == 0)
		write(1, "rrr\n", 4);
}
