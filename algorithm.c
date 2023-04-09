/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:45:28 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 16:49:53 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_list **a, t_list **b, t_list *max)
{
	t_list	*move;

	while (check_afterall_sort(*a, ft_lstsize(*a) + 1, 0))
	{
		move = ideal(&max, *a, *b);
		// print_all(*a,*b);
		*a = move;
		*b = move->b;
		// priznt_all(*a,*b);
		print_how_to_move(ft_lstsize(*a), ft_lstsize(*b), move, 0);
		process_px(a, b, 'b');
	}
	// print_all(*a,*b);
	b_rotate(b, max);
	a_rotate(a);
	return_rotate(a, b);
	// print_all(*a,*b);
	last_rotate(a);
}

t_list	*ideal(t_list **max, t_list *temp_a, t_list *b)
{
	int		i;
	t_list	*temp_b;
	t_list	*move;

	i = 0;
	move = NULL;
	while (i < ft_lstsize(temp_a))
	{
		temp_a->a_index = i;
		temp_b = b_ideal_check(i, &b, temp_a, max);
		// ft_printf("^^%d:%d\n", temp_a->num, temp_a->flag);
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
	// ft_printf("**%d:%d\n", move->num, move->flag);
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
			temp_a->flag = place_cmp(j, ft_lstsize(temp_b), i, ft_lstsize(temp_a));
			ideal_rotate_check(i, j, temp_a, temp_b);
			
			break ;
		}
		temp_b = temp_b->next;
		j++;
	}
	return (temp_b);
}
