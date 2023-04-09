/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:01:13 by tanakasola        #+#    #+#             */
/*   Updated: 2023/03/27 00:43:30 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	num[11];
	int		index;
	int		j;

	j = 0;
	if (n < 0)
		j += write(fd, "-", 1);
	else
		n *= -1;
	index = num_count(n);
	num[index + 1] = '\0';
	while (index >= 0)
	{
		num[index--] = (n % 10) * -1 + '0';
		n /= 10;
	}
	index++;
	while (num[index] != '\0')
		j += write(fd, &(num[index++]), 1);
	return (j);
}

int	num_count(int n)
{
	int	nbr;
	int	index;

	nbr = n;
	index = 0;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		index++;
	}
	return (index);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
		i++;
	}
	return (i);
}
