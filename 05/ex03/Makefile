# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 21:02:04 by cjulienn          #+#    #+#              #
#    Updated: 2022/09/01 21:03:28 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 18:41:55 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/31 11:52:39 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Interns

SRCS = ./main.cpp \
	   ./Bureaucrat.cpp \
	   ./Form.cpp \
	   ./PresidentialPardonForm.cpp \
	   ./RobotomyRequestForm.cpp \
	   ./ShrubberyCreationForm.cpp \
	   ./Intern.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98

.cpp.o: 
	$(CC) $(CFLAGS) -c $<

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
