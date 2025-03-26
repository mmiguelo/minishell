/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:37:52 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 14:07:58 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Frees the memory allocated for the environment variables array in the shell structure.
 * 
 * @param shell The shell structure containing the array of environment variables (`envp`).
 * @param i The number of environment variables in the `envp` array that should be freed.
 * @return int Returns 0 upon successful completion.
 */
int	free_envp(t_bt **shell, int i)
{
	while (i > 0)
	{
		free((*shell)->envp[--i]);
	}
	free((*shell)->envp);
	(*shell)->envp = NULL;
	return (0);
}

/**
 * @brief Frees the memory allocated for the command array in the shell structure.
 * 
 * @param shell The shell structure containing the array of commands (`cmd`).
 * @param i The number of commands in the `cmd` array that should be freed.
 * @return int Returns 0 upon successful completion.
 */
int	free_cmd(t_bt **shell, int i)
{
	while (i > 0)
	{
		free((*shell)->cmd[--i]);
		i++;
	}
	free((*shell)->cmd);
	(*shell)->cmd = NULL;
	return (0);
}
