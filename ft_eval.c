/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/19 20:27:19 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_percentage(t_printf *val)
{
	char	perc;

	perc = va_arg(val->args, int);
	val->tl += write(1, "%", 1);
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
		i++;
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
	if (format[i] == '%')
		ft_print_percentage(val);
	return (i);
}
