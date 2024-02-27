/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:57:57 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/27 08:54:54 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_stack **a)
{
	swap(a);
	if (bonus(0) == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	if (bonus(0) == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	if (bonus(0) == 0)
		write(1, "ss\n", 3);
}
