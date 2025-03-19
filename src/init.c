/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:26:03 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/19 11:59:51 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char 	**init_env(char **envp)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = ft_calloc(i + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
		{
			while (i > 0)
				free(new_env[--i]);
			free(new_env);
			return (NULL);
		}
	}
	new_env[i] = NULL;
	return (new_env);
}

char	**init_export(char **envp)
{
	char	**new_export;
	int		i;
	int		j;
	char	*temp;

	i = -1;
	new_export = init_env(envp);
	if (!new_export)
		return (NULL);
	while (new_export[++i] != NULL)
	{
		j = i;
		while (new_export[++j] != NULL)
		{
			if (ft_strcmp(new_export[i], new_export[j]) > 0)
			{
				temp = new_export[i];
				new_export[i] = new_export[j];
				new_export[j] = temp;
			}
		}
	}
	return (new_export);
}

void	ft_init(t_shell *shell, char **envp)
{
	if (!envp || !envp[0])
	{
		shell->envp = when_no_env(shell, envp);
		shell->export = when_no_env(shell, envp);
	}
	else
	{
		shell->envp = init_env(envp);
		shell->export = init_export(envp);
	}
	shell->cmd = NULL;
}
