/*
** EPITECH PROJECT, 2018
** c code
** File description:
** matchstik
*/

#include "my_h.h"

int	error2(t_match *Match)
{
	int x = 0;

	if (my_get_nbr(Match->getline) >  my_get_nbr(Match->av[1]) || my_get_nbr(Match->getline) <= 0) {
		my_putstr("Error: this line is out of range");
		x = 1;
	}
	return (x);
}
