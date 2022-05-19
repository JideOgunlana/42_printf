/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:03:41 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/19 19:09:43 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(t_printf *val)
{
	int num;
	char *str;

	num = va_arg(val->args, int);
	str = ft_itoa(num);
	val->tl += ft_strlen(str);
	free(str);
	ft_putnbr_fd(num, 1);
}