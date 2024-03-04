/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:10:23 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/23 11:34:43 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* It takes a format string and a variable number of arguments. It uses
va_start() to initialize an argument list args. Then, it goes through the
format string character by character. If it finds a % character, it expects
the next character to be a format specifier (c, s, or d in this case) and
calls the corresponding function to write the next argument to standard
output. If the character is not a %, it simply writes it to standard
output. Finally, it uses va_end() to clean up args.*/

static int	ft_selector(va_list args, char const place)
{
	int	size;

	size = 0;
	if (place == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (place == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (place == 'd' || place == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (place == 'u')
		size += ft_putunbr(va_arg(args, unsigned int));
	else if (place == 'x' || place == 'X')
		size += ft_puthex(va_arg(args, unsigned int), place);/*
	else if (place == 'p')
		size += ft_putptr(va_arg(args, void *));*/
	else
		size += ft_putchar(place);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			size += ft_selector(args, format[i + 1]);
			i++;
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}

/*int main(void) 
{
	int i;
    i = ft_printf("hola %c %s %i %d %u %x %X", 'c', "HEllo", 547, -13, -1, 255, 255);
	printf("\n%d\n", i);
    return (0);
}*/
