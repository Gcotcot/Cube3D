/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:37:10 by gcot              #+#    #+#             */
/*   Updated: 2023/09/19 17:37:15 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_copy_b_to_z(char *line, int i)
{
	int		j;
	char	*res;

	j = 0;
	while (line[i + j] > 32)
		j++;
	res = malloc(sizeof(*res) * j + 1);
	j = 0;
	while (line[i + j] > 32)
	{
		res[j] = line[i + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

int	ft_strchrstr(char *s1, char *s2)
{
	int	i;
	int	x;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i])
	{
		x = 0;
		while (s1[i + x] == s2[x])
			x++;
		if (!s2[x])
			return (0);
		i++;
	}
	return (1);
}

int	ft_error(char *str)
{
	printf("\033[0;31mERROR\033[0;37m :\n[\033[0;31m");
	printf("%s\033[0;37m] !!\n", str);
	return (1);
}
