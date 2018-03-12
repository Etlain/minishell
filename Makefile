# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/09/16 22:58:33 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIB = lib/libft/libft.a

NAME_SRC = 	builtin/ft_builtin.c			\
			builtin/ft_cd.c					\
			builtin/ft_echo.c				\
			builtin/ft_get_ascii.c			\
			builtin/env/ft_env.c			\
			builtin/env/ft_setenv.c			\
			builtin/env/ft_unsetenv.c		\
			builtin/env/ft_get_lst_elem.c	\
			builtin/env/ft_get_one_env.c	\
			ft_init.c						\
			ft_free_all.c					\
			ft_prompt.c						\
			bin/ft_bin.c					\
			bin/ft_exec_bin.c				\
			ft_error.c						\
			main.c

PATH_SRC = src/

SRC = $(addprefix $(PATH_SRC), $(NAME_SRC))

OBJ = $(SRC:.c=.o)

FLAGS = 

LIBFT = -C lib/libft/

all: $(NAME)

$(NAME): $(OBJ)
	@make $(LIBFT)
	@gcc $(FLAGS) $(LIB) $^ -o $@
	@echo "\033[36;40mMake $(NAME)\033[0m"

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean :
	@echo "\033[36;40mMake clean $(NAME)\033[0m"
	@make clean $(LIBFT)
	@rm -rf $(OBJ)

fclean: 
	@echo "\033[36;40mMake fclean $(NAME)\033[0m"
	@make fclean $(LIBFT)
	@rm -rf $(NAME)
	@rm -rf $(OBJ)

re: fclean all

.PHONY: all clean fclean re
