/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_fct_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:44:31 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 21:40:42 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

long long int	*conv_n_lli(va_list ap, t_format *comb)
{
	long long int *arg;

	arg = NULL;
	if (comb->ll_length)
	{
		arg = (long long int*)va_arg(ap, long long int*);
		*arg = (long long int)comb->nb_char;
	}
	return (arg);
}

long int		*conv_n_li(va_list ap, t_format *comb)
{
	long int *arg;

	arg = NULL;
	if (comb->l_length)
	{
		arg = (long int*)va_arg(ap, long int*);
		*arg = (long int)comb->nb_char;
	}
	return (arg);
}

char			*conv_n_c(va_list ap, t_format *comb)
{
	char *arg;

	arg = NULL;
	if (comb->hh_length)
	{
		arg = (char*)va_arg(ap, char*);
		*arg = (char)comb->nb_char;
	}
	return (arg);
}

short int		*conv_n_si(va_list ap, t_format *comb)
{
	short int *arg;

	arg = NULL;
	if (comb->h_length)
	{
		arg = (short int*)va_arg(ap, short int*);
		*arg = (short int)comb->nb_char;
	}
	return (arg);
}

char			*conv_n(va_list ap, t_format *comb)
{
	int				*arg_i;
	short int		*arg_si;
	char			*arg_c;
	long int		*arg_li;
	long long int	*arg_lli;

	arg_si = conv_n_si(ap, comb);
	arg_c = conv_n_c(ap, comb);
	arg_li = conv_n_li(ap, comb);
	arg_lli = conv_n_lli(ap, comb);
	if (!arg_si && !arg_c && !arg_li && !arg_lli)
	{
		arg_i = (int*)va_arg(ap, int*);
		*arg_i = (int)comb->nb_char;
	}
	return (ft_strdup(""));
}
