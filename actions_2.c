/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:33:14 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/12 13:14:13 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate

int	ra(t_node **stack_a)
{
	if (!rotate(stack_a))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_node **stack_b)
{
	if (!rotate(stack_b))
		return (0);
	write(1, "rb\n", 3);
	return (1);
}

// reverse rotate

int	rra(t_node **stack_a)
{
	if (!reverse_rotate(stack_a))
		return (0);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_node **stack_b)
{
	if (!reverse_rotate(stack_b))
		return (0);
	write(1, "rrb\n", 4);
	return (1);
}