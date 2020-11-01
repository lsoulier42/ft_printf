/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:33:17 by louise            #+#    #+#             */
/*   Updated: 2020/10/12 18:03:39 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define SPEC_CHARSET "cspdiuxX%n"
# define LENGTH_CHARSET "lh"
# define FLAGS_CHARSET "-0.*# +"
# define BASE_HEX_LOW "0123456789abcdef"
# define BASE_HEX_UP "0123456789ABCDEF"
# define BASE_DEC "0123456789"

typedef struct	s_format
{
	char			*data;
	int				data_len;
	int				parse_len;
	char			spec_char;
	long long int	nb_char;
	int				nb_sign;

	unsigned int	width;
	int				precision;

	int				minus_flag;
	int				zero_flag;
	int				point_flag;
	int				padding_flag;
	int				space_flag;
	int				plus_flag;

	int				l_length;
	int				ll_length;
	int				h_length;
	int				hh_length;
}				t_format;

int				ft_printf(const char *fmt, ...);
int				is_charset(char c);
char			*create_str(char c, int len);

int				print_char(char c);
int				print_conv(const char **str, va_list ap,
		long long int nb_char);
int				print_and_count(char *str, t_format *comb);

t_format		*parse_comb(const char *fmt, va_list ap, long long int nb_char);
char			*create_parse_str(const char *fmt);
t_format		*init_comb(char *parse_str, int parse_len,
		long long int nb_char);

void			set_width(t_format *comb, char *parse_str, va_list ap);
void			set_precision(t_format *comb, char *parse_str, va_list ap);
void			set_flags(t_format *comb, char *parse_str);
void			set_length(t_format *comb, char *parse_str);
void			set_data(t_format *comb, va_list ap);

char			*conv_char(va_list ap, t_format *comb);
char			*conv_str(va_list ap, t_format *comb);
char			*conv_ptr(va_list ap, t_format *comb);
char			*conv_d(va_list ap, t_format *comb);
char			*conv_u(va_list ap, t_format *comb);
char			*set_base(char c);
char			*setchar_unicode(unsigned int c);
int				count_bytes(unsigned int codepoint);
char			*setstr_unicode(int *str);
int				count_char_unicode(int *str);
char			*conv_mod(va_list ap, t_format *comb);
char			*conv_n(va_list ap, t_format *comb);
short int		*conv_n_si(va_list ap, t_format *comb);
long long int	*conv_n_lli(va_list ap, t_format *comb);
long int		*conv_n_li(va_list ap, t_format *comb);
char			*conv_n_c(va_list ap, t_format *comb);
short int		*conv_n_si(va_list ap, t_format *comb);

char			*process_comb(t_format *comb);
char			*process_precision(t_format *comb);
int				precision_len(t_format *comb);
char			*process_width(t_format *comb, char *str);

char			*pf_itoa_base(unsigned long long int n, char *base);
#endif
