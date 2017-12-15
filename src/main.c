/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:55:18 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/15 15:24:05 by mmouhssi         ###   ########.fr       */
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
	prompt = ft_prompt(sh->envp->built);
	while (1)
	{
		if (sh->process != 0)
			ft_putstr(prompt);
		sh->cmd = ft_init_cmd(ft_get_input());
		i = 0;
		while (sh->cmd[i] != NULL)
		{
			if (b == 0)
				b = ft_builtin(&sh, sh->cmd[i]);
			if (b == 0)
				b = ft_bin(&sh, sh->cmd[i]);
			if (b == 0)
				ft_error_cmd(sh->cmd[i]);
			// si chaine vide rien ne se passe
			b = 0;
			i++;
		}
		ft_free_tab(sh->cmd);
	}
	free(prompt);
	// free builtin etc..
	exit(0);
}
