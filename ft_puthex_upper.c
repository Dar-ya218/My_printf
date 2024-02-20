/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:42:14 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/20 14:44:05 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#includo "ft_printf.h"
/*imprime un número en formato hexadecimal
Esta función funciona de manera similar a ft_putnbr(), pero en
lugar de dividir y tomar el módulo por 10, divide y toma el
módulo por 16, y luego usa el resultado para indexar en una
cadena de dígitos hexadecimales. Si n es mayor o igual a 16,
hace una llamada recursiva a ft_puthex(n / 16) para imprimir
los dígitos más significativos. Luego, imprime el dígito menos
significativo*/
void	ft_puthex_upper(unsigned int n)
{
	char *hexDigits = "0123456789ABCDEF";

	if (n >= 16)
		ft_puthex_upper(n / 16);
	ft_putchar(hexDigits[n % 16]);
}
