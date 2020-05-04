/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:20:40 by fcoudert          #+#    #+#             */
/*   Updated: 2020/02/10 11:47:31 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H# define FT_PRINTF_H

# include "ft_printf_basic.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

enum			e_bool
{
	true = 1,
	false = 0
};

enum			e_dir
{
	right = 0,
	left = 1
};

typedef struct	s_flag
{
	va_list			*arg;
	enum e_dir		justified;
	enum e_bool		width;
	enum e_bool		precision;
	enum e_bool		zero;
	enum e_bool		digit;
	enum e_bool		arg_neg;

	int				len_precision;
	int				len_width;
	char			converter;
}				t_flag;

typedef struct	s_reglages
{
	enum e_bool		return_zero;
}				t_reglages;

typedef void	(*t_convert_funct)(t_flag *flag);
typedef size_t	(*t_flag_funct)(const char *, size_t, t_flag *);

void			ft_print_buffer(void);
void			add_str_to_buffer(char *str);
void			add_char_to_buffer(char c);
int				ft_return(void);

void			set_funct_converter_tab(t_convert_funct *funct_convert_ptr);
void			set_flag_funct_tab(t_flag_funct *funct_flag_ptr);
t_flag			create_t_flag(va_list *arg);
void			reset_t_flag(t_flag *flag);

int				ft_printf(const char *format, ...);

void			converter_digit(t_flag *flag);
void			converter_char(t_flag *flag);
void			converter_percent(t_flag *flag);
void			converter_string(t_flag *flag);
void			converter_unsigned_int(t_flag *flag);
void			converter_adress(t_flag *flag);
void			converter_x(t_flag *flag);
void			converter_x_up(t_flag *flag);
void			converter_char_else(t_flag *flag, int c);

size_t			activate_prec(const char *format, size_t index, t_flag *flag);
size_t			activate_minus(const char *format, size_t index, t_flag *flag);
size_t			activate_zero(const char *format, size_t index, t_flag *flag);
size_t			activate_w_p(const char *format, size_t index, t_flag *flag);
size_t			activate_number(const char *format, size_t index, t_flag *flag);

size_t			check_len_prec(const char *format, size_t index, t_flag *flag);
size_t			check_len_width(const char *format, size_t index, t_flag *flag);

char			*check_flag(t_flag *flag, char *arg, int len_arg);
char			*check_flag_spe(t_flag *flag, char *arg, int len_arg);
char			*check_precision(t_flag *flag, char *arg);
char			*check_precision_digit(t_flag *flag, char *arg);

int				nbr_conv(int i, int d);

void			add_char_convert(t_flag *flag, char *result, int value);

char			*ft_place_adr(t_flag *flag, char *result, unsigned int value);
char			*get_place_di(t_flag *flag, char *result, unsigned int value);
char			*get_place_to_add(t_flag *flag, int len_arg);

#endif
