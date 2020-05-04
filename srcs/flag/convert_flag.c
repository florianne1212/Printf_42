/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:09:14 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 11:51:50 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_flag	create_t_flag(va_list *arg)
{
	t_flag result;

	result.arg = arg;
	result.justified = right;
	result.precision = false;
	result.zero = false;
	result.digit = false;
	result.width = false;
	result.arg_neg = false;
	result.len_precision = -1;
	result.len_width = -1;
	result.converter = 0;
	return (result);
}

void	reset_t_flag(t_flag *flag)
{
	flag->justified = right;
	flag->precision = false;
	flag->zero = false;
	flag->digit = false;
	flag->width = false;
	flag->arg_neg = false;
	flag->len_precision = -1;
	flag->len_width = -1;
	flag->converter = 0;
}

void	set_flag_funct_tab(t_flag_funct *funct_flag_ptr)
{
	size_t	i;

	i = 0;
	while (i < 254)
	{
		funct_flag_ptr[i] = NULL;
		i++;
	}
	funct_flag_ptr[0] = (void *)(-1);
	funct_flag_ptr['0'] = activate_zero;
	funct_flag_ptr['*'] = activate_w_p;
	funct_flag_ptr['.'] = activate_prec;
	funct_flag_ptr['-'] = activate_minus;
	funct_flag_ptr['1'] = activate_number;
	funct_flag_ptr['2'] = activate_number;
	funct_flag_ptr['3'] = activate_number;
	funct_flag_ptr['4'] = activate_number;
	funct_flag_ptr['5'] = activate_number;
	funct_flag_ptr['6'] = activate_number;
	funct_flag_ptr['7'] = activate_number;
	funct_flag_ptr['8'] = activate_number;
	funct_flag_ptr['9'] = activate_number;
}
