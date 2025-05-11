/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:06:55 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/11 15:48:41 by gostroum         ###   ########.fr       */
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
		return 0;
	i = 0;
	while (*s)
		i += ft_putchar(*(s++));
	return (i);
}

static int	ft_putnumber(int n)
{
	long	ln;
	int		ans;

	ans = 0;
	ln = n;
	if (ln == 0)
	{
		ft_putchar('0');
		return 1;
	}
	if (ln < 0)
	{
		ft_putchar('-');
		ln = -ln;
		ans += 1;
	}
	if (ln > 10)
		ans += ft_putnumber(ln / 10);
	ans += 1;
	ft_putchar(ln % 10 + '0');
	return (ans);
}

static int	ft_puthex(int n, int c)
{
	long	ln;
	int		ans;

	ln = n;
	ans = 0;
	if (ln == 0)
	{
		ft_putchar('0');
		return 1;
	}
	if (ln < 0)
	{
		ft_putchar('-');
		ln = -ln;
		ans += 1;
	}
	if (ln > 16)
		ans += ft_puthex(ln / 16, c);
	ans += 1;
	if (!c)
		ft_putchar("0123456789abcdef"[ln % 16]);
	else
		ft_putchar("0123456789ABCDEF"[ln % 16]);
	return (ans);
}

static int	ft_putpointer(const void *s)
{
	size_t	s_conv;

	if (!s)
		return ft_putstr("(null)");
	s_conv = (size_t)s;
	return (ft_putstr("0x") + ft_puthex(s_conv, 0) + ft_putchar('x'));
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
				ans += ft_putpointer(va_arg(args, void *));
			else if (str[i] == 'd')
				ans += ft_putnumber(va_arg(args, int) % 10);
			else if (str[i] == 'i')
				ans += ft_putnumber(va_arg(args, int));
			else if (str[i] == 'u')
				ans += ft_putnumber(va_arg(args, int));
			else if (str[i] == 'x')
				ans += ft_puthex(va_arg(args, int), 0);
			else if (str[i] == 'X')
				ans += ft_puthex(va_arg(args, int), 1);
			i++;
		}
	}
	return (ans);
}

#include <stdlib.h>

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
	i[5] = ft_printf("Print dec = %d, num = %i \n", 9, -2147483648);
	i[6] = ft_printf("Print hex = %x, HEX = %X \n", 12, 24532);
	
	i[7] = printf("Print percent: %% \n");
	i[8] = printf("Print char: %c\n", 'X');
	i[9] = printf("Print string: %s\n", "COOL");
	i[10] = printf("Print pointer: %p hmm\n", p);
	i[11] = printf("Print dec = %d, num = %i \n", 9, -2147483647);
	i[12] = printf("Print hex = %x, HEX = %X \n", 12, 24532);
	
	j = 0;
	while (j < 13)
	{
		printf("output of test %i == %i\n", j, i[j]);
		j++;
	}
	free(p);
	free(i);
	return (0);
}
