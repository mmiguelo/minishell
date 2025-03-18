/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:21:06 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/18 19:22:20 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_erase_var(char *var, t_shell *shell)
{
	int	i;

	i = get_env_line(var, shell);
	if (i >= 0)
	{
		free (shell->envp[i]);
		while (shell->envp[i])
		{
			shell->envp[i] = shell->envp[i + 1];
			i++;
		}
		shell->envp[i] = NULL;
	}
}

int	ft_unset(char **args, t_shell *shell)
{
	int		i;
	char	*error;

	i = 0;
	(void)shell;
	if (args[1] && args[1][0] == '-')
	{
		error = ft_strdup_free(ft_strjoin("unset: ", ft_strdup(args[1])),
				ft_strdup(":invalid option\n"));
		if (!error)
			return (errno);
		print_msg_error(error);
		free(error);
	}
	while (args[++i])
		ft_erase_var(args[i], shell);
	return (0);
}
