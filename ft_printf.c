/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:06:55 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/11 21:14:16 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

static int	ft_putchar(char c)
{
	if (write(1, &c, 1))
		return (1);
	return (0);
}

static int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (*s)
		i += ft_putchar(*(s++));
	return (i);
}

static int	ft_putnbr(long n)
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

static int	ft_puthex(unsigned long n, int c)
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

static int	ft_putptr(const void *s)
{
	if (!s)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_puthex((unsigned long)s, 0));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ans;

	i = 0;
	ans = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			ans += ft_putchar(str[i++]);
		if (str[i] && str[i] == '%')
		{
			if (!str[++i])
				return (ans);
			else if (str[i] == '%')
				ans += ft_putchar('%');
			else if (str[i] == 'c')
				ans += ft_putchar((char)va_arg(args, int));
			else if (str[i] == 's')
				ans += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'p')
				ans += ft_putptr(va_arg(args, void *));
			else if (str[i] == 'd' || str[i] == 'i')
				ans += ft_putnbr(va_arg(args, int));
			else if (str[i] == 'u')
				ans += ft_putnbr(va_arg(args, unsigned int));
			else if (str[i] == 'x')
				ans += ft_puthex(va_arg(args, unsigned int), 0);
			else if (str[i] == 'X')
				ans += ft_puthex(va_arg(args, unsigned int), 1);
			i++;
		}
	}
	return (ans);
}
/*
#include <stdlib.h>
#include <limits.h>
int	main(void)
{
	void	*p;
	int		*i;
	int		j;

	p = malloc(0);
	i = malloc(20*sizeof(int));
	i[0] = -1;
	i[1] = ft_printf("Print percent: %% \n");
	i[2] = ft_printf("Print char: %c\n", 'X');
	i[3] = ft_printf("Print string: %s\n", "COOL");
	i[4] = ft_printf("Print pointer: %p hmm\n", p);
	i[5] = ft_printf("Print i1 = %i, num = %i \n", 10, INT_MIN);
	i[6] = ft_printf("Print hex = %x, HEX = %X \n", -42, 24532);
	ft_printf("POINTA %p\n", 0);
	ft_printf("POINTA %s\n", 0);
	
	i[7] = printf("Print percent: %% \n");
	i[8] = printf("Print char: %c\n", 'X');
	i[9] = printf("Print string: %s\n", "COOL");
	i[10] = printf("Print pointer: %p hmm\n", p);
	i[11] = printf("Print i1 = %i, num = %i \n", 10, INT_MIN);
	i[12] = printf("Print hex = %x, HEX = %X \n", -42, 24532);
	printf("POINTA %p\n", 0);
	printf("POINTA %s\n", 0);
	j = 0;
	while (j < 13)
	{
		printf("output of test %i == %i\n", j, i[j]);
		j++;
	}
	free(p);
	free(i);
	return (0);
}*/
