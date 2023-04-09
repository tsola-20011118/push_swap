/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:39:02 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 11:53:55 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_multiple(t_list *lst, int size)
{
	int	i;
	int	j;
	t_list	*temp;

	

	i = 0;
	while (i < size)
	{
		// ft_printf("%d == %d",lst->num, temp->num);
		temp = lst;
		j = 0;
		while (j < size)
		{
			// if (lst != temp)
			// 	ft_printf("%d == %d\n",lst->num, temp->num);
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

int	check_sort(t_list *lst, int size)
{
	int		i;
	t_list	*temp;

	if (size == 1)
		return (0);
	temp = lst;
	i = 0;
	while (i < size - 1)
	{
		// ft_printf("%d-%d>0\n", lst->num ,lst->next->num);
		if (lst->num > lst->next->num)
		{
			lst = temp;
			return (1);
		}
		lst = lst->next;
		i++;
	}
	lst = temp;
	return (0);
}

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
		// ft_printf("%d>%d\n", lst->num ,lst->next->num);
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
	// if ((!(max->num < temp_a->num
	// 			|| max->prev->num > temp_a->num)
	// 		&& (temp_b->num < temp_a->num && temp_a->num < temp_b->prev->num))
	// 	|| (max == temp_b
	// 		&& ((max->num < temp_a->num && max->prev->num < temp_a->num)
	// 			|| (max->num > temp_a->num && max->prev->num > temp_a->num))))
	// {
	// 	return (1);
	// }
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
		// ft_printf("$$$$");
		if (temp_b->num < temp_a->num && temp_a->num < temp_b->prev->num)
			return (1);
	}
	return (0);
}

void	ideal_rotate_check(int i, int j, t_list *temp_a, int flag)
{
	if (flag == -1)
	{
		temp_a->flag = -1;
		if (i < j)
			temp_a->index = j;
		else
			temp_a->index = i;
	}
	else if (flag == 1)
	{
		temp_a->flag = 1;
		if (i < j)
			temp_a->index = j;
		else
			temp_a->index = i;
	}
	else
	{
		temp_a->flag = 0;
		temp_a->index = i + j;
	}
}

int	place_cmp(int j, int size_b, int i, int size_a)
{
	if (i != 0 && j != 0 && j <= (int)(size_b / 2) && i <= (int)(size_a / 2))
		return (-1);
	if (i != 0 && j != 0 && j > (int)(size_b / 2) && i > (int)(size_a / 2))
		return (1);
	return (0);
}
