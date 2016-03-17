/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:17:24 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/17 16:36:57 by mabuchwa         ###   ########.fr       */
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

int		*ft_rrange(int start, int end)
{
	int		*tab;
	int		size;

	size = get_size(start, end);
	tab = (int*)malloc(sizeof(int) * size);
	while (size - 1 >= 0)
	{
		tab[size - 1] = start;
		if (end < start)
			start--;
		else
			start++;
		size--;
	}
	return (tab);
}
