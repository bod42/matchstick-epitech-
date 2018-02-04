/*
** EPITECH PROJECT, 2018
** c code
** File description:
** matstik
*/

#include "my_h.h"
#include <stdlib.h>
#include <time.h>

void	get_line_and_match(t_match Match)
{
	int i = 0;

	while (Match.getline[i] != '\0' || Match.getmatches[i] != '\0') {
		if (Match.getline[i] == '\n' || Match.getmatches[i] == '\n') {
			Match.getline[i] = '\0';
			Match.getmatches[i] = '\0';
 		}
		i++;
	}
	my_putstr("Player removed ");
	my_putstr(Match.getmatches);
	my_putstr(" match(es) from line ");
	my_putstr(Match.getline);
	my_putchar('\n');
}

void    get_line_and_match_ai(int nb1, int nb2)
{
        my_putstr("AI's removed ");
        my_put_nbr(nb2);
        my_putstr(" match(es) from line ");
        my_put_nbr(nb1);
        my_putchar('\n');
}

int	game(t_match Match)
{
	int turn = 0;
	int err = 0;
	int err2 = 0;

	srand(time(NULL));
	Match.tab = my_pipe3(Match);
	show_tab(Match);
	Match.getline = malloc(sizeof(char) + 1);
	Match.getmatches = malloc(sizeof(char) + 1);
	while (42) {
		my_putchar('\n');
		if (turn == 0) {
			my_putstr("Your turn:\n");
			my_putstr("Line: ");
			read(0, Match.getline, 255);
			 err2 = error2(Match);
			 if (err2 != 1) {
				 my_putstr("Matches: ");
				 read(0, Match.getmatches, 255);
				 err = error(Match);
				 if (err != 1) {
					 get_line_and_match(Match);
					 turn = 1;
					 remove_player(Match);
				 }
			 }
			Match.victory = finish(Match);
			Match.turn = turn;
		}
		else if (turn == 1) {
			my_putstr("AI's turn...\n");
			Match.nbline_ai = (rand() %  Match.nb + 1);
			Match.nbmatch_ai = (rand() % Match.nbmatch + 1);
			get_line_and_match_ai(Match.nbline_ai, Match.nbmatch_ai);
			turn = 0;
			remove_AI(Match);
			Match.victory = finish(Match);
		}
		if (err != 1 && err2 != 1) {
			show_tab(Match);
		}
		if (Match.victory == 0 && turn == 0)
			return (1);
		if (Match.victory == 0 && turn == 1)
			return (2);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_match Match;

	if (ac == 3) {
		Match.av = av;
		Match.nb = my_get_nbr(av[1]);
		Match.nbmatch = my_get_nbr(av[2]);
		if (Match.nb > 1 && Match.nb < 100)
			Match.turn = game(Match);
	}else {
		my_putstr("wrong argument");
		return (84);
	}
	if (Match.turn == 2) {
		my_putstr("You lost, too bad...");
		return (2);
	}
	 if (Match.turn == 1)
		my_putstr("I lost... snif... but I'll get you next time!!");
	return (1);
}
