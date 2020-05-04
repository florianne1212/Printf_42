/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:21:14 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 18:12:45 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*check_precision_adresse(t_flag *flag, char *arg, int len_arg)
{
	char			*result;
	char			*to_add;

	if (flag->precision == true && flag->len_precision < len_arg)
	{
		len_arg = flag->len_precision;
		result = ft_strdup(arg);
	}
	else if (flag->precision == true && flag->len_precision > len_arg)
	{
		to_add = ft_strnew(flag->len_precision - len_arg, '0');
		result = ft_strjoin(to_add, arg);
		free(to_add);
	}
	else
		result = ft_strdup(arg);
	free(arg);
	return (result);
}

char	*check_flag_adress(t_flag *flag, char *arg, int len_arg)
{
	char			*to_add;
	char			*result;

	len_arg = len_arg + 2;
	if (arg[0] == '0' && arg[1] == 'x')
		len_arg = 2;
	if (flag->len_width > 0 && flag->len_width > len_arg)
	{
		if (flag->zero == true && flag->justified == right &&
		flag->precision == false)
			to_add = ft_strnew(flag->len_width - len_arg, '0');
		else
			to_add = ft_strnew(flag->len_width - len_arg, 32);
		if (flag->justified == left)
			result = ft_str_add_suffix(arg, to_add);
		else if (flag->justified == right ||
		(flag->justified == left && flag->zero == true))
			result = ft_str_add_prefixe(to_add, arg);
		else
			result = ft_strdup("NULL");
	}
	else
		result = ft_strdup(arg);
	free(arg);
	return (result);
}

char	*put_adresse(int i, char *str)
{
	char			*tmp;
	char			*to_add;
	char			*tmp2;
	int				j;
	char			*result;

	to_add = ft_strnew(i, ' ');
	tmp = ft_strjoin(to_add, "0x");
	j = i;
	i = 0;
	if (!(tmp2 = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[j] != '\0')
	{
		tmp2[i] = str[j];
		i++;
		j++;
	}
	tmp2[i] = '\0';
	result = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	free(to_add);
	return (result);
}

char	*ft_put_adr(char *str)
{
	int				i;
	char			*tmp;
	char			*result;

	i = 0;
	if (str[0] == '0' && str[1] == 'x')
	{
		tmp = ft_strdup(str);
		free(str);
		return (tmp);
	}
	if (ft_strcmp_c("0x123456789", str[0]) == true)
		result = ft_strjoin("0x", str);
	else
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if (str[i] == '0' && str[i + 1] == 'x')
			return (str);
		result = put_adresse(i, str);
	}
	free(str);
	return (result);
}

void	converter_adress(t_flag *flag)
{
	unsigned long	value;
	char			*result;
	char			*fin;
	int				len_arg;

	value = va_arg(*(flag->arg), unsigned long);
	fin = ft_itoa_base(value, "0123456789abcdef");
	len_arg = ft_strlen(fin);
	result = check_precision_adresse(flag, fin, len_arg);
	if (value == 0 && flag->precision == true &&
	(flag->len_precision == -1 || flag->len_precision == 0))
		result = ft_place_adr(flag, result, value);
	if (result == NULL)
		return ;
	len_arg = ft_strlen(result);
	result = check_flag_adress(flag, result, len_arg);
	result = ft_put_adr(result);
	add_str_to_buffer(result);
	free(result);
}
