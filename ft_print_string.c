/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:33:38 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/20 23:59:22 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_string(t_printf *val)
{
	char	*str;
	int		width_count;

	width_count = 0;
	str = va_arg(val->args, char *);
	if (str == NULL)
		str = "(null)";
	val->tl += ft_strlen(str);
	width_count = val->width - val->tl;
	while (width_count > 0)
	{
		write(1, " ", 1);
		width_count--;
	}
	if (val->width > val->tl)
		val->tl = val->width;
	val->width = width_count;
	ft_putstr_fd(str, 1);
}
