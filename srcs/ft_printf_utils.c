/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:10:01 by louise            #+#    #+#             */
/*   Updated: 2020/10/11 17:39:07 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*create_str(char c, int len)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		str[i] = c;
	str[i] = '\0';
	return (str);
}

int			is_charset(char c)
{
	return (ft_strchr(SPEC_CHARSET, c) || ft_strchr(FLAGS_CHARSET, c)
			|| ft_isdigit(c) || ft_strchr(LENGTH_CHARSET, c));
}
