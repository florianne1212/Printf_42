/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:12:07 by fcoudert          #+#    #+#             */
/*   Updated: 2020/01/28 16:03:49 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

enum e_bool	ft_strcmp_c(char *p_src, char p_target)
{
	int	i;

	i = 0;
	if (p_src == NULL || p_target == '\0')
		return (0);
	while (p_src[i] != '\0')
	{
		if (p_src[i] == p_target)
			return (true);
		i++;
	}
	return (false);
}
