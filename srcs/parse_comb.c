/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:03:19 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 21:42:11 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*create_parse_str(const char *fmt)
{
	char	*parse_str;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (fmt[len] && !(ft_strchr(SPEC_CHARSET, fmt[len])))
		len++;
	len++;
	if (!(parse_str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < len)
		parse_str[i] = fmt[i];
	parse_str[i] = '\0';
	return (parse_str);
}

t_format	*init_comb(char *parse_str, int parse_len,
		long long int nb_char)
{
	t_format	*comb;

	if (!(comb = (t_format*)malloc(sizeof(t_format))))
		return (NULL);
	comb->data = NULL;
	comb->data_len = 0;
	comb->parse_len = parse_len;
	comb->spec_char = parse_str[parse_len - 1];
	comb->nb_char = nb_char;
	comb->nb_sign = 1;
	comb->width = 0;
	comb->precision = 0;
	comb->minus_flag = 0;
	comb->zero_flag = 0;
	comb->point_flag = 0;
	comb->padding_flag = 0;
	comb->space_flag = 0;
	comb->plus_flag = 0;
	comb->l_length = 0;
	comb->ll_length = 0;
	comb->h_length = 0;
	comb->hh_length = 0;
	return (comb);
}

t_format	*parse_comb(const char *fmt, va_list ap,
		long long int nb_char)
{
	t_format	*comb;
	char		*parse_str;
	int			parse_len;

	parse_str = create_parse_str(fmt);
	parse_len = ft_strlen(parse_str);
	if (!(comb = init_comb(parse_str, parse_len, nb_char)))
		return (NULL);
	set_flags(comb, parse_str);
	set_length(comb, parse_str);
	set_width(comb, parse_str, ap);
	set_precision(comb, parse_str, ap);
	set_data(comb, ap);
	comb->data_len = comb->data ? ft_strlen(comb->data) : 0;
	free(parse_str);
	return (comb);
}
