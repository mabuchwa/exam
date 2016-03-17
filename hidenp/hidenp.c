/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 10:44:01 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/13 11:02:27 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		hidenp(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s1[i] != s2[j] && s2[j])
			j++;
		if (s2[j] == '\0' && s1[i])
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		result;

	if (ac == 3)
	{
		result = hidenp(av[1], av[2]);
		if (result == 1)
			write(1, "1\n", 2);
		else
			write(1, "0\n", 2);
	}
	else   
		write(1, "\n", 1);

	return (0);
}
