/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:43:48 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/17 17:19:48 by bdropper         ###   ########.fr       */
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
	else if (size == 5)
	{
		assign_index(*stack_a);
		sort_five(stack_a, stack_b);
	}
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

void	sort_five(t_node **a, t_node **b)
{
	int	pos;
	int	size;

	// push first smallest
	pos = find_smallest_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
	pb(a, b);
	// push second smallest
	pos = find_smallest_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
	pb(a, b);
	// sort remaining 3
	sort_three(a);
	// restore
	pa(a, b);
	pa(a, b);
	// final fix: compare by value, not index
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

int	find_smallest_pos(t_node *stack)
{
	int	pos;
	int	smallest;
	int	i;

	pos = 0;
	i = 0;
	smallest = stack->index;
	while (stack)
	{
		if (stack->index < smallest)
		{
			smallest = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

// we check if it is already sorted to not run the other functions while we already have what we desire
int	sorted_stack(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			// is the current value bigger than the next value
			return (0);
		stack = stack->next; // move to the next node
	}
	return (1);
}
