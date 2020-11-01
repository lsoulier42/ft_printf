/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:03:25 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 21:58:50 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			print_char(char c)
{
	unsigned char uc;

	uc = (unsigned char)c;
	write(1, &uc, 1);
	return (1);
}

int			print_and_count(char *str, t_format *comb)
{
	int ret;
	int null_char;

	null_char = comb->spec_char == 'c' && comb->data[0] == '\0';
	ret = ft_strlen(str);
	ret = null_char ? ret + 1 : ret;
	if (null_char && comb->minus_flag)
		write(1, "\0", 1);
	ft_putstr(str);
	if (null_char && !comb->minus_flag)
		write(1, "\0", 1);
	return (ret);
}

int			print_conv(const char **fmt, va_list ap,
		long long int nb_char)
{
	char		*full_str;
	t_format	*comb;
	int			full_str_len;

	comb = parse_comb(*fmt, ap, nb_char);
	full_str_len = 0;
	if (comb->spec_char != 'n')
	{
		full_str = process_comb(comb);
		full_str_len = print_and_count(full_str, comb);
		free(full_str);
	}
	*fmt += comb->parse_len;
	free(comb->data);
	free(comb);
	return (full_str_len);
}
