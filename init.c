/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:39:29 by idakhlao          #+#    #+#             */
/*   Updated: 2024/03/13 13:39:46 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initstack(int content)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (s == NULL)
		return (NULL);
	s->content = content;
	s->index = -1;
	s->target = -1;
	s->position = -1;
	s->couta = -1;
	s->coutb = -1;
	s->next = NULL;
	return (s);
}

t_stack	*fill_stack(char **params)
{
	int		i;
	t_stack	*s;
	t_stack	*new;

	i = 0;
	s = NULL;
	new = NULL;
	while (params[i] != NULL)
	{
		if (i == 0)
			s = initstack(ft_atol(params[i]));
		else
		{
			new = initstack(ft_atol(params[i]));
			ft_lstadd_back(&s, new);
		}
		i++;
	}
	return (s);
}

void	indexage(t_stack *a, int taille)
{
	t_stack	*ptr;
	t_stack	*changed;
	int		value;
	int		i;

	i = 0;
	while (++i <= taille)
	{
		ptr = a;
		changed = NULL;
		value = INT_MAX;
		while (ptr)
		{
			if (ptr->content == INT_MAX && ptr->index == -1)
				ptr->index = taille;
			if (ptr->content < value && ptr->index == -1)
				echange(&value, &changed, &ptr, a);
			else
				ptr = ptr->next;
		}
		if (changed != NULL)
			changed->index = i;
	}
}

int	stack_size(t_stack *s)
{
	t_stack	*tmp;
	int		i;

	tmp = s;
	i = 1;
	if (tmp == NULL)
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
