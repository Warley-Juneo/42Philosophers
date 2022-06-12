# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 15:55:15 by wjuneo-f          #+#    #+#              #
#    Updated: 2022/06/12 11:16:38 by wjuneo-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = ./includes/philo.h

SRCM =	./main.c \
		./src/initialize.c ./src/philo.c ./src/utils.c \
		./src/routine.c ./src/validade.c

OBJM = ${SRCM:.c=.o}
NAME =	philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
PTHREAD = -lpthread

all:		$(NAME)

$(NAME):	$(OBJM)
			$(CC) $(CFLAGS) $(OBJM) $(PTHREAD) -o $(NAME)

clean:
	rm ${OBJM}

fclean:		clean
	rm ${NAME}

re:		 fclean all

.PHONY:		all clean fclean re
