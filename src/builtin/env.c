/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:21:45 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/13 16:13:33 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_env(char *arg)
{
	if (!arg)
		return (0);
	if (arg[0] == '-' && arg[1])
	{
		ft_printf("env: illegal option -- %c\n", arg[1]);
		ft_printf("Try 'env --help' for more information.\n");
		return (0);
	}
	else
	{
		ft_printf("env: '%s': No such file or directory\n", arg);
		return(125);
	}
}
int	ft_env(char **args, char ***envp)
{
	int	i;

	(void)args;
	i = 0;
	if (!*envp)
		return (0);
	if (args[1])
		ft_parse_env(args[1]);
	else
	{
		while ((*envp)[i])
		{
			ft_printf("%s\n", (*envp)[i]);
			i++;
		}
	}
	return (0);
}
