/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:13 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/21 11:43:22 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_pwd(char *arg)
{
	if (ft_strcmp(arg, ">") == 0 || ft_strcmp (arg, ">>") == 0
		|| ft_strcmp(arg, "|") == 0)
	{
		ft_printf("pipe or redirect\n");
		return (1);
	}
	return (0);
}

int	ft_pwd(char **args, t_bt *shell)
{
	char	cwd[4096];

	(void)shell;
	if (args[1] && parse_pwd(args[1]))
		return (1);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_printf("%s\n", cwd);
		return (0);
	}
	else
	{
		//TODO: implementar o return code para 1
		ft_printf("pwd: error retrieving current directory\n");
		return (1);
	}
}
