/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:33:38 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/19 17:23:15 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

void	ft_print_string(t_printf *val)
{
	char *str;
	
	str = va_arg(val->args, char *);
	if (str == NULL)
		str = "(null)";
	val->tl += ft_strlen(str);
	ft_putstr_fd(str, 1);
}
