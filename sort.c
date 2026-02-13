/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:43:48 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/13 20:25:59 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		assign_index(*stack_a);
		radix_sort(stack_a, stack_b);
	}
}

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && first > third && second < third)
		ra(stack);
	else if (first < second && first > third)
		rra(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first < second && second > third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first > second && second < third)
		sa(stack);
}

// void	sort_five(t_node **stack_a, t_node **stack_b, int stack_size)
// {
// 	t_node	*smallest;

// 	if (sorted_stack(*stack_a))
// 		return ;
// 	while (stack_size-- > 3)
// 	{
// 		smallest = find_smallest(*stack_a);
// 		move_to_top(stack_a, smallest->value);
// 		pb(stack_a, stack_b);
// 	}
// 	sort_three(stack_a);
// 	while (*stack_b)
// 		pa(stack_a, stack_b);
// }