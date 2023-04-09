/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:02:56 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 16:56:10 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	if (argc <= 2)
		return (0);
	a = store(argc, argv);
	b = NULL;
	if (argc == 3 && a->num > a->next->num)
		process_sx(&a, 'a');
	if (argc == 3 || check_afterall_sort(a, ft_lstsize(a), -1) == 0)
		return (0);
	if (check_multiple(a, ft_lstsize(a)) == 0)
		error_print();
	process_px(&a, &b, 'b');
	process_px(&a, &b, 'b');
	if (b->num < b->next->num)
		process_sx(&b, 'b');
	algorithm(&a, &b, b);
	return (0);
}

t_list	*store(int argc, char **argv)
{
	t_list	*a;
	int		num;
	int		i;

	a = NULL;
	i = argc - 1;
	while (i > 0)
	{
		if (argv_digit_check(argv[i], &num))
		{
			if (i == argc - 1)
				a = lst_new(num);
			else
				new_lst_add_front(&a, num);
		}
		else
			error_print();
		i--;
	}
	return (a);
}
