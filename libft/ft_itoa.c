/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:37 by rdubois           #+#    #+#             */
/*   Updated: 2023/02/03 15:03:39 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fill(int size, int offset, int n, char *sol)
{
	while (size > offset)
	{
		sol[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		offset;
	int		size;
	char	*sol;

	offset = 0;
	size = ft_size(n);
	sol = (char *)malloc(sizeof(char) * size + 1);
	if (!sol)
		return (NULL);
	if (n == -2147483648)
	{
		sol[0] = '-';
		sol[1] = '2';
		n = 147483648;
		offset = 2;
	}
	if (n < 0)
	{
		sol[0] = '-';
		offset = 1;
		n = -n;
	}
	ft_fill(size, offset, n, sol);
	sol[size] = '\0';
	return (sol);
}
