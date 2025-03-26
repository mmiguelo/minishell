/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 11:43:21 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args, t_bt *shell)
{
	//char	cwd[1024];
	//char	*old_pwd;

	(void)shell;
	if (args[1] && (args[1][0] == '-') && args[1][1])
		ft_printf("minishell: cd: %s: invalid option\n", args[1]);
	if (!args[1])
		ft_printf("change directory to HOME\n");
	else if (args[2])
		ft_printf("minishell: cd: too many arguments\n");
	return (0);
}
