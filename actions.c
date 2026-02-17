/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:19:12 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/17 18:35:31 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push

int	pa(t_node **stack_a, t_node **stack_b)
{
	if (!push(stack_b, stack_a))
		return (0);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_node **stack_a, t_node **stack_b)
{
	if (!push(stack_a, stack_b))
		return (0);
	write(1, "pb\n", 3);
	return (1);
}

// swap

int	sa(t_node **stack_a)
{
	if (!swap(stack_a))
		return (0);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_node **stack_b)
{
	if (!swap(stack_b))
		return (0);
	write(1, "sb\n", 3);
	return (1);
}
