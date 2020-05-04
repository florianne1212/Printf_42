  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:41:09 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 09:54:06 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_parse_flag(const char *format, size_t index, t_flag *flag)
{
	static t_flag_funct funct_flag_ptr[255] = {NULL};
	size_t				flag_len;

	if (funct_flag_ptr[0] == NULL)
		set_flag_funct_tab(funct_flag_ptr);
	flag_len = 0;
	index++;
	while (ft_strcmp_c("-0.*123456789", format[index + flag_len]) == true)
	{
		flag_len += funct_flag_ptr[(int)format[index + flag_len]](
			(char *)format, index + flag_len, flag);
	}
	flag->converter = format[index + flag_len];
	return (flag_len + 1);
}

void		ft_parse_c(const char *format, t_flag flag)
{
	static t_convert_funct	funct_convert_ptr[255] = {NULL};
	size_t					index;
	size_t					flag_len;
	char					c;

	if (funct_convert_ptr[0] == NULL)
		set_funct_converter_tab(funct_convert_ptr);
	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			flag_len = ft_parse_flag(format, index, &flag);
			c = flag.converter;
			if (funct_convert_ptr[(int)c] != NULL)
				funct_convert_ptr[(int)c](&flag);
			else
				converter_char_else(&flag, c);
			index += flag_len;
			reset_t_flag(&flag);
		}
		else
			add_char_to_buffer(format[index]);
		index++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	t_flag	flag;

	va_start(arg, format);
	flag = create_t_flag(&arg);
	ft_parse_c(format, flag);
	va_end(arg);
	ft_print_buffer();
	return (ft_return());
}
