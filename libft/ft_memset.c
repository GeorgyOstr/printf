/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:12:04 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/05 13:59:38 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*p;
	size_t			i;

	p = s;
	cc = (unsigned char)c;
	i = 0;
	while (i++ < n)
		*(p++) = cc;
	return (s);
}
