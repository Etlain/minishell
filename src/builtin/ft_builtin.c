/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:43:46 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/09 16:21:07 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_builtin(t_sh **sh, char *cmd)
{
	char	**tab;
	int		b;

	b = 0;
	tab = ft_strsplit(cmd, ' ');
	if (!tab)
		return (b);
	if (tab[0] && ft_strcmp(tab[0], "exit") == 0)
		b = -1;
	else if (tab[0] && ft_strcmp(tab[0], "echo") == 0)
	{
		ft_echo(&tab[1]);
		b = 1;
	}
	else if (tab[0] && ft_strcmp(tab[0], "cd") == 0)
	{
		ft_cd(sh, &tab[1]);
		b = 1;
	}
	else
		b = ft_env(sh, cmd, 1);
	ft_free_tab(tab);
	return (b);
}
