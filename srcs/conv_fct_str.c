/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_fct_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:24:54 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 03:02:03 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		count_char_unicode(int *str)
{
	int nb_char;
	int i;

	nb_char = 0;
	i = -1;
	while (str[++i])
		nb_char += count_bytes(str[i]);
	return (nb_char);
}

char	*setstr_unicode(int *str)
{
	int		i;
	char	*data;
	int		nb_char;
	int		offset;
	char	*char_unicode;

	i = -1;
	nb_char = count_char_unicode(str);
	if (!(data = (char*)ft_calloc(nb_char + 1, sizeof(char))))
		return (NULL);
	offset = 0;
	while (str[++i])
	{
		if (str[i] >= 0x80)
		{
			char_unicode = setchar_unicode(str[i]);
			offset += count_bytes(str[i]) - 1;
			data = ft_strcat(data, char_unicode);
		}
		else
			data[offset + i] = (char)str[i];
	}
	data[nb_char] = '\0';
	return (data);
}

char	*conv_str(va_list ap, t_format *comb)
{
	char	*data;
	int		*str;

	str = (int*)va_arg(ap, int*);
	if (!str)
		data = ft_strdup("(null)");
	else
	{
		if (comb->l_length)
			data = setstr_unicode(str);
		else
			data = ft_strdup((char*)str);
	}
	return (data);
}
