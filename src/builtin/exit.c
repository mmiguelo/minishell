/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:01 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 13:53:15 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		free_envp(shell, ft_arrlen((*shell)->envp));
	if ((*shell)->cmd)
		free_cmd(shell, ft_arrlen((*shell)->cmd));
	//free((*shell));
	*shell = NULL;
	rl_clear_history();
	exit(status);
}

int	ft_exit(char **args, t_bt *shell)
{
	ft_printf("exit\n");
	if (ft_arrlen(args) > 2)
	{
		if (!ft_isnum(args[1]))
		{
			ft_printf(NO_NUMERIC, args[1]);
			ft_kill(&shell, 2);
		}
		else
			return (ft_printf("minishell: exit: too many arguments\n"), 1);
	}
	if (ft_arrlen(args) == 2)
	{
		if (!ft_isnum(args[1]))
		{
			ft_printf(NO_NUMERIC, args[1]);
			ft_kill(&shell, 2);
		}
		else
			ft_kill(&shell, ft_atoi(args[1]));
	}
	if (ft_arrlen(args) == 1)
		ft_kill(&shell, 0);
	return (0);
}
