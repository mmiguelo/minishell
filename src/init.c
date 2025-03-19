/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:26:03 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/19 10:31:48 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_shell *shell, char **envp)
{
	int		i;

	i = 0;
	if (!envp || !envp[0])
		when_no_env(shell);
	else
	{
		while (envp[i])
			i++;
		shell->envp = ft_calloc(1, sizeof(char **));
		shell->envp[0] = ft_calloc(i + 1, sizeof(char *));
		if (!shell->envp)
			return ;
		i = -1;
		while (envp[++i])
		{
			shell->envp[0][i] = strdup(envp[i]);
			if (!shell->envp[0][i])
			{
				free_envp(shell, i);
				return ;
			}
		}
	}
}

void	init_export(t_shell *shell, char **envp)
{
	int	i;
	int	j;

	i = -1;
	if (!envp || !envp[0])
		export_without_env(shell);
	while ()
}

void	ft_init(t_shell *shell, char **envp)
{
	init_env(shell, envp);
	init_export(shell, envp);
	shell->cmd = NULL;
}
