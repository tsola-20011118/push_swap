/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:13:32 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 13:01:49 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_multiple(t_list *lst, int size)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	while (i < size)
	{
		temp = lst;
		j = 0;
		while (j < size)
		{
			if (lst->num == temp->num && lst != temp)
				return (0);
			temp = temp->next;
			j++;
		}
		lst = lst->next;
		i++;
	}
	return (1);
}

int	argv_digit_check(char *s, int *number)
{
	long	num;
	int		minus;

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
	num = ps_atoi(s);
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

long	ps_atoi(char *s)
{
	long	num;

	num = 0;
	while (*s)
	{
		if ('0' <= *s && *s <= '9')
			num = 10 * num + *s - '0';
		else
			return (0);
		s++;
	}
	return (num);
}
