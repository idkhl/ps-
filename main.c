/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:48:16 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/27 17:29:16 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2 && !sorted(*a))
	{
		ra(a);
		return ;
	}
	else if (stack_size(*a) == 3 && !sorted(*a))
	{
		minisort(a);
		return ;
	}
	else if (stack_size(*a) > 3 && !sorted(*a))
	{
		megasort(a, b);
		return ;
	}
}

void	minisort(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = -1;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	if ((*stack)->index == max)
		ra(stack);
	else if ((*stack)->next->index == max)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

int	bonus(int flag)
{
	if (flag == 0)
		return (0);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**params;
	char	*join_all;

	bonus(0);
	join_all = ft_strjoin2(ac - 1, &av[1], " ");
	if (!join_all)
		return (0);
	params = ft_split(join_all, ' ');
	free(join_all);
	if (params == NULL)
		return (0);
	if (check_doublons(ac, params) == -1 || check_max(params) == -1
		|| check_int(params) == -1)
		return (0);
	a = fill_stack(params);
	b = NULL;
	free(params);
	indexage(a, stack_size(a));
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

// void	writelsta(t_stack *stack)
// {
// 	printf("\n");

// 	printf(" \nDEBUT AFFICHAGE DE LISTE A\n");
// 	while (stack != NULL)
// 	{
// 		printf("%d\n", stack->content);
// 		stack = stack->next;
// 		//if (stack != NULL)
// 		//printf(" - ");
// 	}
// 	printf(" \nFIN AFFICHAGE DE LISTE A\n");
// 	//printf("stack : %d\n", stack->content);
// }

// void	writelstb(t_stack *stack)
// {
// 	printf("\n");
// 	printf(" \nDEBUT AFFICHAGE DE LISTE B\n");
// 	while (stack != NULL)
// 	{
// 		printf("%d\n", stack->content);
// 		stack = stack->next;
// 		//if (stack != NULL)
// 		//printf(" - ");
// 	}
// 	printf(" \nFIN AFFICHAGE DE LISTE B\n");
// 	//printf("stack : %d\n", stack->content);
// }
