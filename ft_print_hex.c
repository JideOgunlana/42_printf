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

#include <stdio.h>
#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	if (num < 16)
		return (1);
	return (ft_hex_len(num / 16) + 1);
}

int	check_width_count(t_printf *val, int num, int width_count, char c)
{
	if (val->pound && c == 'x' && num != 0)
	{
		width_count -= 2;
		width_count = ft_width_count(val, width_count);
		write(1, "0x", 2);
		if (width_count < 0)
			val->tl += 2;
		val->pound = FALSE;
	}
	if (val->pound && c == 'X' && num != 0)
	{
		width_count -= 2;
		write(1, "0X", 2);
		width_count = ft_width_count(val, width_count);
		width_count -= 2;
		if (width_count < 0)
		val->tl += 2;
		val->pound = FALSE;
	}
	val->width = 0;
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

void	hex_has_dash(t_printf *val, int num, char c, int width_count)
{
	if (c == 'x' && num != 0)
	{
		if (val->pound)
			width_count -= write(1, "0x", 2);
		ft_put_hex(num, c, 1);
		width_count = ft_width_count(val, width_count);
		if (width_count < 0 && val->pound)
			val->tl += 2;
		val->pound = FALSE;
	}
	if (c == 'X' && num != 0)
	{
		if (val->pound)
			width_count -= write(1, "0X", 2);
		ft_put_hex(num, c, 1);
		width_count = ft_width_count(val, width_count);
		if (width_count < 0 && val->pound)
			val->tl += 2;
		val->pound = FALSE;
	}
	val->width = 0;
}

void	ft_print_hex(t_printf *val, char c)
{
	unsigned int	num;
	int				width_count;
	
	num = va_arg(val->args, unsigned int);
	val->tl += ft_hex_len(num);
	width_count = val->width - ft_hex_len(num);
	if (width_count > 0)
		val->tl += width_count;
		while (width_count > 0 && !val->pound)
		{
			if (val->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			width_count--;
		}
	if (val->dash)
	{
		hex_has_dash(val, num, c, width_count);
		val->dash = FALSE;
		return ;
	}
	width_count = check_width_count(val, num, width_count, c);
	val->width = width_count;
	ft_put_hex(num, c, 1);
}
