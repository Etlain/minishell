/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:43:46 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/08 22:41:23 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	**ft_tab_function()
{
	void **function;

	function = (void **)malloc(sizeof(void *) * 6);
	function[0] = NULL;
	function[1] = NULL;
	function[2] = NULL;
	function[3] = NULL;
	function[4] = &ft_env;
	function[5] = NULL;
	return (function);
}

void	***ft_tab_builtin()
{
	void ***builtin;
	char **cmd;
	void **function;

	builtin = (void ***)malloc(sizeof(void**) * 2);
	builtin[0] = (void **)ft_strsplit("echo;cd;setenv;unsetenv;env", ';');
	builtin[1] = ft_tab_function();
	return (builtin);
}

static void	ft_built_exec(void *(f)(t_sh **sh), t_sh **sh)
{
	(*f)(sh);
}

int		ft_builtin(t_sh **sh, char *cmd)
{
	char ***builtin;
	int i;
	int lgt;

	builtin = (char ***)(*sh)->builtin;
	i = 0;
	while (builtin[0][i] != NULL)
	{
		lgt = ft_strlen(builtin[0][i]);
		if (ft_strncmp(cmd, builtin[0][i], lgt) == 0)
		{
			if (builtin[1][i])
				ft_built_exec((void *)builtin[1][i], sh);
			return (1);
		}
		i++;
	}
	if (ft_strncmp(cmd, "exit", 4) == 0)
	{
		ft_free_tab((*sh)->cmd);
		exit(0);
	}
	return (0);
}
