#include "../includes/libft.h"

int	ft_isanbr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '-')
			return (ft_isdigit(str[i]));
		i++;
	}
	return (0);
}
