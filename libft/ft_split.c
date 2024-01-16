/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:44:42 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/03 11:44:44 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static int	ft_size(const char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	*ft_free(char **str, int j)
{
	while (j-- > 0)
		free(str[j]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**str;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_count(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])
			return (ft_free(str, j));
		i += size;
	}
	str[j] = 0;
	return (str);
}
