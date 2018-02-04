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

	while (str[i] != '\0')
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

int	my_get_nbr(char *nbr)
{
	int n = 1;
	int i = my_strlen(nbr) - 1;;
	int res = 0;

	while(i >= 0) {
		res = res + (n * (nbr[i] - 48));
		n = n * 10;
		i--;
	}
	return (res);
}

int	show_tab(t_match Match)
{
	int i = 0;
	int j;

	while (Match.tab[i] != NULL) {
		j = 0;
		while (Match.tab[i][j] != '\0') {
			my_putchar(Match.tab[i][j]);
			j++;
		}
		i++;
		my_putchar('\n');
	}
	return (0);
}
