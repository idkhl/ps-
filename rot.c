/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:19:52 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/27 10:31:44 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	ra(t_stack **a)
{
	rot(a);
	if (bonus(0) == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rot(b);
	if (bonus(0) == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rot(a);
	if (b == NULL)
		return ;
	else
	{
		rot(b);
		if (bonus(0) == 0)
			write(1, "rr\n", 3);
	}
}
