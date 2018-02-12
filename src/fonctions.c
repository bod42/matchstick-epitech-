/*
** EPITECH PROJECT, 2018
** c code
** File description:
** matchstik
*/

#include "my_h.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void	my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}

int	my_get_nbr(char *str)
{
	int     i = 0;
	int     n = 0;

	while (str[i] != '\n' && str[i] != '\0') {
		if (str[0] == '-' && str[1] != '\0')
			i++;
		if (str[i] < 0 && str[i] > 9)
			i++;
		n = n + str[i] - 48;
		n = n * 10;
		i++;
	}
	n /= 10;
	if (str[0] == '-')
		return (-1 * n);
	else
		return (n);
}

int	show_tab(t_match *Match)
{
	int i = 0;
	int j;

	while (Match->tab[i] != NULL) {
		j = 0;
		while (Match->tab[i][j] != '\0') {
			my_putchar(Match->tab[i][j]);
			j++;
		}
		i++;
		my_putchar('\n');
	}
	return (0);
}
