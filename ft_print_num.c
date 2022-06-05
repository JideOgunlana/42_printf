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

void	num_point_flag(t_printf *val, char *str)
{
	if (strchr(str, '-'))
	{
		write(1, "-", 1);
		str = ft_strtrim(str, "-");
	}
	while (val->point > (int) ft_strlen(str))
	{
		val->tl += write(1, "0", 1);
		val->point--;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return ;
}

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
	if (val->point)
		num_point_flag(val, str);
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
	if (num < 0 && num != -2147483648 && val->zero)
	{
		write(1, "-", 1);
		num *= -1;
	}
	width_count = ft_width_count(val, width_count);
	val->width = width_count;
	if (!val->point)
		ft_putnbr_fd(num, 1);
}
