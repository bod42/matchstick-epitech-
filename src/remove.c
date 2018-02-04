/*
** EPITECH PROJECT, 2018
** c code
** File description:
** matchstik
*/

#include "my_h.h"

int find(char *str)
{
	int i = 1;
	int size = my_strlen(str);

	while (str[i] != '*') {
		if (str[i] == '|' && str[i + 1] == ' ') {
			if (i >= size)
				return (0);
			return (i);
		}
		if (str[i] == '|' && str[i + 1] == '*') {
			if (i >= size)
				return (0);
			return (i);
		}
		i++;
	}
	if (i >= size)
		return (0);
	return (i);
}

void	remove_player(t_match Match)
{
	int find_stick = find(Match.tab[atoi(Match.getline)]);
	int remove = atoi(Match.getmatches);
	int line = atoi(Match.getline);

	while (remove > 0) {
		Match.tab[line][find_stick] = ' ';
		find_stick--;
		remove--;
	}
}

void    remove_AI(t_match Match)
{
        int find_stick = find(Match.tab[Match.nbline_ai]);
        int remove = Match.nbmatch_ai;
        int line = Match.nbline_ai;

        while (remove > 0) {
                Match.tab[line][find_stick] = ' ';
                find_stick--;
                remove--;
        }
}

int	finish(t_match Match)
{
	int y = 0;
	int x = 0;

	while (Match.tab[y] != NULL) {
		x = 0;
		while (Match.tab[y][x] != '\0') {
			if (Match.tab[y][x] == '|')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	error(t_match Match)
{
	int x = 0;

	if (my_get_nbr(Match.getmatches) >  my_get_nbr(Match.av[2])) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(Match.nbmatch);
		my_putstr(" matches per turn\n");
		x = 1;
	}
	return (x);
}
