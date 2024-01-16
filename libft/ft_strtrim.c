/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:26:48 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/03 10:26:49 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charin(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sol;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_charin(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && ft_charin(s1[end -1], set))
		end--;
	sol = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!sol)
		return (NULL);
	i = 0;
	while (start < end)
		sol[i++] = s1[start++];
	sol[i] = 0;
	return (sol);
}
