/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:04:29 by bdropper          #+#    #+#             */
/*   Updated: 2026/01/27 06:20:06 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **source, t_node **destenation)
{
	t_node	*temp;

	if (!source || !*destenation)
		return (0);
	temp = *source;
	*source = (*source)->next;
	temp->next = *destenation;
	*destenation = temp;
	return (1);
}

/*take the first node and move it to the end
 */
int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		// an empty stack or idevidual nodes dont return anything
		return (0);
	first = *stack;       // save the first head
	*stack = first->next;
		/*move the stack head (the 'first' head still remains the same)
		visual [1] [2] [3] this is before ([1]) [2] [3] after 1 is still linked but no longer the headwh*/
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

int	reverse_rotate(t_node **stack)
{
	t_node *last;
	t_node *prev;

	if (!stack || !*stack || !(*stack)->next)
		return (0);

	last = *stack;
	prev = NULL;

	while (last->next)
	{
		prev = last;       // prev is now at the start of the stack
		last = last->next; // last is now one spot ahead of prev
	}

	prev->next = NULL;   // disconnect the end of the stack
	last->next = *stack; // attach end to the front of the list

	*stack = last;//now the stack officially starts with the original last number

	return (1);
}

int	swap(t_node **stack)
{
	t_node head;
	t_node tail;
}