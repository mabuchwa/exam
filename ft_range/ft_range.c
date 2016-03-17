/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:50:13 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/17 14:24:15 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_size(int start, int end)
{
	int		result;

	result = 0;
	if (end > start)
		result = (end - start) + 1;
	if (end < start)
		result = (start - end) + 1;
	return (result);
}

int		*ft_range(int start, int end)
{
	int		*tab;
	int		i;
	int		size;

	i = 0;
	size = get_size(start, end);
	tab = (int*)malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i] = start;
		if (start > end)
			start--;
		else
			start++;
		i++;
	}
	return (tab);
}
