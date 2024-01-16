/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:56:11 by rdubois           #+#    #+#             */
/*   Updated: 2022/12/08 19:56:13 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		j;
	int		u;

	u = (ft_strlen((char *)s) + 1);
	j = 0;
	new = (char *)malloc(u * sizeof(char));
	if (!new)
		return (NULL);
	while (s[j] != '\0')
	{
		new[j] = s[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
