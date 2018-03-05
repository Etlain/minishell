/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:55:18 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/05 12:56:26 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <locale.h>

static void	ft_send_cmd(t_sh **sh, char *prompt)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while ((*sh)->cmd[i] != NULL)
	{
		if (b == 0)
			b = ft_builtin(sh, (*sh)->cmd[i]);
		if (b == 0)
			b = ft_bin(sh, (*sh)->cmd[i]);
		if (b == -1)
		{
			free(prompt);
			ft_free_sh(sh);
			exit(0); // valeur de retour voir wait
		}
		b = 0;
		i++;
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_sh	*sh;
	char	*prompt;
	int		i;
	int		b;

	ft_init_sh(&sh, envp);
	prompt = ft_prompt(sh->envp->built);
	while (1)
	{
		if (sh->process != 0)
			ft_putstr(prompt);
		sh->cmd = ft_init_cmd(ft_get_input());
		ft_send_cmd(&sh, prompt);
		ft_free_tab(sh->cmd);
	}
	return (0);
}
