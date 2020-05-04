/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:10:19 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 17:42:23 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char				*check_flag_unsigned(t_flag *flag, char *arg, int len_arg)
{
	char			*to_add;
	char			*result;

	if (flag->len_width > 0 && flag->len_width > len_arg)
	{
		if (flag->zero == true && flag->justified == right &&
		(flag->len_precision == -1 || flag->len_precision == 0) &&
		flag->precision == true)
			to_add = ft_strnew(flag->len_width - len_arg, 32);
		if (flag->zero == true && flag->justified == right)
			to_add = ft_strnew(flag->len_width - len_arg, '0');
		else
			to_add = ft_strnew(flag->len_width - len_arg, 32);
		if (flag->justified == left)
			result = ft_str_add_suffix(arg, to_add);
		else if (flag->justified == right)
			result = ft_str_add_prefixe(to_add, arg);
		else
			result = ft_strdup("NULL");
	}
	else
		result = ft_strdup(arg);
	free(arg);
	return (result);
}

void				converter_unsigned_int(t_flag *flag)
{
	unsigned int	value;
	char			*result;

	value = va_arg(*(flag->arg), unsigned int);
	result = ft_itoa_base(value, "0123456789");
	if (flag->precision == true && flag->len_width > 0)
		flag->zero = false;
	if (value == 0 && flag->precision == true && flag->len_width > 0 &&
	(flag->len_precision == -1 || flag->len_precision == 0))
	{
		free(result);
		result = ft_strnew(1, 32);
		flag->zero = false;
	}
	else if (value == 0 && flag->precision == true &&
	(flag->len_precision == -1 || flag->len_precision == 0))
	{
		free(result);
		return ;
	}
	result = check_precision_digit(flag, result);
	result = check_flag_unsigned(flag, result, ft_strlen(result));
	add_str_to_buffer(result);
	free(result);
}
