#******************************************************************************#
#                                                      .##################.    #
#                                                      ##############   ###    #
#    Makefile                                          ##############   ###    #
#                                                      ########'        ###    #
#    By: yaronmarciano <yaronmarciano@ecole-deco       ######'  .###.   ###    #
#                                                      ######   #####   ###    #
#    Created: 2026/10/27 21:03:55 by mmoumini          ##   #.  '###'   ###    #
#    Updated: 2026/11/04 09:53:37 by yaronmarcia       ##   ###.        ###    #
#                                                      '##################'    #
#******************************************************************************#

CC = gcc

CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/main.c \
      src/joueur.c \
      src/jeu.c

OBJ = $(SRC:.c=.o)

NAME = blackjack

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
