/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 08:08:21 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 09:50:24 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <string.h>

char	g_buffer[300] = {0};
int		g_buffer_curseur = 0;
int		g_to_return = 0;

void	ft_print_buffer(void)
{
	write(1, g_buffer, g_buffer_curseur);
}

void	add_char_to_buffer(char c)
{
	if (g_buffer_curseur == 298)
	{
		ft_print_buffer();
		g_buffer_curseur = 0;
		ft_memset(g_buffer, 0, sizeof(g_buffer));
		g_buffer[g_buffer_curseur] = c;
		g_buffer_curseur++;
		g_to_return++;
	}
	else
	{
		g_buffer[g_buffer_curseur] = c;
		g_buffer_curseur++;
		g_to_return++;
	}
}

void	add_str_to_buffer(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		add_char_to_buffer(str[i]);
		i++;
	}
}

int		ft_return(void)
{
	int i;
	int j;

	j = 0;
	i = g_to_return;
	while (j < g_buffer_curseur)
	{
		g_buffer[j] = 0;
		j++;
	}
	g_to_return = 0;
	g_buffer_curseur = 0;
	ft_memset(g_buffer, 0, sizeof(g_buffer));
	return (i);
}
