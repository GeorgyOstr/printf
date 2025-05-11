/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:49:31 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/08 16:35:07 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	val;

	if (!nmemb || !size)
		return (malloc(0));
	val = nmemb * size;
	if (val / nmemb != size)
		return (NULL);
	p = malloc(val);
	if (!p)
		return (NULL);
	ft_bzero(p, val);
	return (p);
}
