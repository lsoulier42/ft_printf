/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_fct_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:14:19 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 02:51:54 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*conv_d(va_list ap, t_format *comb)
{
	char					*data;
	long long int			dvar;
	unsigned long long int	dvar_to_itoa;

	dvar = (long long int)va_arg(ap, long long int);
	if (comb->l_length)
		dvar = (long int)dvar;
	else if (comb->ll_length)
		;
	else if (comb->h_length)
		dvar = (short int)dvar;
	else if (comb->hh_length)
		dvar = (char)dvar;
	else
		dvar = (int)dvar;
	if (dvar < 0)
		comb->nb_sign = -1;
	if (dvar < 0)
		dvar_to_itoa = ((unsigned long long int)-(dvar + 1)) + 1;
	else
		dvar_to_itoa = dvar;
	data = pf_itoa_base(dvar_to_itoa, BASE_DEC);
	return (data);
}
