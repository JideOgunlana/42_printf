/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/17 17:24:29 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}
int	ft_eval(t_printf *val, const char *format, int i)
{
	char	str[] = "cdsupixX%";
	while (!(ft_strchr(str, format[i])))
	{
		if (format[i] == '-')
		{
			write(1, "9", 1);
		}
		i++;
	}
	if (format[i] == 'c')
		ft_print_char(format[i]);
	printf("%c",val->args);
	return (i);

}
