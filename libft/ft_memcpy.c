/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:56:29 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/02 09:56:31 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*dst;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	str = (unsigned char *)src;
	dst = (unsigned char *)dest;
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}
