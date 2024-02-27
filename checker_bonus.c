/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:11:24 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/27 17:33:00 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include "string.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

static void	check(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(b, a);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else
		write(2, "Error\n", 6);
}

static int	sortedd(t_stack *stack)
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

static void	check_if_sorted(t_stack **a)
{
	if (!sortedd(*a))
		write(2, "KO\n", 3);
	else if (sortedd(*a))
		write(1, "OK\n", 3);
}

int	bonus(int flag)
{
	if (flag == 1)
		return (1);
	else
		return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**params;
	char	*join_all;

	bonus(1);
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
	line = get_next_line(0);
	while (line)
	{
		check(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	check_if_sorted(&a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
