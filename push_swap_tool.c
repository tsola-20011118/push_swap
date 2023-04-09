/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:13:32 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/02 13:15:43 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 入ってきたargvが数字かの判定
int	argv_digit_check(char *s, int *number)
{
	long	num;
	int		minus;

	// ft_printf("%s\n", s);
	num = 0;
	if (*s == '0' && *(s + 1) == 0)
	{
		*number = 0;
		return (1);
	}
	if (*s == '-')
	{
		minus = -1;
		s++;
	}
	else
		minus = 1;
	while (*s)
	{
		if ('0' <= *s && *s <= '9')
			num = 10 * num + *s - '0';
		else
		{
			num = 0;
			break ;
		}
		s++;
	}
	if (num < INT32_MIN || INT32_MAX < num)
		num = 0;
	if (num == 0)
		return (0);
	*number = (int)num * minus;
	return (1);
}

void	error_print(void)
{
	ft_printf("Error\n");
	exit (0);
}
