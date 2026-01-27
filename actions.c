/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:19:12 by bdropper          #+#    #+#             */
/*   Updated: 2026/01/27 02:55:09 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push

void	pa(t_node **stack_a, t_node **stack_b)
{
	if(!push(stack_b, stack_a))
        return(0);
    ft_printf("pa\n");
    return(1);
}

void    pb(t_node **stack_a, t_node **stack_b)
{
    if(!push(stack_a, stack_b))
        return(0);
    ft_printf("pb\n");
    return(1);
}
