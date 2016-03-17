/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 11:16:00 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/03/13 12:23:08 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

void	rostring(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*word;

	i = first_word(str);
	j = 0;
	k = 0;
	while (is_space(str[i + j]) == 0)
		   j++;
	word = (char*)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (is_space(str[i]) == 0)
	{
		word[j] = str[i];
		j++;
		i++;
	}
	while (str[i])
	{
		k++;
		while (str[i] && (is_space(str[i]) == 1) && str[i + 1] != '\0')
			i++;
		if ((is_space(str[i]) == 0) && (is_space(str[i - 1]) == 1) && k > 1)
			write(1, " ", 1);
		if (is_space(str[i]) == 0)
			write(1, &str[i], 1);
		i++;
	}
	j = 0;
	if (k > 1)
		write(1, " ", 1);
	while (word[j])
	{
		write(1, &word[j], 1);
		j++;
	}
	write(1, "\n", 1);
	free(word);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	   write(1, "\n", 1);
	else
		rostring(av[1]);
	return (0);
}
