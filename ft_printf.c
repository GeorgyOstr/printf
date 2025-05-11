/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:06:55 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/11 12:35:21 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
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
		}
		if (str[i])
			i++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("Hello %% dude\n");
	ft_printf("Hello %% dude%c\n", 'X');
	return (0);
}
