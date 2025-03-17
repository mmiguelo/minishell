/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:06:24 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/17 15:57:21 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char *s1, char *s2)
{
	char *dest;

	dest = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (dest);
}
