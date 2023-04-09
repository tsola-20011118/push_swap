/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:07:25 by tanakasola        #+#    #+#             */
/*   Updated: 2023/04/09 17:13:34 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include <inttypes.h>
# include <limits.h>
# include <sysexits.h>

// printf
# include "printf.h"

typedef struct s_list
{
	int				num;
	int				a_index;
	int				b_index;
	int				flag;
	int				index;
	struct s_list	*b;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// push_swap
t_list	*store(int argc, char **argv);

// push_swap_tool
int		check_multiple(t_list *lst, int size);
int		argv_digit_check(char *s, int *number);
void	error_print(void);
long	ps_atoi(char *s);

// algorithm
void	algorithm(t_list **a, t_list **b, t_list *max);
t_list	*ideal(t_list **max, t_list *temp_a, t_list *b);
t_list	*b_ideal_check(int i, t_list **b, t_list *temp_a, t_list **max);

// algorithm_rotate
void	print_how_to_move(int size_a, int size_b, t_list *move, int i);
int		b_rotate(t_list **b, t_list *max);
int		a_rotate(t_list **a);
void	a_b_rotate(t_list **a, t_list **b, int a_index, int b_index);
void	last_rotate(t_list **a);
void	return_rotate(t_list **a, t_list **b);

// algorithm_tool
int		check_afterall_sort(t_list *lst, int size, int num);
int		ideal_place_check(t_list *max, t_list *temp_a, t_list *temp_b);
void	ideal_rotate_check(int i, int j, t_list *temp_a, t_list *temp_b);
int		place_cmp(int j, int size_b, int i, int size_a);

// lst_operation
t_list	*lst_new(int content);
int		ft_lstsize(t_list *lst);
void	new_lst_add_front(t_list **lst, int content);

// process
void	process_sx(t_list **lst, char flag);
void	process_px(t_list **from, t_list**to, char flag);
void	process_rx(t_list **lst, char flag);
void	process_rrx(t_list **lst, char flag);

// tool
void	print_all(t_list	*a, t_list	*b);
void	print_any(t_list *lst);

#endif