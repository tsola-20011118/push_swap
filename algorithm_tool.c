/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:39:02 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 16:59:07 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_afterall_sort(t_list *lst, int size, int num)
{
	int		i;
	int		flag;
	t_list	*temp;

	if (size == 1)
		return (0);
	temp = lst;
	i = 0;
	flag = 0;
	while (i < size - 1)
	{
		if (lst->num > lst->next->num)
		{
			if (flag == num)
				flag ++;
			else
				return (1);
		}
		lst = lst->next;
		i++;
	}
	lst = temp;
	return (0);
}

int	ideal_place_check(t_list *max, t_list *temp_a, t_list *temp_b)
{
	if (max->num < temp_a->num)
	{
		if (temp_b == max)
			return (1);
	}
	else if (max->prev->num > temp_a->num)
	{
		if (temp_b == max)
			return (1);
	}
	else
	{
		if (temp_b->num < temp_a->num && temp_a->num < temp_b->prev->num)
			return (1);
	}
	return (0);
}

void	ideal_rotate_check(int i, int j, t_list *temp_a, t_list *temp_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(temp_a);
	size_b = ft_lstsize(temp_b);
	if (temp_a->flag == -1)
	{
		if (i < j)
			temp_a->index = j;
		else
			temp_a->index = i;
	}
	else if (temp_a->flag == 1)
	{
		if ((size_a - i) > (size_b - j))
			temp_a->index = size_a - i;
		else
			temp_a->index = size_b - j;
		temp_a->a_index = size_a - i;
		temp_a->b_index = size_b - j;
	}
	else
	{
		if (i <= size_a / 2)
			temp_a->index = size_b + i - j;
		else
			temp_a->index = size_a - i + j;
	}
}

int	place_cmp(int j, int size_b, int i, int size_a)
{
	if (j <= (int)(size_b / 2) && i <= (int)(size_a / 2))
		return (-1);
	if (j > (int)(size_b / 2) && i > (int)(size_a / 2))
		return (1);
	return (0);
}
