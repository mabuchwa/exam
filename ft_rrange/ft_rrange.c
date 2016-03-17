/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:18:34 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/10 11:34:59 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		get_size(int start, int end)
{
	int		result;

	if (end > start)
		result = (end - start) + 1;
	if (end < start)
		result = (end + start) + 1;
	return (result);
}

int		*ft_rrange(int start, int end)
{
	int		size;
	int		i;
	int		*tab;

	i = 0;
	size = get_size(start, end);
	tab = (int*)malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i] = start;
		printf("%d, ", tab[i]);
		start++;
		i++;
	}
	return (tab);
}

int		main(void)
{
	ft_rrange(21, 2313);
	return (0);
}
