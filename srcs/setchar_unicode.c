/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setchar_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:07:06 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 02:00:48 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				count_bytes(unsigned int codepoint)
{
	int nb_bytes;

	nb_bytes = 0;
	if (codepoint >= 0x0 && codepoint <= 0x7f)
		nb_bytes = 1;
	else if (codepoint >= 0x80 && codepoint <= 0x07ff)
		nb_bytes = 2;
	else if (codepoint > 0x800 && codepoint <= 0xffff)
		nb_bytes = 3;
	else if (codepoint > 0x10000 && codepoint <= 0x10ffff)
		nb_bytes = 4;
	return (nb_bytes);
}

static void		set_three_bytes(char *data, unsigned int c)
{
	data[0] = 0xe0 | (c >> 12);
	data[1] = 0x80 | ((c >> 6) & 0x3f);
	data[2] = 0x80 | (c & 0x3f);
}

static void		set_four_bytes(char *data, unsigned int c)
{
	data[0] = 0xf0 | (c >> 18);
	data[1] = 0x80 | ((c >> 12) & 0x3f);
	data[2] = 0x80 | ((c >> 6) & 0x3f);
	data[3] = 0x80 | (c & 0x3f);
}

char			*setchar_unicode(unsigned int c)
{
	char	*data;
	int		nb_bytes;

	nb_bytes = count_bytes(c);
	if (!(data = (char*)malloc(sizeof(char) * (nb_bytes + 1))))
		return (NULL);
	if (nb_bytes == 1)
		data[0] = (char)c;
	else if (nb_bytes == 2)
	{
		data[0] = 0xc0 | (c >> 6);
		data[1] = 0x80 | (c & 0x3f);
	}
	else if (nb_bytes == 3)
		set_three_bytes(data, c);
	else if (nb_bytes == 4)
		set_four_bytes(data, c);
	data[nb_bytes] = '\0';
	return (data);
}
