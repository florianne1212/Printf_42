/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:47:46 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 16:29:22 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*check_precision(t_flag *flag, char *arg)
{
	char	*result;
	int		len_arg;

	len_arg = ft_strlen(arg);
	if (flag->precision == true && flag->len_precision < len_arg)
	{
		len_arg = flag->len_precision;
		result = ft_strndup(arg, len_arg);
	}
	else
		result = ft_strdup(arg);
	return (result);
}

char		*check_flag(t_flag *flag, char *arg, int len_arg)
{
	char	*to_add;
	char	*result;

	if (flag->len_width > 0 && flag->len_width > len_arg)
	{
		if (flag->zero == true && flag->justified == right)
			to_add = ft_strnew(flag->len_width - len_arg, '0');
		else if (flag->zero == true && flag->justified == left)
			to_add = ft_strnew(flag->len_width - len_arg, ' ');
		else
			to_add = ft_strnew(flag->len_width - len_arg, ' ');
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

void		converter_string(t_flag *flag)
{
	char		*arg;
	char		*result;
	int			len_arg;

	arg = va_arg(*(flag->arg), char*);
	if (arg == NULL)
	{
		arg = "(null)";
	}
	result = check_precision(flag, arg);
	len_arg = ft_strlen(result);
	result = check_flag(flag, result, len_arg);
	add_str_to_buffer(result);
	free(result);
}
