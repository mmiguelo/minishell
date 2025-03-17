/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:26:03 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/17 12:48:11 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	***init_env(t_shell *shell, char **envp)
{
	int		i;

	i = 0;
	if (!envp || !envp[0])
		shell->envp = create_no_env(shell);
	else
	{
		while (envp[i])
			i++;
		shell->envp = ft_calloc(1, sizeof(char **));
		shell->envp[0] = ft_calloc(i + 1, sizeof(char *));
		if (!shell->envp)
			return (NULL);
		i = -1;
		while (envp[++i])
		{
			shell->envp[0][i] = strdup(envp[i]);
			if (!shell->cmd[0][i])
			{
				while (i > 0)
					free(shell->envp[0][--i]);
				return (free(shell->envp[0]), free(shell->envp), NULL);
			}
		}
	}
}

void	ft_init(t_shell *shell, char **envp)
{
	shell->envp = copy_env(envp);
	if (!envp || !envp[0])
		shell->envp = init_env(shell, envp);
}