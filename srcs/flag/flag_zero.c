/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:56:35 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 09:48:03 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	activate_zero(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	if (flag->zero == false && flag->precision == false)
		flag->zero = true;
	else
		flag->len_precision = ft_atoi(&format[index]);
	return (1);
}
