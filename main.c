/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:26:14 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/17 19:03:45 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_node	*create_node(char *str)
{
	t_node	*new_node;

	new_node = calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = atoi(str);
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	create_stack_a(t_node **stack_a, int argc, char **argv)
{
	int		i;
	t_node	*curr;

	i = 1;
	*stack_a = create_node(argv[i++]);
	if (!*stack_a)
		return ;
	curr = *stack_a;
	while (i < argc)
	{
		curr->next = create_node(argv[i]);
		if (!curr->next)
			return ;
		curr = curr->next;
		i++;
	}
	curr->next = NULL;
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	create_stack_a(&stack_a, argc, argv);
	if (!error_check(argc, argv, stack_a))
		return (1);
	if (sorted_stack(stack_a))
		return (free_stack(stack_a), 0);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
