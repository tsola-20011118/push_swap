/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:12:25 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 13:26:11 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_how_to_move(int size_a, int size_b, t_list *move, int i)
{
	if (move->flag == -1)
		while ((move->index)--)
			ft_printf("rr\n");
	else if (move->flag == 0)
	{
		i = 0;
		if (move->a_index <= (int)(size_a / 2))
			while (i++ < (move->a_index))
				ft_printf("ra\n");
		else
			while (i++ < (size_a - move->a_index))
				ft_printf("rra\n");
		i = 0;
		if (move->b_index <= (int)(size_b / 2))
			while (i++ < (move->b_index))
				ft_printf("rb\n");
		else
			while (i++ < (size_b - move->b_index))
				ft_printf("rrb\n");
	}
	else
		while ((move->index)--)
			ft_printf("rrr\n");
}

void	b_rotate(t_list **b, t_list *max)
{
	t_list	*temp;
	int		b_index;

	b_index = 0;
	temp = *b;
	while (temp->num != max->num)
	{
		temp = temp->next;
		b_index++;
	}
	if (b_index <= ft_lstsize(*b) / 2)
		while (b_index--)
			process_rx(b, 'b');
	else
	{
		b_index = ft_lstsize(*b) - b_index;
		while (b_index--)
			process_rrx(b, 'b');
	}
}

void	a_rotate(t_list **a)
{
	t_list	*temp;
	int		a_index;

	a_index = 0;
	temp = *a;
	while (check_afterall_sort(*a, ft_lstsize(*a), -1))
	{
		*a = (*a)->next;
		a_index++;
	}
	*a = temp;
	if (a_index <= ft_lstsize(*a) / 2)
		while (a_index--)
			process_rx(a, 'a');
	else
	{
		a_index = ft_lstsize(*a) - a_index;
		while (a_index--)
			process_rrx(a, 'a');
	}
}

void	last_rotate(t_list **a)
{
	t_list	*temp;
	int		index;

	index = 0;
	temp = *a;
	while (temp->prev->num < temp->num)
	{
		index ++;
		temp = temp->next;
	}
	if (index < ft_lstsize(*a))
		while (index--)
			process_rx(a, 'a');
	else
	{
		index = ft_lstsize(*a) - index;
		while (index--)
			process_rrx(a, 'a');
	}
}

void	return_rotate(t_list **a, t_list **b)
{
	t_list	*a_max;

	a_max = (*a)->prev;
	while (*b)
	{
		if (!((a_max->num < (*b)->num && a_max == (*a)->prev)
				|| ((*b)->num > (*a)->prev->num && (*b)->num < (*a)->num)
				|| (a_max->next->num > (*b)->num && a_max == (*a)->prev)))
		{
			process_rx(a, 'a');
		}
		else
		{
			if (a_max->num < (*b)->num && a_max == (*a)->prev)
				a_max = *b;
			process_px(b, a, 'a');
		}
	}
}
