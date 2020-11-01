/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:17:15 by louise            #+#    #+#             */
/*   Updated: 2020/10/09 23:19:20 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			precision_len(t_format *comb)
{
	int		len;
	int		data_len;

	data_len = comb->data_len;
	if (comb->point_flag)
	{
		if (comb->spec_char == 's')
			len = comb->precision < data_len ? comb->precision : data_len;
		else
		{
			if (comb->data[0] == '0' && comb->precision == 0)
			{
				comb->data[0] = '\0';
				data_len--;
			}
			len = comb->precision > data_len ? comb->precision : data_len;
		}
	}
	else
		len = data_len;
	return (len);
}

char		*process_precision(t_format *comb)
{
	int		len;
	char	*str;
	char	*z_str;

	if (comb->point_flag && comb->precision >= 0)
	{
		len = precision_len(comb);
		if (!(str = (char *)ft_calloc(len + 1, sizeof(char))))
			return (NULL);
		if (comb->spec_char == 's')
			ft_strlcpy(str, comb->data, len + 1);
		else if (comb->precision > comb->data_len)
		{
			z_str = create_str('0', comb->precision - comb->data_len);
			str = ft_strcat(ft_strcat(str, z_str), comb->data);
			free(z_str);
		}
		else
			str = ft_strcat(str, comb->data);
	}
	else
		str = ft_strdup(comb->data);
	return (str);
}

char		*process_width(t_format *comb, char *str)
{
	char			*final_str;
	char			*add_str;
	unsigned int	add_len;
	unsigned int	intermediate_len;
	char			add_char;

	intermediate_len = ft_strlen(str);
	add_len = comb->width - intermediate_len;
	if ((comb->spec_char == 'c' && comb->data[0] == '\0') || (comb->zero_flag
	&& (comb->nb_sign == -1 || (comb->nb_sign == 1 && comb->plus_flag)
	|| (comb->space_flag && comb->nb_sign == 1))))
		add_len--;
	if (comb->zero_flag && comb->padding_flag)
		add_len -= 2;
	add_char = comb->zero_flag ? '0' : ' ';
	add_str = create_str(add_char, add_len);
	if (comb->minus_flag && !comb->zero_flag)
		final_str = ft_strjoin(str, add_str);
	else
		final_str = ft_strjoin(add_str, str);
	free(add_str);
	free(str);
	return (final_str);
}

char		*process_sign(char *str, t_format *comb)
{
	char *str_with_sign;

	str_with_sign = ft_strdup(str);
	if (comb->spec_char != 'u' && comb->spec_char != 'x'
		&& comb->spec_char != 'X')
	{
		if (comb->nb_sign == -1)
			str_with_sign = ft_strjoin("-", str);
		else if (comb->plus_flag && comb->nb_sign == 1)
			str_with_sign = ft_strjoin("+", str);
		else if (comb->space_flag && comb->nb_sign == 1)
			str_with_sign = ft_strjoin(" ", str);
	}
	free(str);
	return (str_with_sign);
}

char		*process_comb(t_format *comb)
{
	char			*precision_str;
	char			*final_str;
	unsigned int	intermediate_len;
	char			*padding_str;

	padding_str = comb->spec_char == 'X' ? "0X" : "0x";
	precision_str = process_precision(comb);
	if (comb->spec_char == 'p'
		|| (comb->padding_flag && !comb->zero_flag && *precision_str))
		precision_str = ft_strjoin(padding_str, precision_str);
	if (!comb->zero_flag)
		precision_str = process_sign(precision_str, comb);
	intermediate_len = ft_strlen(precision_str);
	if (comb->width > intermediate_len)
		final_str = process_width(comb, precision_str);
	else
		final_str = precision_str;
	if (comb->zero_flag)
		final_str = process_sign(final_str, comb);
	if (comb->zero_flag && comb->padding_flag && *final_str)
		final_str = ft_strjoin(padding_str, final_str);
	return (final_str);
}
