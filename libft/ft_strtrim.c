/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:28:17 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/09 00:24:07 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*extract_str(char const *s1, size_t left, size_t right)
{
	char	*p;

	if (left > right)
	{
		p = ft_strdup("");
		return (p);
	}
	p = malloc(right - left + 2);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1 + left, right - left + 2);
	return (p);
}

static void	fill_set(unsigned char *arr, char const *set)
{
	int	i;

	i = 0;
	while (i < 256)
		arr[i++] = 0;
	i = 0;
	while (set[i])
		arr[(unsigned char)set[i++]] = 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	arr[256];
	size_t			left;
	size_t			right;

	if (!s1 || !set)
		return (NULL);
	fill_set(arr, set);
	left = 0;
	while (s1[left])
	{
		if (!arr[(unsigned char)s1[left]])
			break ;
		left++;
	}
	right = ft_strlen(s1);
	while (--right)
	{
		if (!arr[(unsigned char)s1[right]])
			break ;
	}
	return (extract_str(s1, left, right));
}
