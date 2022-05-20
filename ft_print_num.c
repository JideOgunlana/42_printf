/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:03:41 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/21 00:26:53 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_width_count(int width_count)
{
	while (width_count > 0)
	{
		write(1, " ", 1);
		width_count--;
	}
	return (width_count);
}

void	ft_print_num(t_printf *val)
{
	int		num;
	char	*str;
	int		width_count;

	width_count = 0;
	num = va_arg(val->args, int);
	str = ft_itoa(num);
	val->tl += ft_strlen(str);
	width_count = val->width - val->tl;
	free(str);
	if (((val->spc && val->sign) || val->sign) && num >= 0)
	{
			ft_putchar_fd('+', 1);
			val->tl += 1;
	}
	else if (val->spc && num >= 0 && width_count <= val->tl)
	{
		ft_putchar_fd(' ', 1);
		val->tl += 1;
	}
	width_count = ft_width_count(width_count);
	if (val->width > val->tl)
		val->tl = val->width;
	val->width = width_count;
	ft_putnbr_fd(num, 1);
}
