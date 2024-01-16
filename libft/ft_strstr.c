/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:55:59 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/02 12:56:01 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return (0);
	if (*little == '\0')
		return (0);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] != '\0'
			&& big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}
