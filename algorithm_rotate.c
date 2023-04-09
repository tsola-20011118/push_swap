/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:12:25 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 17:29:11 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_how_to_move(int size_a, int size_b, t_list *move, int i)
{
	if (move->flag == -1)
	{
		while (move->index)
		{
			if (move->a_index > 0 && move->b_index > 0)
				ft_printf("rr\n");
			else if (move->a_index > 0)
				ft_printf("ra\n");
			else if (move->b_index > 0)
				ft_printf("rb\n");
			move->a_index--;
			move->b_index--;
			move->index--;
		}
	}
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
	{
		while ((move->index)--)
		{
			if (move->a_index > 0 && move->b_index > 0)
				ft_printf("rrr\n");
			else if (move->a_index > 0)
				ft_printf("rra\n");
			else if (move->b_index > 0)
				ft_printf("rrb\n");
			move->a_index--;
			move->b_index--;
		}
	}
}

int	b_rotate(t_list **b, t_list *max)
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
	return(b_index);
}

int	a_rotate(t_list **a)
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
	return(a_index);

}

void	a_b_rotate(t_list **a, t_list **b, int a_index, int b_index)
{
	int	flag;
	int i;

	flag = place_cmp(b_index, ft_lstsize(*b), a_index, ft_lstsize(*a));
	if (flag == -1)
	{
		while (a_index > 0 || b_index > 0)
		{
			if (a_index > 0 && b_index > 0)
			{
				process_rx(a, 0);
				process_rx(b, 0);
				ft_printf("rr\n");
			}
			else if (a_index > 0 && b_index <= 0)
				process_rx(a, 'a');
			else if (a_index <= 0 && b_index > 0)
				process_rx(b, 'b');
			a_index--;
			b_index--;
		}
	}
	else if (flag == 1)
	{
		a_index = ft_lstsize(*a) - a_index;
		b_index = ft_lstsize(*b) - b_index;
		while (a_index > 0 || b_index > 0)
		{
			if (a_index > 0 && b_index > 0)
			{
				process_rrx(a, 0);
				process_rrx(b, 0);
				ft_printf("rrr\n");
			}
			else if (a_index > 0 && b_index <= 0)
				process_rrx(a, 'a');
			else if (a_index <= 0 && b_index > 0)
				process_rrx(b, 'b');
			a_index--;
			b_index--;
		}
	}
	else
	{
		i = 0;
		if (a_index <= ft_lstsize(*a) / 2)
			while (i++ < a_index)
				process_rx(a, 'a');
		else
			while (i++ < (ft_lstsize(*a) - a_index))
				process_rrx(a, 'a');
		i = 0;
		if (b_index <= ft_lstsize(*b) / 2)
			while (i++ < b_index)
				process_rx(b, 'b');
		else
			while (i++ < (ft_lstsize(*b) - b_index))
				process_rrx(b, 'b');
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
	t_list	*temp;
	int		index;

	a_max = (*a)->prev;
	while (*b)
	{
		temp = *a;
		index = 0;
		while (!((a_max->num < (*b)->num && a_max == (*a)->prev)
				|| ((*b)->num > (*a)->prev->num && (*b)->num < (*a)->num)
				|| (a_max->next->num > (*b)->num && a_max == (*a)->prev)))
		{
			index++;
			*a = (*a)->next;
		}
		*a = temp;
		if (index <= ft_lstsize(*a))
			while (index--)
				process_rx(a, 'a');
		else
		{
			index = ft_lstsize(*a) - index;
			while (index--)
				process_rrx(a, 'a');
		}
		if (a_max->num < (*b)->num && a_max == (*a)->prev)
			a_max = *b;
		process_px(b, a, 'a');
	}
}
