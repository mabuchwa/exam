/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:03:51 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/16 16:19:56 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void	print_hex(char *str)
{
	char	base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	int		convert[64];
	int		i;
	int		value;
	int		base;

	base = 16;
	i = 0;
	value = ft_atoi(str);
	if (value == 0)
		write (1, "0", 1);
	while (value != 0)
	{
		convert[i] = value % base;
		value = value / base;
		i++;
	}
	--i;
	while (i >= 0)
	{
		write(1, &base_digits[convert[i]], 1);
		i--;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_hex(av[1]);
	write(1, "\n", 1);
	return (0);
}
