/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:17:59 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/20 17:54:57 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TRUE 1
# define FALSE 0

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_printf
{
	//	variables used in the struct identify the flags passed in the printf function
	va_list	args;
	int		width;
	int		zero;	// zero padding
	int		point;
	int		dash;
	int		tl;		// total length
	int		sign;
	int		perc;
	int		spc;
	int		pound;
}				t_printf;

int			ft_printf(const char *format, ...);
int			ft_eval(t_printf *val, const char *format, int i);
t_printf	*ft_intialize(t_printf *val);
void		ft_print_char(t_printf *val);
void		ft_print_num(t_printf *val);
void		ft_print_string(t_printf *val);
void		ft_print_pointer(t_printf *val);
void		ft_print_unsigned_int(t_printf *val);
void		ft_print_hex(t_printf *val, char c);

#endif