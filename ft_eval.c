/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/17 17:24:29 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_char(t_printf *val)
{
	char c;

	c = va_arg(val->args, int);
	val->tl += write(1, &c, 1);
}

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
	else
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

int	ft_eval(t_printf *val, const char *format, int i)
{
	char	str[] = "cdsupixX%";
	while (!(ft_strchr(str, format[i])))
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
	return (i);

}
