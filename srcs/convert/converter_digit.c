/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:30:50 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 17:49:35 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*check_precision_digit(t_flag *flag, char *arg)
{
	char			*result;
	int				len_arg;
	char			*to_add;

	len_arg = ft_strlen(arg);
	if (flag->precision == true && flag->len_precision < len_arg)
	{
		len_arg = flag->len_precision;
		result = ft_strdup(arg);
	}
	else if (flag->precision == true && flag->len_precision > len_arg)
	{
		to_add = ft_strnew(flag->len_precision - len_arg, '0');
		result = ft_str_add_prefixe(to_add, arg);
	}
	else
		result = ft_strdup(arg);
	free(arg);
	return (result);
}

char	*check_flag_digit(t_flag *flag, char *arg, int len_arg)
{
	char			*to_add;
	char			*result;

	if (flag->len_width > 0 && flag->len_width > len_arg)
	{
		if ((flag->arg_neg == true && flag->justified == true) ||
		(flag->arg_neg == true && flag->zero == true &&
		flag->precision == false))
			len_arg++;
		to_add = get_place_to_add(flag, len_arg);
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

int		check_flag_convert(t_flag *flag)
{
	int				value;
	unsigned int	value_po;

	value_po = 0;
	flag->digit = true;
	value = va_arg(*(flag->arg), int);
	if (value == -2147483648)
		value_po = 2147483648;
	else if (value < 0)
	{
		flag->arg_neg = true;
		value_po = value * (-1);
	}
	else
		value_po = value;
	return (value_po);
}

char	*ft_put_neg(char *str)
{
	int				i;
	char			*tmp;

	i = 0;
	if (ft_strcmp_c("0123456789", str[0]) == true)
	{
		tmp = ft_strjoin("-", str);
		free(str);
		return (tmp);
	}
	else
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		str[i - 1] = '-';
		tmp = ft_strdup(str);
	}
	free(str);
	return (tmp);
}

void	converter_digit(t_flag *flag)
{
	unsigned int	value;
	char			*result;
	int				len_arg;
	int				i;

	i = 0;
	len_arg = 0;
	value = check_flag_convert(flag);
	result = ft_itoa(value);
	result = get_place_di(flag, result, value);
	if (result == NULL)
		return ;
	result = check_precision_digit(flag, result);
	len_arg += ft_strlen(result);
	result = check_flag_digit(flag, result, len_arg);
	if (flag->arg_neg == true)
		result = ft_put_neg(result);
	add_str_to_buffer(result);
	free(result);
}
