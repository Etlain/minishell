/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:55:18 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/08 22:46:58 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_sh	*sh;
	char	*prompt;
	int		i;
	int		b;

	ft_init_sh(&sh, envp);
	prompt = ft_prompt(sh->envp);
	while (1)
	{
		if (sh->process != 0)
			ft_putstr(prompt);
		sh->cmd = ft_init_cmd(ft_get_input());
		i = 0;
		while (sh->cmd[i] != NULL)
		{
			//ft_putendl(sh->cmd[i]);
			// builtin
			if (b == 0)
				b = ft_builtin(&sh, sh->cmd[i]);
			// binaries
			/*if (b == 0)
				b = ft_bin();
			*/// error
			/*
			else
				;
			*/

	/*		else if (ft_strncmp(sh->cmd[i], "test", 4) == 0)
			{
				sh->process = fork();
				if (sh->process == 0)
					execve("/bin/ls", argv, sh->envp);
				else
					waitpid(sh->process, NULL, 0);
			}
			else if (ft_strncmp(sh->cmd[i], "env", 3) == 0)
				ft_env(sh->envp);
		*/	// si chaine vide rien ne se passe
			b = 0;
			i++;
		}
		ft_free_tab(sh->cmd);
	}
	// free builtin etc..
	exit(0);
}
