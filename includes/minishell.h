/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:11:42 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/13 11:24:38 by mmiguelo         ###   ########.fr       */
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
typedef int (*t_builtin)(char **, char ***);

/*=============================================================================#
#                               BUILTIN                                        #
#=============================================================================*/

t_builtin	ft_isbuiltin(char *cmd);
void		ft_echo(char **args, char ***envp);
void		ft_cd(char **args, char ***envp);
void		ft_pwd(char **args, char ***envp);
void		ft_export(char **args, char ***envp);
void		ft_unset(char **args, char ***envp);
void		ft_env(char **args, char ***envp);
void		ft_exit(char **args, char ***envp);

#endif
