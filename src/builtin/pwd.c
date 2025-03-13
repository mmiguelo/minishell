/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:13 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/13 13:07:28 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int parse_pwd(char *arg)
{
	if (arg)
	{
		ft_printf("pwd: too many arguments\n");
		return (0);
	}
	return (1);
}

int ft_pwd(char **args, char ***envp)
{
	(void)envp;
	if (parse_pwd(args[1]))
		
}
