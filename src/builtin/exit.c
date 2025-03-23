/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:01 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/23 00:51:02 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **args, t_bt *shell)
{
	ft_printf("exit\n");
	if (ft_arrlen(args) > 2)
	{
		if (!ft_isnum(args[1]))
			ft_kill(shell, 2);
		else
			return (ft_printf("minishell: exit: too many arguments\n"), 1);
	}
	if (ft_arrlen(args) == 2)
	{
		if (!ft_isnum(args[1]))
		{
			ft_printf("minishell: exit: %s: numeric argument required\n",
				args[1]);
			ft_kill(shell, 2);
		}
		else
			ft_kill(shell, ft_atoi(args[1]));
	}
	if (ft_arrlen(args) == 1)
		ft_kill(shell, 0);
	return (0);
}

void	ft_kill(t_bt *shell, int status)
{
	errno = status;
	if (shell->envp)
		free_envp(shell, ft_arrlen(shell->envp));
	if (shell->cmd)
		free_cmd(shell, ft_arrlen(shell->cmd));
	free(shell);
	rl_clear_history();
	exit(status);
}
