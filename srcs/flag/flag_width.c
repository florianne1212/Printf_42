/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:00:06 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 11:54:15 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	width_zero(t_flag *flag)
{
	if (flag->len_precision == 0)
	{
		flag->len_width = va_arg(*(flag->arg), int);
		if (flag->len_width == '0')
			flag->len_precision = 0;
		if (flag->len_width < 0)
		{
			flag->len_width = flag->len_width * (-1);
			flag->justified = left;
		}
	}
}

size_t	activate_w_p(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	flag->width = true;
	if (flag->precision == true)
	{
		if (flag->len_precision == 0)
			width_zero(flag);
		else
		{
			flag->len_precision = va_arg(*(flag->arg), int);
			if (flag->len_precision < 0)
				flag->precision = false;
		}
	}
	else
	{
		flag->len_width = va_arg(*(flag->arg), int);
		if (flag->len_width < 0)
		{
			flag->len_width = flag->len_width * (-1);
			flag->justified = left;
		}
	}
	return (1);
}
