# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbespin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/09 03:04:59 by hbespin           #+#    #+#              #
#    Updated: 2020/07/09 03:05:02 by hbespin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

SOURCES	=	parse_rights.c	\
			prep_display.c	\
			prep_display2.c \
			ft_time.c		\
			display.c		\
			main.c			\
			merge_sort.c	\
			list_util.c		\
			list_util2.c	\
			comparison.c	\
			comparison2.c	\
			parse_args.c	\
			dir.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

STL = libft/

LIB = libft.a

HEADER = ft_ls.h

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(STL)
	@printf "\e[38;5;87mBuilding $<\e[0m\n"

all: $(NAME) $(HEADER)

$(NAME): $(OBJECTS) $(STL)$(LIB)
	@$(CC) $(CFLAGS) $(OBJECTS) $(STL)$(LIB) -o $(NAME)
	@printf "\e[38;5;255m$(NAME) Build complete!\e[0m\n"

$(STL)$(LIB):
	@make -C $(STL)

clean:
	@make -C $(STL) clean
	@/bin/rm -f $(OBJECTS)
	@printf "\e[38;5;9mClean!\e[0m\n"
fclean: clean
	@/bin/rm -f $(NAME) $(STL)libft.a
	@printf "\e[38;5;226mFully clean!\e[0m\n"
re: fclean all
