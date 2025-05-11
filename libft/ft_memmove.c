/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:34:22 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/09 00:11:00 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dstc;
	unsigned char	*srcc;
	size_t			i;

	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	if (dst - src >= 0)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dstc[i] = srcc[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
			dstc[i++] = *(srcc++);
	}
	return (dst);
}
