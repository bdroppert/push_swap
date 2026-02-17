/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:46 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/17 16:13:58 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

int					number_check(char *str);
int					error_check(int argc, char *argv[], t_node *stack);
t_node				*create_node(char *str);
void				create_stack_a(t_node **stack_a, int argc, char **argv);
void				print_list(t_node *stack_a);
int					no_duplicates(t_node *stack);
int					sorted_stack(t_node *stack);
void				free_stack(t_node *stack);
size_t				node_index(t_node *stack, t_node *node);

int					push(t_node **source, t_node **destenation);
int					rotate(t_node **stack);
int					reverse_rotate(t_node **stack);
int					swap(t_node **stack);

int					pa(t_node **stack_a, t_node **stack_b);
int					pb(t_node **stack_a, t_node **stack_b);
int					sa(t_node **stack_a);
int					sb(t_node **stack_b);
int					ra(t_node **stack_a);
int					rb(t_node **stack_b);
int					rra(t_node **stack_a);
int					rrb(t_node **stack_b);
int					ss(t_node **stack_a, t_node **stack_b);
int					rr(t_node **stack_a, t_node **stack_b);
int					rrr(t_node **stack_a, t_node **stack_b);

void				radix_sort(t_node **a, t_node **b);
int					stack_size(t_node *stack);
int					get_max_bits(t_node *stack);
void				assign_index(t_node *stack);
void				sort_stack(t_node **stack_a, t_node **stack_b);

void				sort_three(t_node **stack);
void				sort_five(t_node **a, t_node **b);
int					find_smallest_pos(t_node *stack);
void				print_stack(t_node *stack);
static int			is_overflow(char *str);

#endif