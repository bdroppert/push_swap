/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:26:14 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/12 20:33:42 by bdropper         ###   ########.fr       */
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
		// create next node
		curr = curr->next;
		// set next pointer to next node
		i++;
	}
	curr->next = NULL;
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

	/*these are not stacks themselves they are pointers tothe first node of two linked lists*/
	stack_a = NULL;
	stack_b = NULL;
	/*we set to null to make sure there is no garbage memory therefor the stacks are now empty*/
	if (argc < 2)
		return (0);
	if (!error_check(argc, argv, stack_a))
		return (1);
	create_stack_a(&stack_a, argc, argv);
	if (!sorted_stack(stack_a))
	{
		if(stack_size == 2)
			sa(stack_a);
		else if(stack_size == 3)
				
			assign_index(stack_a);
			radix_sort(&stack_a, &stack_b);
	}
	
	// print_stack(stack_a);
	return (0);
}

// void	print_stack(t_node *stack)
// {
// 	int i;

// 	i = 0;
// 	if (!stack)
// 	{
// 		printf("(empty stack)\n");
// 		return ;
// 	}
// 	while (stack)
// 	{
// 		printf("[%d] value=%d index=%d\n", i, stack->value, stack->index);
// 		stack = stack->next;
// 		i++;
// 	}
// 	printf("----\n");
// }