/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:46:29 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/12 19:23:06 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		first_word(char *str)
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

void	epur_str(char *str)
{
	int		i;

	i = first_word(str);
	while (str[i])
	{
		while (str[i] && is_space(str[i]) == 1 && str[i + 1] != '\0')
			i++;
		if (is_space(str[i]) == 0 && is_space(str[i - 1]) == 1 
				&& i != first_word(str))
			write(1, " ", 1);
		if (is_space(str[i]) == 0)
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	ac == 2 ? epur_str(av[1]) : write(1, "\n", 1);
	return (0);
}
