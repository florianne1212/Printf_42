/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:06:50 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 17:48:04 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	set_funct_converter_tab(t_convert_funct *funct_convert_ptr)
{
	size_t	i;

	i = 0;
	while (i < 254)
	{
		funct_convert_ptr[i] = NULL;
		i++;
	}
	funct_convert_ptr[0] = (void *)(-1);
	funct_convert_ptr['c'] = converter_char;
	funct_convert_ptr['s'] = converter_string;
	funct_convert_ptr['p'] = converter_adress;
	funct_convert_ptr['d'] = converter_digit;
	funct_convert_ptr['i'] = converter_digit;
	funct_convert_ptr['u'] = converter_unsigned_int;
	funct_convert_ptr['x'] = converter_x;
	funct_convert_ptr['X'] = converter_x_up;
	funct_convert_ptr['%'] = converter_percent;
}

char	*ft_place_adr(t_flag *flag, char *result, unsigned int value)
{
	if (value == 0 && flag->precision == true &&
	(flag->len_precision == -1 || flag->len_precision == 0)
	&& (flag->len_width == -1 || flag->len_width == 0))
	{
		free(result);
		add_str_to_buffer("0x");
		return (NULL);
	}
	else if (value == 0 && flag->precision == true &&
	(flag->len_precision == -1 || flag->len_precision == 0)
	&& flag->len_width > 0)
	{
		free(result);
		result = ft_strdup("0x");
		return (result);
	}
	return (NULL);
}

char	*get_place_di(t_flag *flag, char *result, unsigned int value)
{
	if (value == 0 && flag->precision == true && flag->len_width > 0 &&
	(flag->len_precision == -1 || flag->len_precision == 0))
	{
		free(result);
		return (ft_strnew(1, 32));
	}
	else if (value == 0 && flag->precision == true &&
	(flag->len_precision == -1 || flag->len_precision == 0))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_place_to_add(t_flag *flag, int len_arg)
{
	char	*to_add;

	if (flag->zero == true && flag->justified == right &&
	flag->precision == false)
		to_add = ft_strnew(flag->len_width - len_arg, '0');
	else if (flag->zero == true && flag->justified == left &&
	flag->precision == true)
		to_add = ft_strnew(flag->len_width - len_arg, 32);
	else
		to_add = ft_strnew(flag->len_width - len_arg, 32);
	return (to_add);
}
