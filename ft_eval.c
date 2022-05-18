/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/18 18:11:21 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_num(t_printf *val)
{
	int num;

	num = va_arg(val->args, int);
	val->tl += ft_strlen(ft_itoa(num));
	ft_putnbr_fd(num, 1);
}

void	ft_print_string(t_printf *val)
{
	char *str;

	str = va_arg(val->args, char *);
	val->tl += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

int ft_unsinged_nbr_l(unsigned int n)
{
	if (n < 0)
		n += 4294967295;
	else if (n < 10)
		return (1);
	return (ft_unsinged_nbr_l(n / 10) + 1);
}

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n < 0)
		n += 4294967295;
	else if (n < 10)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_put_unsigned_nbr_fd(n / 10, fd);
		n = (n % 10) + '0';
		write(fd, &n, 1);
	}
}


void	ft_print_unsigned_int(t_printf *val)
{
	unsigned int	u;

	u = va_arg(val->args, unsigned int);
	val->tl += ft_unsinged_nbr_l(u);
	ft_put_unsigned_nbr_fd(u, 1);
}

int	ft_pointer_l(unsigned long p)
{
	if (p == 0)
		return (0);
	return ft_pointer_l(p / 16) + 1;
}

void	ft_put_ptr(unsigned long p, int fd)
{
	if (p < 10)
	{
		p = p + '0';
		write(fd, &p, 1);
	}
	else
	{
		ft_put_ptr(p / 16, fd);
		if ((p % 16) < 10)
			p = (p % 16) + '0';
		else
			p = ((p % 16) - 10) + 'a';
		write(fd, &p, 1);
	}
}

void	ft_print_pointer(t_printf *val)
{
	unsigned long	p;

	p = va_arg(val->args, unsigned long);
	val->tl += ft_pointer_l(p) + 2;
	write(1, "0x", 2);
	ft_put_ptr(p, 1);
}

int	ft_hex_l(unsigned long x)
{
	if (x == 0)
		return (0);
	return ft_hex_l(x / 16) + 1;
}

void	ft_put_hex(unsigned long x, char c, int fd)
{
	if (x == 0)
		return;
	if (x < 10)
	{
		x = x + '0';
		write(fd, &x, 1);
	}
	else
	{
		ft_put_hex(x / 16, c, fd);
		if ((x % 16) < 10)
			x = (x % 16) + '0';
		else
		{
			if (c == 'X')
				x = ((x % 16) - 10) + 'A';
			if (c == 'x')
				x = ((x % 16) - 10) + 'a';
		}
		write(fd, &x, 1);
	}
}

void	ft_print_hex(t_printf *val, char c)
{
	unsigned long	x;

	x = va_arg(val->args, unsigned long);
	val->tl += ft_hex_l(x);
	ft_put_hex(x, c, 1);
}

int	ft_eval(t_printf *val, const char *format, int i)
{
	while (!(ft_strchr("cdsupixX%", format[i])))
	{
		if (format[i] == '-')
			write(1, "9", 1);
		i++;
		if (format[i] == '0')
			write(1, "0", 1);
	}
	if (format[i] == 'c')
		ft_print_char(val);
	if (format[i] == 'i' || format[i] == 'd')
		ft_print_num(val);
	if (format[i] == 's')
		ft_print_string(val);
	if (format[i] == 'u')
		ft_print_unsigned_int(val);
	if (format[i] == 'p')
		ft_print_pointer(val);
	if (format[i] == 'x' || format[i] == 'X')
		ft_print_hex(val, format[i]);
	return (i);
}
