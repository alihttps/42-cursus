/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:10:23 by aait-bou          #+#    #+#             */
/*   Updated: 2023/12/25 19:27:05 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_s(va_list argp)
{
	char	*str;
	int		countchr;

	countchr = 0;
	str = va_arg(argp, char *);
	if (str == NULL)
		countchr += write(1, "(null)", 6);
	else
		countchr += ft_putstr(str);
	return (countchr);
}

static int	ft_printspec(char spec, va_list argp)
{
	int	countchr;

	countchr = 0;
	if (spec == '%')
		countchr += (write(1, "%", 1));
	else if (spec == 'c')
		countchr += ft_putchar(va_arg(argp, int));
	else if (spec == 's')
		countchr += (handle_s(argp));
	else if (spec == 'i' || spec == 'd')
		countchr += ft_putnbr((long)va_arg(argp, int), 10, spec);
	else if (spec == 'u')
		countchr += ft_putunsigned(va_arg(argp, unsigned int));
	else if (spec == 'x' || spec == 'X')
		countchr += ft_putnbr((long)va_arg(argp, unsigned int), 16, spec);
	else if (spec == 'p')
		countchr += ft_putadd(va_arg(argp, void *));
	else
		countchr = -1;
	return (countchr);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		countchr;
	int		i;

	i = 0;
	countchr = 0;
	va_start(argp, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			countchr += ft_printspec(format[i + 1], argp);
			i++;
		}
		else
			countchr += ft_putchar(format[i]);
		i++;
	}
	va_end(argp);
	return (countchr);
}
