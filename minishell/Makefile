
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchanal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 11:13:05 by fchanal           #+#    #+#              #
#    Updated: 2017/03/02 14:09:11 by tribeiro         ###   ########.fr        #
#    Updated: 2016/11/21 20:40:52 by fchanal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
###                  Settings                 ###
#################################################

NAME = minishell

CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

INC_PATH = includes/
LIB_PATH = Libft/

SRCDIR= srcs/
OBJDIR = object/

#################################################
###                  Colors                   ###
#################################################

BLACK  = "\033[1;30m"
RED    = "\033[1;31m"
GREEN  = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE   = "\033[1;34m"
PURPLE = "\033[1;35m"
WHITE  = "\033[1;37m"

CLEAR = "\033[2K"
UP =	"\033[A"
DEF	=	"\033[0;0m"

#################################################
###                 Sources                   ###
#################################################

SRC =	$(SRCDIR)main.c \
		$(SRCDIR)ft_core.c \
		$(SRCDIR)ft_error.c \
		$(SRCDIR)ft_read.c \
		$(SRCDIR)ft_envdup.c \
		$(SRCDIR)ft_prompt.c \
		$(SRCDIR)ft_builtins_names.c \
		$(SRCDIR)ft_strsplit_blank.c \
		$(SRCDIR)builtins/ft_cd.c \
		$(SRCDIR)builtins/ft_echo.c \
		$(SRCDIR)builtins/ft_env.c \
		$(SRCDIR)builtins/ft_exit.c \
		$(SRCDIR)builtins/ft_setenv.c \
		$(SRCDIR)builtins/ft_unsetenv.c \
		$(SRCDIR)builtins/ft_pwd.c


#################################################
###                   Format                  ###
#################################################

OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC = -I./$(INC_PATH) -I./$(LIB_PATH)$(INC_PATH)
LIB = -L./$(LIB_PATH) -lft

#################################################
###                   Rules                   ###
#################################################

.PHONY: all norme clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	$(CC) $(FLAGS) $(OBJ) -o $@ $(LIB) $(INC)


$(OBJDIR)%.o: $(SRCDIR)%.c $(CHECK)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)builtins
	@$(CC) $(FLAGS) -c $< -o $@ $(INC)
	printf "\r"
	printf $(YELLOW)"-> "$(CYAN) "$@.\n"$(DEF)

$(CHECK):
	echo "create  $(OBJDIR)"
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)builtins

%.c:
	echo "$(COL_RED) Missing file -> $@\n"

clean:
	make -C $(LIB_PATH) clean
	echo $(YELLOW)"[    CLEANING LIBFT    ]\n"$(DEF)
	@rm -rf $(OBJDIR)
	echo $(YELLOW)"-> "$(BLACK)"object removed."

fclean: clean
	rm -f $(NAME)
	printf $(YELLOW)"-> "$(BLACK)"$(NAME) removed.\n"

re: fclean all
