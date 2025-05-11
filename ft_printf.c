/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:06:55 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/11 14:50:27 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*(s++));
}

static void	ft_putpointer(const void *s)
{
	size_t	s_conv;

	s_conv = (size_t)s;
	printf("0x%zux", s_conv);
}

static void	ft_putnumber(int n)
{
	long	ln;

	ln = n;
	if (ln == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (ln < 0)
	{
		ft_putchar('-');
		ln = -ln;
	}
	if (ln > 10)
		ft_putnumber(ln / 10);
	ft_putchar(ln % 10 + '0');
}

static void	ft_puthex(int n, int c)
{
	long	ln;

	ln = n;
	if (ln == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (ln < 0)
	{
		ft_putchar('-');
		ln = -ln;
	}
	if (ln > 16)
		ft_puthex(ln / 16, c);
	ft_putchar("0123456789abcdefABCDEF"[ln % 16]);
	(void)c;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			ft_putchar(str[i++]);
		if (str[i] && str[i] == '%')
		{
			if (!str[++i])
				return (1);
			else if (str[i] == '%')
				ft_putchar('%');
			else if (str[i] == 'c')
				ft_putchar((char)va_arg(args, int));
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (str[i] == 'p')
				ft_putpointer(va_arg(args, void *));
			else if (str[i] == 'd')
				ft_putnumber(va_arg(args, int) % 10);
			else if (str[i] == 'i')
				ft_putnumber(va_arg(args, int));
			else if (str[i] == 'u')
				ft_putnumber(va_arg(args, int));
			else if (str[i] == 'x')
				ft_puthex(va_arg(args, int), 0);
			else if (str[i] == 'X')
				ft_puthex(va_arg(args, int), 1);
		}
		if (str[i])
			i++;
	}
	return (0);
}

#include <stdlib.h>

int	main(void)
{
	void	*p;

	p = malloc(0);
	ft_printf("Print percent: %% \n");
	ft_printf("Print char: %c\n", 'X');
	ft_printf("Print string: %s\n", "COOL");
	//ft_printf("Print pointer: %p hmm\n", p);
	ft_printf("Print dec = %d, num = %i \n", 9, -2147483648);
	ft_printf("Print hex = %x, HEX = %X", 12, 24532);
	free(p);
	return (0);
}
