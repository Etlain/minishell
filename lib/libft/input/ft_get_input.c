/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:29:50 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/08 17:58:20 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#define SIZE_INPUT_BUF 10

char	*ft_get_input(void)
{
	char	*input;
	char	*buf;
	char	*tmp;

	input = NULL;
	buf = (char *)ft_memalloc(SIZE_INPUT_BUF);
	while (read(0, buf, SIZE_INPUT_BUF) != 0)
	{
		if (input)
		{
			tmp = input;
			input = ft_strjoin(tmp, buf);
			free(tmp);
		}
		else
		{
			input = (char *)malloc(ft_strlen(buf));
			input = ft_strcpy(input, buf);
		}
		if (ft_strchr(buf, '\n'))
			break ;
		ft_bzero(buf, SIZE_INPUT_BUF);
	}
	free(buf);
	return (input);
}
