/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:03:41 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/20 16:58:44 by bogunlan         ###   ########.fr       */
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
	if((val->spc && val->sign) || val->sign)
	{
		// if (num < 0)
		// {
			// write(1, "-", 1);
			// val->tl += 1;
		// }
		if (num >= 0)
		{
			write(1, "+", 1);
			val->tl += 1;
		}
	}
	else if (val->spc && num >= 0)
	{
		write(1, " ", 1);
		val->tl += 1;
	}
	ft_putnbr_fd(num, 1);
}