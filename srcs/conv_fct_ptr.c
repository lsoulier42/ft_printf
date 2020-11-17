/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_fct_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:16:06 by louise            #+#    #+#             */
/*   Updated: 2020/11/17 00:05:12 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*conv_ptr(va_list ap, t_format *comb)
{
	char	*data;
	void	*ptr;

	(void)comb;
	ptr = (void*)va_arg(ap, void*);
	data = pf_itoa_base((long)ptr, BASE_HEX_LOW);
	return (data);
}
