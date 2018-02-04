##
## EPITECH PROJECT, 2018
## c code
## File description:
## matchstick
##

CC	=	gcc -g3 -W -Wall -Wextra -I ./include

SRCS	=	src/fonctions.c		\
		src/remove.c		\
		src/error.c		\
		src/fonction2.c		\
		src/map.c		\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME): 	$(OBJS)
		$(CC) $(OBJS)  -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
