/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:50:36 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/03/16 16:55:34 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*t;

	if (alst && new)
	{
		t = *alst;
		while (t->next != NULL)
			t = t->next;
		t->next = new;
	}
}
