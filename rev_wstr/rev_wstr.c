/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:23:33 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/14 12:46:52 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	rev_wstr(char *str)
{
	int 	i;

	i = 0;
	if (str[i])
	{
		while (is_space(str[i]) == 0 && str[i] != '\0')
			i++;
		if (is_space(str[i]) == 1)
			rev_wstr(str + i + 1);
		if (str[i] != '\0')
			write(1, " ", 1);
		ft_putstr(str);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2) 
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
