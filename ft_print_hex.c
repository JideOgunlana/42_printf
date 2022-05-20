/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:38:06 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/20 17:48:30 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_l(unsigned int num)
{
	if (num < 16)
		return (1);
	return (ft_hex_l(num / 16) + 1);
}

void	ft_put_hex(unsigned int num, char c, int fd)
{
	if (num < 10)
	{
		num = num + '0';
		ft_putchar_fd(num, fd);
	}
	else
	{
		if (num / 16 != 0)
			ft_put_hex(num / 16, c, fd);
		if ((num % 16) < 10)
			num = (num % 16) + '0';
		else
		{
			if (c == 'x')
				num = ((num % 16) - 10) + 'a';
			if (c == 'X')
				num = ((num % 16) - 10) + 'A';
		}
		ft_putchar_fd(num, fd);
	}
}

void	ft_print_hex(t_printf *val, char c)
{
	unsigned int	num;

	num = va_arg(val->args, unsigned int);
	val->tl += ft_hex_l(num);
	if (val->pound && c == 'x' && num != 0)
	{
		write(1, "0x", 2);
		val->tl += 2;
	}
	if (val->pound && c == 'X' && num != 0)
	{
		write(1, "0X", 2);
		val->tl += 2;
	}
	ft_put_hex(num, c, 1);
}
