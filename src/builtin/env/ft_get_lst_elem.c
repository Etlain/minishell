/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lst_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:11:48 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/31 13:06:18 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_list  *ft_get_lst_elem(t_list **built, char *name)
{
	t_list  *tmp;
	int     lgt;

	tmp = *built;
	lgt = ft_strlen(name);
	while (tmp != NULL)
	{
		if (ft_strncmp((char *)tmp->content, name, lgt) == 0)
		{
			if (((char *)tmp->content)[lgt] == '=')
				return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_list  *ft_get_lst_elem_prev(t_list **built, char *name, t_list **last)
{
	t_list  *tmp;
	int     lgt;

	tmp = *built;
	*last = NULL;
	lgt = ft_strlen(name);
	while (tmp != NULL)
	{
		if (ft_strncmp((char *)tmp->content, name, lgt) == 0)
		{
			if (((char *)tmp->content)[lgt] == '=')
				return (tmp);
		}
		if (*last == NULL && tmp->next != NULL && tmp->next->next == NULL)
			*last = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}
