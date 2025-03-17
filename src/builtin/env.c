/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:21:45 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/17 13:13:26 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_no_env(t_shell *shell)
{
	char	cwd[1024];
	
	shell->envp = ft_calloc(1, sizeof(char **));
	shell->envp[0] = ft_calloc(4, sizeof(char *));
	if (!shell->envp)
		return (NULL);
	shell->envp[0][0] = ft_strdup_free("PWD=", getcwd(cwd, sizeof(cwd)));
	shell->envp[0][1] = ft_strdup("SHLVL=1");
	shell->envp[0][2] = ft_strdup("_=/usr/bin/env");
}

int	ft_parse_env(char *arg)
{
	if (!arg)
		return (0);
	if (arg[0] == '-' && arg[1])
	{
		ft_printf("env: illegal option -- %c\n", arg[1]);
		ft_printf("Try 'env --help' for more information.\n");
		return (0);
	}
	else
	{
		ft_printf("env: '%s': No such file or directory\n", arg);
		return(125);
	}
}

int	ft_env(char **args, t_shell *shell)
{
	int	i;

	(void)args;
	i = 0;
	if (!shell->envp)
		return (0);
	if (args[1])
		ft_parse_env(args[1]);
	else
	{
		while ((*shell->envp)[i])
		{
			ft_printf("%s\n", (*shell->envp)[i]);
			i++;
		}
	}
	return (0);
}
