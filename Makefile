#^ **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 12:10:52 by idakhlao          #+#    #+#              #
#    Updated: 2024/02/25 17:04:26 by idakhlao         ###   ########.fr        #
#                                                                              #
#& **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SOURCES = check_arguments.c swap.c push.c rev_rot.c\
			rot.c prout.c utils.c lst.c init.c \
			sort.c cost.c move.c main.c split.c strjoin.c

SOURCES_BONUS = checker_bonus.c get_next_line.c get_next_line_utils.c \
				check_arguments.c swap.c push.c rev_rot.c rot.c \
				utils.c lst.c init.c split.c strjoin.c
			
OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

INCS = push_swap.h

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): $(OBJECTS) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

# bonus: FLAGS += -D BONUS=1
bonus: $(OBJECTS_BONUS)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJECTS_BONUS)

all: $(NAME)


re: clean fclean all

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)


.PHONY: all clean fclean re
