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

SRC = 	builtin/ft_builtin.c			\
		builtin/env/ft_env.c			\
		builtin/env/ft_get_one_env.c	\
		ft_list.c						\
		ft_init.c						\
		ft_prompt.c						\
		bin/ft_bin.c					\
		bin/ft_exec_bin.c				\
		builtin/ft_echo.c				\
		ft_error.c						\
		main.c

PATH_SRC = src/

FLAGS =

LIBFT = -C lib/libft/

all:
	make $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(addprefix $(PATH_SRC), $(SRC)) $(LIB)

clean :
	make clean $(LIBFT)

fclean:
	make fclean $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
