/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:19:40 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/03 10:19:42 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sol;
	size_t	i;
	size_t	j;

	sol = (char *)malloc(sizeof(*s1) * (ft_strlen((char *)s1) \
		+ ft_strlen((char *)s2) + 1));
	if (!sol)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		sol[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		sol[j++] = s2[i];
		i++;
	}
	sol[j] = 0;
	return (sol);
}
