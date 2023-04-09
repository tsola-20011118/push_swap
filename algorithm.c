/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:45:28 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 12:36:22 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_list **a, t_list **b, t_list *max)
{
	t_list	*move;

	// if (check_sort(*a, ft_lstsize(*a)) == 0)
	// {
	// 	max = *b;
	// 	ft_printf("test2\n");
	// }
	// else{
	while (check_afterall_sort(*a, ft_lstsize(*a) + 1, 0))
	{
		
		move = ideal(&max, *a, *b);
		*a = move;
		*b = move->b;
		// ft_printf("flag:%d, num:%d, a_index:%d, b_index:%d\n", move->flag,move->num, move->a_index, move->b_index);
		print_how_to_move(ft_lstsize(*a), ft_lstsize(*b), move, 0);
		// print_all(*a, *b);
		process_px(a, b, 'b');
	}
	// print_all(*a, *b);
	// }
	// ft_printf("####");
	t_list *temp;
	int		b_index;
	b_index = 0;
	temp = *b;
	while(temp->num != max->num)
	{
		temp = temp->next;
		b_index++;
	}
	
	if (b_index <= ft_lstsize(*b) / 2)
		while(b_index--)
			process_rx(b, 'b');
	else
	{
		// ft_printf("%d", index);
		b_index = ft_lstsize(*b) - b_index;
		while(b_index--)
			process_rrx(b, 'b');
	}
	// print_all(*a, *b);
	// ft_printf("%%%d\n", max->num);
	int		a_index;
	a_index = 0;
	temp = *a;
	while(check_afterall_sort(*a, ft_lstsize(*a), -1))
	{
		*a = (*a)->next;
		a_index++;
	}
	*a = temp;
	// ft_printf("%%%d\n", a_index);
	if (a_index <= ft_lstsize(*a) / 2)
		while(a_index--)
			process_rx(a, 'a');
	else
	{
		a_index = ft_lstsize(*a) - a_index;
		while(a_index--)
			process_rrx(a, 'a');
	}
	int i = 0;
	t_list	*a_max;
	a_max = (*a)->prev;
	while(*b)
	{
		if (!((a_max->num < (*b)->num && a_max == (*a)->prev ) 
				|| ((*b)->num > (*a)->prev->num && (*b)->num < (*a)->num) 
				|| (a_max->next->num >  (*b)->num && a_max == (*a)->prev)))
		{
			// ft_printf("####");
			process_rx(a, 'a');
		}
		else
		{
			if (a_max->num < (*b)->num && a_max == (*a)->prev ) 
				a_max = *b;
			i ++;
			// ft_printf("####");
			process_px(b, a, 'a');
		}
		// ft_printf("%d\n", i);
		// print_all(*a, *b);
		
	}
	while ((*a)->prev->num < (*a)->num)
	{
		// ft_printf("####");
		process_rx(a, 'a');
	}
	// print_all(*a, *b);
}

t_list	*ideal(t_list **max, t_list *temp_a, t_list *b)
{
	int		i;
	t_list	*temp_b;
	t_list	*move;

	i = 0;
	move = NULL;
	while (i < ft_lstsize(b))
	{
		temp_a->a_index = i;
		temp_b = b_ideal_check(i, &b, temp_a, max);
		if (!move || (move->index > temp_a->index))
		{
			move = temp_a;
			move->b = temp_b;
		}
		temp_a = temp_a->next;
		i++;
		if (move && ((move->index < i) || (move->index == 0)))
			break ;
	}
	if ((*max)->num < move->num)
		(*max) = move;
	return (move);
}

t_list	*b_ideal_check(int i, t_list **b, t_list *temp_a, t_list **max)
{
	int		j;
	t_list	*temp_b;

	j = 0;
	temp_b = *b;
	while (j < ft_lstsize(temp_b))
	{
		temp_a->b_index = j;
		if (ideal_place_check((*max), temp_a, temp_b))
		{
			ideal_rotate_check(i, j, temp_a,
				place_cmp(j, ft_lstsize(temp_b), i, ft_lstsize(temp_a)));
			break ;
		}
		temp_b = temp_b->next;
		j++;
	}
	return (temp_b);
}

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
