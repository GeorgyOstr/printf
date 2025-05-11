/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:07:50 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/08 16:18:23 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (str[i] && str[i] != cc)
		i++;
	if (str[i] == cc)
		return ((char *)str + i);
	return (0);
}
