/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:35:01 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/20 17:51:01 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsinged_nbr_l(unsigned int n)
{
	if (n < 0)
		n += 4294967295;
	else if (n < 10)
		return (1);
	return (ft_unsinged_nbr_l(n / 10) + 1);
}

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n < 0)
		n += 4294967295;
	else if (n < 10)
	{
		n = n + '0';
		ft_putchar_fd(n, fd);
	}
	else
	{
		ft_put_unsigned_nbr_fd(n / 10, fd);
		n = (n % 10) + '0';
		ft_putchar_fd(n, fd);
	}
}

void	ft_print_unsigned_int(t_printf *val)
{
	unsigned int	u;

	u = va_arg(val->args, unsigned int);
	val->tl += ft_unsinged_nbr_l(u);
	ft_put_unsigned_nbr_fd(u, 1);
}
