/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:36:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/19 18:17:16 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_l(unsigned long p)
{
	if (p < 16)
		return (1);
	return (ft_pointer_l(p / 16) + 1);
}

void	ft_put_ptr(unsigned long p, int fd)
{
	if (p < 10)
	{
		p = p + '0';
		write(fd, &p, 1);
	}
	else
	{
		if (p / 16 != 0)
			ft_put_ptr(p / 16, fd);
		if ((p % 16) < 10)
			p = (p % 16) + '0';
		else
			p = ((p % 16) - 10) + 'a';
		write(fd, &p, 1);
	}
}

void	ft_print_pointer(t_printf *val)
{
	unsigned long	p;

	p = va_arg(val->args, unsigned long);
	val->tl += ft_pointer_l(p) + 2;
	write(1, "0x", 2);
	ft_put_ptr(p, 1);
}

