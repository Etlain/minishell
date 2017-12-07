/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:55:18 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/07 22:23:32 by mmouhssi         ###   ########.fr       */
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
	//close(0);
	return (input);	
}

int main(int argc, char **argv, char **envp)
{
	char *input;
	char *tmp;
	
	//ft_putendl(ft_strtrim(input));
	while (1)
	{
		ft_putstr("$>"); // mettre variable env user un jour
		tmp = get_input();
		input = ft_strtrim(tmp);
		free(tmp);
		if (ft_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			break ;
		}
		else if (ft_strncmp(input, "test", 4) == 0)
		{
			execve("/bin/ls", argv, envp);
		}
		else if (ft_strncmp(input, "env", 3) == 0)
			ft_env(envp);
		free(input);
	}
	exit(0);
	//ft_env(envp);
	/*char *tmp = get_input();
	ft_printf(tmp);*/
	//ft_putendl_tab(envp);
}
