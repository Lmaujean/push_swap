# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:05:04 by lmaujean          #+#    #+#              #
#    Updated: 2021/09/29 14:05:07 by lmaujean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

SRC =	./srcs/main.c\
		./srcs/error.c\
		./srcs/utils.c\
		./srcs/utils2.c\

BONUS = 

OBJ = $(SRC:.c=.o)

BNS = $(BONUS:.c=.o)

OBJBONUS = $(OBJ) $(BNS)

INC = ./inc/

$(NAME): $(OBJ)
				ar -rcs $(NAME) $(OBJ)
				gcc $(CFLAGS) ./srcs/main.c push_swap -o push_swap

%.o: %.c
				$(CC) $(CFLAGS) -I. -o $@ -c $?

all: $(NAME)

clean:
				$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
				$(RM) $(NAME)
				$(RM) push_swap
			
reset: clean
				$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re reset