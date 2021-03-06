# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 16:49:44 by epham             #+#    #+#              #
#    Updated: 2021/01/22 18:34:05 by emiliepham       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

detected_OS :=	$(shell uname)
ifeq ($(detected_OS),Darwin)        # Mac OS X
	BLANK		=	\x1b[0m
	GREEN		=	\x1b[32;01m
	RED			=	\x1b[31;01m
	YELLOW		=	\x1b[38;5;228m
endif
ifeq ($(detected_OS),Linux)
    BLANK		=	\033[39m
	GREEN		=	\033[32m
	RED			=	\033[31m
	YELLOW		=	\033[33m
endif

CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -MD
NAME		=	computor
INCLUDES	=	includes
SRCS_DIR	=	srcs
OBJS_DIR	=	obj
SRCS		=	main.cpp		\
				computor.cpp	\
				parser.cpp		\
				polynomial.cpp

OBJS		=	$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all:$(NAME)

#Creates obj directory if doesn't exist
$(OBJS_DIR):
	mkdir $@

#Compiling cpp files into object files
$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "\n$(RED)LINKING STAGE : CREATING COMPUTOR ...$(BLANK)"
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) $^ -o $@
	@echo "$(GREEN)[computor created]$(BLANK)"

clean:
	@echo "\n$(RED)REMOVING OBJECT FILES ...$(BLANK)"
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@echo "$(YELLOW)[object files removed]$(BLANK)"

fclean: clean
	@echo "\n$(RED)REMOVING COMPUTOR ...$(BLANK)"
	@rm -f $(NAME)
	@echo "$(YELLOW)[computor removed]$(BLANK)"

re: fclean all

.PHONY: all

#Detects changes in header files
-include $(OBJS:.o=.d)