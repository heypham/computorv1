# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 16:49:44 by epham             #+#    #+#              #
#    Updated: 2021/01/05 17:32:04 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	g++
CXXFLAGS		=	-Wall -Wextra -Werror
NAME		=	computor
INCLUDES	=	includes
SRCS		=	srcs
OBJS		=	obj
SRC			=	main.cpp		\
				computor.cpp

OBJ			=	$(SRC:$(SRCS)/%.cpp=$(OBJS)/%.o)

all:$(NAME)

$(OBJS)/%.o: $(SRCS)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "\n$(RED)CREATING COMPUTOR ...$(BLANK)"
	@$(CXX) $(CXXFLAGS) -I$(INCLUDES) $^ -o $@
	@echo "$(GREEN)[computor created]$(BLANK)"

clean:
	@echo "\n$(RED)REMOVING COMPUTOR ...$(BLANK)"
	@rm -f $(NAME)
	@echo "$(YELLOW)[computor removed]$(BLANK)"

.PHONY: all
# g++ -Wall -Werror -Wextra -o computor srcs/main.cpp srcs/computor.cpp -I includes