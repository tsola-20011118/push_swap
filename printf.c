/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanakasola <tanakasola@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:07:09 by sola              #+#    #+#             */
/*   Updated: 2023/03/27 00:43:27 by tanakasola       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		temp_str;
	int		ret;

	ret = 0;
	temp_str = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			write(1, str++ - temp_str, temp_str);
			ret += temp_str;
			temp_str = 0;
			ret += printf_if(&ap, *str);
		}
		else
			temp_str++;
		str++;
	}
	if (temp_str)
		ret += write(1, str - temp_str, temp_str);
	va_end(ap);
	return (ret);
}

int	printf_if(va_list *ap, char str)
{
	if (str == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), 1));
	else if (str == 's')
		return (ft_putstr_fd(va_arg(*ap, char *), 1));
	else if (str == 'p')
		return (uintptr16(va_arg(*ap, uintptr_t)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr_fd(va_arg(*ap, int), 1));
	else if (str == 'u')
		return (unsignedint(va_arg(*ap, unsigned int)));
	else if (str == 'x')
		return (int16((long)va_arg(*ap, int), 'a'));
	else if (str == 'X')
		return (int16((long)va_arg(*ap, int), 'A'));
	else if (str == '%')
		return (write(1, &str, 1));
	return (0);
}

int	unsignedint(unsigned int num)
{
	char			number[12];
	int				i;
	unsigned int	temp;
	int				temp_i;

	if (num == 0)
		return (write(1, "0", 1));
	temp = num;
	i = 0;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	temp_i = i;
	number[i--] = 0;
	while (i >= 0)
	{
		number[i--] = '0' + num % 10;
		num /= 10;
	}
	return (write(1, number, temp_i));
}

int	uintptr16(uintptr_t num)
{
	uintptr_t	buf;
	char		number[100];
	int			amount;

	write(1, "0x", 2);
	if (num == 0)
		return (2 + write(1, "0", 1));
	buf = 1;
	while (buf <= num / 16)
		buf *= 16;
	amount = 0;
	while (num != 0 || buf != 1)
	{
		if (num / buf < 10)
			number[amount++] = '0' + num / buf ;
		else
			number[amount++] = 'a' + num / buf - 10;
		if (num % buf == 0 && buf / 16 == 1)
			number[amount++] = '0';
		if (buf == 1)
			break ;
		num = num - num / buf * buf;
		buf /= 16;
	}
	return (2 + write(1, number, amount));
}

int	int16(long num, char st)
{
	char	number[11];
	int		i;
	long	temp;
	int		i_temp;

	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
		num = num + 4294967295 + 1;
	i = 0;
	temp = num;
	while (temp / 16 != 0 && i++ != -1)
		temp /= 16;
	number[i + 1] = 0;
	i_temp = i + 1;
	while (num != 0)
	{
		if (num % 16 < 10)
			number[i--] = '0' + num % 16;
		else
			number[i--] = st + num % 16 - 10;
		num /= 16;
	}
	return (write(1, number, i_temp));
}
