/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:37:52 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/31 15:44:27 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Frees the memory allocated for the environment variables array in
 * the shell structure.
 * 
 * @param shell The shell structure containing the array of environment
 * variables (`envp`).
 * @param i The number of environment variables in the `envp` array that should
 * be freed.
 * @return int Returns 0 upon successful completion.
 */
int	free_matriz(char **shell, int i)
{
	if (!shell)
		return (0);
	while (i >= 0)
	{
		free(shell[i]);
		shell[i] = NULL;
		i--;
	}
	free(shell);
	shell = NULL;
	return (0);
}

/**
 * @brief Frees allocated memory and exits the shell with the specified status.
 * 
 * This function is responsible for cleaning up the shell's resources before 
 * terminating the program. It frees memory allocated for the environment 
 * variables (`envp`) and the command history (`cmd`). Afterward, it clears 
 * the history in the readline library and exits the program with the given 
 * exit status. The `errno` is set to the provided status before exiting.
 * 
 * @param shell Pointer to the shell structure that contains environment 
 *               variables and commands.
 * @param status Exit status code to be returned when exiting the shell.
 */
void	ft_kill(t_bt **shell, int status)
{
	errno = status;
	if ((*shell)->envp)
		free_matriz((*shell)->envp, ft_arrlen((*shell)->envp));
	if ((*shell)->cmd)
		free_matriz((*shell)->cmd, ft_arrlen((*shell)->cmd));
	if ((*shell)->old_pwd)
		free((*shell)->old_pwd);
	*shell = NULL;
	rl_clear_history();
	exit(status);
}
