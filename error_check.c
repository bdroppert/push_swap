/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:26:14 by bdropper          #+#    #+#             */
/*   Updated: 2026/01/24 08:04:42 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int number_check(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
/*in this function check will go one step ahead of curr to compare if the first node is equal to any of the
rest of the stack and if this isnt the case it will move the curr forwards and repeat this process*/
int no_duplicates(t_node *stack)
{
    t_node  *curr;
    t_node  *check; //will go ahead in the node to check against curr

    curr = stack;
    while(curr)
    {
        check = curr->next;
        while(check)
        {
            if (curr->value == check->value)
                return(1);
            check = check->next;
        }
        curr = curr->next;
    }
    return(0);
}


int     error_check(int argc, char *argv[], t_node *stack)
{
    int i = 1;
    while (i < argc)
    {
        if (!number_check(argv[i]))
    	{	
            printf("error\n");
            return(0);
        }
        if (no_duplicates(stack))
    	{	
            printf("error\n");
            return(0);
        }
		i++;
    }
    return (1);
}


