/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_one_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:05:56 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/02 18:32:18 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char    *ft_get_one_env(t_list *built, char *name)
{
	t_list	*tmp;
	int		lgt_name;
	int 	i;

	i = 0;
	tmp = built;
	lgt_name = ft_strlen(name);
	while (tmp->next != NULL)
	{
		if (ft_strncmp((char *)tmp->content, name, lgt_name) == 0)
		{
			if (((char *)tmp->content)[lgt_name] != '=')
				return (NULL);
			return ((char *)&tmp->content[lgt_name + 1]);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
