/*
** EPITECH PROJECT, 2018
** c code
** File description:
** machtstik
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_h.h"

char	**malloc_arr(int lines, int cl)
{
	char **tab;
	int i = 0;

	if ((tab = malloc(sizeof(char *) * (lines + 2))) == NULL)
		return (NULL);
	while (i <= lines + 1) {
		if ((tab[i] = malloc(sizeof(char) * cl + 2)) == NULL)
			return (NULL);
		i++;
	}
	return (tab);
}

char	**map(t_match Match)
{
	int nb = Match.nb;
	int x = 0;
	int y;

	Match. tab = malloc_arr(nb +3, nb * 2 + 2);
	while (x <= nb + 1) {
		y = 0;
		while (y <= nb * 2) {
			Match.tab[0][y] = '*';
			Match.tab[x][0] = '*';
			Match.tab[x][y] = ' ';
			Match.tab[nb + 1][y] = '*';
			Match.tab[x][nb*2] = '*';
			y++;
		}
		x++;
		Match.tab[x][y] = '\0';
	}
	Match.tab[x] = NULL;
	return (Match.tab);
}

char	**my_pipe(t_match Match)
{
  int	nb = Match.nb;
  int	x = nb;
  int	y = nb * 2;

  Match.tab = map(Match);
  while (x >= 1)
    {
      y--;
      Match.tab[x][y] = '|';
      x--;
    }
  return (Match.tab);
}

char	**my_pipe2(t_match Match)
{
  int	nb = Match.nb;
  int	x = nb;
  int	y = 1;

  Match.tab = my_pipe(Match);
  while (x >= 1)
    {
      Match.tab[x][y] = '|';
      x--;
      y++;
    }
  return (Match.tab);
}

char	**my_pipe3(t_match Match)
{
  int	x = 2;
  int	y;

  Match.tab = my_pipe2(Match);
  while (Match.tab[x][3] != '*')
    {
      y = 1;
      while (Match.tab[x][y] != '|')
	y++;
      y++;
      while (Match.tab[x][y] == ' ')
	{
	  Match.tab[x][y] = '|';
	  y++;
	}
      x++;
    }
  return (Match.tab);
}
