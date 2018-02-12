/*
** EPITECH PROJECT, 2018
** c code
** File description:
** matchstik
*/

#include "my_h.h"

int	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		my_put_nbr((nb / 10) * -1);
		my_putchar(((nb % 10) * -1) + '0');
	} else {
		if (nb >= 10)
			my_put_nbr(nb / 10);
		my_putchar((nb % 10) + '0');
	}
	return (0);
}

char	*change_matches(char *str)
{
	int i = 0;
	char *new_str = malloc(sizeof(char ) + 255);

	new_str[i] = str[i + 2];
	return (new_str);
}
