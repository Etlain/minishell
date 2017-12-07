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

SRC = 	builtin/env/ft_env.c	\
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
