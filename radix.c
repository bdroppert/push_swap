/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:31:06 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/12 16:21:58 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **a, t_node **b)
{
	int	bit;
	int	i;
	int	size;
	int	max_bits;

	bit = 0;
	max_bits = get_max_bits(*a);
	while (bit < max_bits)
	{
		i = 0;
		size = stack_size(*a);
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_max_bits(t_node *stack)
{
	int	max;
	int	bits;

	max = stack_size(stack) - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	assign_index(t_node *stack)
{
	t_node *a;
	t_node *b;
	int index;
	a = stack;
	while (a)
	{
		index = 0;
		b = stack;
		while (b)
		{
			if (b->value < a->value)
				index++;
			b = b->next;
		}
		a->index = index;
		a = a->next;
	}
}