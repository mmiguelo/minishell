/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 11:32:09 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args, t_bt *shell)
{
	(void)shell;
	if (!args[1])
		printf("change directory to HOME\n");
	else if ((args[1][0] == '-') && args[1][1])
		printf("minishell: cd: %s: invalid option\n", args[1]);
	return (0);
}

