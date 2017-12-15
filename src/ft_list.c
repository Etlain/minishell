/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:48:38 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/14 21:55:18 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list		*ft_lst_cpy_envp(char **envp)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;

	lst = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (!lst)
			lst = ft_lstnew((void *)envp[i], ft_strlen(envp[i]));
		else
		{
			tmp = ft_lstnew((void *)envp[i], ft_strlen(envp[i]));
			ft_lstadd(&lst, tmp);
		}
		i++;
	}
	return (lst);
}

void		ft_lst_putendl(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	if (tmp == NULL)
		return ;
	while (tmp->next != NULL)
	{
		ft_putendl((char *)tmp->content);
		tmp = tmp->next;
	}
}
