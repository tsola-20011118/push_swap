/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:29:09 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 12:18:39 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_all(t_list *a, t_list *b)
{
	ft_printf("\n~~~~PRINT_ALL~~~~\n");
	ft_printf("a: ");
	print_any(a);
	ft_printf("\nb: ");
	print_any(b);
	ft_printf("\n-----------------\n");
}

void	print_any(t_list *lst)
{
	int		i;
	int		limit;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (lst)
	{
		limit = ft_lstsize(lst);
		while (i < limit)
		{
			ft_printf("%d ", lst->num);
			lst = lst->next;
			i++;
		}
	}
	else
		ft_printf("NULL");
	lst = temp;
}
