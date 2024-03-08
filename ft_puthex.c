/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:37:44 by dabochko          #+#    #+#             */
/*   Updated: 2024/03/08 12:38:13 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*imprime un número en formato hexadecimal
Esta función funciona de manera similar a ft_putnbr(), pero en
lugar de dividir y tomar el módulo por 10, divide y toma el
módulo por 16, y luego usa el resultado para indexar en una
cadena de dígitos hexadecimales. Si n es mayor o igual a 16,
hace una llamada recursiva a ft_puthex(n / 16) para imprimir
los dígitos más significativos. Luego, imprime el dígito menos
significativo*/

static int	ft_size(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int n, char const place)
{
	int		size;
	char	*hex;
	char	*hex_digits2;

	size = ft_size(n);
	hex = "0123456789abcdef";
	hex_digits2 = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 16 && ft_puthex(n / 16, place) == -1)
		return (-1);
	if (place == 'x' && ft_putchar(hex[n % 16]) == -1)
		return (-1);
	if (place == 'X' && ft_putchar(hex_digits2[n % 16]) == -1)
		return (-1);
	return (size);
}
