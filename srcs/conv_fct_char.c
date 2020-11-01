/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_fct_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:15:53 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 01:21:42 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*conv_char(va_list ap, t_format *comb)
{
	int		char_arg;
	char	*data;

	char_arg = (int)va_arg(ap, int);
	if (!comb->l_length)
	{
		if (!(data = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		data[0] = (char)char_arg;
		data[1] = '\0';
	}
	else
		data = setchar_unicode((unsigned int)char_arg);
	return (data);
}
