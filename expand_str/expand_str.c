/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:35:02 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/16 13:53:57 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		first_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (is_space(str[i]) == 1)
			i++;
		return (i);
	}
	return (0);
}

void	expand_str(char *str)
{
	int		i;
	int		j;

	i = first_space(str);
	while (str[i])
	{
		j = 0;
		while(is_space(str[i]) == 1 && str[i + 1] != '\0')
			i++;
		if (is_space(str[i]) == 0 && is_space(str[i - 1]) == 1 
				&& i != first_space(str) && str[i])
		{
			while (j < 3)
			{
				write(1, " ", 1);
				j++;
			}
		}
		if (is_space(str[i]) == 0 && str[i])
				write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
