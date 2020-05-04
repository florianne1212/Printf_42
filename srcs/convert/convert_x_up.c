/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:38 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 15:27:09 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void				converter_x_up(t_flag *flag)
{
	unsigned int	value;
	char			*result;
	int				len_arg;

	value = va_arg(*(flag->arg), unsigned int);
	result = ft_itoa_base(value, "0123456789ABCDEF");
	if (value == 0 && flag->precision == true && flag->len_width > 0 &&
	(flag->len_precision == -1 || flag->len_precision == 0))
	{
		free(result);
		result = ft_strnew(1, 32);
	}
	else if (value == 0 && flag->precision == true &&
	(flag->len_precision == -1 || flag->len_precision == 0))
	{
		free(result);
		return ;
	}
	result = check_precision_digit(flag, result);
	len_arg = ft_strlen(result);
	result = check_flag_spe(flag, result, len_arg);
	add_str_to_buffer(result);
	free(result);
}
