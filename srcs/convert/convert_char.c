/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:25:06 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 16:14:02 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*check_flag_char(t_flag *flag, char *arg, int value)
{
	char	*to_add;
	char	*result;
	int		len_arg;

	len_arg = ft_strlen(arg);
	if (value == '\x00')
		len_arg++;
	if (flag->len_width > 0 && flag->len_width > len_arg)
	{
		if (flag->zero == true && flag->justified == right)
			to_add = ft_strnew(flag->len_width - len_arg, '0');
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

void		add_char_convert(t_flag *flag, char *result, int value)
{
	int		len_arg;

	len_arg = ft_strlen(result);
	if (value == '\x00')
	{
		if (flag->justified == left)
			add_char_to_buffer('\0');
		if (len_arg < flag->len_width)
			add_str_to_buffer(result);
		if (flag->justified == right)
			add_char_to_buffer('\0');
	}
	else
		add_str_to_buffer(result);
}

void		converter_char(t_flag *flag)
{
	int		value;
	char	*result;

	value = va_arg(*(flag->arg), int);
	if (value == '\x00')
		result = ft_strnew(0, '\0');
	else
	{
		if (!(result = malloc(sizeof(char) * (2))))
			return ;
		result[0] = value;
		result[1] = '\0';
	}
	result = check_flag_char(flag, result, value);
	add_char_convert(flag, result, value);
	free(result);
}
