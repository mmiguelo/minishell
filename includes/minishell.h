/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:11:42 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/17 13:10:23 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

//function pointer type for builtins
typedef int (*t_builtin)(char **, t_shell *);

typedef struct s_shell
{
	char		***envp;
	char		**cmd;
}				t_shell;


/*=============================================================================#
#                               BUILTIN                                        #
#=============================================================================*/

t_builtin	ft_isbuiltin(char *cmd, t_shell *shell);
int			ft_echo(char **args, t_shell *shell);
int			ft_cd(char **args, t_shell *shell);
int			ft_pwd(char **args, t_shell *shell);
int			ft_export(char **args, t_shell *shell);
int			ft_unset(char **args, t_shell *shell);
int			ft_env(char **args, t_shell *shell);
int			ft_exit(char **args, t_shell *shell);

/*=============================================================================#
#                               UTILS                                          #
#=============================================================================*/

void		ft_init(t_shell *shell, char **envp);
void		ft_signals(void);
void		ft_minishell(t_shell *shell, char **envp);
void		sigint_handler(int sig);


#endif