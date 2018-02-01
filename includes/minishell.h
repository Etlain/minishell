/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:17:06 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/02/01 18:24:11 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/libft/includes/libft.h"
# include <dirent.h>

typedef struct	s_envp
{
	t_list		*built; // list tab env
	char		**bin; // tab env bin
	char		**bin_path; // folder bin
	int			modif; // modif tab env bin
	int			no_env;
}				t_envp;



typedef struct	s_sh
{
	int			process;
	t_envp 		*envp;
	char 		**cmd;
}				t_sh;

char			**ft_init_cmd(char *input);
void			ft_init_sh(t_sh **sh, char **envp);
int				ft_env(t_sh **sh, char *cmd);
void			ft_setenv(t_sh **sh, char **tab);
void			ft_unsetenv(t_sh **sh, char **tab);
void			ft_echo(char *cmd);
char			*ft_get_one_env(t_list *built, char *name);
t_list			*ft_get_lst_elem(t_list **built, char *name);
t_list			*ft_get_lst_elem_prev(t_list **built, char *name, t_list **last);
char			*ft_prompt(t_list *built);
int				ft_builtin(t_sh **sh, char *cmd);
int				ft_bin(t_sh **sh, char *cmd);
char			**ft_fill_bin_path(t_list *built);
void			ft_error_cmd(char *cmd);
int				ft_exec_bin(t_sh **sh, char *path_folder, char *cmd);
wchar_t			ft_get_ascii(char *word, int b, int *ret);

#endif
