/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:13 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/13 14:45:25 by mmiguelo         ###   ########.fr       */
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

int	ft_pwd(char **args, char ***envp)
{
	char	cwd[1024];

	(void)envp;
	if (args[1] && parse_pwd(args[1]))
		return (1);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_printf("%s\n", cwd);
		return (0);
	}
	else
	{
		ft_printf("pwd: error retrieving current directory\n");
		return (1);
	}
}
