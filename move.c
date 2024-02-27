/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:12:17 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/26 10:59:42 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move(t_stack **a, t_stack **b, t_stack *tmp)
{	
	if (tmp->couta < 0 && tmp->coutb < 0)
	{
		while (tmp->couta < 0 && tmp->coutb < 0)
		{
			tmp->couta++;
			tmp->coutb++;
			rrr(a, b);
		}
	}
	if (tmp->couta > 0 && tmp->coutb > 0)
	{
		while (tmp->couta > 0 && tmp->coutb > 0)
		{
			tmp->couta--;
			tmp->coutb--;
			rr(a, b);
		}
	}
	rota(a, &tmp->couta);
	rotb(b, &tmp->coutb);
	pa(a, b);
}

void	rota(t_stack **a, int *couta)
{
	while (*couta)
	{
		if (*couta > 0)
		{
			ra(a);
			(*couta)--;
		}
		else if (*couta < 0)
		{
			rra(a);
			(*couta)++;
		}
	}
}

void	rotb(t_stack **b, int *coutb)
{
	while (*coutb)
	{
		if (*coutb > 0)
		{
			rb(b);
			(*coutb)--;
		}
		else if (*coutb < 0)
		{
			rrb(b);
			(*coutb)++;
		}
	}
}
