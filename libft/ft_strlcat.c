/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:06:35 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/02 11:37:48 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int size)
{
	int	i;
	int	j;

	if (!src || !size)
		return (ft_strlen((char *)src));
	if (size <= ft_strlen(dst))
		return (size + ft_strlen((char *)src));
	i = 0;
	j = ft_strlen(dst);
	while (src[i] != '\0' && j + 1 < size)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(dst) + ft_strlen((char *)&src[i]));
}
