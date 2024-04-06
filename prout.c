/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:42:13 by idakhlao          #+#    #+#             */
/*   Updated: 2024/03/13 14:01:43 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	megasort(t_stack **a, t_stack **b)
{	
	t_stack	*cheapest;

	if (stack_size(*a) > 5)
	{
		push_lower(a, b);
		push_higher(a, b);
	}
	else
	{
		pb(b, a);
		pb(b, a);
	}
	minisort(a);
	while (*b)
	{
		init_target_pos(a, b);
		cost(a, b);
		cheapest = find_cheapest(b);
		do_move(a, b, cheapest);
	}
	if (!sorted(*a))
		replacing(a);
}

void	cost(t_stack **a, t_stack **b)
{
	t_stack	*tmpb;
	int		sizea;
	int		sizeb;

	sizea = stack_size(*a);
	sizeb = stack_size(*b);
	tmpb = *b;
	while (tmpb)
	{
		tmpb->coutb = tmpb->position;
		if (tmpb->coutb > sizeb / 2)
			tmpb->coutb = (sizeb - tmpb->position) * -1;
		tmpb->couta = tmpb->target;
		if (tmpb->target > sizea / 2)
			tmpb->couta = (sizea - tmpb->target) * -1;
		tmpb = tmpb->next;
	}
}

void	init_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		tpos;

	get_position(a);
	get_position(b);
	tmp = *b;
	tpos = 0;
	while (tmp)
	{
		tpos = get_target(a, tmp->index, 2147483647, tpos);
		tmp->target = tpos;
		tmp = tmp->next;
	}
}

t_stack	*find_cheapest(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*cheapests;
	int		cheapest;

	tmp = *b;
	cheapest = 2147483647;
	while (tmp)
	{
		if (nb_abs(tmp->couta) + nb_abs(tmp->coutb) < (cheapest))
		{
			cheapest = nb_abs(tmp->coutb) + nb_abs(tmp->couta);
			cheapests = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapests);
}
