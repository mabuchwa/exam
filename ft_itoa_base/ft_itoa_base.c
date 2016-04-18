/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 11:47:07 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/04/18 13:17:01 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(int size)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (size + 1));
	while (size >= 0)
	{
		str[size] = '\0';
		size--;
	}
	return (str);
}

int		count_nb(int value, int base)
{
	int		result;

	result = 1;
	while (value >= base || value <= -base)
	{
		result++;
		value = value / base;
	}
	return (result);
}

char	*ft_itoa_base(int value, int base)
{
	char	*numb;
	int		is_neg;
	int		buf;

	is_neg = 0;
	if (value < 0)
	{
		if (base == 10)
			is_neg = 1;
	}
	buf = count_nb(value, base) + is_neg;
	numb = ft_strnew(buf);
	if (value < 0)
	{
		numb[buf - 1] = ((value % base) * -1) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base * -1;
		buf--;
		if (base == 10)
			numb[0] = '-';
	}
	while ((buf - is_neg) > 0)
	{
		numb[buf - 1] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
		buf--;
	}
	return (numb);
}
