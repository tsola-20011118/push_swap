/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:55:52 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/02 09:08:05 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	ret->a_index = 0;
	ret->b_index = 0;
	ret->flag = -1;
	ret->index = 0;
	ret->next = ret;
	ret->prev = ret;
	ret->num = content;
	return (ret);
}

int	ft_lstsize(t_list *lst)
{
	int		index;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	index = 1;
	while (lst->next && lst->next != temp)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

void	new_lst_add_front(t_list **lst, int content)
{
	t_list	*ret;

	ret = lst_new(content);
	if ((*lst)->next == *lst)
	{
		(*lst)->next = ret;
		ret->next = *lst;
		ret->prev = *lst;
	}
	else
	{
		ret->next = *lst;
		ret->prev = (*lst)->prev;
		(*lst)->prev->next = ret;
	}
	(*lst)->prev = ret;
	*lst = ret;
}
