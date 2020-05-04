/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_numeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:35:54 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 11:52:47 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	activate_number(const char *format, size_t index, t_flag *flag)
{
	if (flag->precision == true)
		return (check_len_prec(format, index, flag));
	else
		return (check_len_width(format, index, flag));
}

size_t	check_len_prec(const char *format, size_t index, t_flag *flag)
{
	flag->len_precision = ft_atoi(&format[index]);
	return (ft_count_base(flag->len_precision, "0123456789"));
}

size_t	check_len_width(const char *format, size_t index, t_flag *flag)
{
	flag->len_width = ft_atoi(&format[index]);
	return (ft_count_base(flag->len_width, "0123456789"));
}
