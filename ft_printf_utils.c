/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:06:55 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/11 21:25:52 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	if (write(1, &c, 1))
		return (1);
	return (0);
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (*s)
		i += ft_putchar(*(s++));
	return (i);
}

int	ft_putnbr(long n)
{
	int		ans;

	ans = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		ans += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ans += ft_putnbr(n / 10);
	ans += ft_putchar(n % 10 + '0');
	return (ans);
}

int	ft_puthex(unsigned long n, int c)
{
	int		ans;

	ans = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 16)
		ans += ft_puthex(n / 16, c);
	if (!c)
		ans += ft_putchar("0123456789abcdef"[n % 16]);
	else
		ans += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (ans);
}

int	ft_putptr(const void *s)
{
	if (!s)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_puthex((unsigned long)s, 0));
}
