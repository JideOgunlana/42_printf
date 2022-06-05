/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:35:01 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/24 17:44:27 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsinged_nbr_l(unsigned int num)
{
	if (num < 10)
		return (1);
	return (ft_unsinged_nbr_l(num / 10) + 1);
}

void	ft_put_unsigned_nbr_fd(unsigned int num, int fd, t_printf *val)
{
	// printf("number is:%d", num);
	if ((long int) num == -2147483648)
	{
		val->tl += write(1, "-", 1);
	// printf("number is:%d", num);
		num *= -1;
	}
	if (num < 10)
	{
		num = num + '0';
		ft_putchar_fd(num, fd);
	}
	else
	{
		ft_put_unsigned_nbr_fd(num / 10, fd, val);
		num = (num % 10) + '0';
		ft_putchar_fd(num, fd);
	}
}

void	unum_dash_flag(unsigned int num, int width_count, t_printf *val)
{
	ft_put_unsigned_nbr_fd(num, 1, val);
	if (width_count > 0)
		val->tl += width_count;
	width_count = ft_width_count(val, width_count);
	val->width = 0;
}

void	ft_print_unsigned_int(t_printf *val)
{
	unsigned int	u;
	int				width_count;
	// char			*str;

	u = va_arg(val->args, unsigned int);
	// str = ft_itoa(u);
	val->tl += ft_unsinged_nbr_l(u);
	if (u >= 0 && (long int)u != -2147483648 )
		width_count = val->width - ft_unsinged_nbr_l(u);
	else
		width_count = val->width - ft_unsinged_nbr_l(u) - 1;
	// free(str);
	if (val->dash)
	{
		unum_dash_flag(u, width_count, val);
		val->dash = FALSE;
		return ;
	}
	if (width_count > 0)
		val->tl += width_count;
	width_count = ft_width_count(val, width_count);
	val->width =width_count;
	ft_put_unsigned_nbr_fd(u, 1, val);
}
