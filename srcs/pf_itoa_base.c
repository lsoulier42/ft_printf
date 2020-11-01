/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:43:09 by louise            #+#    #+#             */
/*   Updated: 2020/10/10 21:52:40 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	pf_itoa_char(unsigned long long int n, int len)
{
	int			nb_char;

	nb_char = 1;
	while (n / len != 0)
	{
		nb_char++;
		n /= len;
	}
	return (nb_char);
}

char		*pf_itoa_base(unsigned long long int n, char *base)
{
	char		*str;
	int			nb_char;
	int			i;
	int			len;

	len = ft_strlen(base);
	nb_char = pf_itoa_char(n, len);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (nb_char + 1))))
		return (NULL);
	str[nb_char] = '\0';
	while (--nb_char >= 0)
	{
		str[nb_char] = base[n % len];
		n /= len;
	}
	return (str);
}
