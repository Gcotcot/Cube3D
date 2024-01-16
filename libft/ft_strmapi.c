/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:33:40 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/03 15:33:41 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sol;
	size_t	i;

	sol = ft_strdup(s);
	if (!(sol))
		return (NULL);
	i = 0;
	while (sol[i])
	{
		sol[i] = (*f)(i, sol[i]);
		i++;
	}
	return (sol);
}
