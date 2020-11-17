/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_comb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:06:15 by louise            #+#    #+#             */
/*   Updated: 2020/11/17 14:08:19 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		set_flags(t_format *comb, char *parse_str)
{
	int i;

	i = -1;
	while (parse_str[++i])
	{
		if (parse_str[i] == '-')
			comb->minus_flag = 1;
		if (parse_str[i] == '.')
			comb->point_flag = 1;
		if (parse_str[i] == '#')
			comb->padding_flag = 1;
		if (parse_str[i] == '+')
			comb->plus_flag = 1;
	}
	comb->space_flag = !comb->plus_flag && ft_strchr(parse_str, ' ') != NULL;
	while (*parse_str == ' ' || *parse_str == '+' || *parse_str == '-'
		|| *parse_str == '#')
		parse_str++;
	if (*parse_str == '0')
		comb->zero_is_present = 1;
	if (!comb->point_flag && !comb->minus_flag && *parse_str == '0')
		comb->zero_flag = 1;
}

void		set_length(t_format *comb, char *parse_str)
{
	if (ft_strstr(parse_str, "ll") != NULL)
		comb->ll_length = 1;
	else if (ft_strstr(parse_str, "hh") != NULL)
		comb->hh_length = 1;
	else if (ft_strchr(parse_str, 'l') != NULL)
		comb->l_length = 1;
	else if (ft_strchr(parse_str, 'h') != NULL)
		comb->h_length = 1;
}

void		set_width(t_format *comb, char *parse_str, va_list ap)
{
	int		star;

	while (*parse_str == '0' || *parse_str == '-' || *parse_str == '#'
		|| *parse_str == ' ' || *parse_str == '+')
		parse_str++;
	if (ft_isdigit(*parse_str))
		comb->width = ft_atoi(parse_str);
	else if (*parse_str == '*')
	{
		star = (int)va_arg(ap, int);
		comb->width = star < 0 ? -(long)star : star;
		comb->minus_flag = star < 0 || comb->minus_flag;
		if (comb->minus_flag)
			comb->zero_flag = 0;
	}
	if (!comb->spec_char && comb->width > 0)
		comb->width--;
}

void		set_precision(t_format *comb, char *parse_str, va_list ap)
{
	while (*parse_str && *parse_str != '.')
		parse_str++;
	if (*parse_str == '.')
	{
		parse_str++;
		if (ft_isdigit(*parse_str))
			comb->precision = ft_atoi(parse_str);
		else if (*parse_str == '*')
		{
			comb->precision = (int)va_arg(ap, int);
			if (comb->precision < 0)
			{
				comb->point_flag = 0;
				comb->precision = 0;
				comb->zero_flag = comb->zero_is_present && !comb->minus_flag;
			}
		}
	}
}

void		set_data(t_format *comb, va_list ap)
{
	char	*charset;
	int		i;
	char	*(*data_fct[10])(va_list, t_format*);

	i = -1;
	if (!comb->spec_char)
		comb->data = conv_null(ap, comb);
	else
	{
		charset = SPEC_CHARSET;
		data_fct[0] = &conv_char;
		data_fct[1] = &conv_str;
		data_fct[2] = &conv_ptr;
		data_fct[3] = &conv_d;
		data_fct[4] = &conv_d;
		data_fct[5] = &conv_u;
		data_fct[6] = &conv_u;
		data_fct[7] = &conv_u;
		data_fct[8] = &conv_mod;
		data_fct[9] = &conv_n;
		while (charset[++i])
			if (charset[i] == comb->spec_char)
				comb->data = data_fct[i](ap, comb);
	}
}
