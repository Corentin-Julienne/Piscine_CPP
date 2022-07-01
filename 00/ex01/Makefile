# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 13:49:54 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/01 12:24:18 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = heighties_phonebook

SRCS = ./main.cpp \
	   ./Contact.cpp \
	   ./Phonebook.cpp

OBJS = $(SRCS:.c=.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I. 

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
