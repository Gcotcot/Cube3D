/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:00 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/02 10:18:01 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*t;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	s = (unsigned char *)src;
	t = (unsigned char *)dest;
	i = 0;
	if (t > s)
		while (n-- > 0)
			t[n] = s[n];
	else
	{
		while (i < n)
		{
			t[i] = s[i];
			i++;
		}
	}
	return (dest);
}
