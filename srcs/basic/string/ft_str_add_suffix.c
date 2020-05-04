/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:10:25 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 16:06:48 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_str_add_suffix(char *str, char *suffix)
{
	char	*tmp;
	char	*tmp2;

	if (suffix == NULL || str == NULL)
		return (NULL);
	tmp = ft_strdup(str);
	tmp2 = ft_strjoin(tmp, suffix);
	free(tmp);
	free(suffix);
	return (tmp2);
}
