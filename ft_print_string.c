/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:33:38 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/21 18:13:21 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	minus_flag(char *str, int width_count, t_printf *val, int str_len)
{
	ft_putstr_fd(str, 1);
	while (width_count > 0)
	{
		write(1, " ", 1);
		width_count--;
	}
	if (val->width > str_len)
		val->tl += val->width - str_len;
	val->width = width_count;
}

void	ft_print_string(t_printf *val)
{
	char	*str;
	int		width_count;
	int		str_len;

	width_count = 0;
	str = va_arg(val->args, char *);
	str_len = ft_strlen(str);
	if (str == NULL)
		str = "(null)";
	val->tl += str_len;
	width_count = val->width - str_len;
	if (val->dash)
	{
		minus_flag(str, width_count, val, str_len);
		return ;
	}
	while (width_count > 0)
	{
		write(1, " ", 1);
		width_count--;
	}
	if (val->width > (int) str_len)
		val->tl += val->width - str_len ;
	val->width = width_count;
	ft_putstr_fd(str, 1);
}
