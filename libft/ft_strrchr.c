/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:07:50 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/08 16:17:57 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*found;
	char	cc;

	i = 0;
	found = 0;
	cc = (char)c;
	while (str[i])
	{
		if (str[i] == cc)
			found = (char *)(str + i);
		i++;
	}
	if (str[i] == cc)
		found = (char *)(str + i);
	return (found);
}
