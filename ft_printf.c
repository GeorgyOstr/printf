/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:06:55 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/11 13:15:26 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

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

#include <stdio.h>
static void ft_putpointer(const void *s)
{
	size_t	s_conv;
	
	s_conv = (size_t)s;
	printf("0x%zux", s_conv);
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
		}
		if (str[i])
			i++;
	}
	return (0);
}

#include <stdlib.h>
int	main(void)
{
	void *p = malloc(0);

	ft_printf("Hello %% dude\n");
	ft_printf("Hello %% dude%c\n", 'X');
	ft_printf("Hello %% dude%c, %s\n", 'X', "COOL");
	ft_printf("Hello %% dude%c, %s, %p hmm\n", 'X', "COOL", p);
	printf("Hi %-s", "padded?");
	return (0);
}
