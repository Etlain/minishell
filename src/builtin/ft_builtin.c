/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:43:46 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/15 23:43:43 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_builtin(t_sh **sh, char *cmd)
{
	char ***builtin;
	int i;
	int lgt;

	if (ft_strncmp(cmd, "exit", 4) == 0)
		return (-1);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		ft_env(sh);
	else if (ft_strncmp(cmd, "echo", 4) == 0)
		ft_echo(&cmd[4]);	
	return (0);
}
