/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:37:52 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 14:06:33 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
 * This function iterates through the array of commands (`cmd`) in the shell structure, 
 * freeing the memory allocated for each command string. After freeing all commands, 
 * the array itself is freed, and the `cmd` pointer is set to `NULL` to prevent dangling pointers.
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
