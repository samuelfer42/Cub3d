# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safernan <safernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 17:15:04 by safernan          #+#    #+#              #
#    Updated: 2019/10/28 22:06:16 by safernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
SRC =	ft_memcmp.c  \
		ft_strlcat.c \
		ft_atoi.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_bzero.c \
		ft_memmove.c \
		ft_strlen.c \
		ft_calloc.c \
		ft_memset.c \
		ft_strmapi.c \
		ft_isalnum.c \
		ft_putchar_fd.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_putendl_fd.c \
		ft_strnstr.c \
		ft_isascii.c \
		ft_putnbr_fd.c \
		ft_strrchr.c \
		ft_isdigit.c \
		ft_putstr_fd.c \
		ft_strtrim.c \
		ft_isprint.c \
		ft_split.c \
		ft_substr.c \
		ft_itoa.c \
		ft_strchr.c \
		ft_tolower.c \
		ft_memccpy.c \
		ft_strdup.c \
		ft_toupper.c \
		ft_memchr.c \
		ft_strjoin.c
	
SRC_BONUS = ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstnew_bonus.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(OBJ) $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;33mCompiling -> \033[0;32m [OK]"
	@$(CC) $(SRC) -I ./ $(CFLAGS)
	@ar r $(NAME) $(OBJ)
	@echo "\033[0;36m Libft ready "
	
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<  -I .

clean:
	@echo "\033[0;33mClean ->\033[0;32m [OK]"
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@rm -f *.gch

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mRemoval $(NAME) ->\033[0;32m [OK]"

re: fclean all

bonus: $(OBJ_BONUS)
	@$(CC) $(SRC) $(SRC_BONUS) -I ./ $(CFLAGS)
	@echo "\033[0;33mCompiling Bonus -> \033[0;32m [OK]"
	@ar r $(NAME) $(OBJ_BONUS)
	
norme:
	@echo "\033[0;32mNorminette ->"
	@norminette *.c

	
.PHONY: clean fclean
