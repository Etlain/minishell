/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_one_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:05:56 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/08 17:24:45 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char    *ft_get_one_env(char **envp, char *name)
{
	int	lgt_name;
	int i;

	i = 0;
	lgt_name = ft_strlen(name);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], name, lgt_name) == 0)
			return (&envp[i][lgt_name + 1]);
		i++;
	}
	return (NULL);
}
