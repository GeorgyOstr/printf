/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:31:16 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/08 16:16:22 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static long	num_len(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buff[12];
	long	ln;
	long	len;

	ln = (long)n;
	len = num_len(ln);
	if (ln == 0)
		buff[0] = '0';
	if (ln < 0)
	{
		ln = -ln;
		buff[0] = '-';
	}
	buff[len] = '\0';
	while (ln)
	{
		buff[--len] = ln % 10 + '0';
		ln /= 10;
	}
	ft_putstr_fd(buff, fd);
}
