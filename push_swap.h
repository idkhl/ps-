/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:42:07 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/27 15:39:26 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	int				content;
	int				couta;
	int				coutb;
	int				position;
	int				index;
	int				target;
	struct s_stack	*next;
}	t_stack;

void		swap(t_stack **stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
void		rot(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rev_rot(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

void		rota(t_stack **a, int *couta);
void		rotb(t_stack **stackb, int *coutb);

int			check_doublons(int ac, char **args);
int			check_max(char **args);
int			check_int(char **args);

t_stack		*initstack(int content);
t_stack		*fill_stack(char **av);
void		indexage(t_stack *a, int ac);
int			stack_size(t_stack *s);

int			sorted(t_stack *stack);
void		push_lower(t_stack **a, t_stack **b);
void		push_higher(t_stack **a, t_stack **b);
void		init_target_pos(t_stack **a, t_stack **stackb);
int			get_target(t_stack **a, int stackb_index, int tindex, int tpos);
void		get_position(t_stack **stack);
void		cost(t_stack **a, t_stack **b);
t_stack		*find_cheapest(t_stack **b);
void		do_move(t_stack **a, t_stack **stackb, t_stack *tmp);
void		replacing(t_stack **a);
int			find_lowest(t_stack **stack);

void		sort(t_stack **a, t_stack **b);
void		minisort(t_stack **stack);
void		megasort(t_stack **a, t_stack **b);
int			main(int ac, char **av);

t_stack		*ft_lstlast(t_stack *lst);
t_stack		*lst_new(long nb);
void		ft_lstadd_back(t_stack **lst, t_stack *elem);

long		ft_atol(char *str);
char		**ft_split(const char *s, char c);
char		*ft_strjoin2(int size, char **strs, char *sep);
int			ft_strlen2(char *str);
void		free_stack(t_stack **stack);
int			nb_abs(int nb);
void		echange(int *v, t_stack **changed, t_stack **ptr, t_stack *stack);

int			bonus(int flag);
// void		writelsta(t_stack *a);
// void		writelstb(t_stack *b);
// void		print_index(t_stack *stack);

#endif