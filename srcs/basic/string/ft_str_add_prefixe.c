/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_prefixe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:05:20 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 16:06:53 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_str_add_prefixe(char *prefix, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (prefix == NULL || str == NULL)
		return (NULL);
	tmp = ft_strdup(str);
	tmp2 = ft_strjoin(prefix, tmp);
	free(tmp);
	free(prefix);
	return (tmp2);
}
