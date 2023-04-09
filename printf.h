/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:08:17 by sola              #+#    #+#             */
/*   Updated: 2023/03/27 00:43:17 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include <inttypes.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	output(char *flag, ...);
int	num_count(int n);
int	ft_putnbr_fd(int n, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	uintptr16(uintptr_t num);
int	int16(long num, char st);
int	unsignedint(unsigned int num);
int	printf_if(va_list *ap, char str);

#endif