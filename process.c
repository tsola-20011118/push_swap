/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:05:42 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/02 09:07:54 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_sx(t_list **lst, char flag)
{
	int	temp;

	if (!(*lst) || ft_lstsize(*lst) == 1)
		return ;
	temp = (*lst)->num;
	(*lst)->num = (*lst)->next->num;
	(*lst)->next->num = temp;
	if (flag)
		ft_printf("s%c\n", flag);
}

void	process_px(t_list **from, t_list**to, char flag)
{
	t_list	*temp;

	if (!(*from))
		return ;
	temp = *from;
	if (ft_lstsize(*from) == 1)
		*from = NULL;
	else
	{
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		*from = temp->next;
	}
	if (*to)
	{
		temp->next = *to;
		temp->prev = (*to)->prev;
		(*to)->prev->next = temp;
		(*to)->prev = temp;
		*to = temp;
	}
	else
	{
		*to = lst_new(temp->num);
		free(temp);
	}
	if (flag)
		ft_printf("p%c\n", flag);
}

void	process_rx(t_list **lst, char flag)
{
	(*lst) = (*lst)->next;
	if (flag)
		ft_printf("r%c\n", flag);
}

void	process_rrx(t_list **lst, char flag)
{
	(*lst) = (*lst)->prev;
	if (flag)
		ft_printf("rr%c\n", flag);
}
