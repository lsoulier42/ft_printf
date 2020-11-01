/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:05:14 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 21:39:51 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	long long int	nb_char;

	nb_char = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			nb_char += print_char(*fmt++);
		else
		{
			fmt++;
			if (is_charset(*fmt))
				nb_char += print_conv(&fmt, ap, nb_char);
			else
				nb_char += print_char(*fmt++);
		}
	}
	va_end(ap);
	return ((int)nb_char);
}
