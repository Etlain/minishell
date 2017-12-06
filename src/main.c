/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:55:18 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/06 19:00:18 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_input()
{
	char	*input;
	char	*buf;
	char	*tmp;

	input = NULL;
	buf = (char *)ft_memalloc(10);
	while (read(0, buf, 10) != 0)
	{	
		if (input)
		{
			tmp = input;
			input = ft_strjoin(tmp, buf);
			free(tmp);
		}
		else
		{
			input = (char *)malloc(ft_strlen(buf));
			input = ft_strcpy(input, buf);
		}
		if (ft_strchr(buf, '\n'))
			break ;
		ft_bzero(buf, 10);
	}
	free(buf);
	return (input);	
}

int main()
{
	/*char *tmp = (char *)ft_memalloc(5);
	
	read(0, tmp, 5);
	ft_printf(tmp);
	read(0, tmp, 5);*/
	char *tmp = get_input();
	ft_printf(tmp);
	
}
