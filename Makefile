# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 14:25:01 by jcollon           #+#    #+#              #
#    Updated: 2021/11/10 14:25:01 by jcollon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_itoa.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c ft_calloc.c ft_isascii.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c
BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c
BONUS_OBJ = $(BONUS:.c=.o)
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
INCLUDE = libft.h Makefile

# COLORS

GOOD_TEXT = \033[32m   # green text (2)
BAD_TEXT = \033[31m    # red text (1)
INFO_TEXT = \033[36m
ERASE = \033[2K\r\033[1A
RESET = \033[0m

all: $(NAME)

%.o: %.c $(INCLUDE)
	@echo "$(GOOD_TEXT)➤ Making libft"
	@printf "$(INFO_TEXT)   ╰╴Making $(RESET)$@$(BAD_TEXT)"
	@gcc $(FLAGS) -o $@ -c $<
	@printf "$(ERASE)"

$(NAME): $(OBJ) $(BONUS_OBJ)
	@echo "$(GOOD_TEXT)➤ Making libft$(BAD_TEXT)"
	@ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@printf "$(RESET)"

clean:
	@echo "$(GOOD_TEXT)➤ Cleaning libft$(BAD_TEXT)"
	@rm -f $(OBJ) $(BONUS_OBJ)
	@printf "$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re