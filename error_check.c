/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:26:14 by bdropper          #+#    #+#             */
/*   Updated: 2026/01/21 19:06:58 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int number_check(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
        {
            printf("(%s) This string has a character in it..", str);
            return (0);
        }
        i++;
    }
    return (1);
}

int     error_check(int argc, char **argv)
{
    int i = 1;
    while (i < argc)
    {
        if (!number_check(argv[i]))
    	{	
        return (0);
        }
		printf("%s\n", argv[i]);
		i++;
    }
    return (1);
}
