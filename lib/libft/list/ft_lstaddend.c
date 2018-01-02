/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:50:36 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/02 21:07:20 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/libft.h"

#include "../../../includes/minishell.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*t;

	if (alst && new)
	{
		int i;

		i = 0;
		t = *alst;
		while ((*alst)->next != NULL)
		{
			ft_printf("str %d: %s\n", i, (char *)(*alst)->content);
			*alst = (*alst)->next;
			i++;
		}
		ft_printf("str %d: %s\n", i, (char *)(*alst)->content);
		//ft_putendl((char *)(*alst)->content);
		//ft_putendl((char *)new->content);
		(*alst)->next = new;
		ft_printf("str %d: %s\n", i + 1, (char *)(*alst)->next->content);
		*alst = t;
		ft_lst_putendl(*alst);
	}
}
