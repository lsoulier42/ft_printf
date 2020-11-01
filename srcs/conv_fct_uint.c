/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_fct_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:49:36 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 01:21:59 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*set_base(char c)
{
	char *base;

	if (c == 'x')
		base = BASE_HEX_LOW;
	else if (c == 'X')
		base = BASE_HEX_UP;
	else
		base = BASE_DEC;
	return (base);
}

char	*conv_u(va_list ap, t_format *comb)
{
	char					*data;
	char					*base;
	unsigned long long int	udvar;

	udvar = (unsigned long long int)va_arg(ap, unsigned long long int);
	if (udvar == 0)
		comb->padding_flag = 0;
	base = set_base(comb->spec_char);
	if (comb->l_length)
		udvar = (unsigned long int)udvar;
	else if (comb->ll_length)
		;
	else if (comb->h_length)
		udvar = (unsigned short int)udvar;
	else if (comb->hh_length)
		udvar = (unsigned char)udvar;
	else
		udvar = (unsigned int)udvar;
	data = pf_itoa_base(udvar, base);
	return (data);
}
