/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:43:23 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/17 16:15:58 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int		ft_atoi(char *nb)
{
	int		result;
	int		i;
	int		is_neg;

	i = 0;
	is_neg = 1;
	result = 0;
	if (nb[i] == '-')
	{
		is_neg = -1;
		i++;
	}
	while (nb[i])
	{
		result = ((result * 10) * is_neg) + nb[i] - '0';
		i++;
	}
	return (result);
}

void	add_prime_sum(int nb)
{
	int		prime;
	int		div;
	int		total;
	int		is_prime;

	prime = 3;
	total = 0;
	while (prime <= nb)
	{
		div = 2;
		is_prime = 1;
		while ((div <= prime / 2) && is_prime == 1)
		{
			if (prime % div == 0)
			   is_prime = 0;
			else
				div++;
		}
		if (is_prime == 1)
			total = total + prime;
		prime += 2;
	}
	ft_putnbr(total + 2);
}

int		main(int ac, char **av)
{
	int		nb;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		if (nb <= 0)
			write(1, "0", 1);
		else
			add_prime_sum(nb);
	}
	else
		write (1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
