/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:16:50 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 11:49:01 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BASIC_H
# define FT_PRINTF_BASIC_H

# include "unistd.h"

char			*ft_itoa_base(unsigned long nbr, char *base);
char			*ft_itoa(int n);
char			*ft_str_add_prefixe(char *str, char *prefix);
char			*ft_str_add_suffix(char *str, char *suffix);
enum e_bool		ft_strcmp_c(char *p_src, char p_target);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size, char a);
size_t			ft_strlen(char *str);
char			*ft_strsub(const char *s, size_t start, size_t length);
void			*ft_memalloc(size_t size);
char			*ft_memset(void *b, int c, size_t len);
int				ft_atoi(const char *str);
char			*ft_strndup(const char *s1, int n);
int				ft_strlen_int(char *str);
size_t			ft_count_base(unsigned long c, char *base);

#endif
