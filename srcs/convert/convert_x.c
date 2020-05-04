/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:28:45 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 17:48:24 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char				*check_flag_spe(t_flag *flag, char *arg, int len_arg)
{
	char			*to_add;
	char			*result;

	if (flag->len_width > 0 && flag->len_width > len_arg)
	{
		if (flag->zero == true && flag->justified == right &&
		flag->precision == false)
			to_add = ft_strnew(flag->len_width - len_arg, '0');
		else if (flag->zero == true && flag->justified == left &&
		flag->precision == true)
			to_add = ft_strnew(flag->len_width - len_arg, ' ');
		else
			to_add = ft_strnew(flag->len_width - len_arg, ' ');
		if (flag->justified == left)
			result = ft_str_add_suffix(arg, to_add);
		else if (flag->justified == right)
			result = ft_str_add_prefixe(to_add, arg);
		else
			return (ft_strdup("NULL"));
	}
	else
		result = ft_strdup(arg);
	free(arg);
	return (result);
}

void				converter_x(t_flag *flag)
{
	unsigned int	value;
	char			*result;
	int				len_arg;

	value = va_arg(*(flag->arg), unsigned int);
	result = ft_itoa_base(value, "0123456789abcdef");
	if (value == 0 && flag->precision == true && flag->len_width > 0 &&
	(flag->len_precision == -1 || flag->len_precision == 0))
	{
		free(result);
		result = " ";
		result = ft_strdup(result);
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
