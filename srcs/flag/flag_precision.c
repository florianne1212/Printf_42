/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 08:51:35 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 11:45:31 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	activate_prec(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	flag->precision = true;
	return (1);
}
