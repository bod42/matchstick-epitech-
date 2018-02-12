/*
** EPITECH PROJECT, 2018
** c code
** File description:
** .h
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>

typedef struct s_match {
	int nb;
	int nbline_ai;
	int nbmatch_ai;
	int nbmatch;
	char **av;
	int turn;
	int victory;
	int line;
	int match;
	char **tab;
	char *getline;
	char *getmatches;
} t_match;

int     error(t_match *);
int	error2(t_match *);
int	my_strlen(char *);
int	finish(t_match *);
char    *change_matches(char *);
void    remove_AI(t_match *);
void	remove_player(t_match *);
char	*get_next_line(const int);
int	my_get_nbr(char *);
int	my_put_nbr(int);
void	my_putchar(char);
void	my_putstr(char*);
int     my_game(t_match *);
int	show_tab(t_match *);
char	**map(t_match *);
char	**malloc_arr_char(int, int);
char	**my_pipe(t_match *);
char	**my_pipe2(t_match *);
char	**my_pipe3(t_match *);

#endif /* !MY_H_ */
