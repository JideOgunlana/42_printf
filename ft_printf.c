/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:30:34 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/18 18:25:21 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_printf	*ft_intialize(t_printf *val)
{
	val->width = 0;
	val->prc = 0;
	val->zero = 0;
	val->point = 0;
	val->dash = 0;
	val->tl = 0;
	val->sign = 0;
	val->perc = 0;
	val->spc = 0;
	val->pound = 0;
	return (val);
}



int	ft_printf(const char *format, ...)
{
	t_printf				*val;
	int						ret;
	int			i;

	val = (t_printf *) malloc(sizeof(t_printf));
	if (!val)
		return(-1);
	ft_intialize(val);
	i = 0;
	ret = 0;
	va_start(val->args, format);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
			i = ft_eval(val, format, i + 1);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(val->args);
	ret += val->tl;
	free(val);
	return (ret);
}

int	main()
{
	char *p;

	p = "h";
	printf("\n%d",ft_printf("a %p", p));
	return (0);
}
