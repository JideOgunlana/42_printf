/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:03:41 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/23 19:59:16 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_num_flags(t_printf *val, int num, char *str, int width_count)
{
	if (((val->spc && val->sign) || val->sign) && num >= 0)
	{
		ft_putchar_fd('+', 1);
		val->tl += 1;
		val->spc = FALSE;
		val->sign = FALSE;
	}
	else if (val->spc && num >= 0 && val->width < (int) ft_strlen(str))
	{
		ft_putchar_fd(' ', 1);
		val->tl += 1;
		val->spc = FALSE;
	}
	if (val->width > (int) ft_strlen(str))
	val->tl += width_count;
	if (val->point > (int) ft_strlen(str) -1)
	{
		val->point = val->point - (ft_strlen(str) - 1);
		while (val->point > 0)
		{
			write(1, "0", 1);
			val->point--;
		}
	}
	return (width_count);
}

void	num_dash_flag(int num, int width_count, t_printf *val)
{
	ft_putnbr_fd(num, 1);
	if (width_count > 0)
		val->tl += width_count;
	width_count = ft_width_count(val, width_count);
	val->width = width_count;
}

void	ft_print_num(t_printf *val)
{
	int		num;
	char	*str;
	int		width_count;

	num = va_arg(val->args, int);
	str = ft_itoa(num);
	val->tl += ft_strlen(str);
	width_count = val->width - ft_strlen(str);
	free(str);
	if (val->dash)
	{
		num_dash_flag(num, width_count, val);
		val->dash = FALSE;
		return ;
	}
	width_count = check_num_flags(val, num, str, width_count);
	if (num < 0 && val->zero)
	{
		write(1, "-", 1);
		num *= -1;
	}
	width_count = ft_width_count(val, width_count);
	val->width = width_count;
	val->point = 0;
	ft_putnbr_fd(num, 1);
}
