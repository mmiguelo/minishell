/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:26:03 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 14:10:57 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Initializes a new environment array by duplicating the provided environment variables.
 * 
 * This function takes an array of environment variables (`envp`) and creates a new array
 * of strings that duplicates the provided environment variables. It allocates memory for
 * the new environment array and copies each string from the original `envp` array into it.
 * 
 * @param envp A pointer to the array of environment variables passed to the program.
 * @return char** A new array of environment variables, or `NULL` if memory allocation fails.
 */
char	**init_env(char **envp)
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

/**
 * @brief Initializes the shell structure with environment variables and command array.
 * 
 * @param shell A pointer to the `t_bt` structure that represents the shell.
 * @param envp A pointer to the environment variables passed to the program (typically from `main`).
 */
void	ft_init(t_bt *shell, char **envp)
{
	shell->envp = init_env(envp);
	shell->cmd = NULL;
}
