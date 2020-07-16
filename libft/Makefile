# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbespin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/09 03:03:38 by hbespin           #+#    #+#              #
#    Updated: 2020/07/09 22:48:02 by hbespin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

SOURCES = ft_putnbr_ll.c ft_putnbr_ll_fd.c ft_int_len.c ft_max.c ft_putnchar.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strequ.c ft_striter.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnlen.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strstr.c ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa_base.c ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memmove.c ft_atoi.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_strrev.c ft_cntwords.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\e[38;5;87mBuilding $<\e[0m\n"

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "\e[38;5;255m$(NAME) Build complete!\e[0m\n"

clean:
	@/bin/rm -f $(OBJECTS)
	@printf "\e[38;5;9mClean!\e[0m\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@printf "\e[38;5;226mFully clean!\e[0m\n"

re: fclean all
