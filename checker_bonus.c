/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:11:24 by idakhlao          #+#    #+#             */
/*   Updated: 2024/03/13 17:31:30 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	check(t_stack **a, t_stack **b, char *line)
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
		return (write(2, "Error\n", 6), exit(0), -1);
	return (1);
}

static int	sortedd(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	if (!a)
		return (exit(0), write(2, "Error\n", 6), -1);
	tmp = a;
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

static void	check_if_sorted(t_stack **a, t_stack **b)
{
	if (!sortedd(*a) || *b)
		write(2, "KO\n", 3);
	else if (sortedd(*a) && !(*b))
		write(1, "OK\n", 3);
	free_stack(a);
	free_stack(b);
}

int	bonus(int flag)
{
	if (flag == 0)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**params;
	char	*line;

	line = ft_strjoin2(ac - 1, &av[1], " ");
	if (!line)
		return (0);
	params = ft_split(line, ' ');
	free(line);
	if (!params || check_entry(ac, params) == -1)
		return (malloc_free(params), -1);
	a = fill_stack(params);
	b = NULL;
	malloc_free(params);
	indexage(a, stack_size(a));
	line = get_next_line(0);
	while (line && check(&a, &b, line))
	{
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	return (check_if_sorted(&a, &b), 0);
}

// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	char	**params;
// 	char	*line;
// 	char	*join_all;

// 	join_all = ft_strjoin2(ac - 1, &av[1], " ");
// 	if (!join_all)
// 		return (0);
// 	params = ft_split(join_all, ' ');
// 	free(join_all);
// 	if (!params)
// 		return (0);
// 	if (check_entry(ac, params) == -1)
// 	{
// 		malloc_free(params);
// 		return (-1);
// 	}
// 	a = fill_stack(params);
// 	b = NULL;
// 	malloc_free(params);
// 	indexage(a, stack_size(a));
// 	line = get_next_line(0);
// 	while (line)
// 	{
// 		check(&a, &b, line);
// 		free(line);
// 		line = get_next_line(0);
// 	}
// 	if (line)
// 		free(line);
// 	check_if_sorted(&a, &b);
// 	return (0);
// }
