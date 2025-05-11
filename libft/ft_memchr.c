/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:33:58 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/05 13:56:35 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == cc)
			return (p + i);
		i++;
	}
	return (0);
}
