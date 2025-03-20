/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:37:52 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/20 12:13:26 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_envp(t_bt *shell, int i)
{
	while (i > 0)
	{
		free(shell->envp[--i]);
	}
	free(shell->envp[0]);
	free(shell->envp);
	shell->envp = NULL;
}
