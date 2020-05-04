/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 08:21:45 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 08:31:41 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strsub(const char *s, size_t start, size_t length)
{
	char	*result;
	size_t	i;

	i = 0;
	if (s == NULL || start > ft_strlen((char*)s) || length == 0)
		return (NULL);
	result = ft_strnew(length, '\0');
	while (i < length && ft_strcmp_c(("-0.*"), s[start]) == true)
		start++;
	while (i < length)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
