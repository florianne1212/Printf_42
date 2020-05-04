/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:06:36 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 16:41:40 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*check_flag_char_(t_flag *flag, char *arg, int value)
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

void		converter_char_else(t_flag *flag, int c)
{
	int		value;
	char	*result;

	value = c;
	if (value == '\x00')
		result = ft_strnew(0, '\0');
	else
	{
		if (!(result = malloc(sizeof(char) * (2))))
			return ;
		result[0] = value;
		result[1] = '\0';
	}
	result = check_flag_char_(flag, result, value);
	add_char_convert(flag, result, value);
	free(result);
}
