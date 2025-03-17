/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:53 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/17 17:35:13 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_var(char *var)
{
	int	i;
	
	i = 0;
	if(var[i] != '_' && !ft_isalpha(var[i]))
		return (0);
	while(++i)
	{
		if(var[i] != '_' && !ft_isalnum(var[i]))
			return(0);
	}
	return (i);
}

t_builtin	ft_isbuiltin(char *cmd, t_shell *shell)
{
	(void)shell;
	static char	*builtins[8] = {
		"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	static int	(*builtin_ft[8])(char **, t_shell *) = {
		&ft_echo, &ft_cd, &ft_pwd, &ft_export, &ft_unset, &ft_env, &ft_exit};
	int			i;

	i = -1;
	if (!cmd)
		return (NULL);
	while (builtins[++i])
	{
		if (strncmp(builtins[i], cmd, ft_strlen(builtins[i]) + 1) == 0)
			return (builtin_ft[i]);
	}
	return (NULL);
}
