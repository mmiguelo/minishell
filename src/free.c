/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:37:52 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/25 12:18:10 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_envp(t_bt **shell, int i)
{
	while (i > 0)
	{
		free((*shell)->envp[--i]);
	}
	free((*shell)->envp);
	(*shell)->envp = NULL;
	return (0);
}

int	free_cmd(t_bt **shell, int i)
{
	while (i > 0)
	{
		free((*shell)->cmd[--i]);
		i++;
	}
	free((*shell)->cmd);
	(*shell)->cmd = NULL;
	return (0);
}
