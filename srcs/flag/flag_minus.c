/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:45:16 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/03 15:56:11 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	activate_minus(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	flag->justified = left;
	return (1);
}
