/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:59:38 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/02 14:59:39 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	len;

	len = nmemb * size;
	if (!len)
		return (malloc(0));
	if (len / size != nmemb)
		return (NULL);
	tmp = malloc(len);
	if (tmp)
		ft_bzero(tmp, len);
	return (tmp);
}
